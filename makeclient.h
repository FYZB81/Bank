#ifndef MAKECLIENT_H
#define MAKECLIENT_H

#include <QMainWindow>
#include"Bank.h"
namespace Ui {
class makeclient;
}

class makeclient : public QMainWindow
{
    Q_OBJECT

public:
    explicit makeclient(QWidget *parent = nullptr);
    ~makeclient();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::makeclient *ui;
};
extern Bank* bank;
extern long long int national_code_new_client;
extern Account * new_account_for_new_client;
#endif // MAKECLIENT_H
