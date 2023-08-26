#include "parvande_page.h"
#include "ui_parvande_page.h"
#include <admin_page.h>
#include <QMessageBox>
#include <fstream>
#include<north_edit_page.h>
#include <south_edit.h>
#include <aparteman_edit_page.h>

using namespace std;



parvande_page::parvande_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::parvande_page)
{
    ui->setupUi(this);
}

parvande_page::~parvande_page()
{
    delete ui;
}

void parvande_page::on_pushButton_1_clicked()
{
    ifstream current_admin;
    current_admin.open("current_admin.txt",ios::in);
    string l;
    current_admin>>l;
    admin_username=QString::fromStdString(l);

    if(ui->comboBox->currentIndex()==0)
    {
        QVector <north_vila> N;

        ui->textEdit->setText("");
        ifstream northfile;
        northfile.open("northfile.txt",ios::in);
        string g1,g2,g3,g4,g5,g6,g7,g8;
        QString k1,k2,k3,k4,k5,k6,k7,k8;
        int t;
        string t1,t2,t3,t4,t5;
        north_vila north;

        while(northfile.eof()==false)
        {
            northfile>>g1>>g2>>g3>>g4>>g5>>g6>>g7>>g8>>t;
            if(t==1)
            {
                north.set_parvande(t);
                foroosh F;
                QString e1,e2;
                northfile>>t1>>t2;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                F.set_comision(e1.toInt());
                F.set_selling_situation(e2);
                north.set_foroosh(F);
                int r1,r2;
                northfile>>r1>>r2;
                north.set_request(r1);
                north.set_sell_maskan(r2);
                if(r1==1)
                {
                    string gg;
                    northfile>>gg;
                    QString jj;
                    jj=QString::fromStdString(gg);
                    north.set_buyer(jj);
                }
            }
            if(t==2)
            {
                north.set_parvande(t);
                ejare E;
                QString e1,e2,e3,e4;
                northfile>>t1>>t2>>t3>>t4;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                e3=QString::fromStdString(t3);
                e4=QString::fromStdString(t4);
                E.set_comision(e1.toInt());
                E.setrahn(e2);
                E.set_cost_rent(e3);
                E.set_time_rent(e4.toInt());
                north.set_ejare(E);
                int r1,r2;
                northfile>>r1>>r2;
                north.set_request(r1);
                north.set_sell_maskan(r2);
                if(r1==1)
                {
                    string gg;
                    northfile>>gg;
                    QString jj;
                    jj=QString::fromStdString(gg);
                    north.set_buyer(jj);
                }
            }
            k1=QString::fromStdString(g1);
            k2=QString::fromStdString(g2);
            k3=QString::fromStdString(g3);
            k4=QString::fromStdString(g4);
            k5=QString::fromStdString(g5);
            k6=QString::fromStdString(g6);
            k7=QString::fromStdString(g7);
            k8=QString::fromStdString(g8);

            north.set_masahat_sakht(k1);
            north.set_area_of_front_yard(k2);
            north.set_area_of_back_yard(k3);
            north.set_masahat_kol(k4);
            north.set_number_of_rooms(k5.toInt());
            north.set_value_of_per_square(k6.toInt());
            north.set_adress(k7);
            north.set_admin_name(k8);
            N.push_back(north);
        }
        N.pop_back();

        QString m;

        m="index\tsharayet foroosh\tcomision";
        ui->textEdit->append(m);

        for (int i=0;i<N.size();i++)
        {
           if(QString::compare(N[i].get_admin_name(),admin_username)==0 && N[i].get_sell_maskan()==0 && N[i].get_parvande()==1)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=N[i].get_foroosh().get_selling_situation()+"\t\t"+QString::number(N[i].get_foroosh().get_comision());

               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        northfile.close();
    }
    if(ui->comboBox->currentIndex()==1)
    {
        QVector <north_vila> N;

        ui->textEdit->setText("");
        ifstream northfile;
        northfile.open("northfile.txt",ios::in);
        string g1,g2,g3,g4,g5,g6,g7,g8;
        QString k1,k2,k3,k4,k5,k6,k7,k8;
        int t;
        string t1,t2,t3,t4,t5;
        north_vila north;

        while(northfile.eof()==false)
        {
            northfile>>g1>>g2>>g3>>g4>>g5>>g6>>g7>>g8>>t;
            if(t==1)
            {
                north.set_parvande(t);
                foroosh F;
                QString e1,e2;
                northfile>>t1>>t2;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                F.set_comision(e1.toInt());
                F.set_selling_situation(e2);
                north.set_foroosh(F);
                int r1,r2;
                northfile>>r1>>r2;
                north.set_request(r1);
                north.set_sell_maskan(r2);
                if(r1==1)
                {
                    string gg;
                    northfile>>gg;
                    QString jj;
                    jj=QString::fromStdString(gg);
                    north.set_buyer(jj);
                }
            }
            if(t==2)
            {
                north.set_parvande(t);
                ejare E;
                QString e1,e2,e3,e4;
                northfile>>t1>>t2>>t3>>t4;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                e3=QString::fromStdString(t3);
                e4=QString::fromStdString(t4);
                E.set_comision(e1.toInt());
                E.setrahn(e2);
                E.set_cost_rent(e3);
                E.set_time_rent(e4.toInt());
                north.set_ejare(E);
                int r1,r2;
                northfile>>r1>>r2;
                north.set_request(r1);
                north.set_sell_maskan(r2);
                if(r1==1)
                {
                    string gg;
                    northfile>>gg;
                    QString jj;
                    jj=QString::fromStdString(gg);
                    north.set_buyer(jj);
                }
            }
            k1=QString::fromStdString(g1);
            k2=QString::fromStdString(g2);
            k3=QString::fromStdString(g3);
            k4=QString::fromStdString(g4);
            k5=QString::fromStdString(g5);
            k6=QString::fromStdString(g6);
            k7=QString::fromStdString(g7);
            k8=QString::fromStdString(g8);

            north.set_masahat_sakht(k1);
            north.set_area_of_front_yard(k2);
            north.set_area_of_back_yard(k3);
            north.set_masahat_kol(k4);
            north.set_number_of_rooms(k5.toInt());
            north.set_value_of_per_square(k6.toInt());
            north.set_adress(k7);
            north.set_admin_name(k8);
            N.push_back(north);
        }
        N.pop_back();

        QString m;

        m="index\trahn\t\tmizan ejare\tzaman ejare\tcomision";
        ui->textEdit->append(m);

        for (int i=0;i<N.size();i++)
        {
           if(QString::compare(N[i].get_admin_name(),admin_username)==0 && N[i].get_sell_maskan()==0 && N[i].get_parvande()==2)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=N[i].get_ejare().get_reahn()+"\t\t"+N[i].get_ejare().get_cost_rent()+"\t\t"
                       +QString::number(N[i].get_ejare().get_time_rent())+"\t\t"+QString::number(N[i].get_ejare().get_comision());

               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        northfile.close();
    }

    if(ui->comboBox->currentIndex()==2)
    {
        QVector <south_vila> S;

        ui->textEdit->setText("");
        ifstream myfile;
        myfile.open("south_vila.txt",ios::in);

        string g1,g2,g3,g4,g5,g6,g7,g8;
        QString k1,k2,k3,k4,k5,k6,k7,k8;
        int t;
        string t1,t2,t3,t4,t5;
        south_vila south;

        while(myfile.eof()==false)
        {
            myfile>>g1>>g2>>g3>>g4>>g5>>g6>>g7>>g8>>t;
            if(t==1)
            {
                south.set_parvande(t);
                foroosh F;
                QString e1,e2;
                myfile>>t1>>t2;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                F.set_comision(e1.toInt());
                F.set_selling_situation(e2);
                south.set_foroosh(F);
                int r1,r2;
                myfile>>r1>>r2;
                south.set_request(r1);
                south.set_sell_maskan(r2);
                if(r1==1)
                {
                    string gg;
                    myfile>>gg;
                    QString jj;
                    jj=QString::fromStdString(gg);
                    south.set_buyer(jj);
                }
            }
            if(t==2)
            {
                south.set_parvande(t);
                ejare E;
                QString e1,e2,e3,e4;
                myfile>>t1>>t2>>t3>>t4;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                e3=QString::fromStdString(t3);
                e4=QString::fromStdString(t4);
                E.set_comision(e1.toInt());
                E.setrahn(e2);
                E.set_cost_rent(e3);
                E.set_time_rent(e4.toInt());
                south.set_ejare(E);
                int r1,r2;
                myfile>>r1>>r2;
                south.set_request(r1);
                south.set_sell_maskan(r2);
                if(r1==1)
                {
                    string gg;
                    myfile>>gg;
                    QString jj;
                    jj=QString::fromStdString(gg);
                    south.set_buyer(jj);
                }
            }

            k1=QString::fromStdString(g1);
            k2=QString::fromStdString(g2);
            k3=QString::fromStdString(g3);
            k4=QString::fromStdString(g4);
            k5=QString::fromStdString(g5);
            k6=QString::fromStdString(g6);
            k7=QString::fromStdString(g7);
            k8=QString::fromStdString(g8);

            south.set_masahat_sakht(k1);
            south.set_area_of_yard(k2);
            south.set_area_of_parking(k3);
            south.set_masahat_kol(k4);
            south.set_number_of_rooms(k5.toInt());
            south.set_value_of_per_square(k6.toInt());
            south.set_adress(k7);
            south.set_admin_name(k8);
            S.push_back(south);
        }

        S.pop_back();

        QString m;

        m="index\tsharayet foroosh\tcomision";
        ui->textEdit->append(m);

        for (int i=0;i<S.size();i++)
        {
           if(QString::compare(S[i].get_admin_name(),admin_username)==0 && S[i].get_sell_maskan()==0 && S[i].get_parvande()==1)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=S[i].get_foroosh().get_selling_situation()+"\t\t"+QString::number(S[i].get_foroosh().get_comision());

               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        myfile.close();

    }
    if(ui->comboBox->currentIndex()==3)
    {
        QVector <south_vila> S;

        ui->textEdit->setText("");
        ifstream myfile;
        myfile.open("south_vila.txt",ios::in);

        string g1,g2,g3,g4,g5,g6,g7,g8;
        QString k1,k2,k3,k4,k5,k6,k7,k8;
        int t;
        string t1,t2,t3,t4,t5;
        south_vila south;

        while(myfile.eof()==false)
        {
            myfile>>g1>>g2>>g3>>g4>>g5>>g6>>g7>>g8>>t;
            if(t==1)
            {
                south.set_parvande(t);
                foroosh F;
                QString e1,e2;
                myfile>>t1>>t2;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                F.set_comision(e1.toInt());
                F.set_selling_situation(e2);
                south.set_foroosh(F);
                int r1,r2;
                myfile>>r1>>r2;
                south.set_request(r1);
                south.set_sell_maskan(r2);
                if(r1==1)
                {
                    string gg;
                    myfile>>gg;
                    QString jj;
                    jj=QString::fromStdString(gg);
                    south.set_buyer(jj);
                }
            }
            if(t==2)
            {
                south.set_parvande(t);
                ejare E;
                QString e1,e2,e3,e4;
                myfile>>t1>>t2>>t3>>t4;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                e3=QString::fromStdString(t3);
                e4=QString::fromStdString(t4);
                E.set_comision(e1.toInt());
                E.setrahn(e2);
                E.set_cost_rent(e3);
                E.set_time_rent(e4.toInt());
                south.set_ejare(E);
                int r1,r2;
                myfile>>r1>>r2;
                south.set_request(r1);
                south.set_sell_maskan(r2);
                if(r1==1)
                {
                    string gg;
                    myfile>>gg;
                    QString jj;
                    jj=QString::fromStdString(gg);
                    south.set_buyer(jj);
                }
            }

            k1=QString::fromStdString(g1);
            k2=QString::fromStdString(g2);
            k3=QString::fromStdString(g3);
            k4=QString::fromStdString(g4);
            k5=QString::fromStdString(g5);
            k6=QString::fromStdString(g6);
            k7=QString::fromStdString(g7);
            k8=QString::fromStdString(g8);

            south.set_masahat_sakht(k1);
            south.set_area_of_yard(k2);
            south.set_area_of_parking(k3);
            south.set_masahat_kol(k4);
            south.set_number_of_rooms(k5.toInt());
            south.set_value_of_per_square(k6.toInt());
            south.set_adress(k7);
            south.set_admin_name(k8);
            S.push_back(south);
        }

        S.pop_back();

        QString m;

        m="index\t\trahn\tmizan ejare\tzaman ejare\tcomision";
        ui->textEdit->append(m);

        for (int i=0;i<S.size();i++)
        {
           if(QString::compare(S[i].get_admin_name(),admin_username)==0 && S[i].get_sell_maskan()==0 && S[i].get_parvande()==2)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=S[i].get_ejare().get_reahn()+"\t\t"+S[i].get_ejare().get_cost_rent()+"\t\t"
                       +QString::number(S[i].get_ejare().get_time_rent())+"\t\t"+QString::number(S[i].get_ejare().get_comision());

               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        myfile.close();
    }
    if(ui->comboBox->currentIndex()==4)
    {
        QVector <apartmant> A;

        ui->textEdit->setText("");
        ifstream aparteman_file;
        aparteman_file.open("aparteman_file.txt",ios::in);

        string g1,g2,g3,g4,g5,g6,g7;
        QString k1,k2,k3,k4,k5,k6,k7;
        int t;
        string t1,t2,t3,t4,t5;
        apartmant ap;

        while(aparteman_file.eof()==false)
        {
            aparteman_file>>g1>>g2>>g3>>g4>>g5>>g6>>g7>>t;
            if(t==1)
            {
                ap.set_parvande(t);
                foroosh F;
                QString e1,e2,e3;
                aparteman_file>>t1>>t2>>t3;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                e3=QString::fromStdString(t3);
                F.set_building_id(e1);
                F.set_comision(e2.toInt());
                F.set_selling_situation(e3);
                ap.set_foroosh(F);
                int r1,r2;
                aparteman_file>>r1>>r2;
                ap.set_request(r1);
                ap.set_sell_maskan(r2);
            }
            if(t==2)
            {
                ap.set_parvande(t);
                ejare E;
                QString e1,e2,e3,e4,e5;
                aparteman_file>>t1>>t2>>t3>>t4>>t5;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                e3=QString::fromStdString(t3);
                e4=QString::fromStdString(t4);
                e5=QString::fromStdString(t5);

                E.set_building_id(e1);
                E.set_comision(e2.toInt());
                E.setrahn(e3);
                E.set_cost_rent(e4);
                E.set_time_rent(e5.toInt());
                ap.set_ejare(E);
                int r1,r2;
                aparteman_file>>r1>>r2;
                ap.set_request(r1);
                ap.set_sell_maskan(r2);
            }
            k1=QString::fromStdString(g1);
            k2=QString::fromStdString(g2);
            k3=QString::fromStdString(g3);
            k4=QString::fromStdString(g4);
            k5=QString::fromStdString(g5);
            k6=QString::fromStdString(g6);
            k7=QString::fromStdString(g7);

            ap.set_masahat_kol(k1);
            ap.set_value_of_per_square(k2.toInt());
            ap.set_is_asansor(k3.toInt());
            ap.set_number_of_floors(k4.toInt());
            ap.set_adress(k5);
            ap.set_id(k6);
            ap.set_admin_name(k7);

            A.push_back(ap);
        }

        A.pop_back();

        QString m;
        m="index\tsharayet foroosh\tcomision";
        ui->textEdit->append(m);

        for (int i=0;i<A.size();i++)
        {
           if(QString::compare(A[i].get_admin_name(),admin_username)==0 && A[i].get_sell_maskan()==0 && A[i].get_parvande()==1)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=A[i].get_foroosh().get_selling_situation()+"\t\t"+QString::number(A[i].get_foroosh().get_comision());

               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        aparteman_file.close();

    }
    if(ui->comboBox->currentIndex()==5)
    {
        QVector <apartmant> A;

        ui->textEdit->setText("");
        ifstream aparteman_file;
        aparteman_file.open("aparteman_file.txt",ios::in);

        string g1,g2,g3,g4,g5,g6,g7;
        QString k1,k2,k3,k4,k5,k6,k7;
        int t;
        string t1,t2,t3,t4,t5;
        apartmant ap;

        while(aparteman_file.eof()==false)
        {
            aparteman_file>>g1>>g2>>g3>>g4>>g5>>g6>>g7>>t;
            if(t==1)
            {
                ap.set_parvande(t);
                foroosh F;
                QString e1,e2,e3;
                aparteman_file>>t1>>t2>>t3;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                e3=QString::fromStdString(t3);
                F.set_building_id(e1);
                F.set_comision(e2.toInt());
                F.set_selling_situation(e3);
                ap.set_foroosh(F);
                int r1,r2;
                aparteman_file>>r1>>r2;
                ap.set_request(r1);
                ap.set_sell_maskan(r2);
            }
            if(t==2)
            {
                ap.set_parvande(t);
                ejare E;
                QString e1,e2,e3,e4,e5;
                aparteman_file>>t1>>t2>>t3>>t4>>t5;
                e1=QString::fromStdString(t1);
                e2=QString::fromStdString(t2);
                e3=QString::fromStdString(t3);
                e4=QString::fromStdString(t4);
                e5=QString::fromStdString(t5);

                E.set_building_id(e1);
                E.set_comision(e2.toInt());
                E.setrahn(e3);
                E.set_cost_rent(e4);
                E.set_time_rent(e5.toInt());
                ap.set_ejare(E);
                int r1,r2;
                aparteman_file>>r1>>r2;
                ap.set_request(r1);
                ap.set_sell_maskan(r2);
            }
            k1=QString::fromStdString(g1);
            k2=QString::fromStdString(g2);
            k3=QString::fromStdString(g3);
            k4=QString::fromStdString(g4);
            k5=QString::fromStdString(g5);
            k6=QString::fromStdString(g6);
            k7=QString::fromStdString(g7);

            ap.set_masahat_kol(k1);
            ap.set_value_of_per_square(k2.toInt());
            ap.set_is_asansor(k3.toInt());
            ap.set_number_of_floors(k4.toInt());
            ap.set_adress(k5);
            ap.set_id(k6);
            ap.set_admin_name(k7);

            A.push_back(ap);
        }

        A.pop_back();

        QString m;

        m="index\t\trahn\tmizan ejare\tzaman ejare\tcomision";
        ui->textEdit->append(m);

        for (int i=0;i<A.size();i++)
        {
           if(QString::compare(A[i].get_admin_name(),admin_username)==0 && A[i].get_sell_maskan()==0 && A[i].get_parvande()==2)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=A[i].get_ejare().get_reahn()+"\t\t"+A[i].get_ejare().get_cost_rent()+"\t\t"
                       +QString::number(A[i].get_ejare().get_time_rent())+"\t\t"+QString::number(A[i].get_ejare().get_comision());

               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        aparteman_file.close();

    }
}


void parvande_page::on_pushButton_2_clicked()
{
    admin_page *o=new admin_page();
    close();
    o->show();
}




