#ifndef EMPLOYEEMAINWINDOW_H
#define EMPLOYEEMAINWINDOW_H

#include <QMainWindow>
#include"Bank.h"
#include"Date.h"
#include<fstream>
namespace Ui {
class employeemainwindow;
}

class employeemainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit employeemainwindow(QWidget *parent = nullptr);
    ~employeemainwindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::employeemainwindow *ui;
};
extern Bank* bank;
extern int employee_index;
#endif // EMPLOYEEMAINWINDOW_H
