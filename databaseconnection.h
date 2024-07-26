#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

class DatabaseConnection {
public:
    DatabaseConnection();
    ~DatabaseConnection();
    QSqlDatabase getDatabase();
private:
    QSqlDatabase db;
};

#endif // DATABASECONNECTION_H
