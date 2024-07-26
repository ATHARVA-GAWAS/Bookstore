#include "databaseconnection.h"

DatabaseConnection::DatabaseConnection() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("testdb");
    db.setUserName("root");
    db.setPassword("your_password");

    if (!db.open()) {
        qWarning() << "Error: Unable to connect to database." << db.lastError().text();
    }
}

DatabaseConnection::~DatabaseConnection() {
    db.close();
}

QSqlDatabase DatabaseConnection::getDatabase() {
    return db;
}
