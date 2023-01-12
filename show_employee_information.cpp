#include "show_employee_information.h"
#include "ui_show_employee_information.h"
#include"Employee.h"
show_employee_information::show_employee_information(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_employee_information)
{
    ui->setupUi(this);
    ui->label_8->setText(QString::fromStdString(bank->get_employee()[show_employee_index]->Getfirst_name()));
    ui->label_9->setText(QString::fromStdString(bank->get_employee()[show_employee_index]->Getlast_name()));
    ui->label_10->setText(QString::number(bank->get_employee()[show_employee_index]->get_personal_id()));
    ui->label_11->setText(QString::number(bank->get_employee()[show_employee_index]->get_salary()));
    ui->label_12->setText(QString::number(bank->get_employee()[show_employee_index]->get_free_hour()));
    ui->label_13->setText(QString::number(bank->get_employee()[show_employee_index]->get_over_work()));
    ui->label_14->setText(QString::fromStdString(bank->get_employee()[show_employee_index]->get_type()));
    string s ;
    s += to_string(bank->get_employee()[show_employee_index]->Get_birth()->get_day());
    s += "/";
    s += to_string(bank->get_employee()[show_employee_index]->Get_birth()->get_month());
    s += "/";
    s += to_string(bank->get_employee()[show_employee_index]->Get_birth()->get_year());
    ui->label_16->setText(QString::fromStdString(s));
}

show_employee_information::~show_employee_information()
{
    delete ui;
}

void show_employee_information::on_pushButton_clicked()
{
    this->close();
}

