#ifndef ADMIN_PAGE_H
#define ADMIN_PAGE_H

#include <QWidget>

namespace Ui {
class admin_page;
}

class admin_page : public QWidget
{
    Q_OBJECT

public:
    explicit admin_page(QWidget *parent = nullptr);
    ~admin_page();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::admin_page *ui;
    QString USERNAME;
signals:
    void send(QString);
public slots:
    void get_username(QString);

};
#endif // ADMIN_PAGE_H
