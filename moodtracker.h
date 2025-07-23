#ifndef MOODTRACKER_H
#define MOODTRACKER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MoodTracker;
}
QT_END_NAMESPACE

class MoodTracker : public QWidget
{
    Q_OBJECT

public:
    MoodTracker(QWidget *parent = nullptr);
    ~MoodTracker();

private slots:
    void handleSubmit();

private:
    Ui::MoodTracker *ui;
};
#endif // MOODTRACKER_H
