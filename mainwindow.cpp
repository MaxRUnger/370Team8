#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moodtracker.h"
#include "journalwindow.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create stacked widget & set as the central widget
    stack = new QStackedWidget(this);
    setCentralWidget(stack);

    // Create the two pages
    moodTracker = new MoodTracker(this);
    journalWindow = new JournalWindow(this);

    // Add them to the stack
    stack->addWidget(moodTracker);    // index 0
    stack->addWidget(journalWindow);  // index 1

    // Show mood tracker first
    stack->setCurrentWidget(moodTracker);

    // 🚀 Connect signals for switching pages
    connect(moodTracker, &MoodTracker::goToJournalPage, this, [=]() {
        stack->setCurrentWidget(journalWindow);
    });

    connect(journalWindow, &JournalWindow::goToMoodTracker, this, [=]() {
        stack->setCurrentWidget(moodTracker);
    });
}

MainWindow::~MainWindow() {
    delete ui;
}
