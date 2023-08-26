#include "vahed_page.h"
#include "ui_vahed_page.h"
#include <QMessageBox>
#include <fstream>
using namespace std;

vahed_page::vahed_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vahed_page)
{
    ui->setupUi(this);
}

vahed_page::~vahed_page()
{
    delete ui;
}



void vahed_page::on_pushButton_clicked()
{
    QString s1,s2,s3;
    s1=ui->lineEdit_1->text();
    s2=ui->lineEdit_2->text();
    s3=ui->lineEdit_3->text();

    if(s1.isEmpty()==true || s2.isEmpty()==true || s3.isEmpty()==true)
    {
        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Warning);
        m->setText("لطفا فیلد هارا پر کنید");
        m->exec();
    }
    else
    {
        apartemani_page *obj=new apartemani_page();

        ofstream myfile;

        string name;
        name=g5.toStdString();

        myfile.open(name+".txt",ios::app);

        string c1,c2,c3;
        c1=s1.toStdString();
        c2=s2.toStdString();
        c3=s3.toStdString();

        myfile<<c1<<" "<<c2<<" "<<c3<<" "<<"0"<<" "<<"0"<<"\n";

        myfile.close();

        connect(this,SIGNAL(send_data(QString,QString,QString,QString,QString,QString,int)),obj,SLOT(get_data(QString,QString,QString,QString,QString,QString,int)));
        emit send_data(g1,g2,g3,g4,g5,g6,y);

        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Information);
        m->setText("واحد اضافه شد");
        m->exec();

        close();
        obj->show();
    }
}

void vahed_page::on_pushButton_2_clicked()
{
     apartemani_page *obj=new apartemani_page();
     close();
     obj->show();
}

void vahed_page::get_data(QString x1, QString x2, QString x3, QString x4, QString x5,QString x6, int z)
{
    g1=x1;
    g2=x2;
    g3=x3;
    g4=x4;
    g5=x5;
    g6=x6;
    y=z;
}


