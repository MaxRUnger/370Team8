#include "User.h"

User::User(const QString& username, const QString& passwordHash)
    : m_username(username), m_passwordHash(passwordHash) {}

QString User::getUsername() const {
    return m_username;
}

QString User::getPasswordHash() const {
    return m_passwordHash;
}