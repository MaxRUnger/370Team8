#ifndef USER_H
#define USER_H

#include <QString>

class User {
public:
    User(const QString& username, const QString& passwordHash);

    QString getUsername() const;
    QString getPasswordHash() const;

private:
    QString m_username;
    QString m_passwordHash;
};

#endif // USER_H
