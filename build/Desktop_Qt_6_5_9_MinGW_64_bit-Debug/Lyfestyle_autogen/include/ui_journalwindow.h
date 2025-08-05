/********************************************************************************
** Form generated from reading UI file 'journalwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNALWINDOW_H
#define UI_JOURNALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JournalWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QFrame *frame_2;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *addEntryButton;
    QPushButton *deleteEntryButton;
    QLabel *label2;
    QPushButton *moodPageButton;
    QPushButton *tasklistButton;
    QPushButton *logoutButton;
    QLabel *label2_2;
    QLineEdit *nameEntryEdit;
    QListWidget *entryListWidget;
    QLabel *label2_3;
    QLabel *label2_4;
    QFrame *frame_3;
    QTextEdit *journalTextEdit;

    void setupUi(QMainWindow *JournalWindow)
    {
        if (JournalWindow->objectName().isEmpty())
            JournalWindow->setObjectName("JournalWindow");
        JournalWindow->resize(810, 650);
        centralwidget = new QWidget(JournalWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(19, 19, 761, 611));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(horizontalLayoutWidget);
        frame->setObjectName("frame");
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(9, 429, 741, 171));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        dateTimeEdit = new QDateTimeEdit(frame_2);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(280, 50, 211, 41));
        sizePolicy.setHeightForWidth(dateTimeEdit->sizePolicy().hasHeightForWidth());
        dateTimeEdit->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        dateTimeEdit->setFont(font);
        dateTimeEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addEntryButton = new QPushButton(frame_2);
        addEntryButton->setObjectName("addEntryButton");
        addEntryButton->setGeometry(QRect(540, 20, 191, 51));
        QFont font1;
        font1.setPointSize(10);
        addEntryButton->setFont(font1);
        deleteEntryButton = new QPushButton(frame_2);
        deleteEntryButton->setObjectName("deleteEntryButton");
        deleteEntryButton->setGeometry(QRect(540, 110, 191, 51));
        deleteEntryButton->setFont(font1);
        label2 = new QLabel(frame_2);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(10, 10, 211, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        label2->setFont(font2);
        label2->setFrameShape(QFrame::Shape::Panel);
        label2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        moodPageButton = new QPushButton(frame_2);
        moodPageButton->setObjectName("moodPageButton");
        moodPageButton->setGeometry(QRect(10, 50, 211, 31));
        moodPageButton->setFont(font1);
        tasklistButton = new QPushButton(frame_2);
        tasklistButton->setObjectName("tasklistButton");
        tasklistButton->setGeometry(QRect(10, 90, 211, 31));
        tasklistButton->setFont(font1);
        logoutButton = new QPushButton(frame_2);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(10, 130, 211, 31));
        logoutButton->setFont(font1);
        label2_2 = new QLabel(frame_2);
        label2_2->setObjectName("label2_2");
        label2_2->setGeometry(QRect(280, 10, 211, 31));
        label2_2->setFont(font2);
        label2_2->setFrameShape(QFrame::Shape::Panel);
        label2_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        nameEntryEdit = new QLineEdit(frame_2);
        nameEntryEdit->setObjectName("nameEntryEdit");
        nameEntryEdit->setGeometry(QRect(280, 100, 171, 41));
        nameEntryEdit->setFont(font1);
        nameEntryEdit->setCursorPosition(0);
        nameEntryEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        entryListWidget = new QListWidget(frame);
        entryListWidget->setObjectName("entryListWidget");
        entryListWidget->setGeometry(QRect(10, 30, 191, 391));
        label2_3 = new QLabel(frame);
        label2_3->setObjectName("label2_3");
        label2_3->setGeometry(QRect(10, 10, 191, 21));
        label2_3->setFont(font2);
        label2_3->setFrameShape(QFrame::Shape::Panel);
        label2_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label2_4 = new QLabel(frame);
        label2_4->setObjectName("label2_4");
        label2_4->setGeometry(QRect(210, 10, 541, 21));
        label2_4->setFont(font2);
        label2_4->setFrameShape(QFrame::Shape::Panel);
        label2_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(209, 29, 541, 391));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        journalTextEdit = new QTextEdit(frame_3);
        journalTextEdit->setObjectName("journalTextEdit");
        journalTextEdit->setGeometry(QRect(13, 9, 521, 371));
        entryListWidget->raise();
        frame_2->raise();
        label2_3->raise();
        label2_4->raise();
        frame_3->raise();

        horizontalLayout->addWidget(frame);

        JournalWindow->setCentralWidget(centralwidget);

        retranslateUi(JournalWindow);

        QMetaObject::connectSlotsByName(JournalWindow);
    } // setupUi

    void retranslateUi(QMainWindow *JournalWindow)
    {
        JournalWindow->setWindowTitle(QCoreApplication::translate("JournalWindow", "Journal", nullptr));
        addEntryButton->setText(QCoreApplication::translate("JournalWindow", "Add Entry", nullptr));
        deleteEntryButton->setText(QCoreApplication::translate("JournalWindow", "Delete Entry", nullptr));
        label2->setText(QCoreApplication::translate("JournalWindow", "Navigation", nullptr));
        moodPageButton->setText(QCoreApplication::translate("JournalWindow", "Mood Page", nullptr));
        tasklistButton->setText(QCoreApplication::translate("JournalWindow", "Tasklist Page", nullptr));
        logoutButton->setText(QCoreApplication::translate("JournalWindow", "Logout", nullptr));
        label2_2->setText(QCoreApplication::translate("JournalWindow", "Date & Name Entry ", nullptr));
        nameEntryEdit->setText(QString());
        nameEntryEdit->setPlaceholderText(QCoreApplication::translate("JournalWindow", "Enter entry name", nullptr));
        label2_3->setText(QCoreApplication::translate("JournalWindow", "Entry Navigator", nullptr));
        label2_4->setText(QCoreApplication::translate("JournalWindow", "Journal", nullptr));
        journalTextEdit->setHtml(QCoreApplication::translate("JournalWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JournalWindow: public Ui_JournalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNALWINDOW_H
