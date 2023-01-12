#include "Date.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include"Error.h"
using namespace std;
Date::Date(int d, int m, int y)
{
    //constructor
    set_date(d, m, y);
}
Date::Date()
{
    //default constructor
    set_date(1, 1, 1390);
}


bool is_leap_year(int year)
{
    int r = year % 33;
    return r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30;
}

int max_day_for_month(int m, int y)
{
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    else
        throw Bad_date();
}

void Date::inc_one_day()
{
    day++;
    if (day > max_day_for_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::set_date(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > max_day_for_month(m, y))
        throw Bad_date();

    day = d;
    month = m;
    year = y;
}

void Date::print_date()
{
    //baraye chape tarikh
    cout << day << '/' << month << '/' << year << endl;
}

bool Date::equals(Date d) {
    //moghaieseye 2 tarikh
    return day == d.day && month == d.month && year == d.year;
}
int days_between(Date d1, Date d2) {
    // Assuming d1 is not later than d2
    int count = 1;
    while (!d1.equals(d2)) {
        d1.inc_one_day();
        count++;
    }
    return count;
}
ostream & operator<<(ostream & out,const Date & d){
    out<<d.day<<"/"<<d.month<<"/"<<d.year<<"\n";
    return out;
}

Date str_to_date(string s) {
    //TODO: Handle formatting errors
    int slash_pos = s.find('/'); //3/12/1394 => slash_pos=1
    int d = stoi(s.substr(0, slash_pos)); //=> d=3
    s = s.substr(slash_pos + 1);//=>s=12/1394
    slash_pos = s.find('/');//=>slash_pos=2
    int m = stoi(s.substr(0, slash_pos));//=>m=12
    int y = stoi(s.substr(slash_pos + 1));//=>y=1394

    return Date(d, m, y);
}
