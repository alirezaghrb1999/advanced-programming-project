#include "aparteman_edit_page.h"
#include "ui_aparteman_edit_page.h"
#include <fstream>
#include <QMessageBox>
#include <observe_edit_maskan.h>
using namespace std;



aparteman_edit_page::aparteman_edit_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aparteman_edit_page)
{
    ui->setupUi(this);
}

aparteman_edit_page::~aparteman_edit_page()
{
    delete ui;
}

void aparteman_edit_page::get(QVector<apartmant> v, int x)
{
    vector=v;
    index=x;
}

void aparteman_edit_page::on_pushButton_clicked()
{
    QString a1,a2,a3,a4,a5,a6;
    string h1,h2,h3,h4;
    long long int x1,x2,x3;

    a1=ui->lineEdit_1->text();
    a2=ui->lineEdit_2->text();
    a3=ui->lineEdit_3->text();
    a4=ui->lineEdit_4->text();
    a5=ui->lineEdit_5->text();
    a6=ui->lineEdit_6->text();


    ofstream aparteman_file;
    aparteman_file.open("aparteman_file.txt",ios::trunc);

    vector[index-1].set_masahat_kol(a1);
    vector[index-1].set_value_of_per_square(a2.toInt());
    vector[index-1].set_is_asansor(elevator);
    vector[index-1].set_number_of_floors(a3.toInt());
    vector[index-1].set_adress(a4);
    vector[index-1].set_id(a5);
    vector[index-1].set_admin_name(a6);

    for (int i=0;i<vector.size();i++)
    {
        h1=vector[i].get_masahat_kol().toStdString();
        x1=vector[i].get_value_of_per_square();
        x2=elevator;
        x3=vector[i].get_number_of_floor();
        h2=vector[i].get_adress().toStdString();
        h3=vector[i].get_id().toStdString();
        h4=vector[i].get_admin_name().toStdString();

        aparteman_file<<h1<<" "<<x1<<" "<<x2<<" "<<x3<<" "<<" "<<h2<<" "<<h3<<" "<<h4<<" ";

        int t;
        t=vector[i].get_parvande();
        if(t==1)
        {
            QString g;
            int u1,u2;
            g=vector[i].get_foroosh().get_building_id();
            string j=g.toStdString();
            u1=vector[i].get_foroosh().get_comision();
            u2=vector[i].get_foroosh().get_selling_situation().toInt();
            int f1,f2;
            f1=vector[i].get_request();
            f2=vector[i].get_sell_maskan();
            aparteman_file<<t<<" "<<j<<" "<<u1<<" "<<u2<<" "<<f1<<" "<<f2<<"\n";
        }
        if(t==2)
        {
            QString g;
            g=vector[i].get_ejare().get_building_id();
            string j=g.toStdString();
            int u1,u2,u3,u4;          
            u1=vector[i].get_ejare().get_comision();
            u2=vector[i].get_ejare().get_reahn().toInt();
            u3=vector[i].get_ejare().get_cost_rent().toInt();
            u4=vector[i].get_ejare().get_time_rent();
            int f1,f2;
            f1=vector[i].get_request();
            f2=vector[i].get_sell_maskan();
            aparteman_file<<t<<" "<<j<<" "<<u1<<" "<<u2<<" "<<u3<<" "<<u4<<" "<<f1<<" "<<f2<<"\n";
        }
    }

    aparteman_file.close();

    QMessageBox *m=new QMessageBox();
    m->setIcon(QMessageBox::Information);
    m->setText("ویرایش شد");
    m->exec();

    observe_edit_maskan *o=new observe_edit_maskan();
    close();
    o->show();
}

void aparteman_edit_page::on_radioButton_clicked()
{
    elevator=1;
}

void aparteman_edit_page::on_radioButton_2_clicked()
{
    elevator=2;
}



