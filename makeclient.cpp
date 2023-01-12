#include "makeclient.h"
#include "ui_makeclient.h"
#include<string>
#include"Date.h"
#include"Bank.h"
#include"qmessagebox.h"
#include"Client.h"
using namespace std;
makeclient::makeclient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::makeclient)
{
    ui->setupUi(this);
}

makeclient::~makeclient()
{
    delete ui;
}

void makeclient::on_pushButton_2_clicked()
{
    this->close();
}


void makeclient::on_pushButton_clicked()
{

       string fname, lname,pas,Id;
       fname = ui->lineEdit->text().toStdString();
       lname = ui->lineEdit_2->text().toStdString();
       int d,m,y;
       d = ui->lineEdit_6->text().toInt();
       m = ui->lineEdit_7->text().toInt();
       y = ui->lineEdit_8->text().toInt();
       if( (m > 6 && d > 30)|| (m <= 6 && d > 31)|| m < 0 || d < 0 || y < 0 ){
           QMessageBox msgbox;
           msgbox.setText("date is invalid!");
           msgbox.setWindowTitle("error!");
           msgbox.exec();
       }
       else{
           Date* birth = new Date(d,m,y);
           Id = ui->lineEdit_4->text().toStdString();
           for( int i = 0 ; i < bank->get_clients().size() ; i++ ){
               if( Id == bank->get_clients()[i]->Getid() ){
                   QMessageBox msgbox;
                   msgbox.setText("Id isn't unique!");
                   msgbox.setWindowTitle("error!");
                   msgbox.exec();
                   return;
               }
           }
           pas = ui->lineEdit_5->text().toStdString();
           Client* c = new Client(fname,lname,birth,Id,pas,national_code_new_client);
           c->add_account(new_account_for_new_client);
           bank->add_client(c);
           QMessageBox msgbox;
           msgbox.setText("client and account create!");
           msgbox.setWindowTitle("ok!");
           msgbox.exec();
       }




}

