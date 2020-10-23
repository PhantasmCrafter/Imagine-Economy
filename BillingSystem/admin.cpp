#include "admin.h"
#include "ui_admin.h"



Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    db.setDatabaseName("C:/Users/PRO-B/Desktop/Billing system/BillingSystem/Resources/database/information.db");
    Admin::setCentralWidget(ui->main_widget);
    ui->logo->setStyleSheet("border-image:url(':/images/Resources/images/curve.png');");


}

Admin::~Admin()
{
    delete ui;
}




void Admin::saveSetting()
{
    QString userName = ui->userName->text();
    QString userId = ui->userId->text();
    QString userLocation = ui->userLocation->text();
    QMessageBox::information(this,"title","this is" +userName + userId + userLocation);
}




int Admin::vectorBiggestNumber(QVector<int> givenVector = {0})
{
    int biggestNumber = givenVector.at(0);
    for(int totalSize = 0; totalSize < givenVector.size(); totalSize++){
        if(biggestNumber < givenVector[totalSize]){
            biggestNumber = givenVector[totalSize];
        }
    }

    return  biggestNumber;
}



void Admin::on_add_item_clicked()
{
    QString price = ui->item_price->text();
    QString vat = ui->item_vat->text();
    QString discount = ui->item_discount->text();
    QString name = ui->item_name->text();
    QString stock = ui->item_stock->text();

    QVector<int> num = {0};

    if(db.open()){
        QSqlQuery q;
        if(q.exec("select product_id from products;")){
            while(q.next()){
            num.push_back(q.value(0).toInt());
            }
        }
        if(price.isEmpty() || vat.isEmpty() || discount.isEmpty() || name.isEmpty() || stock.isEmpty()){
            QApplication::beep();
            QMessageBox::warning(this,"Incorrect","Please Fill all the data properly");
        }else{

            int product_id  = 0;
            product_id = vectorBiggestNumber(num);
            product_id++;
            QString command = "insert into products values("+QString::number(product_id)+",'"+name+"',"+ price+","+stock+",0,"+ discount+"," +vat+");";
            if(q.exec(command)){
                QMessageBox::information(this,"Data inserted","Item was added succesfully");
                ui->item_vat->setText("");
                ui->item_name->setText("");
                ui->item_price->setText("");
                ui->item_discount->setText("");
                ui->item_stock->setText("");

            }else{
               QMessageBox::information(this,"Data not","Item was not added succesfully" , "Fixes\nTry putting integer/number in prices column\nReload the program");
            }


        }



    }else{
        QMessageBox::warning(this,"ERROR","We cannot connect with database\nMay be Database is not available\n Fix:::Reload the program");
    }


    db.close();

}

