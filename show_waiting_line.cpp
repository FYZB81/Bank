#include "show_waiting_line.h"
#include "ui_show_waiting_line.h"
#include"Account.h"
#include"Facilityemployee.h"
show_waiting_line::show_waiting_line(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_waiting_line)
{
    ui->setupUi(this);
}

show_waiting_line::~show_waiting_line()
{
    delete ui;
}

void show_waiting_line::on_pushButton_clicked()
{
    int size = bank->get_facility()->get_waiting_line().size();
    QStringList list = {" Account id ", " National id of account owner ", " Day of create account " , "balance", " day over balance","active condition"};
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->setColumnCount(7);
    for(int i = 0; i < size; i++)
    {
        ui->tableWidget->setItem (i, 0, new QTableWidgetItem (QString::number (bank->get_facility()->get_waiting_line()[i]->get_Account_id())));
        ui->tableWidget->setItem (i, 1, new QTableWidgetItem (QString::number (bank->get_facility()->get_waiting_line()[i]->get_national_id_owner())));
        string s ;
        s += to_string(bank->get_facility()->get_waiting_line()[i]->get_start()->get_day());
        s += "/";
        s += to_string(bank->get_facility()->get_waiting_line()[i]->get_start()->get_month());
        s += "/";
        s += to_string(bank->get_facility()->get_waiting_line()[i]->get_start()->get_year());
        ui->tableWidget->setItem (i, 2, new QTableWidgetItem (QString::fromStdString(s)));
        ui->tableWidget->setItem (i, 3, new QTableWidgetItem (QString::number (bank->get_facility()->get_waiting_line()[i]->get_balance())));
        ui->tableWidget->setItem (i, 4, new QTableWidgetItem (QString::number (bank->get_facility()->get_waiting_line()[i]->get_day_over_balance())));
        if(bank->get_facility()->get_waiting_line()[i]->get_active() == true ){
            ui->tableWidget->setItem (i, 5, new QTableWidgetItem (QString::fromStdString("active")));
        }
        else{
            ui->tableWidget->setItem (i, 5, new QTableWidgetItem (QString::fromStdString("deactive")));
        }
        ui->tableWidget->setItem (i, 6, new QTableWidgetItem(QString::number (bank->get_facility()->get_profit()[i])));
    }
}


void show_waiting_line::on_pushButton_2_clicked()
{
    this->close();
}

