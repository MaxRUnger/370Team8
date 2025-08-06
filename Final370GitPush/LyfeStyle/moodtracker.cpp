#include "moodtracker.h"
#include "ui_moodtracker.h"
#include "journalwindow.h"
#include "tasklistwindow.h"
#include "DatabaseManager.h"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

struct Recommendation {
    QString shortTask;
    QString longTask;
};

MoodTracker::MoodTracker(const QString &username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MoodTracker)
    , m_username(username)
{
    ui->setupUi(this);
    this->resize(810, 660);
    this->setWindowTitle("Mood Window");

    ui->MoodSlider->setRange(1, 6);
    ui->EnergySlider->setRange(1, 6);
    ui->AnxietySlider->setRange(1, 6);

    ui->MoodRecommendationLabel->setTextFormat(Qt::RichText);
    ui->AnxietyRecommendationLabel->setTextFormat(Qt::RichText);
    ui->EnergyRecommendationLabel->setTextFormat(Qt::RichText);

    ui->MoodRecommendationLabel->setOpenExternalLinks(true);
    ui->AnxietyRecommendationLabel->setOpenExternalLinks(true);
    ui->EnergyRecommendationLabel->setOpenExternalLinks(true);

    connect(ui->SubmitButton, &QPushButton::clicked, this, &MoodTracker::handleSubmit);
    connect(ui->LoginButton, &QPushButton::clicked, this, &MoodTracker::handleLoginClicked);
    connect(ui->JournalButton, &QPushButton::clicked, this, &MoodTracker::handleJournalClicked);
    connect(ui->TasksButton, &QPushButton::clicked, this, &MoodTracker::handleTasksClicked);

    loadPreviousMood();
}

MoodTracker::~MoodTracker()
{
    delete ui;
}

void MoodTracker::handleSubmit()
{
    int mood = ui->MoodSlider->value();
    int energy = ui->EnergySlider->value();
    int anxiety = ui->AnxietySlider->value();

    previousMood = mood;
    previousEnergy = energy;
    previousAnxiety = anxiety;

    Recommendation moodRec = getMoodRecommendation(mood);
    Recommendation anxietyRec = getAnxietyRecommendation(anxiety);
    Recommendation energyRec = getEnergyRecommendation(energy);

    ui->MoodRecommendationLabel->setText("Short task: " + moodRec.shortTask + "<br>Long task: " + moodRec.longTask);
    ui->AnxietyRecommendationLabel->setText("Short task: " + anxietyRec.shortTask + "<br>Long task: " + anxietyRec.longTask);
    ui->EnergyRecommendationLabel->setText("Short task: " + energyRec.shortTask + "<br>Long task: " + energyRec.longTask);

    saveMoodToDatabase();

    QSqlQuery recQuery(DatabaseManager::getDatabase());
    recQuery.prepare(R"(
        INSERT INTO recommendations (
            username,
            mood_short, mood_long,
            energy_short, energy_long,
            anxiety_short, anxiety_long
        ) VALUES (?, ?, ?, ?, ?, ?, ?)
    )");
    recQuery.addBindValue(m_username);
    recQuery.addBindValue(moodRec.shortTask);
    recQuery.addBindValue(moodRec.longTask);
    recQuery.addBindValue(energyRec.shortTask);
    recQuery.addBindValue(energyRec.longTask);
    recQuery.addBindValue(anxietyRec.shortTask);
    recQuery.addBindValue(anxietyRec.longTask);

    if (!recQuery.exec()) {
        qDebug() << "Failed to insert recommendations:" << recQuery.lastError().text();
    }

    QSqlQuery resetQuery(DatabaseManager::getDatabase());
    resetQuery.prepare("DELETE FROM recommendations_cleared WHERE username = ?");
    resetQuery.addBindValue(m_username);
    resetQuery.exec();

    loadPreviousMood();
}

