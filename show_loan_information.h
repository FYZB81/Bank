#ifndef SHOW_LOAN_INFORMATION_H
#define SHOW_LOAN_INFORMATION_H

#include <QMainWindow>
#include"Loan.h"
namespace Ui {
class show_loan_information;
}

class show_loan_information : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_loan_information(QWidget *parent = nullptr);
    ~show_loan_information();

private slots:
    void on_pushButton_clicked();

private:
    Ui::show_loan_information *ui;
};
extern Loan * show_by_id_loan;
#endif // SHOW_LOAN_INFORMATION_H
