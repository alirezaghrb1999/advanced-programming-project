#pragma once

#include <QWidget>
#include <vahed_page.h>
#include <QVector>

namespace Ui {
class apartemani_page;
}

class apartemani_page : public QWidget
{
    Q_OBJECT

public:
    explicit apartemani_page(QWidget *parent = nullptr);
    ~apartemani_page();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::apartemani_page *ui;
    int elevator;
    int vahed=0;
public slots:
    void get_data(QString,QString,QString,QString,QString,QString,int);
 signals:
    void send_data(QString,QString,QString,QString,QString,QString,int);

    void send(int);
};




