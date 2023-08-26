#ifndef SOUTH_EDIT_H
#define SOUTH_EDIT_H
#include <south_vila.h>
#include <QVector>

#include <QWidget>

namespace Ui {
class south_edit;
}

class south_edit : public QWidget
{
    Q_OBJECT

public:
    explicit south_edit(QWidget *parent = nullptr);
    ~south_edit();

private:
    Ui::south_edit *ui;
    QVector <south_vila> vector;
    int index;
public slots:
    void get(QVector <south_vila>,int);
private slots:
    void on_pushButton_clicked();
};

#endif // SOUTH_EDIT_H



