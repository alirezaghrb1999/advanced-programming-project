#include "foroosh_page.h"
#include "ui_foroosh_page.h"
#include <vila_jonoob_page.h>
#include <vila_shomal_page.h>
#include <apartemani_page.h>

foroosh_page::foroosh_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::foroosh_page)
{
    ui->setupUi(this);
    ui->lineEdit_1->setPlaceholderText("فقط برای مسکن های آپارتمانی");
}

foroosh_page::~foroosh_page()
{
    delete ui;
}

void foroosh_page::get_type(int x)
{
    type=x;
}

void foroosh_page::on_pushButton_clicked()
{
    QString q1,q2;
    q1=ui->lineEdit_1->text();
    q2=ui->lineEdit_2->text();

    string a1,a2;
    a1=q1.toStdString();
    a2=q2.toStdString();

    if(type==1) // north
    {
        fstream northfile;
        northfile.open("northfile.txt",ios::app);

        northfile<<a1<<" "<<a2<<" "<<situation<<" "<<"0"<<" "<<"0"<<"\n";
        northfile.close();

        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Information);
        m->setText("پرونده ثبت شد");
        m->exec();

        vila_shomal_page *o=new vila_shomal_page;
        close();
        o->show();
    }
    if(type==2) // south
    {
        fstream south_vila;
        south_vila.open("south_vila.txt",ios::app);

        south_vila<<a1<<" "<<a2<<" "<<situation<<" "<<"0"<<" "<<"0"<<"\n";
        south_vila.close();

        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Information);
        m->setText("پرونده ثبت شد");
        m->exec();

        vila_jonoob_page *o=new vila_jonoob_page;
        close();
        o->show();
    }
    if(type==3) //aparteman
    {
        fstream aparteman_file;
        aparteman_file.open("aparteman_file.txt",ios::app);

        aparteman_file<<a1<<" "<<a2<<" "<<situation<<" "<<"0"<<" "<<"0"<<"\n";
        aparteman_file.close();

        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Information);
        m->setText("پرونده ثبت شد");
        m->exec();

        apartemani_page *o=new apartemani_page;
        close();
        o->show();
    }
}


void foroosh_page::on_radioButton_1_clicked()
{
    situation=1;
}

void foroosh_page::on_radioButton_2_clicked()
{
    situation=2;
}







