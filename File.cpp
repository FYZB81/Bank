#include "File.h"
#include<iostream>
#include<fstream>
#include<vector>
#include <sstream>
#include<string>
#include"Client.h"
#include"Date.h"
#include"Account.h"
#include"Loan.h"
#include"Employee.h"
#include"Manager.h"
#include"Facilityemployee.h"
#include"Bank.h"
using namespace std;
void read_client(istream & in,bool &check,Bank * bank){
    string first_name,last_name,b,username,passweord,seprator;
    int64_t national_code;
    in>>first_name;
    in>>last_name;
    in>>b;
    Date * birth = new Date(str_to_date(b).get_day(),str_to_date(b).get_month(),str_to_date(b).get_year());
    in>>username;
    in>>passweord;
    in>>national_code;
    Client * cl = new Client(first_name,last_name,birth,username,passweord,national_code);
    cl->set_bank(bank);
    //c.push_back(cl);
    bank->add_client(cl);
    in>>seprator;
    string date_create,day_over,active;
    int account_id;
    long int balance;
    while( seprator == "******" ){
        in>>account_id;
        in>>national_code;
        in>>date_create;
        Date * create_account = new Date(str_to_date(date_create).get_day(),str_to_date(date_create).get_month(),str_to_date(date_create).get_year());
        in>>balance;
        in>>day_over;
        in>>active;
        int day_o = stoi(day_over);
        Account * ac = new Account(national_code,create_account,balance);
        ac->set_day_over_balance(day_o);
        if( active == "active" ){
            ac->set_active(true);
        }
        else{
            ac->set_active(false);
        }
        ac->set_account_id(account_id);
        cl->accounts.push_back(ac);
        in>>seprator;
    }
    while( seprator == "&&&&&&" ){
        int account_id,number_of_in,number_paid_in,number_overdue_in,check_pay;
        long long int Loan_id,profit,loan_amount,amount_in;
        string date;
        in>>account_id;
        in>>Loan_id;
        in>>date;
        in>>loan_amount;
        in>>profit;
        in>>number_of_in;
        in>>amount_in;
        in>>number_paid_in;
        in>>number_overdue_in;
        in>>check_pay;
        Date * start = new Date(str_to_date(date).get_day(),str_to_date(date).get_month(),str_to_date(date).get_year());
        Loan * l = new Loan(account_id,start,loan_amount,profit,number_of_in,amount_in,number_paid_in,number_overdue_in);
        l->set_loan_id(Loan_id);
        bool ch;
        if( check_pay == 1 ){
            ch = true;
        }
        else{
            ch = false;
        }
        l->set_check_pay(ch);
        cl->loans.push_back(l);
        in>>seprator;
    }
    if(seprator == "EEEEEEE"){
        check = false;
    }
}

