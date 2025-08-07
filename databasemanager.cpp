#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QSqlDatabase DatabaseManager::db = QSqlDatabase();

QSqlDatabase& DatabaseManager::getDatabase()
{
    if (!db.isValid()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("lifestyle.db");
    }

    if (!db.isOpen()) {
        if (!db.open()) {
            qWarning() << "Failed to open database:" << db.lastError();
        }
    }

    return db;
}

void DatabaseManager::initialize()
{
    QSqlDatabase db = getDatabase();
    QSqlQuery query;

    // Fix tasks table if column count is wrong
    query.exec("PRAGMA table_info(tasks)");
    int columnCount = 0;
    while (query.next()) {
        columnCount++;
    }

    if (columnCount != 4) {
        qDebug() << "[Migration] Dropping old tasks table due to schema mismatch.";
        query.exec("DROP TABLE IF EXISTS tasks");
    }

    // Create users table
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "username TEXT PRIMARY KEY, "
               "password TEXT)");

    // Create journal_entries table
    query.exec("CREATE TABLE IF NOT EXISTS journal_entries ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT NOT NULL, "
               "entry_name TEXT, "
               "entry TEXT NOT NULL, "
               "timestamp TEXT NOT NULL)");

    // Add 'entry_name' column to journal_entries if missing
    query.exec("PRAGMA table_info(journal_entries)");
    bool hasEntryName = false;
    while (query.next()) {
        if (query.value(1).toString() == "entry_name") {
            hasEntryName = true;
            break;
        }
    }
    if (!hasEntryName) {
        qDebug() << "[Migration] Adding missing 'entry_name' column to journal_entries.";
        QSqlQuery alterQuery(db);
        alterQuery.exec("ALTER TABLE journal_entries ADD COLUMN entry_name TEXT");
    }

    // Create tasks table
    query.exec("CREATE TABLE IF NOT EXISTS tasks ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT NOT NULL, "
               "task_text TEXT NOT NULL, "
               "timestamp TEXT NOT NULL)");

    // Create recommendations_cleared table
    query.exec("CREATE TABLE IF NOT EXISTS recommendations_cleared ("
               "username TEXT PRIMARY KEY)");

    // Create moods table
    query.exec("CREATE TABLE IF NOT EXISTS moods ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT NOT NULL, "
               "mood INTEGER NOT NULL, "
               "energy INTEGER NOT NULL, "
               "anxiety INTEGER NOT NULL, "
               "timestamp TEXT NOT NULL DEFAULT (datetime('now')))");

    // Create recommendations table
    query.exec("CREATE TABLE IF NOT EXISTS recommendations ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT NOT NULL, "
               "mood_short TEXT, "
               "mood_long TEXT, "
               "energy_short TEXT, "
               "energy_long TEXT, "
               "anxiety_short TEXT, "
               "anxiety_long TEXT, "
               "timestamp TEXT NOT NULL DEFAULT (datetime('now')))");
}
