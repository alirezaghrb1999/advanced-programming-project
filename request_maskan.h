#ifndef REQUEST_MASKAN_H
#define REQUEST_MASKAN_H
#include <north_vila.h>
#include <south_vila.h>
#include <apartmant.h>
#include <QVector>
#include <QWidget>


namespace Ui {
class request_maskan;
}

class request_maskan : public QWidget
{
    Q_OBJECT

public:
    explicit request_maskan(QWidget *parent = nullptr);
    ~request_maskan();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::request_maskan *ui;
    QVector <north_vila> N1;
    QVector <south_vila> S1;
    QVector <apartmant> A1;

    QString username;
    int STOCK;
};

#endif // REQUEST_MASKAN_H






