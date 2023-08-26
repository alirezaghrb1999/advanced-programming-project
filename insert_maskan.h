#ifndef INSERT_MASKAN_H
#define INSERT_MASKAN_H

#include <QWidget>
#include <vila_shomal_page.h>
#include <vila_jonoob_page.h>

namespace Ui {
class insert_maskan;
}

class insert_maskan : public QWidget
{
    Q_OBJECT

public:
    explicit insert_maskan(QWidget *parent = nullptr);
    ~insert_maskan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::insert_maskan *ui;
};

#endif // INSERT_MASKAN_H
