#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
using namespace std;
class Date;
class Account{
    static int cnt;
    int Account_id;
    int64_t national_id_owner;
    Date* start;
    long long int balance;
    int day_over_balance;
    bool active;
public:
    Account(int64_t,Date*,long long int);
    int get_Account_id();
    void set_national_id_owner(int64_t);
    int64_t get_national_id_owner();
    void set_start(Date*);
    Date* get_start();
    long long int get_balance();
    void set_balance(long long int);
    void set_day_over_balance(int);
    int get_day_over_balance();
    void set_active(bool);
    bool get_active();
    void add_balance(int);
    void reduction_balance(int);
    void show_account();
    void set_account_id(int);
    static void set_cnt(int);
};

#endif
