#include <QApplication>
#include "LoginPage.h"
#include "UserManager.h"

UserManager userManager;
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    LoginPage window;
    window.show();

    return app.exec();
}
