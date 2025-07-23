#ifndef JOURNALWINDOW_H
#define JOURNALWINDOW_H

#include <QMainWindow>
#include "journal.h"

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
    void onEntrySelected();
    void onAddClicked();
    void onDeleteClicked();

private:
    Ui::JournalWindow *ui;
    Journal journal;

    int selectedId = -1;
    void refreshEntryList();
};
#endif // JOURNALWINDOW_H
