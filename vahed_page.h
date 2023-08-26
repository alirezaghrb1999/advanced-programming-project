#pragma once
#include <apartemani_page.h>
#include <QWidget>

namespace Ui {
class vahed_page;
}

class vahed_page : public QWidget
{
    Q_OBJECT

public:
    explicit vahed_page(QWidget *parent = nullptr);
    ~vahed_page();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::vahed_page *ui;
    QString g1,g2,g3,g4,g5,g6;
    int y;
signals:
    void send_data(QString,QString,QString,QString,QString,QString,int);

public slots:
    void get_data(QString,QString,QString,QString,QString,QString,int);
};


