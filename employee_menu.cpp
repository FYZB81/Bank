#include "employee_menu.h"
#include "ui_employee_menu.h"
#include"Date.h"
#include"Employee.h"
#include<fstream>
#include<qmessagebox.h>
#include"show_employee_information.h"
#include"Client.h"
#include"show_personal_client_information.h"
#include"Account.h"
#include"facility_menu.h"
#include"manager_menu.h"
employee_menu::employee_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::employee_menu)
{
    ui->setupUi(this);
    ui->pushButton_8->setEnabled(false);
    ui->pushButton_9->setEnabled(false);
    string s ;
    s = bank->get_employee()[employee_index]->get_type();
    if( s == "Facility_employee" ){
        ui->pushButton_8->setEnabled(true);
    }
    else if( s == "Manager" ){
        ui->pushButton_9->setEnabled(true);
    }
    s += " MENU";
    ui->label_9->setText(QString::fromStdString(s));
    report_file<<"Clerk with personal ID "<<bank->get_employee()[employee_index]->get_personal_id()
    <<" login in date "<<bank->get_now()->get_day()<<"/"
    <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
}

employee_menu::~employee_menu()
{
    delete ui;
}

void employee_menu::on_pushButton_clicked()
{
    int free_hour = ui->lineEdit->text().toInt();
    if( free_hour < 0 ){
        QMessageBox msgbox;
        msgbox.setText("you should enter positive number!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }
    else{
        bank->get_employee()[employee_index]->request_free_hour(free_hour);
        report_file<<"Clerk with personal ID "<<bank->get_employee()[employee_index]->get_personal_id()<<"get"<<free_hour
        <<" hour rest in date "<<bank->get_now()->get_day()<<"/"
        <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
    }

}


void employee_menu::on_pushButton_7_clicked()
{
    this->close();
}


void employee_menu::on_pushButton_2_clicked()
{
    int over_time = ui->lineEdit_2->text().toInt();
    if( over_time < 0 ){
        QMessageBox msgbox;
        msgbox.setText("you should enter positive number!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }
    else{
        bank->get_employee()[employee_index]->request_over_work(over_time);
        report_file<<"Clerk with personal ID "<<bank->get_employee()[employee_index]->get_personal_id()<<"get"<<over_time
        <<" hour over work "<<bank->get_now()->get_day()<<"/"
        <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
    }
}


void employee_menu::on_pushButton_3_clicked()
{
    show_employee_index = employee_index;
    show_employee_information * newform = new show_employee_information;
    newform->show();
}


void employee_menu::on_pushButton_4_clicked()
{
    long long national_code = ui->lineEdit_3->text().toLongLong();
    bool check = false;
    for( int i = 0 ; i < bank->get_clients().size() ; i++ ){
        if( bank->get_clients()[i]->get_national_code() == national_code ){
            index_ckient_in_search_employee = i;
            check = true;
        }
    }
    if( !check ){
        QMessageBox msgbox;
        msgbox.setText("not Found!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();

    }
    else{
        show_personal_client_information * newform = new show_personal_client_information;
        newform->show();
    }
}


void employee_menu::on_pushButton_5_clicked()
{
    long long int national_code = ui->lineEdit_4->text().toLongLong();
    long long int balance = ui->lineEdit_5->text().toLongLong();
    if( balance < 50000 ){
        QMessageBox msgbox;
        msgbox.setText("balance should over 50000!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }
    else{
        Account* accont_=new Account(national_code,now,balance);
        national_code_new_client = national_code;
        bank->get_employee()[employee_index]->create_account(accont_);
        report_file<<"Account with national code  "<<national_code<<" Create in date"
        <<bank->get_now()->get_day()<<"/"
        <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
    }

}


void employee_menu::on_pushButton_6_clicked()
{
    long long int national_code = ui->lineEdit_6->text().toLongLong();
    int id = ui->lineEdit_7->text().toInt();
    bank->get_employee()[employee_index]->Delete_Account(id,national_code);
    report_file<<"Account with ID "<<id<<" and national code "<<national_code<<" deleted in date"
    <<bank->get_now()->get_day()<<"/"
    <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;

}


void employee_menu::on_pushButton_8_clicked()
{
    facility_menu * newform = new facility_menu;
    newform->show();
}


void employee_menu::on_pushButton_9_clicked()
{
    manager_menu * newform = new manager_menu;
    newform->show();

}

