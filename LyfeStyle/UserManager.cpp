#include "UserManager.h"
#include "PasswordHasher.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

UserManager::UserManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError();
    } else {
        initializeDatabase();
    }
}

void UserManager::initializeDatabase()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "username TEXT PRIMARY KEY, "
               "password TEXT)");
}

bool UserManager::addUser(const QString& username, const QString& password)
{
    QString hashed = PasswordHasher::hashPassword(password);

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(hashed);

    if (!query.exec()) {
        qWarning() << "Add user failed:" << query.lastError();
        return false;
    }

    return true;
}

bool UserManager::validateUser(const QString& username, const QString& password)
{
    QString hashed = PasswordHasher::hashPassword(password);

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec()) {
        qWarning() << "Login query failed:" << query.lastError();
        return false;
    }

    if (query.next()) {
        QString storedHash = query.value(0).toString();
        return storedHash == hashed;
    }

    return false;
}
