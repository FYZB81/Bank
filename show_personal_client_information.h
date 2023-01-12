#ifndef SHOW_PERSONAL_CLIENT_INFORMATION_H
#define SHOW_PERSONAL_CLIENT_INFORMATION_H

#include <QMainWindow>
#include"Bank.h"
namespace Ui {
class show_personal_client_information;
}

class show_personal_client_information : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_personal_client_information(QWidget *parent = nullptr);
    ~show_personal_client_information();

private slots:
    void on_pushButton_clicked();

private:
    Ui::show_personal_client_information *ui;
};
extern Bank* bank;
extern int index_ckient_in_search_employee;
#endif // SHOW_PERSONAL_CLIENT_INFORMATION_H
