#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dbConn()
    , model(new QSqlQueryModel(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addBookButton_clicked() {
    QString title = ui->titleLineEdit->text();
    QString author = ui->authorLineEdit->text();
    QString publisher = ui->publisherLineEdit->text();
    QString isbn = ui->isbnLineEdit->text();
    double price = ui->priceLineEdit->text().toDouble();
    int quantity = ui->quantitySpinBox->value();

    QSqlQuery query(dbConn.getDatabase());
    query.prepare("INSERT INTO Books(title, author, publisher, isbn, price, quantity) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(title);
    query.addBindValue(author);
    query.addBindValue(publisher);
    query.addBindValue(isbn);
    query.addBindValue(price);
    query.addBindValue(quantity);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Book added successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to add book: " + query.lastError().text());
    }
}

void MainWindow::on_updateBookButton_clicked() {
    // Implement the update book functionality
}

void MainWindow::on_deleteBookButton_clicked() {
    // Implement the delete book functionality
}

void MainWindow::on_searchBookButton_clicked() {
    // Implement the search book functionality
}

void MainWindow::on_viewAllBooksButton_clicked() {
    QSqlQuery query(dbConn.getDatabase());
    query.exec("SELECT * FROM Books");
    model->setQuery(query);
    ui->booksTableView->setModel(model);
}
