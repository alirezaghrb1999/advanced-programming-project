#pragma once
#include <QWidget>
#include <signup.h>

namespace Ui {
class userregister;
}

class userregister : public QWidget
{
    Q_OBJECT

public:
    explicit userregister(QWidget *parent = nullptr);
    ~userregister();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::userregister *ui;
    int position;
public slots:
    void radio1();
    void radio2();
};


