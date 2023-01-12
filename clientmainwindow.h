#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <QMainWindow>
#include"Bank.h"
namespace Ui {
class clientmainwindow;
}

class clientmainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientmainwindow(QWidget *parent = nullptr);
    ~clientmainwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::clientmainwindow *ui;

};
extern Bank* bank;
extern int client_index;
#endif // CLIENTMAINWINDOW_H
