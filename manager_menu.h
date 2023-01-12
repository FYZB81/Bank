#ifndef MANAGER_MENU_H
#define MANAGER_MENU_H

#include <QMainWindow>
#include"Bank.h"
namespace Ui {
class manager_menu;
}

class manager_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit manager_menu(QWidget *parent = nullptr);
    ~manager_menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::manager_menu *ui;
};
extern Bank * bank;
extern int show_employee_index ;
extern fstream report_file;
#endif // MANAGER_MENU_H
