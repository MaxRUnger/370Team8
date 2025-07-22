#include "LoginPage.h"
#include "ui_LoginPage.h"
#include <QDebug> // optional: for console output
#include "UserManager.h"
#include "PasswordHasher.h"
#include <QMessageBox> // for popup messages

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginPage) {
    ui->setupUi(this);

    connect(ui->signupButton, &QPushButton::clicked, this, &LoginPage::handleSignup);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginPage::handleLogin);
}
void LoginPage::handleSignup() {
    QString username = ui->usernameField->text();
    QString password = ui->passwordField->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Username and password cannot be empty.");
        return;
    }

    bool success = userManager.createUser(username, password);
    if (success) {
        QMessageBox::information(this, "Success", "Account created.");
    } else {
        QMessageBox::warning(this, "Error", "Username already exists.");
    }
}


void LoginPage::handleLogin() {
    QString username = ui->usernameField->text();
    QString password = ui->passwordField->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Error", "Username and password cannot be empty.");
        return;
    }

    bool success = userManager.verifyUser(username, password);
    if (success) {
        QMessageBox::information(this, "Success", "Login successful.");
        // TODO: transition to the next page here
    } else {
        QMessageBox::critical(this, "Error", "Invalid username or password.");
    }
}


LoginPage::~LoginPage() {
    delete ui;
}
