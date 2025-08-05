/********************************************************************************
** Form generated from reading UI file 'LoginPage.ui'
**
** Created by: Qt User Interface Compiler version 6.5.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *usernameLabel;
    QLineEdit *leUsername;
    QLabel *statusLabel;
    QLineEdit *lePassword;
    QPushButton *loginButton;
    QPushButton *signupButton;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(400, 300);
        layoutWidget = new QWidget(LoginPage);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 80, 201, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        usernameLabel = new QLabel(layoutWidget);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout->addWidget(usernameLabel);

        leUsername = new QLineEdit(layoutWidget);
        leUsername->setObjectName("leUsername");

        verticalLayout->addWidget(leUsername);

        statusLabel = new QLabel(layoutWidget);
        statusLabel->setObjectName("statusLabel");

        verticalLayout->addWidget(statusLabel);

        lePassword = new QLineEdit(layoutWidget);
        lePassword->setObjectName("lePassword");
        lePassword->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(lePassword);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName("loginButton");

        verticalLayout->addWidget(loginButton);

        signupButton = new QPushButton(layoutWidget);
        signupButton->setObjectName("signupButton");

        verticalLayout->addWidget(signupButton);


        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginPage", "Username", nullptr));
        statusLabel->setText(QCoreApplication::translate("LoginPage", "Password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginPage", "Login", nullptr));
        signupButton->setText(QCoreApplication::translate("LoginPage", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
