#ifndef JOURNALWINDOW_H
#define JOURNALWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class JournalWindow;
}
QT_END_NAMESPACE

class JournalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit JournalWindow(const QString &username, QWidget *parent = nullptr);
    ~JournalWindow();

private slots:
    void onSaveEntryClicked();
    void onDeleteEntryClicked();
    void onEntrySelected(QListWidgetItem *item);
    void onLogoutClicked();
    void onMoodPageClicked();
    void onTaskListPageClicked();

private:
    Ui::JournalWindow *ui;
    QString m_username;

    void loadEntries();
};

#endif // JOURNALWINDOW_H
