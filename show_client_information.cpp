#include "show_client_information.h"
#include "ui_show_client_information.h"
#include<string>
#include"Account.h"
#include"Client.h"
#include"Date.h"
show_client_information::show_client_information(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_client_information)
{
    ui->setupUi(this);
}

show_client_information::~show_client_information()
{
    delete ui;
}

void show_client_information::on_pushButton_3_clicked()
{
    this->close();
}


void show_client_information::on_pushButton_clicked()
{

    int size = bank->get_clients()[client_index]->get_account().size();
    QStringList list = {" Account id ", " National id of account owner ", " Day of create account " , "balance", " day over balance","active condition"};
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->setColumnCount(6);
    for(int i = 0; i < size; i++)
    {
        ui->tableWidget->setItem (i, 0, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_account()[i]->get_Account_id())));
        ui->tableWidget->setItem (i, 1, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_account()[i]->get_national_id_owner())));
        string s ;
        s += to_string(bank->get_clients()[client_index]->get_account()[i]->get_start()->get_day());
        s += "/";
        s += to_string(bank->get_clients()[client_index]->get_account()[i]->get_start()->get_month());
        s += "/";
        s += to_string(bank->get_clients()[client_index]->get_account()[i]->get_start()->get_year());
        ui->tableWidget->setItem (i, 2, new QTableWidgetItem (QString::fromStdString(s)));
        ui->tableWidget->setItem (i, 3, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_account()[i]->get_balance())));
        ui->tableWidget->setItem (i, 4, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_account()[i]->get_day_over_balance())));
        if(bank->get_clients()[client_index]->get_account()[i]->get_active() == true ){
            ui->tableWidget->setItem (i, 5, new QTableWidgetItem (QString::fromStdString("active")));
        }
        else{
            ui->tableWidget->setItem (i, 5, new QTableWidgetItem (QString::fromStdString("deactive")));
        }
    }

}


void show_client_information::on_pushButton_2_clicked()
{
    int size = bank->get_clients()[client_index]->get_loan().size();
    QStringList list = {" Loan id ", " Account id for loan ", " Date start ", "Loan amount","number of installment","amount of installments", "Number of paid installment","Number of overdue installment"};
    ui->tableWidget_2->clear();
    ui->tableWidget_2->setRowCount(size);
    ui->tableWidget_2->setHorizontalHeaderLabels(list);
    ui->tableWidget_2->setColumnCount(9);
    for(int i = 0; i < size; i++)
    {
        ui->tableWidget_2->setItem (i, 0, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_loan()[i]->get_Loan_id())));
        ui->tableWidget_2->setItem (i, 1, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_loan()[i]->get_account_id())));
        string s ;
        s += to_string(bank->get_clients()[client_index]->get_loan()[i]->get_date_of_get_loan()->get_day());
        s += "/";
        s += to_string(bank->get_clients()[client_index]->get_loan()[i]->get_date_of_get_loan()->get_month());
        s += "/";
        s += to_string(bank->get_clients()[client_index]->get_loan()[i]->get_date_of_get_loan()->get_year());
        ui->tableWidget_2->setItem (i, 2, new QTableWidgetItem (QString::fromStdString(s)));
        ui->tableWidget_2->setItem (i, 3, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_loan()[i]->Getloan_amount())));
        ui->tableWidget_2->setItem (i, 4, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_loan()[i]->GetNumber_of_installments())));
        ui->tableWidget_2->setItem (i, 5, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_loan()[i]->Getamount_of_installments())));
        ui->tableWidget_2->setItem (i, 6, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_loan()[i]->GetNumber_of_paid_installments())));
        ui->tableWidget_2->setItem (i, 7, new QTableWidgetItem (QString::number (bank->get_clients()[client_index]->get_loan()[i]->GetNumber_of_Overdue_installments())));

    }
}

