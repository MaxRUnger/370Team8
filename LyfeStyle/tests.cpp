#include "tests.h"

#include <QTest>
#include <QPushButton>
#include <QSlider>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QListWidget>
#include <QLabel>

#include "DatabaseManager.h"
#include "moodtracker.h"
#include "tasklistwindow.h"
#include "journalwindow.h"

void AllTests::testDatabaseConnection() {
    QSqlDatabase db = DatabaseManager::getDatabase();
    QVERIFY(db.isOpen());
    QVERIFY(db.isValid());
    QCOMPARE(db.driverName(), QString("QSQLITE"));
}

void AllTests::testMoodTrackerButtons() {
    MoodTracker mood("testuser");
    QVERIFY(mood.findChild<QPushButton*>("SubmitButton"));
    QVERIFY(mood.findChild<QPushButton*>("LoginButton"));
    QVERIFY(mood.findChild<QPushButton*>("JournalButton"));
    QVERIFY(mood.findChild<QPushButton*>("TasksButton"));
}

void AllTests::testTaskListWindowButtons() {
    taskListWindow task("testuser");
    QVERIFY(task.findChild<QPushButton*>("clearRecButton"));
    QVERIFY(task.findChild<QPushButton*>("logoutButton"));
    QVERIFY(task.findChild<QPushButton*>("journalPageButton"));
    QVERIFY(task.findChild<QPushButton*>("moodPageButton"));
}

void AllTests::testJournalWindowButtons() {
    JournalWindow journal("testuser");
    QVERIFY(journal.findChild<QPushButton*>("tasklistButton"));
    QVERIFY(journal.findChild<QPushButton*>("logoutButton"));
    QVERIFY(journal.findChild<QPushButton*>("moodPageButton"));
}

void AllTests::testMoodSlidersInitialized() {
    MoodTracker mood("testuser");
    QVERIFY(mood.findChild<QSlider*>("MoodSlider")->minimum() == 1);
    QVERIFY(mood.findChild<QSlider*>("MoodSlider")->maximum() == 6);
    QVERIFY(mood.findChild<QSlider*>("EnergySlider")->minimum() == 1);
    QVERIFY(mood.findChild<QSlider*>("EnergySlider")->maximum() == 6);
    QVERIFY(mood.findChild<QSlider*>("AnxietySlider")->minimum() == 1);
    QVERIFY(mood.findChild<QSlider*>("AnxietySlider")->maximum() == 6);
}

void AllTests::testTaskListDisplaysNoCrash() {
    taskListWindow taskWin("testuser");
    auto listWidget = taskWin.findChild<QListWidget*>("taskListWidget");
    QVERIFY(listWidget != nullptr);
}

void AllTests::testMoodRecommendationLabelPresent() {
    MoodTracker mood("testuser");
    auto label = mood.findChild<QLabel*>("MoodRecommendationLabel");
    QVERIFY(label != nullptr);
}

void AllTests::testJournalWindowNavigationButtons() {
    JournalWindow journal("testuser");
    QVERIFY(journal.findChild<QPushButton*>("tasklistButton"));
    QVERIFY(journal.findChild<QPushButton*>("logoutButton"));
    QVERIFY(journal.findChild<QPushButton*>("moodPageButton"));
}

void AllTests::testClearRecommendationsButton() {
    taskListWindow task("testuser");
    auto clearBtn = task.findChild<QPushButton*>("clearRecButton");
    QVERIFY(clearBtn != nullptr);
}

void AllTests::testLoginButtonFunctionality() {
    MoodTracker mood("testuser");
    auto loginBtn = mood.findChild<QPushButton*>("LoginButton");
    QVERIFY(loginBtn != nullptr);
    QVERIFY(loginBtn->isEnabled());
}

QTEST_MAIN(AllTests)
