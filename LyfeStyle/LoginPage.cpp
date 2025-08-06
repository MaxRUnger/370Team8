#include "LoginPage.h"
#include "ui_LoginPage.h"

LoginPage::LoginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_loginButton_clicked()
{
    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    // TODO: Add your user validation logic here
    if (!username.isEmpty() && !password.isEmpty()) {
        // If credentials are valid:
        emit loginSuccessful(username);
    } else {
        // Show error if credentials are invalid
        ui->statusLabel->setText("Invalid username or password.");
    }
}
