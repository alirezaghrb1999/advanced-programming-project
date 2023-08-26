#ifndef SEARCH_MASKAN_H
#define SEARCH_MASKAN_H

#include <QWidget>
#include <QVector>
#include <north_vila.h>
#include <south_vila.h>
#include <apartmant.h>

namespace Ui {
class search_maskan;
}

class search_maskan : public QWidget
{
    Q_OBJECT

public:
    explicit search_maskan(QWidget *parent = nullptr);
    ~search_maskan();

    void set_N();
    void set_S();
    void set_A();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::search_maskan *ui;

    QVector <north_vila> N;
    QVector <south_vila> S;
    QVector <apartmant> A;

};

#endif // SEARCH_MASKAN_H











