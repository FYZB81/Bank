#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;
class Manager:public Employee{
public:
    Manager(string fname,string lname,Date* b,string ID,string pass,Bank* ba);
    void show_information_employee(int);
    void add_employee(Employee*);
    void delete_employee(int);
};
#endif // MANAGER_H
