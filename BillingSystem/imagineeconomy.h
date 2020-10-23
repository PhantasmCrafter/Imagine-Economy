#ifndef IMAGINEECONOMY_H
#define IMAGINEECONOMY_H
#include <QMainWindow>
#include<sellscurve.h>
#include<admin.h>
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


QT_BEGIN_NAMESPACE
namespace Ui { class ImagineEconomy; }
QT_END_NAMESPACE

class ImagineEconomy : public QMainWindow
{
    Q_OBJECT

public:
    ImagineEconomy(QWidget *parent = nullptr);
    ~ImagineEconomy();
    sellsCurve sells;
    Admin admin;

private:
    Ui::ImagineEconomy *ui;
};
#endif // IMAGINEECONOMY_H
