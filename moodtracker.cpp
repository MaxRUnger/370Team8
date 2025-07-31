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

    // Set slider ranges from 1 to 6
    ui->MoodSlider->setRange(1, 6);
    ui->EnergySlider->setRange(1, 6);
    ui->AnxietySlider->setRange(1, 6); // Renamed from EmotionSlider

    connect(ui->SubmitButton, &QPushButton::clicked,this, &MoodTracker::handleSubmit);
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

    // Save current values as previous answers
    previousMood = mood;
    previousEnergy = energy;
    previousAnxiety = anxiety;

    // Update previous answer labels
    ui->PreviousMoodLabel->setText("Previous Mood: " + QString::number(previousMood));
    ui->PreviousEnergyLabel->setText("Previous Energy: " + QString::number(previousEnergy));
    ui->PreviousAnxietyLabel->setText("Previous Anxiety: " + QString::number(previousAnxiety));




    Recommendation moodRec = getMoodRecommendation(mood);
    Recommendation anxietyRec = getAnxietyRecommendation(anxiety);
    Recommendation energyRec = getEnergyRecommendation(energy);

    QString output;
    output += "Mood Recommendations:\n";
    output += "  Short Task: " + moodRec.shortTask + "\n";
    output += "  Long Task: " + moodRec.longTask + "\n\n";

    output += "Anxiety Recommendations:\n";
    output += "  Short Task: " + anxietyRec.shortTask + "\n";
    output += "  Long Task: " + anxietyRec.longTask + "\n\n";

    output += "Energy Recommendations:\n";
    output += "  Short Task: " + energyRec.shortTask + "\n";
    output += "  Long Task: " + energyRec.longTask;

    qDebug().noquote() << output;

    // Set text in UI labels
    ui->MoodRecommendationLabel->setText(
        "Short Task: " + moodRec.shortTask + "\nLong Task: " + moodRec.longTask);
    ui->AnxietyRecommendationLabel->setText(
        "Short Task: " + anxietyRec.shortTask + "\nLong Task: " + anxietyRec.longTask);
    ui->EnergyRecommendationLabel->setText(
        "Short Task: " + energyRec.shortTask + "\nLong Task: " + energyRec.longTask);
}


void MoodTracker::handleLoginClicked()
{
    emit goToLoginPage();
}

void MoodTracker::handleJournalClicked()
{
    emit goToJournalPage();
}

void MoodTracker::handleTasksClicked()
{
    emit goToTasksPage();
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
    case 1: return {"Do breathwork for 5 minutes", "Go for a long walk or hike"};
    case 2: return {"Color in an adult coloring book", "Do yoga or meditation for 45 minutes"};
    case 3:
    case 4: return {"Make a to-do list", "Clean a room or reorganize a space"};
    case 5: return {"Take a warm shower", "Have a long talk with someone trusted"};
    case 6: return {"Hold ice cube in hand for focus", "See therapist or journal deeply for 45+ minutes"};
    default: return {"No anxiety task", "No anxiety task"};
    }
}

Recommendation MoodTracker::getEnergyRecommendation(int energy) {
    switch (energy) {
    case 1: return {"Have a cup of coffee and splash cold water on your face", "Listen to music and nap for an hour"};
    case 2: return {"Stretch outside and get some fresh air", "Go on a walk and practice breathwork"};
    case 3: return {"Make tea or coffee", "Read a book or study material for 45 minutes"};
    case 4: return {"Do jumping jacks", "Clean your room or take a walk"};
    case 5: return {"Do a full workout", "Run errands or complete a major chore"};
    case 6: return {"Sprint for 5 mins or dance", "Take on a high-focus work session"};
    default: return {"No energy task", "No energy task"};
    }
}

