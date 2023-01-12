#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientmainwindow.h"
#include"employeemainwindow.h"
#include "File.h"
#include"Bank.h"
#include"Date.h"
#include"Client.h"
#include"Account.h"
void block_unblock_all_account(Client* a, bool b)
{
    for(int i=0; i<a->get_account().size(); i++)
       a->get_account()[i]->set_active(b);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*fstream input_client("C:/Users/PcNiloofar/Documents/bank/file_information/client_information.txt",ios::in);
    bool check = true;
    while(check && input_client){
        read_client(input_client,check,bank);
    }
    input_client.close();*/
    /////////////////////////////////////////////////////////read employee from file
        fstream Input_employee("C:/Users/PcNiloofar/Documents/bank/file_information/employee_information.txt",ios::in);
        bool check = true;
        while(check && Input_employee){
            read_employee(Input_employee,check,bank);
        }
        Input_employee.close();
        ////////////////////////////////////////////////////////read client from file
        fstream input_client("C:/Users/PcNiloofar/Documents/bank/file_information/client_information.txt",ios::in);
        check = true;
        while(check && input_client){
            read_client(input_client,check,bank);
        }
        input_client.close();
        ///////////////////////////////////////////////////////////read date from file
        fstream input_date("C:/Users/PcNiloofar/Documents/bank/file_information/date_information.txt",ios::in);
        string date;
        Date get_from__file;
        input_date>>date;
        get_from__file = str_to_date(date);
        now->set_date(get_from__file.get_day(),get_from__file.get_month(),get_from__file.get_year());
        bank->set_date(now);
        input_date.close();
        /////////////////////////////////////////////////////////////// read wait line from file
        fstream input_line("C:/Users/PcNiloofar/Documents/bank/file_information/wait_line.txt",ios::in);
        check = true;
        while(check && input_line){
            read_wait_line(input_line,check,bank);
        }
        input_line.close();
}

