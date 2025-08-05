#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moodtracker.h"
#include "journalwindow.h"

#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stack = new QStackedWidget(this);
    setCentralWidget(stack);

    moodTracker = new MoodTracker(this);
    journalWindow = new JournalWindow(this);

    stack->addWidget(moodTracker);    // index 0
    stack->addWidget(journalWindow);  // index 1

    stack->setCurrentWidget(moodTracker);
}

MainWindow::~MainWindow() {
    delete ui;
}
