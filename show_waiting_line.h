#ifndef SHOW_WAITING_LINE_H
#define SHOW_WAITING_LINE_H

#include <QMainWindow>
#include"Bank.h"
namespace Ui {
class show_waiting_line;
}

class show_waiting_line : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_waiting_line(QWidget *parent = nullptr);
    ~show_waiting_line();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::show_waiting_line *ui;
};
extern Bank * bank;
#endif // SHOW_WAITING_LINE_H
