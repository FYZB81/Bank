#include "show_loan_information.h"
#include "ui_show_loan_information.h"

show_loan_information::show_loan_information(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_loan_information)
{
    ui->setupUi(this);
    ui->label_8->setText(QString::number(show_by_id_loan->get_Loan_id()));
    ui->label_9->setText(QString::number(show_by_id_loan->get_account_id()));
    string s ;
    s += to_string(show_by_id_loan->get_date_of_get_loan()->get_day());
    s += "/";
    s += to_string(show_by_id_loan->get_date_of_get_loan()->get_month());
    s += "/";
    s += to_string(show_by_id_loan->get_date_of_get_loan()->get_year());
    ui->label_10->setText(QString::fromStdString(s));
    ui->label_11->setText(QString::number(show_by_id_loan->Getloan_amount()));
    ui->label_12->setText(QString::number(show_by_id_loan->GetNumber_of_installments()));
    ui->label_13->setText(QString::number(show_by_id_loan->Getamount_of_installments()));
    ui->label_14->setText(QString::number(show_by_id_loan->GetNumber_of_Overdue_installments()));
    ui->label_16->setText(QString::number(show_by_id_loan->GetNumber_of_paid_installments()));
    ui->label_18->setText(QString::number(show_by_id_loan->Getprofit()));
}

show_loan_information::~show_loan_information()
{
    delete ui;
}

void show_loan_information::on_pushButton_clicked()
{
    this->close();
}

