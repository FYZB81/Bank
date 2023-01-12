#include "employeemainwindow.h"
#include "ui_employeemainwindow.h"
#include"employee_menu.h"
#include"Employee.h"
#include"qmessagebox.h"
employeemainwindow::employeemainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::employeemainwindow)
{
    ui->setupUi(this);
}

employeemainwindow::~employeemainwindow()
{
    delete ui;
}

void employeemainwindow::on_pushButton_2_clicked()
{
    this->close();
}


void employeemainwindow::on_pushButton_clicked()
{
    for( int i = 0 ; i < bank->get_employee().size() ; i++ ){
        if( ui->lineEdit->text().toStdString() == bank->get_employee()[i]->Getid() && ui->lineEdit_2->text().toStdString() == bank->get_employee()[i]->Getpassword() ){
            employee_index = i;
            employee_menu * newform = new employee_menu;
            newform->show();
            return;
        }

    }
    QMessageBox msgbox;
    msgbox.setText("ENTER AGAIN");
    msgbox.setWindowTitle("Error!");
    msgbox.exec();
}

