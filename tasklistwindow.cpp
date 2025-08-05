#include "tasklistwindow.h"
#include "./ui_tasklistwindow.h"
#include "journalwindow.h"
#include "moodtracker.h"
#include <QTime>
#include <QListWidgetItem>
#include <QMessageBox>

taskListWindow::taskListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::taskListWindow)
{
    ui->setupUi(this);
    this->resize(810, 660);

    connect(ui->addTaskButton, &QPushButton::clicked, this, &taskListWindow::addTask);
    connect(ui->completeTaskButton, &QPushButton::clicked, this, &taskListWindow::completeSelectedTask);

    // Navigation button connections
    connect(ui->journalPageButton, &QPushButton::clicked, this, &taskListWindow::onJournalPageClicked);
    connect(ui->moodPageButton, &QPushButton::clicked, this, &taskListWindow::onMoodPageClicked);
    connect(ui->logoutButton, &QPushButton::clicked, this, &taskListWindow::onLogoutClicked);

    ui->taskTimeEdit->setTime(QTime::currentTime());

    initializeDatabase();
    loadTasksFromDatabase();
}

taskListWindow::~taskListWindow()
{
    delete ui;
}

void taskListWindow::initializeDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasks.db");

    if (!db.open()) {
        qWarning() << "Database error:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS tasks ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "task_text TEXT,"
               "task_time TEXT,"
               "completed INTEGER)");
}

void taskListWindow::loadTasksFromDatabase() {
    QSqlQuery query("SELECT task_text, task_time, completed FROM tasks");

    while (query.next()) {
        QString text = query.value(0).toString();
        QTime time = QTime::fromString(query.value(1).toString(), "hh:mm AP");
        bool completed = query.value(2).toInt();

        QString displayText = QString("[%1] %2").arg(time.toString("hh:mm AP")).arg(text);
        QListWidgetItem* item = new QListWidgetItem(displayText);
        item->setData(Qt::UserRole, time);
        item->setData(Qt::UserRole + 1, completed);

        if (completed) {
            QFont font = item->font();
            font.setStrikeOut(true);
            item->setFont(font);
            item->setForeground(Qt::gray);
        }

        ui->taskListWidget->addItem(item);
    }

    sortTaskList();
}

void taskListWindow::saveTaskToDatabase(const QString& text, const QTime& time, bool completed) {
    QSqlQuery query;
    query.prepare("INSERT INTO tasks (task_text, task_time, completed) VALUES (?, ?, ?)");
    query.addBindValue(text);
    query.addBindValue(time.toString("hh:mm AP"));
    query.addBindValue(completed ? 1 : 0);

    if (!query.exec()) {
        qWarning() << "Insert failed:" << query.lastError().text();
    }
}

void taskListWindow::markTaskAsCompletedInDatabase(const QString& text, const QTime& time) {
    QSqlQuery query;
    query.prepare("DELETE FROM tasks WHERE task_text = ? AND task_time = ?");
    query.addBindValue(text);
    query.addBindValue(time.toString("hh:mm AP"));

    if (!query.exec()) {
        qWarning() << "Delete failed:" << query.lastError().text();
    }
}

void taskListWindow::addTask()
{
    QString taskText = ui->taskInput->text().trimmed();
    QTime taskTime = ui->taskTimeEdit->time();
    if (taskText.isEmpty()) return;

    QString displayText = QString("[%1] %2").arg(taskTime.toString("hh:mm AP")).arg(taskText);

    QListWidgetItem* item = new QListWidgetItem(displayText);
    item->setData(Qt::UserRole, taskTime);
    item->setData(Qt::UserRole + 1, false);

    ui->taskListWidget->addItem(item);
    ui->taskInput->clear();

    sortTaskList();
    saveTaskToDatabase(taskText, taskTime, false);
}

void taskListWindow::sortTaskList()
{
    int count = ui->taskListWidget->count();

    struct TaskData {
        QTime time;
        QString text;
        bool isCompleted;
    };

    QList<TaskData> taskList;

    for (int i = 0; i < count; ++i) {
        QListWidgetItem* item = ui->taskListWidget->item(i);
        TaskData task;
        task.time = item->data(Qt::UserRole).toTime();
        task.text = item->text();
        task.isCompleted = item->data(Qt::UserRole + 1).toBool();
        taskList.append(task);
    }

    std::sort(taskList.begin(), taskList.end(), [](const TaskData& a, const TaskData& b) {
        return a.time < b.time;
    });

    ui->taskListWidget->clear();
    for (const TaskData& task : taskList) {
        QListWidgetItem* item = new QListWidgetItem(task.text);
        item->setData(Qt::UserRole, task.time);
        item->setData(Qt::UserRole + 1, task.isCompleted);

        if (task.isCompleted) {
            QFont font = item->font();
            font.setStrikeOut(true);
            item->setFont(font);
            item->setForeground(Qt::gray);
        }

        ui->taskListWidget->addItem(item);
    }
}

void taskListWindow::completeSelectedTask()
{
    QListWidgetItem* item = ui->taskListWidget->currentItem();
    if (!item) return;

    item->setData(Qt::UserRole + 1, true);

    QFont font = item->font();
    font.setStrikeOut(true);
    item->setFont(font);
    item->setForeground(Qt::gray);

    QString displayText = item->text();
    QString taskText = displayText.section("] ", 1);
    QTime taskTime = item->data(Qt::UserRole).toTime();

    markTaskAsCompletedInDatabase(taskText, taskTime);
}

// Navigation Handlers
void taskListWindow::onJournalPageClicked()
{
    this->hide();
    JournalWindow *journalWin = new JournalWindow();
    journalWin->show();
}

void taskListWindow::onMoodPageClicked()
{
    auto *moodWin = new MoodTracker();
    moodWin->show();
    this->close();
}

void taskListWindow::onLogoutClicked()
{
    QMessageBox::information(this, "Logout", "Logging out...");
}
