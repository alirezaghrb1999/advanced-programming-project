#include "ejare_page.h"
#include "ui_ejare_page.h"
#include <vila_jonoob_page.h>
#include <vila_shomal_page.h>
#include <apartemani_page.h>

ejare_page::ejare_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ejare_page)
{
    ui->setupUi(this);
    ui->lineEdit_1->setPlaceholderText("فقط برای مسکن های آپارتمانی");
}

ejare_page::~ejare_page()
{
    delete ui;
}

void ejare_page::get_type(int x)
{
    type=x;
}

void ejare_page::on_pushButton_clicked()
{
    QString q1,q2,q3,q4,q5;
    string a1,a2,a3,a4,a5;

    q1=ui->lineEdit_1->text();
    q2=ui->lineEdit_2->text();
    q3=ui->lineEdit_3->text();
    q4=ui->lineEdit_4->text();
    q5=ui->lineEdit_5->text();

    a1=q1.toStdString();
    a2=q2.toStdString();
    a3=q3.toStdString();
    a4=q4.toStdString();
    a5=q5.toStdString();


    if(type==1) // north
    {
        fstream northfile;
        northfile.open("northfile.txt",ios::app);

        northfile<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<"0"<<" "<<"0"<<"\n";
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

        south_vila<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<"0"<<" "<<"0"<<"\n";
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

        aparteman_file<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<"0"<<" "<<"0"<<"\n";
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


