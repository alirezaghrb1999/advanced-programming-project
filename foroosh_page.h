#ifndef FOROOSH_PAGE_H
#define FOROOSH_PAGE_H

#include <QWidget>
#include <fstream>
#include <QMessageBox>
using namespace std;

namespace Ui {
class foroosh_page;
}

class foroosh_page : public QWidget
{
    Q_OBJECT

public:
    explicit foroosh_page(QWidget *parent = nullptr);
    ~foroosh_page();

private:
    Ui::foroosh_page *ui;
    int type;
    int situation;
public slots:
    void get_type(int);
private slots:
    void on_pushButton_clicked();
    void on_radioButton_1_clicked();
    void on_radioButton_2_clicked();
};

#endif // FOROOSH_PAGE_H
