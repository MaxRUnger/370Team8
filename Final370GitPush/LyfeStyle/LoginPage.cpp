#include "LoginPage.h"
#include "ui_LoginPage.h"
#include "UserManager.h"

LoginPage::LoginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setWindowTitle("Login Window");
}

LoginPage::~LoginPage()
{
    delete ui;
}

// LOGIN BUTTON
void LoginPage::on_loginButton_clicked()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    UserManager userManager;
    if (userManager.validateUser(username, password)) {
        emit loginSuccessful(username);
    } else {
        ui->statusLabel->setText("Invalid username or password.");
    }
}

// SIGNUP BUTTON
void LoginPage::on_signupButton_clicked()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        ui->statusLabel->setText("Please enter both username and password.");
        return;
    }

    UserManager userManager;
    if (userManager.addUser(username, password)) {
        ui->statusLabel->setText("Signup successful. You can now log in.");
    } else {
        ui->statusLabel->setText("Username already exists.");
    }
}
