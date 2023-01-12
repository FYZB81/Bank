#include "Bank.h"
#include<iostream>
#include<vector>
#include"Employee.h"
#include"Client.h"
#include"Facilityemployee.h"
#include"Loan.h"
#include"Account.h"
#include"Error.h"
#include"Manager.h"
using namespace std;
/*Bank::Bank(vector<Employee*>e,vector<Client*>c,string n,string i,Manager * ma){
    for( int i = 0 ; i < e.size() ; i++ ){
        //employees[i] = new Employee();
        employees.push_back(e[i]);
    }
    for( int i = 0 ; i < c.size() ; i++ ){
        //clients[i] = new Client();
        clients.push_back(c[i]);
    }
    name = n;
    id = i;
    //m = new Manager;
    //m = ma;
    //f = new Facility_employee();
    //f = fa;
}*/
/*Bank::Bank(){

}*/
vector<Employee*>Bank::get_employee(){
    return employees;
}
vector<Client*> Bank::get_clients(){
    return clients;
 }
void Bank::add_request_from_client_to_waiting_line(Account* c,int profit){
    f->add_to_waiting_line(c,profit);
}
void Bank::send_accept_loan_request_to_client(Account*a,int profit, iostream & report){
    int index = -1;
    for( int i = 0 ; i < clients.size() ; i++ ){
        if(a->get_national_id_owner() == clients[i]->get_national_code() )
            index = i;
    }
    if( index != -1 ){
        Loan* l = new Loan;
        l->set_account_id(a->get_Account_id());
        l->Setprofit(profit);
        int loan_amount = a->get_balance() * a->get_day_over_balance();
        l->Setloan_amount(loan_amount);
        if( profit == 4 ){
            l->SetNumber_of_installments(12);
        }
        else if( profit == 8 ){
            l->SetNumber_of_installments(24);
        }
        else if( profit == 12 ){
            l->SetNumber_of_installments(36);
        }
        //loan_amount += (loan_amount*profit/100);
        l->Set_Date_of_get_loan(now);
        l->SetNumber_of_Overdue_installments(0);
        l->SetNumber_of_paid_installments(0);
        l->Setamount_of_installments((loan_amount + loan_amount*profit/100)/l->GetNumber_of_installments());
        a->add_balance(loan_amount);
        clients[index]->add_loan(l);
        report<<"Client whit national code "<<clients[index]->get_national_code()<<" get accept for loan with account with ID "<<a->get_Account_id()
        <<" in date "<<now->get_day()<<"/"<<now->get_month()<<"/"<<now->get_year()<<endl;
    }

}

void Bank::set_manager(Manager *ma){
    //m = new Manager(ma->Getfirst_name(),ma->Getlast_name(),ma->Get_birth(),ma->Getid(),ma->Getpassword(),this);
    m = ma;
}
void Bank::set_facility(Facility_employee *fa){
   //f = new Facility_employee(f->Getfirst_name(),f->Getlast_name(),f->Get_birth(),f->Getid(),f->Getpassword(),this);
    f = fa;

}
Manager * Bank::get_manager(){
    return m;
}
Facility_employee * Bank::get_facility(){
    return f;
}

void Bank::set_date(Date* d)
{
    now=d;
}
void Bank::add_employee(Employee* e){
    employees.push_back(e);
}
void Bank::add_client(Client* c){
    clients.push_back(c);
}
Date* Bank::get_now(){
    return now;
}
Bank::~Bank(){
    for( int i = 0 ; i < clients.size() ; i++ ){
            for( int j = 0 ; j < clients[i]->accounts.size() ; j++ ){
                delete clients[i]->accounts[j];
            }
            for( int j = 0 ; j < clients[i]->loans.size() ; j++ ){
                delete clients[i]->loans[j];
            }
            delete clients[i];
        }
        for( int i = 0 ; i < employees.size() ; i++ ){
            delete employees[i];
        }
        delete m;
        delete f;
        delete now;
}
