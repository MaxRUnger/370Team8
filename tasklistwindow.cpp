#include "tasklistwindow.h"
#include "ui_tasklistwindow.h"
#include "journalwindow.h"
#include "moodtracker.h"
#include "DatabaseManager.h"

#include <QListWidgetItem>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QRegularExpression>

taskListWindow::taskListWindow(const QString& username, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::taskListWindow),
    m_username(username)
{
    ui->setupUi(this);
    this->resize(810, 660);
    this->setWindowTitle("Tasklist Window");

    loadTasksFromDatabase();
    loadMoodRecommendations();

    connect(ui->clearRecButton, &QPushButton::clicked, this, &taskListWindow::on_clearRecButtonClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &taskListWindow::onLogoutClicked);
    connect(ui->journalPageButton, &QPushButton::clicked, this, &taskListWindow::onJournalPageClicked);
    connect(ui->moodPageButton, &QPushButton::clicked, this, &taskListWindow::onMoodPageClicked);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &taskListWindow::on_addTaskButton_clicked);
    connect(ui->completeTaskButton, &QPushButton::clicked, this, &taskListWindow::on_completeTaskButton_clicked);
}

taskListWindow::~taskListWindow()
{
    delete ui;
}

void taskListWindow::loadTasksFromDatabase()
{
    ui->taskListWidget->clear();

    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("SELECT task_text, timestamp FROM tasks WHERE username = ? ORDER BY timestamp ASC");
    query.addBindValue(m_username);

    if (query.exec()) {
        while (query.next()) {
            QString taskText = query.value(0).toString();
            QString timestamp = query.value(1).toString();
            QTime time = QTime::fromString(timestamp, "HH:mm");
            QString displayTime = time.toString("hh:mm AP");
            QString displayText = QString("[%1] %2").arg(displayTime, taskText);
            ui->taskListWidget->addItem(displayText);
        }
    } else {
        qDebug() << "Failed to load tasks:" << query.lastError().text();
    }
}

void taskListWindow::on_addTaskButton_clicked()
{
    QString taskText = ui->taskInput->text().trimmed();
    QString timeText = ui->taskTimeEdit->time().toString("HH:mm");  // Store in sortable 24-hour format

    if (taskText.isEmpty()) return;

    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("INSERT INTO tasks (username, task_text, timestamp) VALUES (?, ?, ?)");
    query.addBindValue(m_username);
    query.addBindValue(taskText);
    query.addBindValue(timeText);

    if (!query.exec()) {
        qDebug() << "Failed to insert task:" << query.lastError().text();
        return;
    }

    ui->taskInput->clear();
    loadTasksFromDatabase();
}

void taskListWindow::on_completeTaskButton_clicked()
{
    QListWidgetItem* selectedItem = ui->taskListWidget->currentItem();
    if (!selectedItem) return;

    QString taskDisplay = selectedItem->text();

    QRegularExpression re(R"(\[(.*?)\] (.+))");
    QRegularExpressionMatch match = re.match(taskDisplay);

    if (!match.hasMatch()) return;

    QString displayTime = match.captured(1);
    QString taskText = match.captured(2);

    QTime time = QTime::fromString(displayTime, "hh:mm AP");
    QString dbTime = time.toString("HH:mm");

    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("DELETE FROM tasks WHERE username = ? AND task_text = ? AND timestamp = ?");
    query.addBindValue(m_username);
    query.addBindValue(taskText);
    query.addBindValue(dbTime);

    if (!query.exec()) {
        qDebug() << "Failed to delete task:" << query.lastError().text();
        return;
    }

    QFont font = selectedItem->font();
    font.setStrikeOut(true);
    selectedItem->setFont(font);
    selectedItem->setForeground(Qt::gray);
}

void taskListWindow::loadMoodRecommendations()
{
    QSqlQuery checkQuery(DatabaseManager::getDatabase());
    checkQuery.prepare("SELECT 1 FROM recommendations_cleared WHERE username = ?");
    checkQuery.addBindValue(m_username);

    if (checkQuery.exec() && checkQuery.next()) return;

    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare(R"(
        SELECT mood_short, mood_long, energy_short, energy_long, anxiety_short, anxiety_long
        FROM recommendations
        WHERE username = ?
        ORDER BY timestamp DESC
        LIMIT 1
    )");
    query.addBindValue(m_username);

    if (query.exec() && query.next()) {
        QStringList recs = {
            "Mood - Short: " + query.value(0).toString(),
            "Mood - Long: " + query.value(1).toString(),
            "Energy - Short: " + query.value(2).toString(),
            "Energy - Long: " + query.value(3).toString(),
            "Anxiety - Short: " + query.value(4).toString(),
            "Anxiety - Long: " + query.value(5).toString()
        };

        auto cleanAndAdd = [&](const QString &text) {
            QString cleaned = text;
            cleaned.replace(QRegularExpression(R"(<[^>]*>)"), " ");
            cleaned = cleaned.simplified();
            if (!cleaned.trimmed().isEmpty()) {
                ui->recommendListWidget->addItem(cleaned.trimmed());
            }
        };

        ui->recommendListWidget->clear();
        for (const QString& rec : recs) {
            cleanAndAdd(rec);
        }
    } else {
        qDebug() << "No recommendations found or query failed:" << query.lastError().text();
    }
}

void taskListWindow::on_clearRecButtonClicked()
{
    QSqlQuery clearQuery(DatabaseManager::getDatabase());
    clearQuery.prepare("INSERT OR IGNORE INTO recommendations_cleared (username) VALUES (?)");
    clearQuery.addBindValue(m_username);
    if (!clearQuery.exec()) {
        qDebug() << "Failed to clear recommendations for user:" << clearQuery.lastError().text();
    }

    ui->recommendListWidget->clear();
}

void taskListWindow::onJournalPageClicked()
{
    auto *journalWindow = new JournalWindow(m_username);
    journalWindow->show();
    this->close();
}

void taskListWindow::onMoodPageClicked()
{
    auto *moodWindow = new MoodTracker(m_username);
    moodWindow->show();
    this->close();
}

void taskListWindow::onLogoutClicked()
{
    qApp->quit();
}
