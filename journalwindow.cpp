#include "journalwindow.h"
#include "ui_journalwindow.h"
#include <QInputDialog>
#include <QMessageBox>

JournalWindow::JournalWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JournalWindow)
{
    ui->setupUi(this);
    journal.init();

    connect(ui->entryListWidget, &QListWidget::currentRowChanged, this, &JournalWindow::onEntrySelected);
    connect(ui->addButton, &QPushButton::clicked, this, &JournalWindow::onAddClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &JournalWindow::onDeleteClicked);
    connect(ui->contentView, &QTextEdit::textChanged, this, [=]() {
        if (selectedId >= 0) {
            journal.updateEntryContent(selectedId, ui->contentView->toPlainText());
        }
    });

    refreshEntryList();
}

JournalWindow::~JournalWindow() {
    delete ui;
}

void JournalWindow::onEntrySelected() {
    int index = ui->entryListWidget->currentRow();
    if (index >= 0 && index < journal.getEntries().size()) {
        const JournalEntry &entry = journal.getEntries()[index];
        selectedId = entry.id;
        ui->contentView->blockSignals(true);
        ui->contentView->setPlainText(entry.content);
        ui->contentView->blockSignals(false);
    } else {
        selectedId = -1;
        ui->contentView->clear();
    }
}

void JournalWindow::onAddClicked() {
    QString title = QInputDialog::getText(this, "New Entry", "Enter title:");
    if (!title.isEmpty()) {
        journal.addEntry(title);
        refreshEntryList();
    }
}

void JournalWindow::onDeleteClicked() {
    int index = ui->entryListWidget->currentRow();
    if (index >= 0 && index < journal.getEntries().size()) {
        journal.deleteEntry(journal.getEntries()[index].id);
        refreshEntryList();
        ui->contentView->clear();
        selectedId = -1;
    }
}

void JournalWindow::refreshEntryList() {
    ui->entryListWidget->clear();
    for (const JournalEntry &entry : journal.getEntries()) {
        ui->entryListWidget->addItem(entry.title + " (" + entry.date.toString("yyyy-MM-dd") + ")");
    }
}
