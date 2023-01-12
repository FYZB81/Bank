#ifndef CLIENT_MENU_H
#define CLIENT_MENU_H

#include <QMainWindow>
#include"Client.h"
namespace Ui {
class client_menu;
}

class client_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit client_menu(QWidget *parent = nullptr);
    ~client_menu();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::client_menu *ui;
};
extern Bank* bank;
extern int client_index;
extern fstream report_file;
extern Date * now;
extern int national_code_new_client;

#endif // CLIENT_MENU_H
