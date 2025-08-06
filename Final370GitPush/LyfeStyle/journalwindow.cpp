#include "journalwindow.h"
#include "ui_journalwindow.h"
#include "moodtracker.h"
#include "tasklistwindow.h"
#include "DatabaseManager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>

JournalWindow::JournalWindow(const QString &username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JournalWindow)
    , m_username(username)
{
    ui->setupUi(this);
    this->resize(810, 660);
    this->setWindowTitle("Journal Window");

    connect(ui->addEntryButton, &QPushButton::clicked, this, &JournalWindow::onSaveEntryClicked);
    connect(ui->deleteEntryButton, &QPushButton::clicked, this, &JournalWindow::onDeleteEntryClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &JournalWindow::onLogoutClicked);
    connect(ui->moodPageButton, &QPushButton::clicked, this, &JournalWindow::onMoodPageClicked);
    connect(ui->tasklistButton, &QPushButton::clicked, this, &JournalWindow::onTaskListPageClicked);
    connect(ui->entryListWidget, &QListWidget::itemClicked, this, &JournalWindow::onEntrySelected);

    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    loadEntries();
}

JournalWindow::~JournalWindow()
{
    delete ui;
}

void JournalWindow::loadEntries()
{
    ui->entryListWidget->clear();

    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("SELECT id, entry_name, timestamp FROM journal_entries WHERE username = ? ORDER BY timestamp DESC");
    query.addBindValue(m_username);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        QString entryName = query.value(1).toString();
        QString isoTimestamp = query.value(2).toString();
        QDateTime datetime = QDateTime::fromString(isoTimestamp, Qt::ISODate);
        QString formattedTime = datetime.toString("yyyy-MM-dd hh:mm AP");

        QString itemText = entryName + " [" + formattedTime + "]";
        QListWidgetItem *item = new QListWidgetItem(itemText);
        item->setData(Qt::UserRole, id);  // Store DB ID for deletion
        ui->entryListWidget->addItem(item);
    }
}


void JournalWindow::onSaveEntryClicked()
{
    QString entry = ui->journalTextEdit->toPlainText();
    QString entryName = ui->nameEntryEdit->text();
    QString timestamp = ui->dateTimeEdit->dateTime().toString(Qt::ISODate);

    if (entry.isEmpty() || entryName.isEmpty()) {
        QMessageBox::warning(this, "Incomplete Entry", "Please enter both a name and content before saving.");
        return;
    }

    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("INSERT INTO journal_entries (username, entry_name, entry, timestamp) VALUES (?, ?, ?, ?)");
    query.addBindValue(m_username);
    query.addBindValue(entryName);
    query.addBindValue(entry);
    query.addBindValue(timestamp);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        return;
    }

    loadEntries();
    ui->journalTextEdit->clear();
    ui->nameEntryEdit->clear();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}



void JournalWindow::onDeleteEntryClicked()
{
    QListWidgetItem *item = ui->entryListWidget->currentItem();
    if (!item) return;

    int entryId = item->data(Qt::UserRole).toInt();

    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("DELETE FROM journal_entries WHERE id = ? AND username = ?");
    query.addBindValue(entryId);
    query.addBindValue(m_username);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete entry:\n" + query.lastError().text());
        return;
    }

    delete item;
    ui->journalTextEdit->clear();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void JournalWindow::onEntrySelected(QListWidgetItem *item)
{
    if (!item) return;

    int entryId = item->data(Qt::UserRole).toInt();

    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("SELECT entry, entry_name, timestamp FROM journal_entries WHERE id = ? AND username = ?");
    query.addBindValue(entryId);
    query.addBindValue(m_username);

    if (query.exec() && query.next()) {
        QString entry = query.value(0).toString();
        QString entryName = query.value(1).toString();
        QString timestamp = query.value(2).toString();
        QDateTime datetime = QDateTime::fromString(timestamp, Qt::ISODate);

        ui->journalTextEdit->setPlainText(entry);
        ui->nameEntryEdit->setText(entryName);
        ui->dateTimeEdit->setDateTime(datetime);
    }
}


void JournalWindow::onLogoutClicked()
{
    QApplication::quit();
}

void JournalWindow::onMoodPageClicked()
{
    auto *mood = new MoodTracker(m_username);
    mood->show();
    this->close();
}

void JournalWindow::onTaskListPageClicked()
{
    auto *tasks = new taskListWindow(m_username);
    tasks->show();
    this->close();
}
