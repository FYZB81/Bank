#ifndef BANK_H
#define BANK_H
#include<vector>
#include<iostream>
using namespace std;
class Employee;
class Client;
class Manager;
class Account;
class Facility_employee;
class Date;
class Bank{
    vector<Employee*> employees;
    vector<Client*> clients;
    string name;
    string id;
    Manager* m;
    Facility_employee* f;
    Date * now;
public:

    //Bank(vector<Employee*>employee,vector<Client*>c,string name,string id,Manager * m);
    vector<Employee*> get_employee();
    vector<Client*> get_clients();
    friend class Employee;
    friend class Manager;
    friend class Facility_employee;
    friend void read_client(istream & in,bool &check,Bank * bank);
    friend void write_client(ostream &out,Bank*bank);
    void add_request_from_client_to_waiting_line(Account*,int);
    void send_accept_loan_request_to_client(Account*,int,iostream &);
    void set_manager(Manager *);
    void set_facility(Facility_employee *);
    Manager * get_manager();
    Facility_employee * get_facility();
    void set_date(Date* d);
    void add_employee(Employee*);
    void add_client(Client*);
    Date* get_now();
    ~Bank();
};
#endif
