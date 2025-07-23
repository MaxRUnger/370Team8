#ifndef TASKLISTWINDOW_H
#define TASKLISTWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

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

private:
    Ui::taskListWindow *ui;
};

#endif // TASKLISTWINDOW_H
