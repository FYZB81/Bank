#ifndef FILE_H
#define FILE_H
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class Client;
class Bank;
class Employee;
void read_client(istream &,bool&,Bank*);
void read_employee(istream &,bool&,Bank*);
void write_client(ostream &,Bank*);
void write_employee(ostream &,Bank*);
void read_wait_line(istream &,bool&,Bank *);
void write_wait_line(ostream &,Bank *);
#endif
