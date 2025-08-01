#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MoodTracker;
class JournalWindow;
class QStackedWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stack;
    MoodTracker *moodTracker;
    JournalWindow *journalWindow;
};

#endif // MAINWINDOW_H
