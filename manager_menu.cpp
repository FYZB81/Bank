#include "manager_menu.h"
#include "ui_manager_menu.h"
#include"show_employee_information.h"
#include"Bank.h"
#include"Employee.h"
#include<qmessagebox.h>
#include"Manager.h"
#include<fstream>
manager_menu::manager_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manager_menu)
{
    ui->setupUi(this);
}

manager_menu::~manager_menu()
{
    delete ui;
}

void manager_menu::on_pushButton_clicked()
{
    bool check = false;
    int id = ui->lineEdit->text().toInt();
    for( int i = 0 ; i < bank->get_employee().size() ; i++ ){
        if( bank->get_employee()[i]->get_personal_id() == id ){
            show_employee_index = i;
            check = true;
        }
    }
    if(!check){
        QMessageBox msgbox;
        msgbox.setText("not found!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }
    else{
        show_employee_information * newform = new show_employee_information;
        newform->show();
    }

}


void manager_menu::on_pushButton_2_clicked()
{
    this->close();
}


void manager_menu::on_pushButton_5_clicked()
{
    string fname, lname,pas,Id;
    fname = ui->lineEdit_2->text().toStdString();
    lname = ui->lineEdit_3->text().toStdString();
    int d,m,y;
    d = ui->lineEdit_6->text().toInt();
    m = ui->lineEdit_7->text().toInt();
    y = ui->lineEdit_9->text().toInt();
    if( (m > 6 && d > 30)|| (m <= 6 && d > 31)|| m < 0 || d < 0 || y < 0 ){
        QMessageBox msgbox;
        msgbox.setText("date is invalid!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }
    else{
        Date* birth = new Date(d,m,y);
        Id = ui->lineEdit_4->text().toStdString();
        for( int i = 0 ; i < bank->get_employee().size() ; i++ ){
            if( Id == bank->get_employee()[i]->Getid() ){
                QMessageBox msgbox;
                msgbox.setText("Id isn't unique!");
                msgbox.setWindowTitle("error!");
                msgbox.exec();
                return;
            }
        }
        pas = ui->lineEdit_5->text().toStdString();
        long long int salary = ui->lineEdit_10->text().toLongLong();
        if( salary < 0 ){
            QMessageBox msgbox;
            msgbox.setText("invalid input Enter again!");
            msgbox.setWindowTitle("error!");
            msgbox.exec();
        }
        else{
            Employee* New=new Employee(fname,lname,birth,Id,pas,bank);
            New->set_free_hour(0);
            New->set_over_work(0);
            New->set_salary(salary);
            bank->get_manager()->add_employee(New);
            report_file<<"Employee with prsonal ID "<<Id<<" added in Date "<<bank->get_now()->get_day()<<"/"
            <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
            QMessageBox msgbox;
            msgbox.setText("employee add succusfully!");
            msgbox.setWindowTitle("ok!");
            msgbox.exec();
        }

    }


}


void manager_menu::on_pushButton_3_clicked()
{
    int ID_personal = ui->lineEdit_11->text().toInt();
    bank->get_manager()->delete_employee(ID_personal);
    report_file<<"Employee with prsonal ID "<<ID_personal<<" Deleted in Date "<<bank->get_now()->get_day()<<"/"
    <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
}

