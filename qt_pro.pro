QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_project
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp \
           databaseconnection.cpp

HEADERS += mainwindow.h \
           databaseconnection.h

FORMS += mainwindow.ui

INCLUDEPATH += /path/to/mysql/connector/include
LIBS += -L/path/to/mysql/connector/lib -lmysqlcppconn
