#pragma once
#include <signup.h>
#include <QWidget>
#include <signup.h>

namespace Ui {
class modirregister;
}

class modirregister : public QWidget
{
    Q_OBJECT

public:
    explicit modirregister(QWidget *parent = nullptr);
    ~modirregister();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::modirregister *ui;
    int position;
public slots:
    void radio1();
    void radio2();
};


