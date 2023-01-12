#ifndef EMPLOYEE_MENU_H
#define EMPLOYEE_MENU_H

#include <QMainWindow>
#include"Bank.h"
namespace Ui {
class employee_menu;
}

class employee_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit employee_menu(QWidget *parent = nullptr);
    ~employee_menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::employee_menu *ui;
};
extern Bank* bank;
extern int employee_index;
extern fstream report_file;
extern Date * now;
extern long long int national_code_new_client;
extern int show_employee_index;;
#endif // EMPLOYEE_MENU_H
