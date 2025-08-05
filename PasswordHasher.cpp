#include "PasswordHasher.h"
#include <QCryptographicHash>

QString PasswordHasher::hashPassword(const QString& password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}
