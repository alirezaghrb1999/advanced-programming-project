#ifndef ACCEPT_PAGE_H
#define ACCEPT_PAGE_H

#include <QWidget>
#include <north_vila.h>
#include <south_vila.h>
#include <apartmant.h>
#include <QVector>

namespace Ui {
class accept_page;
}

class accept_page : public QWidget
{
    Q_OBJECT

public:
    explicit accept_page(QWidget *parent = nullptr);
    ~accept_page();

    void transfer_to_admin();
    void reduce_from_user(QString s);

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::accept_page *ui;
    QVector <north_vila> N1;
    QVector <south_vila> S1;
    QVector <apartmant> A1;

    QString username;
    int STOCK;
};

#endif // ACCEPT_PAGE_H








