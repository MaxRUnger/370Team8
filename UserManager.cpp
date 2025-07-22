#include "UserManager.h"
#include "PasswordHasher.h"

bool UserManager::createUser(const QString& username, const QString& password) {
    QString hashed = PasswordHasher::hashPassword(password);
    users.append(User(username, hashed));
    return true;
}

bool UserManager::verifyUser(const QString& username, const QString& password) {
    QString hashed = PasswordHasher::hashPassword(password);
    for (const User& user : users) {
        if (user.getUsername() == username && user.getPasswordHash() == hashed) {
            return true;
        }
    }
    return false;
}
