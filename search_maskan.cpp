#include "search_maskan.h"
#include "ui_search_maskan.h"
#include <user_page.h>
#include <QMessageBox>
#include <fstream>
#include <north_edit_page.h>
#include <south_edit.h>
#include <aparteman_edit_page.h>
#include <foroosh.h>
#include <ejare.h>
using namespace std;

search_maskan::search_maskan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search_maskan)
{
    ui->setupUi(this);
}

search_maskan::~search_maskan()
{
    delete ui;
}



void search_maskan::on_pushButton_1_clicked()
{
    user_page *o=new user_page();
    close();
    o->show();
}






void search_maskan::on_pushButton_2_clicked() //show
{
    set_A();
    set_N();
    set_S();

    if(ui->comboBox->currentIndex()==0)
    {
        QString m1;

        m1="north vila \nindex     masahatsakgt     hayat jolo     hayat posht     masahat kol     tedad otagh      gheymat paye       adres       namkarbari";
        ui->textEdit->append(m1);
        for (int i=0;i<N.size();i++)
        {

               int x=i+1;
               QString l=QString::number(x);

               QString f=N[i].get_masahat_sakht()+"\t"+N[i].get_area_of_front_yard()+"\t\t"+N[i].get_area_of_back_yard()+"\t"+N[i].get_masahat_kol()+"\t\t"
                       +QString::number(N[i].get_number_of_rooms())+"\t"+QString::number(N[i].get_value_of_per_square())
                       +"\t"+N[i].get_adress()+"\t"+N[i].get_admin_name()+"\n";

               ui->textEdit->append(l+"\t"+f);
        }

        QString m2;
        m2="south vila \nindex   masahat sakgt  masahat hayat   masahat parking   masahat kol     tedad otagh      gheymat paye      adres      namkarbari";
        ui->textEdit->append(m2);
        for (int i=0;i<S.size();i++)
        {
                int x=i+1;
                QString l=QString::number(x);

                QString f=S[i].get_masahat_sakht()+"\t"+S[i].get_area_of_yard()+"\t\t"+
                        S[i].get_area_of_parking()+"\t"+S[i].get_masahat_kol()+"\t\t"
                        +QString::number(S[i].get_number_of_rooms())+"\t"+QString::number(S[i].get_value_of_per_square())
                        +"\t"+S[i].get_adress()+"\t"+S[i].get_admin_name()+"\n";

                ui->textEdit->append(l+"\t"+f);
        }

    }
    if(ui->comboBox->currentIndex()==1)
    {
        QString m;
        m="aparteman \nindex   masahat kol  gheymat paye   asansor   tedad tabaghe     adres      shenase       namkarbari";
        ui->textEdit->append(m);

        for (int i=0;i<A.size();i++)
        {
                int x=i+1;
                QString l=QString::number(x);

                QString f=A[i].get_masahat_kol()+"\t"+QString::number(A[i].get_value_of_per_square())+"\t"+QString::number(A[i].get_asansor())+"\t"+QString::number(A[i].get_number_of_floor())+"\t"
                        +A[i].get_adress()+"\t"+A[i].get_id()
                        +"\t"+A[i].get_admin_name()+"\n";

                ui->textEdit->append(l+"\t"+f);
        }
    }
    if(ui->comboBox->currentIndex()==2)
    {
        QString s1,s2;
        s1=ui->lineEdit_1->text();
        s2=ui->lineEdit_2->text();

        if(s1.isEmpty()==true || s2.isEmpty()==true)
        {
            QMessageBox *m=new QMessageBox();
            m->setIcon(QMessageBox::Warning);
            m->setText("قسمت الف و ب را وارد کنید");
            m->exec();
        }
        else
        {
            QString m1;

            m1="north vila \nindex     masahatsakgt     hayat jolo     hayat posht     masahat kol     tedad otagh      gheymat paye       adres       namkarbari";
            ui->textEdit->append(m1);
            for (int i=0;i<N.size();i++)
            {
                if(N[i].get_value_of_per_square()<s1.toInt() && N[i].get_masahat_sakht()>s2.toInt())
                {
                    int x=i+1;
                    QString l=QString::number(x);

                    QString f=N[i].get_masahat_sakht()+"\t"+N[i].get_area_of_front_yard()+"\t\t"+N[i].get_area_of_back_yard()+"\t"+N[i].get_masahat_kol()+"\t\t"
                            +QString::number(N[i].get_number_of_rooms())+"\t"+QString::number(N[i].get_value_of_per_square())
                            +"\t"+N[i].get_adress()+"\t"+N[i].get_admin_name()+"\n";

                    ui->textEdit->append(l+"\t"+f);
                }
            }

            QString m2;
            m2="south vila \nindex   masahat sakgt  masahat hayat   masahat parking   masahat kol     tedad otagh      gheymat paye      adres      namkarbari";
            ui->textEdit->append(m2);
            for (int i=0;i<S.size();i++)
            {
                if(S[i].get_value_of_per_square()<s1.toInt() && S[i].get_masahat_sakht()>s2.toInt())
                {
                    int x=i+1;
                    QString l=QString::number(x);

                    QString f=S[i].get_masahat_sakht()+"\t"+S[i].get_area_of_yard()+"\t\t"+
                            S[i].get_area_of_parking()+"\t"+S[i].get_masahat_kol()+"\t\t"
                            +QString::number(S[i].get_number_of_rooms())+"\t"+QString::number(S[i].get_value_of_per_square())
                            +"\t"+S[i].get_adress()+"\t"+S[i].get_admin_name()+"\n";

                    ui->textEdit->append(l+"\t"+f);
                }
            }
            QString m3;
            m3="aparteman \nindex   masahat kol  gheymat paye   asansor   tedad tabaghe     adres      shenase       namkarbari";
            ui->textEdit->append(m3);

            for (int i=0;i<A.size();i++)
            {
                if(A[i].get_value_of_per_square()<s1.toInt() && A[i].get_masahat_kol()>s2.toInt())
                {
                    int x=i+1;
                    QString l=QString::number(x);

                    QString f=A[i].get_masahat_kol()+"\t"+QString::number(A[i].get_value_of_per_square())+"\t"+QString::number(A[i].get_asansor())+"\t"+QString::number(A[i].get_number_of_floor())+"\t"
                            +A[i].get_adress()+"\t"+A[i].get_id()
                            +"\t"+A[i].get_admin_name()+"\n";

                    ui->textEdit->append(l+"\t"+f);
                }
            }
        }

    }
    if(ui->comboBox->currentIndex()==3)
    {
        QString s1;
        s1=ui->lineEdit_1->text();

        if(s1.isEmpty()==true)
        {
            QMessageBox *m=new QMessageBox();
            m->setIcon(QMessageBox::Warning);
            m->setText("قسمت الف را وارد کنید");
            m->exec();
        }
        else
        {
            QString m1;

            m1="north vila \nindex     masahatsakgt     hayat jolo     hayat posht     masahat kol     tedad otagh      gheymat paye       adres       namkarbari";
            ui->textEdit->append(m1);
            for (int i=0;i<N.size();i++)
            {
                if(N[i].get_adress()==s1)
                {
                    int x=i+1;
                    QString l=QString::number(x);

                    QString f=N[i].get_masahat_sakht()+"\t"+N[i].get_area_of_front_yard()+"\t\t"+N[i].get_area_of_back_yard()+"\t"+N[i].get_masahat_kol()+"\t\t"
                            +QString::number(N[i].get_number_of_rooms())+"\t"+QString::number(N[i].get_value_of_per_square())
                            +"\t"+N[i].get_adress()+"\t"+N[i].get_admin_name()+"\n";

                    ui->textEdit->append(l+"\t"+f);
                }
            }

            QString m2;
            m2="south vila \nindex   masahat sakgt  masahat hayat   masahat parking   masahat kol     tedad otagh      gheymat paye      adres      namkarbari";
            ui->textEdit->append(m2);
            for (int i=0;i<S.size();i++)
            {
                if(S[i].get_adress()==s1)
                {
                    int x=i+1;
                    QString l=QString::number(x);

                    QString f=S[i].get_masahat_sakht()+"\t"+S[i].get_area_of_yard()+"\t\t"+
                            S[i].get_area_of_parking()+"\t"+S[i].get_masahat_kol()+"\t\t"
                            +QString::number(S[i].get_number_of_rooms())+"\t"+QString::number(S[i].get_value_of_per_square())
                            +"\t"+S[i].get_adress()+"\t"+S[i].get_admin_name()+"\n";

                    ui->textEdit->append(l+"\t"+f);
                }
            }
            QString m3;
            m3="aparteman \nindex   masahat kol  gheymat paye   asansor   tedad tabaghe     adres      shenase       namkarbari";
            ui->textEdit->append(m3);

            for (int i=0;i<A.size();i++)
            {
                if(A[i].get_adress()==s1)
                {
                    int x=i+1;
                    QString l=QString::number(x);

                    QString f=A[i].get_masahat_kol()+"\t"+QString::number(A[i].get_value_of_per_square())+"\t"+QString::number(A[i].get_asansor())+"\t"+QString::number(A[i].get_number_of_floor())+"\t"
                            +A[i].get_adress()+"\t"+A[i].get_id()
                            +"\t"+A[i].get_admin_name()+"\n";

                    ui->textEdit->append(l+"\t"+f);
                }
            }
        }
    }
}













void search_maskan::set_N()
{
    QVector <north_vila> N1;

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
        N1.push_back(north);
    }
    N1.pop_back();
    QString m;
    N=N1;
    northfile.close();
}

void search_maskan::set_S()
{
    QVector <south_vila> S1;

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
        S1.push_back(south);
    }

    S1.pop_back();
    S=S1;
    myfile.close();
}

void search_maskan::set_A()
{
    QVector <apartmant> A1;

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

        A1.push_back(ap);
    }

    A1.pop_back();
    A=A1;
    aparteman_file.close();
}





