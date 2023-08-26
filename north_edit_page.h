#ifndef NORTH_EDIT_PAGE_H
#define NORTH_EDIT_PAGE_H

#include <QWidget>
#include <QVector>
#include <north_vila.h>

namespace Ui {
class north_edit_page;
}

class north_edit_page : public QWidget
{
    Q_OBJECT

public:
    explicit north_edit_page(QWidget *parent = nullptr);
    ~north_edit_page();

private:
    Ui::north_edit_page *ui;
    QVector <north_vila> vector;
    int index;
public slots:
    void get(QVector <north_vila>,int);
private slots:
    void on_pushButton_clicked();
};

#endif // NORTH_EDIT_PAGE_H
