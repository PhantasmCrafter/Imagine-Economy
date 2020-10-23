#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include<QtSql>
#include<QtSql/QSqlDriver>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlDatabase>
#include<QMessageBox>
#include<QFileDialog>
#include<QPixmap>
#include<QFile>
#include<QDir>
#include<QPdfWriter>
#include<QPrinter>


namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    int vectorBiggestNumber(QVector<int>);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    void saveSetting();

    ~Admin();

private slots:
    void on_add_item_clicked();
private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
