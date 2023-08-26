#ifndef MY_MASKAN_H
#define MY_MASKAN_H

#include <QWidget>
#include <QVector>
#include <north_vila.h>
#include <south_vila.h>
#include <apartmant.h>

namespace Ui {
class my_maskan;
}

class my_maskan : public QWidget
{
    Q_OBJECT

public:
    explicit my_maskan(QWidget *parent = nullptr);
    ~my_maskan();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

private:
    Ui::my_maskan *ui;
    QString username;

};

#endif // MY_MASKAN_H
