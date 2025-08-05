#ifndef JOURNALWINDOW_H
#define JOURNALWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class JournalWindow; }
QT_END_NAMESPACE

class JournalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit JournalWindow(QWidget *parent = nullptr);
    ~JournalWindow();

private slots:
    void onAddEntryClicked();
    void onDeleteEntryClicked();
    void onEntrySelected();
    void onDatetimeClicked();

    // Navigation buttons
    void onTaskListButtonClicked();
    void onMoodPageButtonClicked();
    void onLogoutButtonClicked();

private:
    Ui::JournalWindow *ui;
    QSqlDatabase db;

    void connectDatabase();
    void loadEntries();
};

#endif // JOURNALWINDOW_H
