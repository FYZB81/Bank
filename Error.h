#ifndef ERROR_H
#define ERROR_H
#include<iostream>
using namespace std;
class Not_found{};
class Bad_date{};
class Bad_salary{
    string error;
public:
    Bad_salary(string s){error = s;}
    string get_error(){ return error;}
};
#endif // ERROR_H
