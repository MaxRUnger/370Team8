#include "journal.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

Journal::Journal() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("journal.db");
}

bool Journal::init() {
    if (!db.open()) {
        qWarning() << "Database failed to open:" << db.lastError();
        return false;
    }

    QSqlQuery query;
    QString sql = R"(
        CREATE TABLE IF NOT EXISTS journal (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            date TEXT NOT NULL,
            content TEXT
        )
    )";
    if (!query.exec(sql)) {
        qWarning() << "Failed to create table:" << query.lastError();
        return false;
    }

    loadFromDatabase();
    return true;
}

void Journal::loadFromDatabase() {
    entries.clear();
    QSqlQuery query("SELECT id, title, date, content FROM journal ORDER BY id ASC");
    while (query.next()) {
        JournalEntry entry;
        entry.id = query.value(0).toInt();
        entry.title = query.value(1).toString();
        entry.date = QDate::fromString(query.value(2).toString(), Qt::ISODate);
        entry.content = query.value(3).toString();
        entries.append(entry);
    }
}

void Journal::addEntry(const QString &title) {
    QSqlQuery query;
    query.prepare("INSERT INTO journal (title, date, content) VALUES (?, ?, ?)");
    query.addBindValue(title);
    query.addBindValue(QDate::currentDate().toString(Qt::ISODate));
    query.addBindValue("");

    if (query.exec()) {
        int id = query.lastInsertId().toInt();
        JournalEntry entry{ id, title, QDate::currentDate(), "" };
        entries.append(entry);
    } else {
        qWarning() << "Failed to add entry:" << query.lastError();
    }
}

void Journal::updateEntryContent(int id, const QString &newContent) {
    for (JournalEntry &entry : entries) {
        if (entry.id == id) {
            entry.content = newContent;
            break;
        }
    }

    QSqlQuery query;
    query.prepare("UPDATE journal SET content = ? WHERE id = ?");
    query.addBindValue(newContent);
    query.addBindValue(id);
    if (!query.exec()) {
        qWarning() << "Failed to update content:" << query.lastError();
    }
}

void Journal::deleteEntry(int id) {
    auto it = std::find_if(entries.begin(), entries.end(),
                           [id](const JournalEntry &e) { return e.id == id; });
    if (it != entries.end()) {
        entries.erase(it);
    }

    QSqlQuery query;
    query.prepare("DELETE FROM journal WHERE id = ?");
    query.addBindValue(id);
    if (!query.exec()) {
        qWarning() << "Failed to delete entry:" << query.lastError();
    }
}

const QList<JournalEntry>& Journal::getEntries() const {
    return entries;
}

JournalEntry* Journal::getEntryById(int id) {
    for (JournalEntry &entry : entries) {
        if (entry.id == id) return &entry;
    }
    return nullptr;
}
