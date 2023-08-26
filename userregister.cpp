#include "userregister.h"
#include "ui_userregister.h"
#include <fstream>
#include <QMessageBox>
using namespace std;

userregister::userregister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userregister)
{
    ui->setupUi(this);

    connect(ui->radioButton_1,SIGNAL(clicked()),this,SLOT(radio1()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(radio2()));
}

userregister::~userregister()
{
    delete ui;
}

void userregister::on_pushButton_2_clicked()
{
    singup *o=new singup();
    close();
    o->show();
}

void userregister::on_pushButton_1_clicked()
{
    ofstream userfile;
    userfile.open("userfile.txt",ios::app);

    QString s1,s2,s3,s4,s5,s6;

    string d1,d2,d3,d4,d5,d6;

    s1=ui->lineEdit_1->text();
    s2=ui->lineEdit_2->text();
    s3=ui->lineEdit_3->text();
    //x
    s4=ui->lineEdit_4->text();
    s5=ui->lineEdit_5->text();
    s6=ui->lineEdit_6->text();

    d1=s1.toStdString();
    d2=s2.toStdString();
    d3=s3.toStdString();
    d4=s4.toStdString();
    d5=s5.toStdString();
    d6=s6.toStdString();

    if(s1.isEmpty()==true || s2.isEmpty()==true || s3.isEmpty()==true || s4.isEmpty()==true || s5.isEmpty()==true || s6.isEmpty()==true )
    {
        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Information);
        m->setText("لطفا تمامی فیلد ها را پر کنید");
        m->exec();
    }
    else
    {
        userfile<<d1<<" "<<d2<<" "<<d3<<" "<<position<<" "<<d4<<" "<<d5<<" "<<d6<<"\n";
        userfile.close();

        QMessageBox *ms=new QMessageBox();
        ms->setIcon(QMessageBox::Information);
        ms->setText("اطلاعات شما با موفقیت ثبت گردید!");
        ms->exec();

        singup *o=new singup();
        close();
        o->show();
    }
}

void userregister::radio1()
{
    position=1;
}

void userregister::radio2()
{
    position=2;
}


