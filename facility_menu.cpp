#include "facility_menu.h"
#include "ui_facility_menu.h"
#include"Facilityemployee.h"
#include"Client.h"
#include<qmessagebox.h>
#include"show_loan_information.h"
#include"show_waiting_line.h"
facility_menu::facility_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::facility_menu)
{
    ui->setupUi(this);
}

facility_menu::~facility_menu()
{
    delete ui;
}

void facility_menu::on_pushButton_clicked()
{
    long long int national_code = ui->lineEdit->text().toLongLong();
    bank->get_facility()->block_account(national_code);
    report_file<<"all accounts of client whith national code "<<national_code<<" blocked in Date "<<bank->get_now()->get_day()<<"/"
    <<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
}


void facility_menu::on_pushButton_3_clicked()
{
    bank->get_facility()->check_request(report_file);
}


void facility_menu::on_pushButton_5_clicked()
{
    this->close();
}


void facility_menu::on_pushButton_4_clicked()
{
    int c_index = -1,l_index = -1;
    int id = ui->lineEdit_2->text().toInt();
        for( int i = 0 ; i < bank->get_clients().size(); i++ ){
            for( int j = 0 ; j < bank->get_clients()[i]->get_loan().size() ; j++){
                if( bank->get_clients()[i]->get_loan()[j]->get_Loan_id() == id ){
                    c_index = i;
                    l_index = j;
                }
            }
        }
        if( c_index != -1  && l_index != -1 ){
            show_by_id_loan = bank->get_clients()[c_index]->get_loan()[l_index];
            show_loan_information * newform = new show_loan_information;
            newform->show();
        }
        else{
            QMessageBox msgbox;
            msgbox.setText("not found!");
            msgbox.setWindowTitle("error!");
            msgbox.exec();
        }
}


void facility_menu::on_pushButton_2_clicked()
{
    show_waiting_line * newform = new show_waiting_line;
    newform->show();
}

