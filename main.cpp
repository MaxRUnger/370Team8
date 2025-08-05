#include <QApplication>
#include "LoginPage.h"
#include "moodtracker.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Use a pointer to manage window lifetime safely
    LoginPage *login = new LoginPage();
    login->show();

    QObject::connect(login, &LoginPage::loginSuccessful, [login](const QString &username) {
        // Open MoodTracker window on successful login
        MoodTracker *tracker = new MoodTracker();
        tracker->show();
        login->close();
        login->deleteLater();
    });

    return app.exec();
}
