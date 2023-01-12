#include "client_menu.h"
#include "ui_client_menu.h"
#include"Bank.h"
#include"Client.h"
#include"qmessagebox.h"
#include"File.h"
#include"show_client_information.h"
#include"show_personal_client_information.h"
client_menu::client_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client_menu)
{
    ui->setupUi(this);
    report_file<<"Account with national code "<<bank->get_clients()[client_index]->get_national_code()<<" login in date"
    <<bank->get_now()->get_day()<<"/"<<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
}

client_menu::~client_menu()
{
    delete ui;
}

void client_menu::on_pushButton_3_clicked()
{
    show_client_information * newform = new show_client_information;
    newform->show();
    index_ckient_in_search_employee = client_index;
    show_personal_client_information * newform2 = new show_personal_client_information;
    newform2->show();
    //bank->get_clients()[client_index]->show_information();
}


void client_menu::on_pushButton_clicked()
{

    int account_id = ui->lineEdit->text().toInt();
    int add = ui->lineEdit_2->text().toInt();
    bank->get_clients()[client_index]->add_salary(account_id,add);
    report_file<<"Account with ID "<<account_id<<" and national code "<<bank->get_clients()[client_index]->get_national_code()
    <<" has "<<add<<"Increase in date"<<bank->get_now()->get_day()<<"/"
    <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
}


void client_menu::on_pushButton_5_clicked()
{
    this->close();
}


void client_menu::on_pushButton_2_clicked()
{
    int account_id = ui->lineEdit_3->text().toInt();
    int remove = ui->lineEdit_4->text().toInt();
    bank->get_clients()[client_index]->remove_salary(account_id,remove);
    report_file<<"Account with ID "<<account_id<<" and national code "<<bank->get_clients()[client_index]->get_national_code()
    <<" has "<<remove<<"decrease in date"<<bank->get_now()->get_day()<<"/"
    <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
}


void client_menu::on_pushButton_4_clicked()
{
    int account_id = ui->lineEdit_5->text().toInt();
    int c = ui->lineEdit_6->text().toInt();
    int profit;
    if(c==4){
       profit=4;
    }
    else if(c==8){
       profit=8;
    }
    else if(c==12){
       profit=12;
    }
    else
    {
        QMessageBox msgbox;
        msgbox.setText("profit must be 4 or 8 or 12!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
        return;
    }
    bank->get_clients()[client_index]->loan_request(account_id,profit);
    report_file<<"Account with ID "<<account_id<<" and national code "<<bank->get_clients()[client_index]->get_national_code()
    <<" request for loane with "<<profit<<" profit in date"<<bank->get_now()->get_day()<<"/"
    <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
}

