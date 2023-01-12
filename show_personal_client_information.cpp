#include "show_personal_client_information.h"
#include "ui_show_personal_client_information.h"
#include"Client.h"
show_personal_client_information::show_personal_client_information(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_personal_client_information)
{
    ui->setupUi(this);
    ui->label_7->setText(QString::fromStdString(bank->get_clients()[index_ckient_in_search_employee]->Getfirst_name()));
    ui->label_8->setText(QString::fromStdString(bank->get_clients()[index_ckient_in_search_employee]->Getlast_name()));
    ui->label_10->setText(QString::number(bank->get_clients()[index_ckient_in_search_employee]->get_national_code()));
    ui->label_11->setText(QString::fromStdString(bank->get_clients()[index_ckient_in_search_employee]->Getid()));
    ui->label_12->setText(QString::fromStdString(bank->get_clients()[index_ckient_in_search_employee]->Getpassword()));
    string s ;
    s += to_string(bank->get_clients()[index_ckient_in_search_employee]->Get_birth()->get_day());
    s += "/";
    s += to_string(bank->get_clients()[index_ckient_in_search_employee]->Get_birth()->get_month());
    s += "/";
    s += to_string(bank->get_clients()[index_ckient_in_search_employee]->Get_birth()->get_year());
    ui->label_9->setText(QString::fromStdString(s));

}

show_personal_client_information::~show_personal_client_information()
{
    delete ui;
}

void show_personal_client_information::on_pushButton_clicked()
{
    this->close();
}

