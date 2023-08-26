#ifndef EJARE_PAGE_H
#define EJARE_PAGE_H

#include <QWidget>
#include <fstream>
#include <QMessageBox>
using namespace std;

namespace Ui {
class ejare_page;
}

class ejare_page : public QWidget
{
    Q_OBJECT

public:
    explicit ejare_page(QWidget *parent = nullptr);
    ~ejare_page();

private:
    int type;
    Ui::ejare_page *ui;
public slots:
    void get_type(int);
private slots:
    void on_pushButton_clicked();
};

#endif // EJARE_PAGE_H
