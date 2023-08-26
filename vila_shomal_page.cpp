#include "vila_shomal_page.h"
#include "ui_vila_shomal_page.h"
#include <fstream>
#include <QMessageBox>
#include <insert_maskan.h>
#include <foroosh_page.h>
#include <ejare_page.h>

using namespace std;

vila_shomal_page::vila_shomal_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vila_shomal_page)
{
    ui->setupUi(this);
}

vila_shomal_page::~vila_shomal_page()
{
    delete ui;
}


void vila_shomal_page::on_pushButton_1_clicked()
{
    QMessageBox *m=new QMessageBox();
    m->setIcon(QMessageBox::Information);
    m->setText("ویلای شمالی ثبت شد");
    m->exec();

    insert_maskan *obj=new insert_maskan();
    close();
    obj->show();
}


void vila_shomal_page::on_pushButton_2_clicked()
{
    insert_maskan *obj=new insert_maskan();
    close();
    obj->show();
}



void vila_shomal_page::on_pushButton_4_clicked() //parvande foroosh
{
    QString s1,s2,s3,s4,s5,s6,s7,s8;
    string d1,d2,d3,d4,d5,d6,d7,d8;

    s1=ui->lineEdit_1->text();
    s2=ui->lineEdit_2->text();
    s3=ui->lineEdit_3->text();
    s4=ui->lineEdit_4->text();
    s5=ui->lineEdit_5->text();
    s6=ui->lineEdit_6->text();
    s7=ui->lineEdit_7->text();
    s8=ui->lineEdit_8->text();

    d1=s1.toStdString();
    d2=s2.toStdString();
    d3=s3.toStdString();
    d4=s4.toStdString();
    d5=s5.toStdString();
    d6=s6.toStdString();
    d7=s7.toStdString();
    d8=s8.toStdString();

    if(s1.isEmpty()==true || s2.isEmpty()==true ||s3.isEmpty()==true  ||s4.isEmpty()==true ||s5.isEmpty()==true ||s6.isEmpty()==true || s7.isEmpty()==true || s8.isEmpty()==true)
    {
        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Warning);
        m->setText("لطفا تمامی فیلد ها را پر کنید");
        m->exec();
    }
    else
    {
        ofstream north_file;
        north_file.open("northfile.txt",ios::app);

        north_file<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<" "<<d5<<" "<<d6<<" "<<d7<<" "<<d8<<" 1 ";
        north_file.close();
    }

    foroosh_page *o=new foroosh_page();
    connect(this,SIGNAL(send(int)),o,SLOT(get_type(int)));
    emit send(1);
    close();
    o->show();
}



void vila_shomal_page::on_pushButton_3_clicked() //parvande ejare
{
    QString s1,s2,s3,s4,s5,s6,s7,s8;
    string d1,d2,d3,d4,d5,d6,d7,d8;

    s1=ui->lineEdit_1->text();
    s2=ui->lineEdit_2->text();
    s3=ui->lineEdit_3->text();
    s4=ui->lineEdit_4->text();
    s5=ui->lineEdit_5->text();
    s6=ui->lineEdit_6->text();
    s7=ui->lineEdit_7->text();
    s8=ui->lineEdit_8->text();

    d1=s1.toStdString();
    d2=s2.toStdString();
    d3=s3.toStdString();
    d4=s4.toStdString();
    d5=s5.toStdString();
    d6=s6.toStdString();
    d7=s7.toStdString();
    d8=s8.toStdString();

    if(s1.isEmpty()==true || s2.isEmpty()==true ||s3.isEmpty()==true  ||s4.isEmpty()==true ||s5.isEmpty()==true ||s6.isEmpty()==true || s7.isEmpty()==true || s8.isEmpty()==true)
    {
        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Warning);
        m->setText("لطفا تمامی فیلد ها را پر کنید");
        m->exec();
    }
    else
    {
        ofstream north_file;
        north_file.open("northfile.txt",ios::app);

        north_file<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<" "<<d5<<" "<<d6<<" "<<d7<<" "<<d8<<" 2 ";
        north_file.close();
    }

    ejare_page *o=new ejare_page();
    connect(this,SIGNAL(send(int)),o,SLOT(get_type(int)));
    emit send(1);
    close();
    o->show();
}




