#ifndef TESTS_H
#define TESTS_H

#include <QObject>

class AllTests : public QObject {
    Q_OBJECT

private slots:
    void testDatabaseConnection();
    void testMoodTrackerButtons();
    void testTaskListWindowButtons();
    void testJournalWindowButtons();
    void testMoodSlidersInitialized();
    void testTaskListDisplaysNoCrash();
    void testMoodRecommendationLabelPresent();
    void testJournalEntryBoxAccessible();
    void testClearRecommendationsFunctionality();
    void testLoginButtonFunctionality();
};

#endif // TESTS_H
