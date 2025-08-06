#ifndef TASKLISTWINDOW_H
#define TASKLISTWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class taskListWindow;
}

class taskListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit taskListWindow(const QString& username, QWidget *parent = nullptr);
    ~taskListWindow();

private slots:
    void onJournalPageClicked();
    void onMoodPageClicked();
    void onLogoutClicked();
    void on_clearRecButtonClicked();
    void on_addTaskButton_clicked();
    void on_completeTaskButton_clicked();

private:
    Ui::taskListWindow *ui;
    QString m_username;
    bool recommendationsCleared = false;

    void loadTasksFromDatabase();
    void loadMoodRecommendations();
};

#endif // TASKLISTWINDOW_H
