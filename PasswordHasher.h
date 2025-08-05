#ifndef PASSWORDHASHER_H
#define PASSWORDHASHER_H

#include <QString>

class PasswordHasher {
public:
    static QString hashPassword(const QString& password);
};

#endif // PASSWORDHASHER_H
