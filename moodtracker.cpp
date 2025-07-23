#include "moodtracker.h"
#include "ui_moodtracker.h"
#include <QDebug>

MoodTracker::MoodTracker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MoodTracker)
{
    ui->setupUi(this);
    connect(ui->SubmitButton, &QPushButton::clicked,this, &MoodTracker::handleSubmit);
}

MoodTracker::~MoodTracker()
{
    delete ui;
}


void MoodTracker::handleSubmit()
{
    int mood = ui->MoodSlider->value();
    int energy = ui->EnergySlider->value();
    int emotion = ui->EmotionSlider->value();

    qDebug() << "Mood:" << mood << "Energy:" << energy << "Emotion:" << emotion;

}
