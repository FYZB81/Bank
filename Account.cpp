#include "Account.h"
#include<iostream>
#include"Date.h"

using namespace std;
int Account::cnt = 10000;
Account::Account(int64_t n,Date* s,long long int b){
    set_national_id_owner(n);
    set_start(s);
    set_balance(b);
    day_over_balance = 0;
    active = true;
    cnt++;
    Account_id = cnt;
}
int Account::get_Account_id(){
    return Account_id;
}
void Account::set_national_id_owner(int64_t n){
    national_id_owner = n;
}
int64_t Account::get_national_id_owner(){
    return national_id_owner;
}
void Account::set_start(Date* s){
    start = s;
}
Date* Account::get_start(){
    return start;
}
long long int Account::get_balance(){
    return balance;
}
void Account::set_balance(long long int s){
    balance = s;
}
void Account::set_day_over_balance(int s){
    day_over_balance = s;
}
int Account::get_day_over_balance(){
    return day_over_balance;
}
void Account::set_active(bool a){
    active = a;
}
bool Account::get_active(){
    return active;
}
void Account::add_balance(int a){
    balance += a;
}
void Account::reduction_balance(int r){
    balance -= r;
}
void Account::show_account(){
    cout<<"Account id is:"<<get_Account_id()<<"\n";
    cout<<"National id of account owner:"<<get_national_id_owner()<<endl;
    cout<<"Day of create account\n";
    get_start()->print_date();
    cout<<"balance of account is:"<<get_balance()<<"\n";
    cout<<"Number of day that's balance over 1000000 "<<get_day_over_balance()<<endl;
    if( get_active() ){
        cout<<"Active\n";
    }
    else{
        cout<<"Deactive\n";
    }
}
void Account::set_account_id(int a)
{
    Account_id=a;
}
void Account::set_cnt(int n){
    cnt = n;
}
