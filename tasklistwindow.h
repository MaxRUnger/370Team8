#ifndef TASKLISTWINDOW_H
#define TASKLISTWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class taskListWindow; }
QT_END_NAMESPACE

class taskListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit taskListWindow(QWidget *parent = nullptr);
    ~taskListWindow();

private slots:
    void addTask();
    void sortTaskList();
    void completeSelectedTask();

    // 🔗 New slots for navigation
    void onJournalPageClicked();
    void onMoodPageClicked();
    void onLogoutClicked();

private:
    Ui::taskListWindow *ui;

    void initializeDatabase();
    void loadTasksFromDatabase();
    void saveTaskToDatabase(const QString& text, const QTime& time, bool completed);
    void markTaskAsCompletedInDatabase(const QString& text, const QTime& time);
};

#endif // TASKLISTWINDOW_H