void MoodTracker::loadPreviousMood()
{
    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("SELECT mood, energy, anxiety FROM moods WHERE username = ? ORDER BY timestamp DESC LIMIT 1");
    query.addBindValue(m_username);

    if (query.exec() && query.next()) {
        previousMood = query.value(0).toInt();
        previousEnergy = query.value(1).toInt();
        previousAnxiety = query.value(2).toInt();

        ui->PreviousMoodLabel->setText("Previous mood: " + QString::number(previousMood));
        ui->PreviousEnergyLabel->setText("Previous energy: " + QString::number(previousEnergy));
        ui->PreviousAnxietyLabel->setText("Previous anxiety: " + QString::number(previousAnxiety));
    }
}

void MoodTracker::saveMoodToDatabase()
{
    QSqlQuery query(DatabaseManager::getDatabase());
    query.prepare("INSERT INTO moods (username, mood, energy, anxiety, timestamp) VALUES (?, ?, ?, ?, datetime('now'))");
    query.addBindValue(m_username);
    query.addBindValue(previousMood);
    query.addBindValue(previousEnergy);
    query.addBindValue(previousAnxiety);

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void MoodTracker::handleLoginClicked()
{
    QApplication::quit();
}

void MoodTracker::handleJournalClicked()
{
    auto *journalWin = new JournalWindow(m_username);
    journalWin->show();
    this->close();
}

void MoodTracker::handleTasksClicked()
{
    auto *taskWin = new taskListWindow(m_username);
    taskWin->show();
    this->close();
}

Recommendation MoodTracker::getMoodRecommendation(int mood) {
    switch (mood) {
    case 1: return {"Journal for 10 minutes", "Call a support line or talk with a friend for 45 minutes"};
    case 2: return {"Watch a calming YouTube video", "Take a slow walk in nature"};
    case 3: return {"Listen to instrumental music", "Write out feelings in a private journal"};
    case 4: return {"Do a short drawing or sketch", "Do a 45-minute workout or creative project"};
    case 5: return {"Send a kind message to someone", "Go out for a social event"};
    case 6: return {"Dance to music for 10 mins", "Spend time with friends doing a shared activity"};
    default: return {"No mood task", "No mood task"};
    }
}

Recommendation MoodTracker::getAnxietyRecommendation(int anxiety) {
    switch (anxiety) {
    case 1: return {
            "Do breathwork for 10 minutes<br><a href='https://www.youtube.com/watch?v=9rP8VQVbwtE'>Watch: Balancing Breathwork</a>",
            "Go for a long walk or hike"
        };
    case 2: return {
            "Draw, do crafts, or practice an instrument",
            "Do yoga or meditation<br><a href='https://www.youtube.com/watch?v=4pLUleLdwY4'>Watch: Deep Stretch Yoga</a>"
        };
    case 3: return {
            "Listen to calming music or nature sounds",
            "Write in a journal or do a brain dump for 20 minutes"
        };
    case 4: return {"Make a to-do list", "Clean a room or reorganize a space"};
    case 5: return {"Take a warm shower", "Have a long talk with someone trusted"};
    case 6: return {"Hold ice cube in hand for focus", "See therapist or journal deeply for 45+ minutes"};
    default: return {"No anxiety task", "No anxiety task"};
    }
}

Recommendation MoodTracker::getEnergyRecommendation(int energy) {
    switch (energy) {
    case 1: return {
            "Have a cup of coffee and splash cold water on your face",
            "Listen to music and nap for an hour"
        };
    case 2: return {
            "Stretch outside<br><a href='https://www.youtube.com/watch?v=qULTwquOuT4'>Watch: 8-Minute Stretch</a>",
            "Walk and breathwork<br><a href='https://www.youtube.com/watch?v=9rP8VQVbwtE'>Watch: Breathwork</a>"
        };
    case 3: return {"Make tea or coffee", "Read a book or study for 45 minutes"};
    case 4: return {
            "Stretch / Plyometrics<br><a href='https://www.youtube.com/watch?v=Go2vqMYufKs'>Watch: Plyo Basics</a>",
            "Clean your room or take a walk"
        };
    case 5: return {
            "Do HIIT workout<br><a href='https://www.youtube.com/watch?v=cbKkB3POqaY'>Watch: 15-Min HIIT</a>",
            "Run errands or complete a major chore"
        };
    case 6: return {"Run intervals: 2 mins fast / 1 min slow", "Do a high-focus study or work session"};
    default: return {"No energy task", "No energy task"};
    }
}
