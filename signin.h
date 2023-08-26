#pragma once
#include <QWidget>
#include<mainwindow.h>

namespace Ui {
class signin;
}

class signin : public QWidget
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::signin *ui;
signals:
    void send_username(QString);
};

