#include "moodtracker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MoodTracker w;
    w.show();
    return a.exec();
}
