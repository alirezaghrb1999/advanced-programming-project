#ifndef USER_PAGE_H
#define USER_PAGE_H

#include <QWidget>

namespace Ui {
class user_page;
}

class user_page : public QWidget
{
    Q_OBJECT

public:
    explicit user_page(QWidget *parent = nullptr);
    ~user_page();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::user_page *ui;
};

#endif // USER_PAGE_H
