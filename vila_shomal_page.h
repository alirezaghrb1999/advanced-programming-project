#ifndef VILA_SHOMAL_PAGE_H
#define VILA_SHOMAL_PAGE_H

#include <QWidget>

namespace Ui {
class vila_shomal_page;
}

class vila_shomal_page : public QWidget
{
    Q_OBJECT

public:
    explicit vila_shomal_page(QWidget *parent = nullptr);
    ~vila_shomal_page();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::vila_shomal_page *ui;
signals:
    void send(int);
};

#endif // VILA_SHOMAL_PAGE_H
