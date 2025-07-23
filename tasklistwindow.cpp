#include "tasklistwindow.h"
#include "./ui_tasklistwindow.h"
#include <QTime>
#include <QListWidgetItem>

taskListWindow::taskListWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::taskListWindow)
{
    ui->setupUi(this);

    // Connect the Add Task button to the addTask function
    connect(ui->addTaskButton, &QPushButton::clicked, this, &taskListWindow::addTask);


    // Set the current time as default in the QTimeEdit
    ui->taskTimeEdit->setTime(QTime::currentTime());

    // Set the current task to complete
    connect(ui->completeTaskButton, &QPushButton::clicked,
            this, &taskListWindow::completeSelectedTask);


}

taskListWindow::~taskListWindow()
{
    delete ui;
}

void taskListWindow::addTask()
{
    QString taskText = ui->taskInput->text().trimmed();
    QTime taskTime = ui->taskTimeEdit->time();

    if (taskText.isEmpty()) return;

    // Create display string: [02:30 PM] Task
    QString displayText = QString("[%1] %2")
                              .arg(taskTime.toString("hh:mm AP"))
                              .arg(taskText);

    // Create a new list item
    QListWidgetItem* item = new QListWidgetItem(displayText);

    item->setData(Qt::UserRole, taskTime);         // time
    item->setData(Qt::UserRole + 1, false);        // isCompleted


    // Add the item to the list
    ui->taskListWidget->addItem(item);

    // Clear the input
    ui->taskInput->clear();

    // Sort the list by stored time
    sortTaskList();
}


    // Sorting to put the task in order by timeslots
void taskListWindow::sortTaskList()
{
    int count = ui->taskListWidget->count();
    struct TaskData {
        QTime time;
        QString text;
        bool isCompleted;
    };

    QList<TaskData> taskList;

    // Extract task data
    for (int i = 0; i < count; ++i) {
        QListWidgetItem* item = ui->taskListWidget->item(i);
        TaskData task;
        task.time = item->data(Qt::UserRole).toTime();
        task.text = item->text();
        task.isCompleted = item->data(Qt::UserRole + 1).toBool();
        taskList.append(task);
    }

    // Sort by time
    std::sort(taskList.begin(), taskList.end(), [](const TaskData& a, const TaskData& b) {
        return a.time < b.time;
    });

    // Clear and re-add
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

    // Marks the task as complete for the day
void taskListWindow::completeSelectedTask()
{
    QListWidgetItem* item = ui->taskListWidget->currentItem();
    if (!item) return;

    item->setData(Qt::UserRole + 1, true);  // Mark as completed

    QFont font = item->font();
    font.setStrikeOut(true);
    item->setFont(font);

    item->setForeground(Qt::gray);
}







