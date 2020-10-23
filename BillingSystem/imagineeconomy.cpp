#include "imagineeconomy.h"
#include "ui_imagineeconomy.h"
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


ImagineEconomy::ImagineEconomy(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImagineEconomy)
{
    ui->setupUi(this);

    admin.show();
ImagineEconomy::close();
ImagineEconomy::hide();

}

ImagineEconomy::~ImagineEconomy()
{
    delete ui;
}

