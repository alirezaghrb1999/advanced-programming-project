#include "south_edit.h"
#include "ui_south_edit.h"
#include <fstream>
#include <QMessageBox>
#include <observe_edit_maskan.h>
#include <foroosh.h>
#include <ejare.h>
#include"QtDebug"
using namespace std;


south_edit::south_edit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::south_edit)
{
    ui->setupUi(this);
}

south_edit::~south_edit()
{
    delete ui;
}

void south_edit::get(QVector<south_vila> v, int x)
{
    vector=v;
    index=x;   
}

void south_edit::on_pushButton_clicked()
{
    QString a1,a2,a3,a4,a5,a6,a7,a8;
    string h1,h2,h3,h4,h5,h6,h7,h8;
    long long int x1,x2;

    a1=ui->lineEdit_1->text();
    a2=ui->lineEdit_2->text();
    a3=ui->lineEdit_3->text();
    a4=ui->lineEdit_4->text();
    a5=ui->lineEdit_5->text();
    a6=ui->lineEdit_6->text();
    a7=ui->lineEdit_7->text();
    a8=ui->lineEdit_8->text();


    ofstream south_vila;
    south_vila.open("south_vila.txt",ios::trunc);

    vector[index-1].set_masahat_sakht(a1);
    vector[index-1].set_area_of_yard(a2);
    vector[index-1].set_area_of_parking(a3);
    vector[index-1].set_masahat_kol(a4);
    vector[index-1].set_number_of_rooms(a5.toInt());
    vector[index-1].set_value_of_per_square(a6.toInt());
    vector[index-1].set_adress(a7);
    vector[index-1].set_admin_name(a8);


    for (int i=0;i<vector.size();i++)
    {
        h1=vector[i].get_masahat_kol().toStdString();
        h2=vector[i].get_area_of_yard().toStdString();
        h3=vector[i].get_area_of_parking().toStdString();
        h4=vector[i].get_masahat_kol().toStdString();
        x1=vector[i].get_number_of_rooms();
        x2=vector[i].get_value_of_per_square();
        h7=vector[i].get_adress().toStdString();
        h8=vector[i].get_admin_name().toStdString();

        south_vila<<h1<<" "<<h2<<" "<<h3<<" "<<h4<<" "<<x1<<" "<<x2<<" "<<h7<<" "<<h8<<" ";

        int t;
        t=vector[i].get_parvande();
        if(t==1)
        {
            int u1,u2;
            u1=vector[i].get_foroosh().get_comision();
            u2=vector[i].get_foroosh().get_selling_situation().toInt();
            int f1,f2;
            f1=vector[i].get_request();
            f2=vector[i].get_sell_maskan();
            south_vila<<t<<" "<<u1<<" "<<u2<<" "<<f1<<" "<<f2;
            if(vector[i].get_request()==1)
            {
                string O;
                QString kh=vector[i].get_buyer();
                O=kh.toStdString();
                south_vila<<" "<<O<<"\n";
            }
            else
            {
                south_vila<<"\n";
            }
        }
        if(t==2)
        {
            int u1,u2,u3,u4;
            u1=vector[i].get_ejare().get_comision();
            u2=vector[i].get_ejare().get_reahn().toInt();
            u3=vector[i].get_ejare().get_cost_rent().toInt();
            u4=vector[i].get_ejare().get_time_rent();
            int f1,f2;
            f1=vector[i].get_request();
            f2=vector[i].get_sell_maskan();
            south_vila<<t<<" "<<u1<<" "<<u2<<" "<<u3<<" "<<u4<<" "<<f1<<" "<<f2;
            if(vector[i].get_request()==1)
            {
                string O;
                QString kh=vector[i].get_buyer();
                O=kh.toStdString();
                south_vila<<" "<<O<<"\n";
            }
            else
            {
                south_vila<<"\n";
            }
        }
    }

    south_vila.close();
    QMessageBox *m=new QMessageBox();
    m->setIcon(QMessageBox::Information);
    m->setText("ویرایش شد");
    m->exec();

    observe_edit_maskan *o=new observe_edit_maskan();
    close();
    o->show();
}




