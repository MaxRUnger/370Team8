#include <QApplication>
#include "LoginPage.h"
#include "moodtracker.h"
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Use a pointer to manage window lifetime safely
    LoginPage *login = new LoginPage();
    login->show();

     DatabaseManager::initialize();

    QObject::connect(login, &LoginPage::loginSuccessful, [login](const QString &username) {
        MoodTracker *tracker = new MoodTracker(username);
        tracker->show();
        login->close();
        login->deleteLater();
    });

    return app.exec();
}
