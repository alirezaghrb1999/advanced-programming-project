#ifndef VILA_JONOOB_PAGE_H
#define VILA_JONOOB_PAGE_H

#include <QWidget>

namespace Ui {
class vila_jonoob_page;
}

class vila_jonoob_page : public QWidget
{
    Q_OBJECT

public:
    explicit vila_jonoob_page(QWidget *parent = nullptr);
    ~vila_jonoob_page();

private slots:


    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::vila_jonoob_page *ui;
signals:
    void send(int);
};

#endif // VILA_JONOOB_PAGE_H
