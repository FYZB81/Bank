#ifndef FACILITYEMPLOYEE_H
#define FACILITYEMPLOYEE_H
#include<iostream>
#include<vector>
#include "Employee.h"
class Bank;
class Account;
using namespace std;

class Facility_employee:public Employee{
    vector<Account*>waiting_line;
    vector<int>profits;
    int daily_loan;
public:
    Facility_employee(string fname,string lname,Date* b,string ID,string pass,Bank* ba);
    void block_account(int64_t);
    void show_waiting_line();
    void check_request(iostream &);
    void show_loan_condition(int64_t);
    void add_to_waiting_line(Account*,int);
    //void add_from_file_to_waiting_line(Account*,int,int);
    int get_daily_loan();
    void set_daily_loan(int);
    vector <Account *> get_waiting_line();
    vector <int> get_profit();
    //Facility_employee* operator=(Facility_employee*);
};
#endif
