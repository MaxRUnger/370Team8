#ifndef JOURNAL_H
#define JOURNAL_H

#include <QString>
#include <QDate>
#include <QList>
#include <QSqlDatabase>

struct JournalEntry {
    int id;
    QString title;
    QDate date;
    QString content;
};

class Journal {
public:
    Journal();
    bool init();
    void loadFromDatabase();
    void addEntry(const QString &title);
    void updateEntryContent(int id, const QString &newContent);
    void deleteEntry(int id);

    const QList<JournalEntry>& getEntries() const;
    JournalEntry* getEntryById(int id);

private:
    QList<JournalEntry> entries;
    QSqlDatabase db;
};

#endif // JOURNAL_H
