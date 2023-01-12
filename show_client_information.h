#ifndef SHOW_CLIENT_INFORMATION_H
#define SHOW_CLIENT_INFORMATION_H

#include <QMainWindow>
#include"Bank.h"
namespace Ui {
class show_client_information;
}

class show_client_information : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_client_information(QWidget *parent = nullptr);
    ~show_client_information();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::show_client_information *ui;
};
extern Bank* bank;
extern int client_index;
#endif // SHOW_CLIENT_INFORMATION_H