void read_employee(istream &in,bool& check,Bank*bank){
    //cout<<Employee::get_cnt()<<"\n";
    string first_name,last_name,b,username,passweord,seprator,type;
    int personal_id,free_day,over_day;
    long int salary;
    in>>first_name;
    in>>last_name;
    in>>b;
    Date * birth = new Date(str_to_date(b).get_day(),str_to_date(b).get_month(),str_to_date(b).get_year());
    in>>username;
    in>>passweord;
    in>>personal_id;
    in>>salary;
    in>>free_day;
    in>>over_day;
    in>>type;
    if( type == "Employee" ){
        Employee * new_employee = new Employee(first_name,last_name,birth,username,passweord,bank);
        new_employee->set_free_hour(free_day);
        new_employee->set_over_work(over_day);
        new_employee->set_salary(salary);
        new_employee->set_type(type);
        //e.push_back(new_employee);
        //new_employee->set_bank(bank);
        bank->add_employee(new_employee);
    }
    else if( type == "Manager"){
        Manager * new_employee = new Manager(first_name,last_name,birth,username,passweord,bank);
        new_employee->set_free_hour(free_day);
        new_employee->set_over_work(over_day);
        new_employee->set_salary(salary);
        new_employee->set_type(type);
        //e.push_back(new_employee);
        //new_employee->set_bank(bank);
        bank->set_manager(new_employee);
        bank->add_employee(new_employee);
    }
    else{
        Facility_employee * new_employee = new Facility_employee(first_name,last_name,birth,username,passweord,bank);
        new_employee->set_free_hour(free_day);
        new_employee->set_over_work(over_day);
        new_employee->set_salary(salary);
        new_employee->set_type(type);
        //e.push_back(new_employee);
        //new_employee->set_bank(bank);
        bank->set_facility(new_employee);
        bank->add_employee(new_employee);
    }
    in>>seprator;
    if( seprator == "#######" )
        check = false;
}
void write_client(ostream &out,Bank*bank){
    bool check = false;
    for( int i = 0 ; i < bank->get_clients().size() ; i++ ){
        out<<bank->get_clients()[i]->Getfirst_name()<<" ";
        out<<bank->get_clients()[i]->Getlast_name()<<" ";
        out<<bank->get_clients()[i]->Get_birth()->get_day()<<"/"<<bank->get_clients()[i]->Get_birth()->get_month()<<"/"<<bank->get_clients()[i]->Get_birth()->get_year()<<" ";
        out<<bank->get_clients()[i]->Getid()<<" ";
        out<<bank->get_clients()[i]->Getpassword()<<" ";
        out<<bank->get_clients()[i]->get_national_code()<<"\n";
        //cout<<bank->get_clients()[i]->get_national_code()<<"\n";
        if(  bank->get_clients()[i]->get_account().size() > 0 ){
            out<<"******\n";
            for( int j = 0 ; j < bank->get_clients()[i]->get_account().size() ; j++ ){
                out<<bank->get_clients()[i]->get_account()[j]->get_Account_id()<<" ";
                out<<bank->get_clients()[i]->get_account()[j]->get_national_id_owner()<<" ";
                out<<bank->get_clients()[i]->get_account()[j]->get_start()->get_day()<<"/"<<bank->get_clients()[i]->get_account()[j]->get_start()->get_month()<<"/"<<bank->get_clients()[i]->get_account()[j]->get_start()->get_year()<<" ";
                out<<bank->get_clients()[i]->get_account()[j]->get_balance()<<" ";
                out<<bank->get_clients()[i]->get_account()[j]->get_day_over_balance()<<" ";

                if( bank->get_clients()[i]->get_account()[j]->get_active() == true ){
                    out<<"active\n";
                }
                else{
                    out<<"deactive\n";
                }
                if( j != bank->get_clients()[i]->get_account().size() - 1 ){
                    out<<"******\n";
                }
                else if(bank->get_clients()[i]->get_loan().size() > 0){
                    out<<"&&&&&&\n";
                    check=true;
                    break;
                }
                else if(bank->get_clients()[i]->get_loan().size() ==0 &&i != bank->get_clients().size() - 1  )
                    out<<"######\n";
            }
        }
        if(  bank->get_clients()[i]->get_loan().size() > 0 )
        {
            for(int j=0; j<bank->get_clients()[i]->get_loan().size(); j++)
            {
                        out<<bank->get_clients()[i]->get_loan()[j]->get_account_id()<<" ";

                        out<<bank->get_clients()[i]->get_loan()[j]->get_Loan_id()<<" ";

                        out<<bank->get_clients()[i]->get_loan()[j]->get_date_of_get_loan()->get_day()<<"/"<<
                        bank->get_clients()[i]->get_loan()[j]->get_date_of_get_loan()->get_month()<<"/"
                        <<bank->get_clients()[i]->get_loan()[j]->get_date_of_get_loan()->get_year()<<" ";

                        out<<bank->get_clients()[i]->get_loan()[j]->Getloan_amount()<<" ";
                        out<<bank->get_clients()[i]->get_loan()[j]->Getprofit()<<" ";
                        out<<bank->get_clients()[i]->get_loan()[j]->GetNumber_of_installments()<<" ";
                        out<<bank->get_clients()[i]->get_loan()[j]->Getamount_of_installments()<<" ";
                        out<<bank->get_clients()[i]->get_loan()[j]->GetNumber_of_paid_installments()<<" ";
                        out<<bank->get_clients()[i]->get_loan()[j]->GetNumber_of_Overdue_installments()<<" ";
                        if( bank->get_clients()[i]->get_loan()[j]->get_check_pay() == false ){
                            out<<0<<endl;
                        }
                        else{
                            out<<1<<endl;
                        }
                        if(j != bank->get_clients()[i]->get_loan().size() - 1){
                            out<<"&&&&&&\n";
                        }
                        else if( i != bank->get_clients().size() - 1 && j == bank->get_clients()[i]->get_loan().size() - 1){
                            out<<"######\n";
                        }
                        else if(i == bank->get_clients().size() - 1 && j == bank->get_clients()[i]->get_loan().size() - 1){

                            check = true;
                            break;
                        }
            }
        }
        /*else{
            check = true;
            //out<<"EEEEEEE\n";
        }*/
    }
    if( bank->get_clients()[bank->get_clients().size() - 1]->get_loan().size() == 0 ){
        check = true;
    }
    if( check ){
        out<<"EEEEEEE\n";
    }
}
void write_employee(ostream & out,Bank* bank){
    for(int i=0; i< bank->get_employee().size(); i++)
    {
        out<<bank->get_employee()[i]->Getfirst_name()<<" ";
        out<<bank->get_employee()[i]->Getlast_name()<<" ";
        out<<bank->get_employee()[i]->Get_birth()->get_day()<<"/"<<bank->get_employee()[i]->Get_birth()->get_month()<<"/"<<bank->get_employee()[i]->Get_birth()->get_year()<<" ";
        out<<bank->get_employee()[i]->Getid()<<" ";
        out<<bank->get_employee()[i]->Getpassword()<<" ";
        out<<bank->get_employee()[i]->get_personal_id()<<" ";
        out<<bank->get_employee()[i]->get_salary()<<" ";
        out<<bank->get_employee()[i]->get_free_hour()<<" ",
        out<<bank->get_employee()[i]->get_over_work()<<" ";
        out<<bank->get_employee()[i]->get_type()<<"\n";
        if( i!= bank->get_employee().size() - 1 )
            out<<"******\n";
    }
    out<<"#######\n";
}
void read_wait_line(istream & in,bool& check,Bank * bank){
    string seprator;
    int account_id;
    int profit;
    in>>account_id;
    in>>profit;
    in>>seprator;
    for( int i = 0 ; i < bank->get_clients().size() ; i++ ){
        for( int j = 0 ; j < bank->get_clients()[i]->get_account().size() ; j++ ){
            if( account_id == bank->get_clients()[i]->get_account()[j]->get_Account_id()  ){
                //cout<<bank->get_facility()->get_personal_id()<<"\n";
                bank->get_facility()->add_to_waiting_line(bank->get_clients()[i]->get_account()[j],profit);
            }
        }
    }
    if( seprator == "######" ){
        check = false;
    }

}
void write_wait_line(ostream &out,Bank *bank){
    for( int i = 0 ; i < bank->get_facility()->get_waiting_line().size() ; i++ ){
        out<<bank->get_facility()->get_waiting_line()[i]->get_Account_id()<<" ";
        out<<bank->get_facility()->get_profit()[i]<<"\n";
        if( i != bank->get_facility()->get_waiting_line().size() - 1 ){
            out<<"******\n";
        }
        else{
            out<<"######\n";
        }
    }
}
