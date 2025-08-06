#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlDatabase>
#include <QSqlQuery>


class DatabaseManager
{
public:
    static QSqlDatabase& getDatabase();
    static void initialize();

private:
    DatabaseManager();
    static QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
