#ifndef OBSERVE_EDIT_MASKAN_H
#define OBSERVE_EDIT_MASKAN_H

#include <QWidget>
#include <QVector>
#include <north_vila.h>
#include <south_vila.h>
#include <apartmant.h>

namespace Ui {
class observe_edit_maskan;
}

class observe_edit_maskan : public QWidget
{
    Q_OBJECT

public:
    explicit observe_edit_maskan(QWidget *parent = nullptr);
    ~observe_edit_maskan();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::observe_edit_maskan *ui;
    int count=1;
    QString admin_username;

    QVector <north_vila> N;
    QVector <south_vila> S;
    QVector <apartmant> A;

public slots:
    void get(QString);
signals:
    void send_north(QVector <north_vila>,int);
    void send_south(QVector <south_vila>,int);
    void send_aparteman(QVector <apartmant>,int);

};


#endif // OBSERVE_EDIT_MASKAN_H


