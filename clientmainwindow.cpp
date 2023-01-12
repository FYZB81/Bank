#include "clientmainwindow.h"
#include "ui_clientmainwindow.h"
#include"Bank.h"
#include"Client.h"
#include <qmessagebox.h>
#include<vector>
#include"client_menu.h"

clientmainwindow::clientmainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientmainwindow)
{
    ui->setupUi(this);
}

clientmainwindow::~clientmainwindow()
{
    delete ui;
}

void clientmainwindow::on_pushButton_clicked()
{
    //bool check = false;
    for( int i = 0 ; i < bank->get_clients().size() ; i++ ){
        if( ui->lineEdit->text().toStdString() == bank->get_clients()[i]->Getid() && ui->lineEdit_2->text().toStdString() == bank->get_clients()[i]->Getpassword() ){
            client_index = i;
            client_menu * newform = new client_menu;
            newform->show();
            return;
            /*QMessageBox msgbox;
            msgbox.setText("YOU SUCCUSFULLY SIGN IN");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
            check = true;*/

        }

    }
    //if(!check){
        QMessageBox msgbox;
        msgbox.setText("ENTER AGAIN");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    //}

}


void clientmainwindow::on_pushButton_2_clicked()
{
    this->close();
}

