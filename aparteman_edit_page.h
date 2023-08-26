#ifndef APARTEMAN_EDIT_PAGE_H
#define APARTEMAN_EDIT_PAGE_H

#include <apartmant.h>
#include <QWidget>
#include <QVector>

namespace Ui {
class aparteman_edit_page;
}

class aparteman_edit_page : public QWidget
{
    Q_OBJECT

public:
    explicit aparteman_edit_page(QWidget *parent = nullptr);
    ~aparteman_edit_page();

private:
    Ui::aparteman_edit_page *ui;
    QVector <apartmant> vector;
    int index;
    int elevator;
public slots:
    void get(QVector <apartmant>,int);
private slots:
    void on_pushButton_clicked();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
};

#endif // APARTEMAN_EDIT_PAGE_H


