#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include "UserManager.h"

namespace Ui {
class LoginPage;
}

extern UserManager userManager;

class LoginPage : public QWidget {
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void handleSignup();
    void handleLogin();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
