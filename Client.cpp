#include<iostream>
#include<vector>
#include "Date.h"
#include "Person.h"
#include "Client.h"
#include"Account.h"
#include"Bank.h"
#include"Error.h"
#include<math.h>
#include<qmessagebox.h>
#include"Facilityemployee.h"
using namespace std;
bool Client::search_account(int id){
    int index = -1;
    for( int i = 0 ; i < accounts.size() ; i++ ){
        if( accounts[i]->get_Account_id() == id ){
            index = i;
        }
    }
    if(index != -1 ){
        return true;
    }
    else{
        return false;
    }

}
Client ::Client(string fname,string lname,Date* b,string ID,string pass,int64_t nat_code):person(fname,lname,b,ID,pass){
    /*int digits=log10(nat_code)+1;
    if(nat_code<0|| digits!=10)
        throw Bad_exception();*/
    national_code=nat_code;
}
vector<Account*> Client::get_account(){
    return accounts;
}
vector<Loan*> Client::get_loan(){
    return loans;
}
void Client::show_information(){
    cout<<"First name:"<<Getfirst_name()<<endl;
    cout<<"last name:"<<Getlast_name()<<endl;
    cout<<"national code:"<<get_national_code()<<endl;
    cout<<"username:"<<Getid()<<endl;
    cout<<"password name:"<<Getpassword()<<endl;
}
int64_t Client::get_national_code(){
    return national_code;
}
void Client::add_salary(int Account_id,int add){
    int index = -1;
    for( int i = 0 ; i < accounts.size() ; i++ ){
        if( accounts[i]->get_Account_id() == Account_id ){
            index = i;
        }
    }
    if( index != -1 ){
        accounts[index]->add_balance(add);
        QMessageBox msgbox;
        msgbox.setText("ADD SUCCUSFULLY!");
        msgbox.setWindowTitle("ok!");
        msgbox.exec();
    }
    else{
        QMessageBox msgbox;
        msgbox.setText("NOT FOUND!");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
}
void Client::remove_salary(int Account_id,int remove){
    int index = -1;
    for( int i = 0 ; i < accounts.size() ; i++ ){
        if( accounts[i]->get_Account_id() == Account_id ){
            index = i;
        }
    }
    if( index != -1 && accounts[index]->get_active() && accounts[index]->get_balance() >= remove  ){
            accounts[index]->reduction_balance(remove);
            QMessageBox msgbox;
            msgbox.setText("remove SUCCUSFULLY!");
            msgbox.setWindowTitle("ok!");
            msgbox.exec();
    }
    else{
        QMessageBox msgbox;
        msgbox.setText("you can't remove!");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
}
void Client::loan_request(int Account_id,int profit){
    int index = -1;
    bool check = true;
    for( int i = 0 ; i < accounts.size() ; i++ ){
        if( accounts[i]->get_Account_id() == Account_id ){
            index = i;
        }
    }
    for( int i = 0 ; i < loans.size() ; i++ ){
        if( loans[i]->get_account_id() == Account_id ){
            if(loans[i]->GetNumber_of_paid_installments() != loans[i]->GetNumber_of_installments() )
               check = false;
        }
    }
    //&& accounts[index]->get_balance() > 1000000
    if( index != -1  && check ){
        for(int i=0 ; i<bank->get_facility()->get_waiting_line().size(); i++){
            if(bank->get_facility()->get_waiting_line()[i]->get_Account_id()==Account_id)
            {
                QMessageBox msgbox;
                msgbox.setText("you can't request for two times");
                msgbox.setWindowTitle("Error!");
                msgbox.exec();
                return;
            }
        }
        bank->add_request_from_client_to_waiting_line(accounts[index],profit);
        QMessageBox msgbox;
        msgbox.setText("Loan Send SUCCUSFULLY!");
        msgbox.setWindowTitle("ok!");
        msgbox.exec();
    }
    else{
        QMessageBox msgbox;
        msgbox.setText("loan reject!");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }

}
istream & operator>>(istream& in,Client& c){
   try
   {
       long int national_code;
       string fname, lname,pas,Id;
       cout<<"First name: ";
       in>>fname;
       cout<<"Last name: ";
       in>>lname;
       bool check_nat=false;
       while (!check_nat)
       {
           cout<<"National code: ";
           in>>national_code;
           int digits=log10(national_code)+1;
           if(national_code<0 || digits!=10)
               cout<<"invalid input Enter again\n";

           else
               break;

       }

       cout<<"birthday:\n";
       int d,m,y;
       cout<<"day: ";
       cin>>d;
       cout<<"month: ";
       cin>>m;
       cout<<"year: ";
       cin>>y;
       Date* birth = new Date(d,m,y);
       cout<<"ID: ";
       in>>Id;
       cout<<"password: ";
       in>>pas;
       Client* c = new Client(fname,lname,birth,Id,pas,national_code);
       //bank->get_employee()[i]->create_account(c);

   }  catch (Bad_date a) {
       cout<<":) do this shit again... :)\n";
   }
    return in;

}
void Client::set_bank(Bank*b){
    bank = b;
}
Bank* Client::get_bank(){
    return bank;
}
void Client::add_loan(Loan *l){
    loans.push_back(l);
}
void Client::add_account(Account*a){
    accounts.push_back(a);
}
