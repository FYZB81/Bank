#ifndef CLIENT_H
#define CLIENT_H
#include<vector>
#include"Person.h"
#include"Loan.h"
using namespace std;
//class Employee;
class Account;
//class Loan;
class Person;
class Bank;
class Employee;
class Client : public person{
    int64_t national_code;
    vector<Account*> accounts;
    vector<Loan*>loans;
    Bank * bank;
public:
    Client(string fname,string lname,Date* b,string ID,string pass,int64_t nat_code);
    int64_t get_national_code();
    void show_information();
    vector<Account*> get_account();
    vector<Loan*> get_loan();
    void add_salary(int Account_id,int add);
    void remove_salary(int Account_id,int add);
    void loan_request(int,int);
    friend class Employee;
    bool search_account(int id);
    friend istream &operator>>(istream& in,Client& c);
    friend void read_client(istream & in,bool &check,Bank*);
    friend class Employee;
    void set_bank(Bank*);
    Bank* get_bank();
    void add_loan(Loan *);
    friend class Bank;
    void add_account(Account*);
};
#endif
