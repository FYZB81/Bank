#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date {
public:
    Date(int, int, int);
    Date();
    void set_date(int, int, int);
    void print_date();
    bool equals(Date);

    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }
    void inc_one_day();
    friend ostream & operator<<(ostream &,const Date &);
private:
    int day;
    int month;
    int year;
};
bool is_leap_year(int year);
int max_day_for_month(int m, int y);
int days_between(Date d1, Date d2);
ostream & operator<<(ostream & out,const Date & d);
Date str_to_date(string s);
#endif // DATE_H
