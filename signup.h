#pragma once
#include <QWidget>
#include <mainwindow.h>
#include <modirregister.h>
#include <userregister.h>



namespace Ui
{
class singup;
}

class singup : public QWidget
{
    Q_OBJECT

public:
    explicit singup(QWidget *parent = nullptr);
    ~singup();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::singup *ui;
};


