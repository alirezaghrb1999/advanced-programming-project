#ifndef PARVANDE_PAGE_H
#define PARVANDE_PAGE_H

#include <QWidget>
#include <QVector>
#include <north_vila.h>
#include <south_vila.h>
#include <apartmant.h>

namespace Ui {
class parvande_page;
}

class parvande_page : public QWidget
{
    Q_OBJECT

public:
    explicit parvande_page(QWidget *parent = nullptr);
    ~parvande_page();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::parvande_page *ui;
    QString admin_username;
};

#endif // PARVANDE_PAGE_H



