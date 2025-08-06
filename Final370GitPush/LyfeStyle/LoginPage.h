#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

signals:
    void loginSuccessful(const QString &username);

private slots:
    void on_loginButton_clicked();
    void on_signupButton_clicked();

private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
