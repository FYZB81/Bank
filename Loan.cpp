#include "Loan.h"
#include<iostream>
using namespace std;
int Loan::count = 100000000;
Loan::Loan(int acc,Date* get_l,long long int a,long long int p,int noi,long long int aoi,int nopi,int novi)
{
    account_id=acc;
    date_get_loan=get_l;
    loan_amount=a;
    profit=p;
    Number_of_installments=noi;
    amount_of_installments=aoi;
    Number_of_paid_installments=nopi;
    Number_of_Overdue_installments=novi;
    count++;
    loan_id = count;
}
Loan::Loan(){
    Number_of_installments = 24;
    count++;
    loan_id = count;
}
void Loan::set_account_id(int a){
    account_id = a;
}

int Loan::get_account_id(){
    return account_id;
}
void Loan::show_loan(){
    cout<<"Loan id is:"<<get_Loan_id()<<endl;
    cout<<"Account id is:"<<get_account_id()<<endl;
    cout<<"Date start :"<<get_date_of_get_loan()->get_day()<<"/"<<get_date_of_get_loan()->get_month()<<"/"<<get_date_of_get_loan()->get_year()<<endl;
    cout<<"Loan amount is:"<<Getloan_amount()<<endl;
    cout<<"Number of installment:"<<GetNumber_of_installments()<<endl;
    cout<<"amount of installments is:"<<Getamount_of_installments()<<endl;
    cout<<"Number of overdue installment is:"<<GetNumber_of_Overdue_installments()<<endl;
    cout<<"Number of paid installment is:"<<GetNumber_of_paid_installments()<<endl;
}
void Loan::set_loan_id(int n){
    loan_id = n;
}
int Loan::get_Loan_id(){
    return loan_id;
}

void Loan ::Set_Date_of_get_loan(Date* a){
    date_get_loan = a;
}
Date* Loan::get_date_of_get_loan() {
    return date_get_loan;
}

void Loan::Setloan_amount(long long int a) {
    loan_amount = a;
}
long long int Loan::Getloan_amount() {
    return loan_amount;
}


void Loan::Setprofit(long long int a) {
    profit = a;
}
long long int Loan::Getprofit() {
    return profit;
}


void Loan::SetNumber_of_installments(int a) {
    Number_of_installments = a;
}
int Loan::GetNumber_of_installments() {
    return Number_of_installments;
}


void Loan::Setamount_of_installments(long long int a) {
    amount_of_installments = a;
}
long long int Loan::Getamount_of_installments() {
    return amount_of_installments;
}


void Loan::SetNumber_of_paid_installments(int a) {
    Number_of_paid_installments = a;
}
int Loan::GetNumber_of_paid_installments() {
    return Number_of_paid_installments;
}


void Loan::SetNumber_of_Overdue_installments (int a) {
    Number_of_Overdue_installments = a;
}
int Loan::GetNumber_of_Overdue_installments() {
    return Number_of_Overdue_installments;
}

bool Loan::check_exist(int Id)
{
    if(Id =loan_id)
    return true;

    return false;
}
void Loan::set_check_pay(bool a)
{
    check_pay=a;
}
bool Loan::get_check_pay(){
    return check_pay;
}

void Loan::set_cnt(int n){
    count = n;
}
