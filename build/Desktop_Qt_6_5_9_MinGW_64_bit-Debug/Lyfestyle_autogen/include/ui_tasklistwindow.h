/********************************************************************************
** Form generated from reading UI file 'tasklistwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKLISTWINDOW_H
#define UI_TASKLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taskListWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLineEdit *taskInput;
    QPushButton *addTaskButton;
    QTimeEdit *taskTimeEdit;
    QLabel *label1;
    QPushButton *completeTaskButton;
    QLabel *label2;
    QPushButton *moodPageButton;
    QPushButton *journalPageButton;
    QPushButton *logoutButton;
    QListWidget *recommendListWidget;
    QLabel *label2_2;
    QLabel *label2_3;
    QListWidget *taskListWidget;
    QFrame *frame_2;

    void setupUi(QMainWindow *taskListWindow)
    {
        if (taskListWindow->objectName().isEmpty())
            taskListWindow->setObjectName("taskListWindow");
        taskListWindow->resize(800, 650);
        centralwidget = new QWidget(taskListWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 440, 741, 191));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        taskInput = new QLineEdit(frame);
        taskInput->setObjectName("taskInput");
        taskInput->setGeometry(QRect(330, 50, 171, 41));
        QFont font;
        font.setPointSize(10);
        taskInput->setFont(font);
        taskInput->setCursorPosition(0);
        taskInput->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addTaskButton = new QPushButton(frame);
        addTaskButton->setObjectName("addTaskButton");
        addTaskButton->setGeometry(QRect(580, 20, 121, 71));
        addTaskButton->setFont(font);
        taskTimeEdit = new QTimeEdit(frame);
        taskTimeEdit->setObjectName("taskTimeEdit");
        taskTimeEdit->setGeometry(QRect(330, 100, 171, 41));
        QFont font1;
        font1.setPointSize(12);
        taskTimeEdit->setFont(font1);
        taskTimeEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        taskTimeEdit->setAutoFillBackground(false);
        taskTimeEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label1 = new QLabel(frame);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(330, 10, 171, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label1->setFont(font2);
        label1->setFrameShape(QFrame::Shape::Panel);
        label1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        completeTaskButton = new QPushButton(frame);
        completeTaskButton->setObjectName("completeTaskButton");
        completeTaskButton->setGeometry(QRect(580, 100, 121, 71));
        completeTaskButton->setFont(font);
        label2 = new QLabel(frame);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(40, 10, 211, 31));
        label2->setFont(font2);
        label2->setFrameShape(QFrame::Shape::Panel);
        label2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        moodPageButton = new QPushButton(frame);
        moodPageButton->setObjectName("moodPageButton");
        moodPageButton->setGeometry(QRect(40, 60, 211, 31));
        moodPageButton->setFont(font);
        journalPageButton = new QPushButton(frame);
        journalPageButton->setObjectName("journalPageButton");
        journalPageButton->setGeometry(QRect(40, 100, 211, 31));
        journalPageButton->setFont(font);
        logoutButton = new QPushButton(frame);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(40, 140, 211, 31));
        logoutButton->setFont(font);
        recommendListWidget = new QListWidget(centralwidget);
        recommendListWidget->setObjectName("recommendListWidget");
        recommendListWidget->setGeometry(QRect(30, 340, 741, 91));
        QFont font3;
        font3.setPointSize(14);
        recommendListWidget->setFont(font3);
        recommendListWidget->setMouseTracking(false);
        label2_2 = new QLabel(centralwidget);
        label2_2->setObjectName("label2_2");
        label2_2->setGeometry(QRect(30, 320, 741, 21));
        label2_2->setFont(font2);
        label2_2->setFrameShape(QFrame::Shape::Panel);
        label2_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label2_3 = new QLabel(centralwidget);
        label2_3->setObjectName("label2_3");
        label2_3->setGeometry(QRect(30, 20, 741, 21));
        label2_3->setFont(font2);
        label2_3->setFrameShape(QFrame::Shape::Panel);
        label2_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        taskListWidget = new QListWidget(centralwidget);
        taskListWidget->setObjectName("taskListWidget");
        taskListWidget->setGeometry(QRect(31, 41, 741, 271));
        taskListWidget->setFont(font3);
        taskListWidget->setMouseTracking(false);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(20, 10, 761, 631));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        taskListWindow->setCentralWidget(centralwidget);
        frame_2->raise();
        taskListWidget->raise();
        recommendListWidget->raise();
        frame->raise();
        label2_2->raise();
        label2_3->raise();

        retranslateUi(taskListWindow);

        QMetaObject::connectSlotsByName(taskListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *taskListWindow)
    {
        taskListWindow->setWindowTitle(QCoreApplication::translate("taskListWindow", "taskListWindow", nullptr));
        taskInput->setText(QString());
        taskInput->setPlaceholderText(QCoreApplication::translate("taskListWindow", "Enter task here", nullptr));
        addTaskButton->setText(QCoreApplication::translate("taskListWindow", "Input Task", nullptr));
        label1->setText(QCoreApplication::translate("taskListWindow", "Enter task and time", nullptr));
        completeTaskButton->setText(QCoreApplication::translate("taskListWindow", "Complete Task", nullptr));
        label2->setText(QCoreApplication::translate("taskListWindow", "Navigation", nullptr));
        moodPageButton->setText(QCoreApplication::translate("taskListWindow", "Mood Page", nullptr));
        journalPageButton->setText(QCoreApplication::translate("taskListWindow", "Journal Page", nullptr));
        logoutButton->setText(QCoreApplication::translate("taskListWindow", "Logout", nullptr));
        label2_2->setText(QCoreApplication::translate("taskListWindow", "Recommendations", nullptr));
        label2_3->setText(QCoreApplication::translate("taskListWindow", "Task List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taskListWindow: public Ui_taskListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKLISTWINDOW_H
