#include "journalwindow.h"
#include "tasklistwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JournalWindow w;
    w.show();
    return a.exec();
}
