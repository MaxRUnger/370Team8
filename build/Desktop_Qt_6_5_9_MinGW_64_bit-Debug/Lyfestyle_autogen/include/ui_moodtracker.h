/********************************************************************************
** Form generated from reading UI file 'moodtracker.ui'
**
** Created by: Qt User Interface Compiler version 6.5.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOODTRACKER_H
#define UI_MOODTRACKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoodTracker
{
public:
    QFrame *frame_3;
    QLabel *MoodLabel;
    QLabel *AnxietyLabel;
    QLabel *EnergyLabel;
    QSlider *EnergySlider;
    QLabel *label_2;
    QLabel *label;
    QSlider *AnxietySlider;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_1mood;
    QSlider *MoodSlider;
    QLabel *label_mood;
    QLabel *label2_2;
    QFrame *frame_4;
    QFrame *frame_5;
    QLabel *PreviousEnergyLabel;
    QLabel *PreviousAnxietyLabel;
    QLabel *PreviousMoodLabel;
    QLabel *label2_5;
    QFrame *frame_6;
    QLabel *EnergyRecommendationLabel;
    QLabel *AnxietyRecommendationLabel;
    QLabel *MoodRecommendationLabel;
    QLabel *label2_6;
    QFrame *frame_2;
    QLabel *label2;
    QPushButton *JournalButton;
    QPushButton *TasksButton;
    QPushButton *LoginButton;
    QPushButton *SubmitButton;
    QLabel *label2_3;
    QLabel *label2_4;
    QFrame *frame;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *MoodTracker)
    {
        if (MoodTracker->objectName().isEmpty())
            MoodTracker->setObjectName("MoodTracker");
        MoodTracker->resize(810, 660);
        frame_3 = new QFrame(MoodTracker);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(20, 290, 261, 171));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        MoodLabel = new QLabel(frame_3);
        MoodLabel->setObjectName("MoodLabel");
        MoodLabel->setGeometry(QRect(10, 10, 61, 31));
        QFont font;
        font.setPointSize(10);
        MoodLabel->setFont(font);
        MoodLabel->setFrameShape(QFrame::Shape::Box);
        MoodLabel->setFrameShadow(QFrame::Shadow::Plain);
        MoodLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AnxietyLabel = new QLabel(frame_3);
        AnxietyLabel->setObjectName("AnxietyLabel");
        AnxietyLabel->setGeometry(QRect(10, 60, 61, 31));
        AnxietyLabel->setFont(font);
        AnxietyLabel->setFrameShape(QFrame::Shape::Box);
        AnxietyLabel->setFrameShadow(QFrame::Shadow::Plain);
        AnxietyLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        EnergyLabel = new QLabel(frame_3);
        EnergyLabel->setObjectName("EnergyLabel");
        EnergyLabel->setGeometry(QRect(10, 110, 61, 31));
        EnergyLabel->setFont(font);
        EnergyLabel->setFrameShape(QFrame::Shape::Box);
        EnergySlider = new QSlider(frame_3);
        EnergySlider->setObjectName("EnergySlider");
        EnergySlider->setGeometry(QRect(80, 110, 160, 25));
        EnergySlider->setMinimum(1);
        EnergySlider->setMaximum(6);
        EnergySlider->setOrientation(Qt::Orientation::Horizontal);
        EnergySlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        EnergySlider->setTickInterval(1);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 140, 16, 16));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(frame_3);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 140, 16, 16));
        AnxietySlider = new QSlider(frame_3);
        AnxietySlider->setObjectName("AnxietySlider");
        AnxietySlider->setGeometry(QRect(80, 60, 160, 25));
        AnxietySlider->setMinimum(1);
        AnxietySlider->setMaximum(6);
        AnxietySlider->setOrientation(Qt::Orientation::Horizontal);
        AnxietySlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        AnxietySlider->setTickInterval(1);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 90, 16, 16));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(frame_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 90, 16, 16));
        label_1mood = new QLabel(frame_3);
        label_1mood->setObjectName("label_1mood");
        label_1mood->setGeometry(QRect(80, 40, 16, 16));
        label_1mood->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MoodSlider = new QSlider(frame_3);
        MoodSlider->setObjectName("MoodSlider");
        MoodSlider->setGeometry(QRect(80, 10, 160, 25));
        MoodSlider->setMinimum(1);
        MoodSlider->setMaximum(6);
        MoodSlider->setOrientation(Qt::Orientation::Horizontal);
        MoodSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        MoodSlider->setTickInterval(1);
        label_mood = new QLabel(frame_3);
        label_mood->setObjectName("label_mood");
        label_mood->setGeometry(QRect(230, 40, 16, 16));
        label2_2 = new QLabel(MoodTracker);
        label2_2->setObjectName("label2_2");
        label2_2->setGeometry(QRect(20, 260, 261, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label2_2->setFont(font1);
        label2_2->setFrameShape(QFrame::Shape::Panel);
        label2_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_4 = new QFrame(MoodTracker);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(10, 10, 791, 641));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(10, 40, 261, 201));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        PreviousEnergyLabel = new QLabel(frame_5);
        PreviousEnergyLabel->setObjectName("PreviousEnergyLabel");
        PreviousEnergyLabel->setGeometry(QRect(50, 140, 141, 41));
        PreviousEnergyLabel->setFont(font);
        PreviousEnergyLabel->setFrameShape(QFrame::Shape::Box);
        PreviousEnergyLabel->setFrameShadow(QFrame::Shadow::Raised);
        PreviousAnxietyLabel = new QLabel(frame_5);
        PreviousAnxietyLabel->setObjectName("PreviousAnxietyLabel");
        PreviousAnxietyLabel->setGeometry(QRect(50, 90, 141, 41));
        PreviousAnxietyLabel->setFont(font);
        PreviousAnxietyLabel->setFrameShape(QFrame::Shape::Box);
        PreviousAnxietyLabel->setFrameShadow(QFrame::Shadow::Raised);
        PreviousMoodLabel = new QLabel(frame_5);
        PreviousMoodLabel->setObjectName("PreviousMoodLabel");
        PreviousMoodLabel->setGeometry(QRect(50, 40, 141, 41));
        PreviousMoodLabel->setFont(font);
        PreviousMoodLabel->setFrameShape(QFrame::Shape::Box);
        PreviousMoodLabel->setFrameShadow(QFrame::Shadow::Raised);
        label2_5 = new QLabel(frame_4);
        label2_5->setObjectName("label2_5");
        label2_5->setGeometry(QRect(10, 10, 261, 31));
        label2_5->setFont(font1);
        label2_5->setFrameShape(QFrame::Shape::Panel);
        label2_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(280, 140, 501, 231));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        EnergyRecommendationLabel = new QLabel(frame_6);
        EnergyRecommendationLabel->setObjectName("EnergyRecommendationLabel");
        EnergyRecommendationLabel->setGeometry(QRect(10, 160, 481, 61));
        EnergyRecommendationLabel->setFont(font);
        EnergyRecommendationLabel->setFrameShape(QFrame::Shape::Box);
        AnxietyRecommendationLabel = new QLabel(frame_6);
        AnxietyRecommendationLabel->setObjectName("AnxietyRecommendationLabel");
        AnxietyRecommendationLabel->setGeometry(QRect(10, 80, 481, 71));
        AnxietyRecommendationLabel->setFont(font);
        AnxietyRecommendationLabel->setFrameShape(QFrame::Shape::Box);
        MoodRecommendationLabel = new QLabel(frame_6);
        MoodRecommendationLabel->setObjectName("MoodRecommendationLabel");
        MoodRecommendationLabel->setGeometry(QRect(10, 10, 481, 61));
        MoodRecommendationLabel->setFont(font);
        MoodRecommendationLabel->setFrameShape(QFrame::Shape::Box);
        label2_6 = new QLabel(frame_4);
        label2_6->setObjectName("label2_6");
        label2_6->setGeometry(QRect(280, 110, 501, 31));
        label2_6->setFont(font1);
        label2_6->setFrameShape(QFrame::Shape::Panel);
        label2_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 460, 771, 171));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label2 = new QLabel(frame_2);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(20, 10, 211, 31));
        label2->setFont(font1);
        label2->setFrameShape(QFrame::Shape::Panel);
        label2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        JournalButton = new QPushButton(frame_2);
        JournalButton->setObjectName("JournalButton");
        JournalButton->setGeometry(QRect(20, 50, 211, 32));
        JournalButton->setFont(font);
        TasksButton = new QPushButton(frame_2);
        TasksButton->setObjectName("TasksButton");
        TasksButton->setGeometry(QRect(20, 90, 211, 32));
        TasksButton->setFont(font);
        LoginButton = new QPushButton(frame_2);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(20, 130, 211, 32));
        LoginButton->setFont(font);
        SubmitButton = new QPushButton(frame_2);
        SubmitButton->setObjectName("SubmitButton");
        SubmitButton->setGeometry(QRect(550, 60, 171, 61));
        SubmitButton->setFont(font);
        label2_3 = new QLabel(frame_2);
        label2_3->setObjectName("label2_3");
        label2_3->setGeometry(QRect(550, 10, 171, 31));
        label2_3->setFont(font1);
        label2_3->setFrameShape(QFrame::Shape::Panel);
        label2_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label2_4 = new QLabel(frame_2);
        label2_4->setObjectName("label2_4");
        label2_4->setGeometry(QRect(270, 10, 211, 31));
        label2_4->setFont(font1);
        label2_4->setFrameShape(QFrame::Shape::Panel);
        label2_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame = new QFrame(frame_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(270, 50, 211, 111));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 10, 191, 91));
        frame_6->raise();
        frame_5->raise();
        label2_5->raise();
        label2_6->raise();
        frame_2->raise();
        frame_4->raise();
        frame_3->raise();
        label2_2->raise();

        retranslateUi(MoodTracker);

        QMetaObject::connectSlotsByName(MoodTracker);
    } // setupUi

    void retranslateUi(QWidget *MoodTracker)
    {
        MoodTracker->setWindowTitle(QCoreApplication::translate("MoodTracker", "Mood Tracker", nullptr));
        MoodLabel->setText(QCoreApplication::translate("MoodTracker", "Mood", nullptr));
        AnxietyLabel->setText(QCoreApplication::translate("MoodTracker", "Anxiety", nullptr));
        EnergyLabel->setText(QCoreApplication::translate("MoodTracker", "Energy:", nullptr));
        label_2->setText(QCoreApplication::translate("MoodTracker", "1", nullptr));
        label->setText(QCoreApplication::translate("MoodTracker", "6", nullptr));
        label_4->setText(QCoreApplication::translate("MoodTracker", "1", nullptr));
        label_3->setText(QCoreApplication::translate("MoodTracker", "6", nullptr));
        label_1mood->setText(QCoreApplication::translate("MoodTracker", "1", nullptr));
        label_mood->setText(QCoreApplication::translate("MoodTracker", "6", nullptr));
        label2_2->setText(QCoreApplication::translate("MoodTracker", "User Control", nullptr));
        PreviousEnergyLabel->setText(QCoreApplication::translate("MoodTracker", "Previous energy:", nullptr));
        PreviousAnxietyLabel->setText(QCoreApplication::translate("MoodTracker", "Previous anxiety: ", nullptr));
        PreviousMoodLabel->setText(QCoreApplication::translate("MoodTracker", "Previous mood:", nullptr));
        label2_5->setText(QCoreApplication::translate("MoodTracker", "Previous Mood", nullptr));
        EnergyRecommendationLabel->setText(QCoreApplication::translate("MoodTracker", "Energy recommendation ", nullptr));
        AnxietyRecommendationLabel->setText(QCoreApplication::translate("MoodTracker", "Anxiety recommendation ", nullptr));
        MoodRecommendationLabel->setText(QCoreApplication::translate("MoodTracker", "Mood recommendation ", nullptr));
        label2_6->setText(QCoreApplication::translate("MoodTracker", "Recommended Activites", nullptr));
        label2->setText(QCoreApplication::translate("MoodTracker", "Navigation", nullptr));
        JournalButton->setText(QCoreApplication::translate("MoodTracker", "Journal ", nullptr));
        TasksButton->setText(QCoreApplication::translate("MoodTracker", "Tasks ", nullptr));
        LoginButton->setText(QCoreApplication::translate("MoodTracker", "Logout", nullptr));
        SubmitButton->setText(QCoreApplication::translate("MoodTracker", "Submit", nullptr));
        label2_3->setText(QCoreApplication::translate("MoodTracker", "Submit for Results", nullptr));
        label2_4->setText(QCoreApplication::translate("MoodTracker", "Welcome", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MoodTracker", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Hello and welcome to lyfestyle your own personal tool for your mental health needs</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoodTracker: public Ui_MoodTracker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOODTRACKER_H
