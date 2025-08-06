#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "journalwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_journalBtn_clicked()
{
    JournalWindow *journalWin = new JournalWindow(this);
    journalWin->setAttribute(Qt::WA_DeleteOnClose);
    journalWin->show();
}