MainWindow::~MainWindow()
{
    for(int i=0; i<bank->get_clients().size(); i++)
      {
       bool check_condition = true;
          for(int j=0; j<bank->get_clients()[i]->get_account().size(); j++)
          {
              for(int z=0 ; z<bank->get_clients()[i]->get_loan().size(); z++)
              {
                  if( bank->get_clients()[i]->get_loan()[z]->get_account_id() == bank->get_clients()[i]->get_account()[j]->get_Account_id() && bank->get_clients()[i]->get_account()[j]->get_day_over_balance()>0 )
                  {
                      if(bank->get_clients()[i]->get_loan()[z]->GetNumber_of_paid_installments()!= bank->get_clients()[i]->get_loan()[z]->GetNumber_of_installments())
                      {
                          if( bank->get_clients()[i]->get_account()[j]->get_balance() < bank->get_clients()[i]->get_loan()[z]->Getamount_of_installments() )
                          {
                              if( bank->get_clients()[i]->get_loan()[z]->GetNumber_of_Overdue_installments() + bank->get_clients()[i]->get_loan()[z]->GetNumber_of_paid_installments() < bank->get_clients()[i]->get_loan()[z]->GetNumber_of_installments() )
                                   bank->get_clients()[i]->get_loan()[z]->SetNumber_of_Overdue_installments(bank->get_clients()[i]->get_loan()[z]->GetNumber_of_Overdue_installments()+1);
                              if(bank->get_clients()[i]->get_loan()[z]->get_check_pay()==false)
                              {
                                  block_unblock_all_account(bank->get_clients()[i],false);
                                  check_condition = false;
                                  report_file<<"Account with ID "<<bank->get_clients()[i]->get_account()[j]->get_Account_id()<<" has no enough mony to pay instalment and all accounts whit this national code blocked."<< '\n' <<"Date: "
                                  <<bank->get_now()->get_day()<<"/"<<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
                                  cout<<"account national code "<<bank->get_clients()[i]->get_national_code()<<"has no enough money to pay instalment and all account with this national code are blocked \n";
                              }
                              else
                              {
                                  bank->get_clients()[i]->get_loan()[z]->set_check_pay(false);
                                  report_file<<"Account with ID "<<bank->get_clients()[i]->get_account()[j]->get_Account_id()<<"has "<<
                                  bank->get_clients()[i]->get_loan()[z]->GetNumber_of_Overdue_installments()<<" overdue installments until now date:"<<
                                  bank->get_now()->get_day()<<"/"<<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;

                              }
                          }
                          else{

                                  long long int am=bank->get_clients()[i]->get_loan()[z]->Getamount_of_installments()*(bank->get_clients()[i]->get_loan()[z]->GetNumber_of_Overdue_installments()+1);
                                  if(bank->get_clients()[i]->get_loan()[z]->get_check_pay()==false && bank->get_clients()[i]->get_account()[j]->get_balance()>=am)
                                  {
                                      block_unblock_all_account(bank->get_clients()[i],true);
                                      bank->get_clients()[i]->get_loan()[z]->SetNumber_of_paid_installments(bank->get_clients()[i]->get_loan()[z]->GetNumber_of_paid_installments()+bank->get_clients()[i]->get_loan()[z]->GetNumber_of_Overdue_installments()+1);
                                      bank->get_clients()[i]->remove_salary(bank->get_clients()[i]->get_account()[j]->get_Account_id(),am);
                                      bank->get_clients()[i]->get_loan()[z]->set_check_pay(true);
                                      report_file<<"Account white ID "<<bank->get_clients()[i]->get_account()[j]->get_Account_id()<<"has "<<
                                      bank->get_clients()[i]->get_loan()[z]->GetNumber_of_paid_installments()<<" paid installments and the accound is acctive now. date:"<<
                                      bank->get_now()->get_day()<<"/"<<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
                                      //bank->get_clients()[i]->get_account()[j]->set_day_over_balance(0);
                                      bank->get_clients()[i]->get_loan()[z]->SetNumber_of_Overdue_installments(0);
                                      if( !check_condition ){
                                           block_unblock_all_account(bank->get_clients()[i],false);
                                      }
                                  }
                                  else if(bank->get_clients()[i]->get_loan()[z]->get_check_pay()==false && bank->get_clients()[i]->get_account()[j]->get_balance()<am)
                                      //if(bank->get_clients()[i]->get_loan()[z]->GetNumber_of_Overdue_installments () + bank->get_clients()[i]->get_loan()[z]->GetNumber_of_paid_installments() < bank->get_clients()[i]->get_loan()[z]->GetNumber_of_installments() )
                                         bank->get_clients()[i]->get_loan()[z]->SetNumber_of_Overdue_installments(bank->get_clients()[i]->get_loan()[z]->GetNumber_of_Overdue_installments()+1);
                                  else
                                  {
                                      bool check_active = true;
                                      if( bank->get_clients()[i]->get_account()[j]->get_active() == false ){
                                        check_active = false;
                                        bank->get_clients()[i]->get_account()[j]->set_active(true);
                                      }
                                      bank->get_clients()[i]->get_loan()[z]->SetNumber_of_paid_installments(bank->get_clients()[i]->get_loan()[z]->GetNumber_of_paid_installments()+1);
                                      bank->get_clients()[i]->remove_salary(bank->get_clients()[i]->get_account()[j]->get_Account_id(),bank->get_clients()[i]->get_loan()[z]->Getamount_of_installments());
                                      report_file<<"Account white ID "<<bank->get_clients()[i]->get_account()[j]->get_Account_id()<<"has "<<
                                      bank->get_clients()[i]->get_loan()[z]->GetNumber_of_paid_installments()<<" paid installments until now. date:"<<
                                      bank->get_now()->get_day()<<"/"<<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<endl;
                                      if( !check_active ){
                                          bank->get_clients()[i]->get_account()[j]->set_active(false);
                                      }
                                  }
                          }
                      }
                      else if(bank->get_clients()[i]->get_loan()[z]->GetNumber_of_paid_installments()!= bank->get_clients()[i]->get_loan()[z]->GetNumber_of_installments())
                      {
                          bank->get_clients()[i]->get_account()[j]->set_day_over_balance(0);
                      }

                  }
              }
          }
      }

      for(int i=0; i<bank->get_clients().size(); i++)
      {
          for(int j=0; j<bank->get_clients()[i]->get_account().size(); j++)

          {
                 if(bank->get_clients()[i]->get_account()[j]->get_balance()>=1000000)
                 {
                     bank->get_clients()[i]->get_account()[j]->set_day_over_balance(bank->get_clients()[i]->get_account()[j]->get_day_over_balance()+1);
                     report_file<<"Account with ID "<<bank->get_clients()[i]->get_account()[j]->get_Account_id()<<" has good condition to get lone "<<endl;
                 }

          }
      }
      now->inc_one_day();
      fstream out_client("C:/Users/PcNiloofar/Documents/bank/file_information/client_information.txt",ios::out);
      fstream out_employee("C:/Users/PcNiloofar/Documents/bank/file_information/employee_information.txt",ios::out);
      fstream write_date("C:/Users/PcNiloofar/Documents/bank/file_information/date_information.txt",ios::out);
      fstream out_line("C:/Users/PcNiloofar/Documents/bank/file_information/wait_line.txt",ios::out);
      write_client(out_client,bank);
      write_employee(out_employee,bank);
      write_wait_line(out_line,bank);
      write_date<<bank->get_now()->get_day()<<"/"<<bank->get_now()->get_month()<<"/"<<bank->get_now()->get_year()<<"\n";
      delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    clientmainwindow * newform = new clientmainwindow();
    newform->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_clicked()
{
    employeemainwindow * newform = new employeemainwindow;
    newform->show();
}

