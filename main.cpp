#include "mainwindow.h"

#include <QApplication>
#include<fstream>
#include"Date.h"
#include<Loan.h>
Bank* bank = new Bank;
Date * now = new Date;
int client_index;
int employee_index;
int index_ckient_in_search_employee;
long long int national_code_new_client;
fstream report_file("C:/Users/PcNiloofar/Documents/bank/file_information/report.txt",ios::app);
Account * new_account_for_new_client;
int show_employee_index;
Loan * show_by_id_loan;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
