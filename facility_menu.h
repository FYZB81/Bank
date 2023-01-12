#ifndef FACILITY_MENU_H
#define FACILITY_MENU_H

#include <QMainWindow>
#include"Bank.h"
#include<fstream>
#include<Loan.h>
namespace Ui {
class facility_menu;
}

class facility_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit facility_menu(QWidget *parent = nullptr);
    ~facility_menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::facility_menu *ui;
};
extern Bank * bank;
extern fstream report_file;
extern Loan * show_by_id_loan;
#endif // FACILITY_MENU_H
