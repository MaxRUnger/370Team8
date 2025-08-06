#ifndef MOODTRACKER_H
#define MOODTRACKER_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MoodTracker;
}
QT_END_NAMESPACE

class MoodTracker : public QMainWindow
{
    Q_OBJECT

public:
    explicit MoodTracker(const QString &username, QWidget *parent = nullptr);
    ~MoodTracker();

private slots:
    void handleSubmit();
    void handleLoginClicked();
    void handleJournalClicked();
    void handleTasksClicked();

private:
    Ui::MoodTracker *ui;
    QString m_username;

    int previousMood = 0;
    int previousEnergy = 0;
    int previousAnxiety = 0;

    void loadPreviousMood();
    void saveMoodToDatabase();

    struct Recommendation getMoodRecommendation(int mood);
    struct Recommendation getAnxietyRecommendation(int anxiety);
    struct Recommendation getEnergyRecommendation(int energy);
};

#endif // MOODTRACKER_H
