#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include"Person.h"
using namespace std;

class Bank;
class Account;
class person;
class Employee : public person{
protected:
    static int cnt;
    string type;
    int personal_id;
    long long int salary;
    int free_hour;
    int over_work;
    Bank* bank;
public:
    Employee(string fname,string lname,Date* b,string ID,string pass,Bank* ba);
    void request_free_hour(int);
    void request_over_work(int);
    void show_information();
    void check_salary_free_hour();
    void check_salary_over_work(int);
    void create_account();
    void show_client_information(int64_t);
    void create_account(Account*);
    void Delete_Account(int,int64_t);
    void set_salary(int);
    int get_salary();
    void set_free_hour(int);
    int get_free_hour();
    void set_over_work(int);
    int get_over_work();
    int get_personal_id();
    string get_type();
    void set_type(string);
    static void set_cnt(int);
    //void set_bank(Bank*);
    //Bank* get_bank();
    static int get_cnt();
};
extern Account * new_account_for_new_client;
#endif // EMPLOYEE_H
