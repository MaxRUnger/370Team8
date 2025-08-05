#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QString>
#include <QSqlDatabase>

class UserManager
{
public:
    UserManager();
    bool addUser(const QString& username, const QString& password);
    bool validateUser(const QString& username, const QString& password);

private:
    QSqlDatabase db;
    void initializeDatabase();
};

#endif // USERMANAGER_H
