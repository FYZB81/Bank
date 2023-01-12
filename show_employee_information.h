#ifndef SHOW_EMPLOYEE_INFORMATION_H
#define SHOW_EMPLOYEE_INFORMATION_H

#include <QMainWindow>
#include<Bank.h>
namespace Ui {
class show_employee_information;
}

class show_employee_information : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_employee_information(QWidget *parent = nullptr);
    ~show_employee_information();

private slots:
    void on_pushButton_clicked();

private:
    Ui::show_employee_information *ui;
};
extern Bank* bank;
extern int show_employee_index;
#endif // SHOW_EMPLOYEE_INFORMATION_H
