#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "PasswordHasher.h"
#include <QString>
#include <QVector>

class UserManager {
public:
    bool createUser(const QString& username, const QString& password);
    bool verifyUser(const QString& username, const QString& password);

private:
    QVector<User> users;
};

#endif // USERMANAGER_H
