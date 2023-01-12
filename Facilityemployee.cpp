#include "Facilityemployee.h"
#include<iostream>
#include"Employee.h"
#include"Bank.h"
#include"Client.h"
#include"Account.h"
#include"Loan.h"
#include"Date.h"
#include"Error.h"
#include<qmessagebox.h>
using namespace std;

Facility_employee::Facility_employee(string fname,string lname,Date* b,string ID,string pass,Bank* ba):Employee(fname,lname,b,ID,pass,ba){
    type = "Facility_employee";
    daily_loan = 0;
}
void Facility_employee::block_account(int64_t id){
    int index = -1;
    for( int i = 0 ; i < bank->get_clients().size() ; i++ ){
        //bank->clients[i]->show_information();
        if( id == bank->clients[i]->get_national_code() ){
            index = i;
        }
    }
    if( index != -1 ){
        for( int i = 0 ; i < bank->clients[index]->get_account().size() ; i++ ){
            bank->clients[index]->get_account()[i]->set_active(false);
            QMessageBox msgbox;
            msgbox.setText("all account blocked!");
            msgbox.setWindowTitle("ok!");
            msgbox.exec();
        }
    }
    else{
        QMessageBox msgbox;
        msgbox.setText("not found!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }

}
void Facility_employee::show_waiting_line(){
    for( int i = 0 ; i < waiting_line.size(); i++ ){
            waiting_line[i]->show_account();
    }
}
void Facility_employee::check_request(iostream & fa){
    if( waiting_line.size() == 0 )
        return;
    if( waiting_line[0]->get_day_over_balance() >= 1 ){
        if( daily_loan == 0 ){
            for( int i = 0 ; i < bank->get_clients().size() ; i++ ){
                if( waiting_line[0]->get_national_id_owner() == bank->get_clients()[i]->get_national_code() ){
                    for( int j = 0 ; j < bank->get_clients()[i]->get_loan().size() ; j++ ){
                        if(bank->get_clients()[i]->get_loan()[j]->get_account_id() == waiting_line[0]->get_Account_id()
                         && bank->get_clients()[i]->get_loan()[j]->GetNumber_of_installments() != bank->get_clients()[i]->get_loan()[j]->GetNumber_of_paid_installments() ){
                            waiting_line.erase(waiting_line.begin());
                            profits.erase(profits.begin());
                            QMessageBox msgbox;
                            msgbox.setText("you can n't get loan twice!");
                            msgbox.setWindowTitle("error!");
                            msgbox.exec();
                            return;
                        }
                    }
                }
            }
            if( waiting_line[0]->get_active() == false ){
                QMessageBox msgbox;
                msgbox.setText("you can n't get loan because the account is deactive!");
                msgbox.setWindowTitle("error!");
                msgbox.exec();
                return;
            }
            int p = profits[0];
            bank->send_accept_loan_request_to_client(waiting_line[0],p,fa);
            waiting_line.erase(waiting_line.begin());
            profits.erase(profits.begin());
            daily_loan = 1;
        }
    }
    QMessageBox msgbox;
    msgbox.setText("first request in line check!");
    msgbox.setWindowTitle("ok!");
    msgbox.exec();

}
void Facility_employee::show_loan_condition(int64_t id){
    int c_index = -1,l_index = -1;
    for( int i = 0 ; i < bank->clients.size(); i++ ){
        for( int j = 0 ; j < bank->clients[i]->get_loan().size() ; j++){
            if( bank->clients[i]->get_loan()[j]->get_Loan_id() == id ){
                c_index = i;
                l_index = j;
            }

        }
    }
    if( c_index != -1  && l_index != -1 ){
        bank->clients[c_index]->get_loan()[l_index]->show_loan();
    }
    else{
        throw Not_found();
    }
}
void Facility_employee::add_to_waiting_line(Account*c,int profit){
    waiting_line.push_back(c);
    profits.push_back(profit);
}
/*void Facility_employee::add_from_file_to_waiting_line(Account* c, int profit,int index){
    waiting_line[index] = c;
    profits[index] = profit;
}*/
int Facility_employee::get_daily_loan(){
    return daily_loan;
}
void Facility_employee::set_daily_loan(int d){
    daily_loan = d;
}
/*Facility_employee* Facility_employee::operator=(Facility_employee* f_copy){
    if( this == f_copy )
        return this;
    salary = f_copy->get_salary();

}*/
vector<Account *> Facility_employee::get_waiting_line(){
    return waiting_line;
}
vector <int> Facility_employee::get_profit()
{
    return profits;
}
