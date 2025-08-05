#include "journalwindow.h"
#include "ui_journalwindow.h"
#include "tasklistwindow.h"
#include "moodtracker.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QMessageBox>

JournalWindow::JournalWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JournalWindow)
{
    ui->setupUi(this);
    this->resize(810, 660);

    connectDatabase();
    loadEntries();

    // Entry-related buttons
    connect(ui->addEntryButton, &QPushButton::clicked, this, &JournalWindow::onAddEntryClicked);
    connect(ui->deleteEntryButton, &QPushButton::clicked, this, &JournalWindow::onDeleteEntryClicked);
    connect(ui->dateTimeEdit, &QDateTimeEdit::editingFinished, this, &JournalWindow::onDatetimeClicked);
    connect(ui->entryListWidget, &QListWidget::itemClicked, this, &JournalWindow::onEntrySelected);

    // Navigation buttons
    connect(ui->tasklistButton, &QPushButton::clicked, this, &JournalWindow::onTaskListButtonClicked);
    connect(ui->moodPageButton, &QPushButton::clicked, this, &JournalWindow::onMoodPageButtonClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &JournalWindow::onLogoutButtonClicked);
}

JournalWindow::~JournalWindow()
{
    db.close();
    delete ui;
}

void JournalWindow::connectDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("journal.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS entries ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT, "
               "timestamp TEXT, "
               "content TEXT)");
}

void JournalWindow::loadEntries()
{
    ui->entryListWidget->clear();

    QSqlQuery query("SELECT id, name, timestamp FROM entries ORDER BY id DESC", db);
    while (query.next()) {
        QString name = query.value(1).toString();
        QString isoTimestamp = query.value(2).toString();

        QDateTime datetime = QDateTime::fromString(isoTimestamp, Qt::ISODate);
        QString formattedTime = datetime.toString("yyyy-MM-dd hh:mm AP");

        QString itemText = name + " [" + formattedTime + "]";
        ui->entryListWidget->addItem(itemText);
    }
}

void JournalWindow::onAddEntryClicked()
{
    QString name = ui->nameEntryEdit->text().trimmed();
    QString timestamp = ui->dateTimeEdit->dateTime().toString(Qt::ISODate);
    QString content = ui->journalTextEdit->toPlainText().trimmed();

    if (name.isEmpty() || content.isEmpty()) {
        QMessageBox::warning(this, "Missing Info", "Please enter both a name and journal content.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO entries (name, timestamp, content) VALUES (?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(timestamp);
    query.addBindValue(content);

    if (!query.exec()) {
        QMessageBox::critical(this, "Insert Failed", query.lastError().text());
        return;
    }

    ui->nameEntryEdit->clear();
    ui->journalTextEdit->clear();

    loadEntries();
}

void JournalWindow::onDeleteEntryClicked()
{
    QListWidgetItem *item = ui->entryListWidget->currentItem();
    if (!item) return;

    QString label = item->text();
    QString name = label.section(" [", 0, 0).trimmed();
    QString timestamp = label.section(" [", 1).chopped(1).trimmed();

    QSqlQuery query;
    query.prepare("DELETE FROM entries WHERE name = ? AND timestamp = ?");
    query.addBindValue(name);
    query.addBindValue(timestamp);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to delete entry from database:\n" + query.lastError().text());
        return;
    }

    delete item;
    ui->journalTextEdit->clear();
    ui->nameEntryEdit->clear();
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void JournalWindow::onEntrySelected()
{
    QListWidgetItem *item = ui->entryListWidget->currentItem();
    if (!item) return;

    QString label = item->text();
    QString name = label.section(" [", 0, 0);

    QSqlQuery query;
    query.prepare("SELECT content FROM entries WHERE name = ?");
    query.addBindValue(name);

    if (query.exec() && query.next()) {
        QString content = query.value(0).toString();
        ui->journalTextEdit->setPlainText(content);
    }
}

void JournalWindow::onDatetimeClicked()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

// ✅ Mood Page Button — IMPLEMENTED
void JournalWindow::onMoodPageButtonClicked()
{
    auto *moodWin = new MoodTracker();
    moodWin->show();
    this->close();
}

void JournalWindow::onTaskListButtonClicked()
{
    auto *taskWin = new taskListWindow();
    taskWin->show();
    this->close();
}

void JournalWindow::onLogoutButtonClicked()
{
    QApplication::quit();
}
