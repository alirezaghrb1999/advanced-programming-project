#include "apartemani_page.h"
#include "ui_apartemani_page.h"
#include <QMessageBox>
#include <insert_maskan.h>
#include <fstream>
#include <foroosh_page.h>
#include <ejare_page.h>
using namespace std;



apartemani_page::apartemani_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::apartemani_page)
{
    ui->setupUi(this);
}

apartemani_page::~apartemani_page()
{
    delete ui;
}

void apartemani_page::on_radioButton_clicked()
{
    elevator=1;
}

void apartemani_page::on_radioButton_2_clicked()
{
    elevator=2;
}

void apartemani_page::on_pushButton_1_clicked() //setvahed
{
    QString e;
    e=ui->lineEdit_5->text();

    if(e.isEmpty()==true)
    {
        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Warning);
        m->setText("لطفا شناسه ی اپارتمان را وارد کنید");
        m->exec();
    }
    else
    {
        vahed=1;
        QString s1,s2,s3,s4,s5,s6;

        s1=ui->lineEdit_1->text();
        s2=ui->lineEdit_2->text();
        s3=ui->lineEdit_3->text();
        s4=ui->lineEdit_4->text();
        s5=ui->lineEdit_5->text();
        s6=ui->lineEdit_6->text();

        vahed_page *obj=new vahed_page();
        connect(this,SIGNAL(send_data(QString,QString,QString,QString,QString,QString,int)),obj,SLOT(get_data(QString,QString,QString,QString,QString,QString,int)));
        emit send_data(s1,s2,s3,s4,s5,s6,elevator);
        close();
        obj->show();
    }
}

void apartemani_page::on_pushButton_3_clicked() //set aparteman
{

    QMessageBox *m=new QMessageBox();
    m->setIcon(QMessageBox::Information);
    m->setText("اپارتمان ثبت شد");
    m->exec();

    insert_maskan *o=new insert_maskan();
    close();
    o->show();
}

void apartemani_page::on_pushButton_2_clicked()
{
    insert_maskan *o=new insert_maskan();
    close();
    o->show();
}

void apartemani_page::get_data(QString x1, QString x2, QString x3, QString x4, QString x5,QString x6, int z)
{
    ui->lineEdit_1->setText(x1);
    ui->lineEdit_2->setText(x2);
    elevator=z;
    ui->lineEdit_3->setText(x3);
    ui->lineEdit_4->setText(x4);
    ui->lineEdit_5->setText(x5);
    ui->lineEdit_6->setText(x6);

    vahed=1;
}





void apartemani_page::on_pushButton_5_clicked() // parvande foroosh
{
    if(vahed==0)
    {
        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Warning);
        m->setText("لطفا واحد ها را اضافه کنید");
        m->exec();
    }
    else
    {
        ofstream aparteman_file;
        aparteman_file.open("aparteman_file.txt",ios::app);


        QString s1,s2,s3,s4,s5,s6;
        string a1,a2,a3,a4,a5,a6;

        s1=ui->lineEdit_1->text();
        s2=ui->lineEdit_2->text();
        s3=ui->lineEdit_3->text();
        s4=ui->lineEdit_4->text();
        s5=ui->lineEdit_5->text();
        s6=ui->lineEdit_6->text();

        a1=s1.toStdString();
        a2=s2.toStdString();
        a3=s3.toStdString();
        a4=s4.toStdString();
        a5=s5.toStdString();
        a6=s6.toStdString();

        aparteman_file<<a1<<" "<<a2<<" "<<" "<<elevator<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<a6;

        aparteman_file.close();
    }

    ofstream aparteman_file;
    aparteman_file.open("aparteman_file.txt",ios::app);
    aparteman_file<<" 1 ";
    aparteman_file.close();
    foroosh_page *o=new foroosh_page();
    connect(this,SIGNAL(send(int)),o,SLOT(get_type(int)));
    emit send(3);
    close();
    o->show();
}


void apartemani_page::on_pushButton_4_clicked() // parvande ejare
{
    if(vahed==0)
    {
        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Warning);
        m->setText("لطفا واحد ها را اضافه کنید");
        m->exec();
    }
    else
    {
        ofstream aparteman_file;
        aparteman_file.open("aparteman_file.txt",ios::app);


        QString s1,s2,s3,s4,s5,s6;
        string a1,a2,a3,a4,a5,a6;

        s1=ui->lineEdit_1->text();
        s2=ui->lineEdit_2->text();
        s3=ui->lineEdit_3->text();
        s4=ui->lineEdit_4->text();
        s5=ui->lineEdit_5->text();
        s6=ui->lineEdit_6->text();

        a1=s1.toStdString();
        a2=s2.toStdString();
        a3=s3.toStdString();
        a4=s4.toStdString();
        a5=s5.toStdString();
        a6=s6.toStdString();

        aparteman_file<<a1<<" "<<a2<<" "<<" "<<elevator<<" "<<a3<<" "<<a4<<" "<<a5<<" "<<a6;

        aparteman_file.close();
    }

    ofstream aparteman_file;
    aparteman_file.open("aparteman_file.txt",ios::app);
    aparteman_file<<" 2 ";
    aparteman_file.close();
    ejare_page *o=new ejare_page();
    connect(this,SIGNAL(send(int)),o,SLOT(get_type(int)));
    emit send(3);
    close();
    o->show();
}










