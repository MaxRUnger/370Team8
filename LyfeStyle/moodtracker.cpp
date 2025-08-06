#include "journalwindow.h"
#include "tasklistwindow.h"
#include <QApplication>

#include "moodtracker.h"
#include "ui_moodtracker.h"
#include <QDebug>
#include <QLabel>
#include <QHBoxLayout>
#include <QMessageBox>

MoodTracker::MoodTracker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MoodTracker)
{
    ui->setupUi(this);
    this->resize(810, 660);

    // Set slider ranges from 1 to 6
    ui->MoodSlider->setRange(1, 6);
    ui->EnergySlider->setRange(1, 6);
    ui->AnxietySlider->setRange(1, 6);

    // Enable rich text and clickable links in recommendation labels
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

    qDebug() << "Mood:" << mood << "Energy:" << energy << "Anxiety:" << anxiety;

    previousMood = mood;
    previousEnergy = energy;
    previousAnxiety = anxiety;

    ui->PreviousMoodLabel->setText("Previous mood: " + QString::number(previousMood));
    ui->PreviousEnergyLabel->setText("Previous energy: " + QString::number(previousEnergy));
    ui->PreviousAnxietyLabel->setText("Previous anxiety: " + QString::number(previousAnxiety));

    Recommendation moodRec = getMoodRecommendation(mood);
    Recommendation anxietyRec = getAnxietyRecommendation(anxiety);
    Recommendation energyRec = getEnergyRecommendation(energy);

    ui->MoodRecommendationLabel->setText(
        "Short task: " + moodRec.shortTask + "<br>Long task: " + moodRec.longTask);
    ui->AnxietyRecommendationLabel->setText(
        "Short task: " + anxietyRec.shortTask + "<br>Long task: " + anxietyRec.longTask);
    ui->EnergyRecommendationLabel->setText(
        "Short task: " + energyRec.shortTask + "<br>Long task: " + energyRec.longTask);
}

// NAVIGATION
void MoodTracker::handleLoginClicked()
{
    QApplication::quit();
}

void MoodTracker::handleJournalClicked()
{
    auto *journalWin = new JournalWindow();
    journalWin->show();
    this->close();
}

void MoodTracker::handleTasksClicked()
{
    auto *taskWin = new taskListWindow();
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
    case 3:
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
