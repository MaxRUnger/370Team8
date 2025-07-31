#ifndef MOODTRACKER_H
#define MOODTRACKER_H

#include <QWidget>
#include <QString> // This is needed for QString.


QT_BEGIN_NAMESPACE
namespace Ui {
class MoodTracker;
}
QT_END_NAMESPACE

struct Recommendation {
    QString shortTask;
    QString longTask;
};

class MoodTracker : public QWidget
{
    Q_OBJECT

public:
    MoodTracker(QWidget *parent = nullptr);
    ~MoodTracker();

signals:
    void goToLoginPage();
    void goToJournalPage();
    void goToTasksPage();

private slots:
    void handleSubmit();
    void handleLoginClicked();
    void handleJournalClicked();
    void handleTasksClicked();


private:
    Ui::MoodTracker *ui;
    // Adding my function declarations for the recommendation logic

    int previousMood = 0;
    int previousEnergy = 0;
    int previousAnxiety = 0;


    Recommendation getMoodRecommendation(int mood);
    Recommendation getAnxietyRecommendation(int anxiety);
    Recommendation getEnergyRecommendation(int energy);

};
#endif // MOODTRACKER_H
