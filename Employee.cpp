#include "Employee.h"
#include <iostream>
#include "Date.h"
#include "Client.h"
#include "Person.h"
#include "Account.h"
#include "Bank.h"
#include"Error.h"
#include"math.h"
#include<math.h>
#include"qmessagebox.h"
#include"makeclient.h"
using namespace std;
int Employee::cnt = 99;
Employee::Employee(string fname,string lname,Date* b,string ID,string pass,Bank* ba):person(fname,lname,b,ID,pass){
    type = "Employee";
    cnt++;
    personal_id = cnt;
    bank = ba;
}
void Employee::set_salary(int s){
    salary = s;
}
int Employee::get_salary(){
    return salary;
}
void Employee::set_free_hour(int f){
    free_hour = f;
}
int Employee::get_free_hour(){
    return free_hour;
}
void Employee::set_over_work(int o){
    over_work = o;
}
int Employee::get_over_work(){
    return over_work;
}
int Employee::get_personal_id(){
    return personal_id;
}
void Employee::request_free_hour(int n){
    free_hour += n;
    check_salary_free_hour();
}
void Employee::request_over_work(int m){
    if( over_work + m <= 12 ){
        over_work += m;
        check_salary_over_work(m);
    }
    else{
        QMessageBox msgbox;
        msgbox.setText("You cannot get over work!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }

}
void Employee::set_type(string t){
    type = t;
}
string Employee::get_type(){
    return type;
}
void Employee::show_information(){
    cout<<"First_name: "<<Getfirst_name()<<endl;
    cout<<"last_name: "<<Getlast_name()<<endl;
    cout<<"username: "<<Getid()<<endl;
    cout<<"password: "<<Getpassword()<<endl;
    cout<<"personal id: "<<get_personal_id()<<endl;
    cout<<"salary: "<<get_salary()<<endl;
    cout<<"Free hour: "<<get_free_hour()<<endl;
    cout<<"over work: "<<get_over_work()<<endl;
    cout<<"type: "<<get_type()<<endl;
}
void Employee::check_salary_free_hour(){
    if( free_hour > 15 ){
        if( salary - 100000*(free_hour-15) > 0 ){
            int n = salary - 100000*(free_hour-15);
            salary = n;
            string s;
            s += "NEW salary is:";
            s += to_string(n);
            QString q = QString::fromStdString(s);
            QMessageBox msgbox;
            msgbox.setText(q);
            msgbox.setWindowTitle("New salary!");
            msgbox.exec();
        }
        else{
            QMessageBox msgbox;
            msgbox.setText("balance will be negative");
            msgbox.setWindowTitle("error!");
            msgbox.exec();
        }

    }
    else{
        int n = 15 - free_hour;
        string s;
        s += "Remaining day is: ";
        s += to_string(n);
        QString q = QString::fromStdString(s);
        QMessageBox msgbox;
        msgbox.setText(q);
        msgbox.setWindowTitle("you can take more free hour!");
        msgbox.exec();
    }
}
void Employee::check_salary_over_work(int m){
    int n = salary + 120000*(m);
    salary = n;
    string s;
    s += "NEW salary is:";
    s += to_string(n);
    QString q = QString::fromStdString(s);
    QMessageBox msgbox;
    msgbox.setText(q);
    msgbox.setWindowTitle("new salary!");
    msgbox.exec();
}
void Employee::show_client_information(int64_t national_code){
    bool check = false;
    for( int i = 0 ; i < bank->clients.size() ; i++ ){
        //bank->get_clients()[i]->show_information();
        if( bank->clients[i]->get_national_code() == national_code ){
            bank->clients[i]->show_information();
            check = true;
        }
    }
    if( !check ){
        QMessageBox msgbox;
        msgbox.setText("not Found!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }
}
void Employee::create_account(Account* a){
    int index = -1;

    for( int i = 0 ; i < bank->clients.size() ; i++ ){
        if( a->get_national_id_owner() == bank->clients[i]->get_national_code() ){
            index = i;
        }
    }
    if( index == -1 ){
        new_account_for_new_client = a;
        makeclient * newform = new makeclient;
        newform->show();

    }
    else{
        bank->clients[index]->accounts.push_back(a);
        QMessageBox msgbox;
        msgbox.setText("account add succesfully!");
        msgbox.setWindowTitle("ok!");
        msgbox.exec();
    }
}
void Employee::Delete_Account(int a,int64_t national_code){
    int index = -1;
    for( int i = 0 ; i < bank->clients.size() ; i++ ){
        if( national_code == bank->clients[i]->get_national_code() ){
            index = i;
        }
    }
    if( index != -1 ){
        if( bank->clients[index]->get_account().size() == 0 ){
            bank->clients.erase(bank->clients.begin()+index);
        }
        else{
            int account_index = -1;
            for ( int i = 0 ; i < bank->clients[index]->get_account().size() ; i++ ){
                if( bank->clients[index]->get_account()[i]->get_Account_id() == a ){
                    account_index = i;
                }
            }
            if( account_index!= -1 ){
                for(int i= 0 ; i < bank->clients[index]->get_loan().size() ; i++ ){
                    if( bank->clients[index]->get_loan()[i]->GetNumber_of_installments() != bank->clients[index]->get_loan()[i]->GetNumber_of_paid_installments() ){
                        QMessageBox msgbox;
                        msgbox.setText("you can't delete!");
                        msgbox.setWindowTitle("error!");
                        msgbox.exec();
                        return;
                    }
                }
                /*for(int i= 0 ; i < bank->clients[index]->get_loan().size() ; i++ ){
                    if(bank->clients[index]->get_loan()[i]->get_account_id()==a )
                        bank->clients[index]->loans.erase(bank->clients[index]->loans.begin()+i);
                }*/
                for(int i= 0 ; i < bank->clients[index]->get_loan().size() ; i++ ){
                    if(bank->clients[index]->get_loan()[i]->get_account_id()==a)
                        bank->clients[index]->loans.erase(bank->clients[index]->loans.begin()+i);
                }
                bank->clients[index]->accounts.erase(bank->clients[index]->accounts.begin()+account_index);
                if(bank->clients[index]->accounts.size()==0)
                    bank->clients.erase(bank->clients.begin()+index);
                QMessageBox msgbox;
                msgbox.setText("account delete!");
                msgbox.setWindowTitle("ok!");
                msgbox.exec();
            }
            else{
                QMessageBox msgbox;
                msgbox.setText("account not found!");
                msgbox.setWindowTitle("error!");
                msgbox.exec();
            }
         }
     }
     else{
        QMessageBox msgbox;
        msgbox.setText("client not found!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }
}
/*void Employee::Delete_Account(int a,int64_t national_code){
    /*int index = -1;
    for( int i = 0 ; i < bank->clients.size() ; i++ ){
        if( national_code == bank->clients[i]->get_national_code() ){
            index = i;
        }
    }
    if( index != -1 ){
        if( bank->clients[index]->get_account().size() == 0 ){
            bank->clients.erase(bank->clients.begin()+index);
        }
        else{
            int account_index = -1;
            for ( int i = 0 ; i < bank->clients[index]->get_account().size() ; i++ ){
                if( bank->clients[index]->get_account()[i]->get_Account_id() == a ){
                    account_index = i;
                }
            }
            if( account_index!= -1 ){
                for(int i= 0 ; i < bank->clients[index]->get_loan().size() ; i++ ){
                    if(bank->clients[index]->get_loan()[i]->get_account_id()==a)
                        bank->clients[index]->loans.erase(bank->clients[index]->loans.begin()+i);
                }
                bank->clients[index]->accounts.erase(bank->clients[index]->accounts.begin()+account_index);
                QMessageBox msgbox;
                msgbox.setText("delete succusfully!");
                msgbox.setWindowTitle("ok!");
                msgbox.exec();
            }
            else{
                QMessageBox msgbox;
                msgbox.setText("account not found!");
                msgbox.setWindowTitle("error!");
                msgbox.exec();
            }
         }
     }
     else{
        QMessageBox msgbox;
        msgbox.setText("client not found!");
        msgbox.setWindowTitle("error!");
        msgbox.exec();
    }

}*/
void Employee::set_cnt(int n){
    cnt = n;
}
/*void Employee::set_bank(Bank*b){
    bank = b;
}
Bank* Employee::get_bank(){
    return bank;
}*/
int Employee::get_cnt(){
    return cnt;
}
