#include "request_maskan.h"
#include "ui_request_maskan.h"
#include <QMessageBox>
#include <fstream>
#include <apartmant_home.h>
#include <user.h>
#include <user_page.h>
using namespace std;




request_maskan::request_maskan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::request_maskan)
{
    ui->setupUi(this);
    ui->lineEdit_2->setPlaceholderText("فقط برای مسکن های آپارتمانی");
}

request_maskan::~request_maskan()
{
    delete ui;
}


void request_maskan::on_pushButton_1_clicked()
{
    ifstream current_user;
    current_user.open("current_user.txt",ios::in);
    string l;
    current_user>>l;
    username=QString::fromStdString(l);

    ifstream userfile;
    userfile.open("userfile.txt",ios::in);

    QVector <user> U;
    user us;

    string l1,l2,l3,l4,l5;
    long long int x1,x2;
    QString a1,a2,a3,a4,a5;

    while (userfile.eof()==false)
    {
        userfile>>l1>>l2>>l3>>x1>>l4>>l5>>x2;
        a1=QString::fromStdString(l1);
        a2=QString::fromStdString(l2);
        a3=QString::fromStdString(l3);
        a4=QString::fromStdString(l4);
        a5=QString::fromStdString(l5);

        us.set_name(a1);
        us.set_lastname(a2);
        us.set_date(a3);
        us.set_position_of_person(x1);
        us.set_username(a4);
        us.set_password(a5);
        us.set_stock(x2);

        U.push_back(us);
    }

    for (int i=0;i<U.size();i++)
    {
        if(U[i].get_username()==username)
        {
            STOCK=U[i].get_stock();
            break;
        }
    }

    QString s1=ui->lineEdit_1->text();
    QString s2=ui->lineEdit_2->text();

    if(s1.isEmpty()==true)
    {
        QMessageBox *m=new QMessageBox();
        m->setIcon(QMessageBox::Warning);
        m->setText("لطفا اندیس را وارد کنید");
        m->exec();
    }
    else
    {
        if(ui->comboBox->currentIndex()==4 || ui->comboBox->currentIndex()==5)
        {
            if(s2.isEmpty()==true)
            {
                QMessageBox *m=new QMessageBox();
                m->setIcon(QMessageBox::Warning);
                m->setText("لطفا اندیس واحد را وارد کنید");
                m->exec();
            }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if(ui->comboBox->currentIndex()==0 || ui->comboBox->currentIndex()==1)
        {
            int a=s1.toInt()-1;
            if(STOCK<QString::number(N1[a].get_foroosh().get_final_price(N1[a].get_all_cost())))
            {
                QMessageBox *m=new QMessageBox();
                m->setIcon(QMessageBox::Warning);
                m->setText("موجودی کافی نیست");
                m->exec();
            }
            else
            {
                N1[a].set_request(1);
                N1[a].set_buyer(username);

                string h1,h2,h3,h4,h5,h6,h7,h8;
                long long int x1,x2;

                ofstream northfile;
                northfile.open("northfile.txt",ios::trunc);

                for (int i=0;i<N1.size();i++)
                {
                    h1=N1[i].get_masahat_kol().toStdString();
                    h2=N1[i].get_area_of_front_yard().toStdString();
                    h3=N1[i].get_area_of_back_yard().toStdString();
                    h4=N1[i].get_masahat_kol().toStdString();
                    x1=N1[i].get_number_of_rooms();
                    x2=N1[i].get_value_of_per_square();
                    h7=N1[i].get_adress().toStdString();
                    h8=N1[i].get_admin_name().toStdString();

                    northfile<<h1<<" "<<h2<<" "<<h3<<" "<<h4<<" "<<x1<<" "<<x2<<" "<<h7<<" "<<h8<<" ";

                    int t;
                    t=N1[i].get_parvande();
                    if(t==1)
                    {
                        int u1,u2;
                        u1=N1[i].get_foroosh().get_comision();
                        u2=N1[i].get_foroosh().get_selling_situation().toInt();
                        int f1,f2;
                        f1=N1[i].get_request();
                        f2=N1[i].get_sell_maskan();
                        northfile<<t<<" "<<u1<<" "<<u2<<" "<<f1<<" "<<f2;
                    }
                    if(t==2)
                    {
                        int u1,u2,u3,u4;
                        u1=N1[i].get_ejare().get_comision();
                        u2=N1[i].get_ejare().get_reahn().toInt();
                        u3=N1[i].get_ejare().get_cost_rent().toInt();
                        u4=N1[i].get_ejare().get_time_rent();
                        int f1,f2;
                        f1=N1[i].get_request();
                        f2=N1[i].get_sell_maskan();
                        northfile<<t<<" "<<u1<<" "<<u2<<" "<<u3<<" "<<u4<<" "<<f1<<" "<<f2;
                    }
                    if(N1[i].get_request()==1)
                    {
                        string O;
                        QString kh=N1[i].get_buyer();
                        O=kh.toStdString();
                        northfile<<" "<<O<<"\n";
                    }
                    else
                    {
                        northfile<<"\n";
                    }
                }

                northfile.close();

                QMessageBox *m=new QMessageBox();
                m->setIcon(QMessageBox::Information);
                m->setText("درخواست خرید برای مدیر ارسال شد");
                m->exec();
            }

        }

        if(ui->comboBox->currentIndex()==2 || ui->comboBox->currentIndex()==3)
        {
            int a=s1.toInt()-1;
            if(STOCK<QString::number(S1[a].get_foroosh().get_final_price(S1[a].get_all_cost())))
            {
                QMessageBox *m=new QMessageBox();
                m->setIcon(QMessageBox::Warning);
                m->setText("موجودی کافی نیست");
                m->exec();
            }
            else
            {
                S1[a].set_request(1);
                S1[a].set_buyer(username);

                string h1,h2,h3,h4,h5,h6,h7,h8;
                long long int x1,x2;

                ofstream south_vila;
                south_vila.open("south_vila.txt",ios::trunc);

                for (int i=0;i<S1.size();i++)
                {
                    h1=S1[i].get_masahat_kol().toStdString();
                    h2=S1[i].get_area_of_yard().toStdString();
                    h3=S1[i].get_area_of_parking().toStdString();
                    h4=S1[i].get_masahat_kol().toStdString();
                    x1=S1[i].get_number_of_rooms();
                    x2=S1[i].get_value_of_per_square();
                    h7=S1[i].get_adress().toStdString();
                    h8=S1[i].get_admin_name().toStdString();

                    south_vila<<h1<<" "<<h2<<" "<<h3<<" "<<h4<<" "<<x1<<" "<<x2<<" "<<h7<<" "<<h8<<" ";

                    int t;
                    t=S1[i].get_parvande();
                    if(t==1)
                    {
                        int u1,u2;
                        u1=S1[i].get_foroosh().get_comision();
                        u2=S1[i].get_foroosh().get_selling_situation().toInt();
                        int f1,f2;
                        f1=S1[i].get_request();
                        f2=S1[i].get_sell_maskan();
                        south_vila<<t<<" "<<u1<<" "<<u2<<" "<<f1<<" "<<f2;
                    }
                    if(t==2)
                    {
                        int u1,u2,u3,u4;
                        u1=S1[i].get_ejare().get_comision();
                        u2=S1[i].get_ejare().get_reahn().toInt();
                        u3=S1[i].get_ejare().get_cost_rent().toInt();
                        u4=S1[i].get_ejare().get_time_rent();
                        int f1,f2;
                        f1=S1[i].get_request();
                        f2=S1[i].get_sell_maskan();
                        south_vila<<t<<" "<<u1<<" "<<u2<<" "<<u3<<" "<<u4<<" "<<f1<<" "<<f2;
                    }
                    if(S1[i].get_request()==1)
                    {
                        string O;
                        QString kh=S1[i].get_buyer();
                        O=kh.toStdString();
                        south_vila<<" "<<O<<"\n";
                    }
                    else
                    {
                        south_vila<<"\n";
                    }
                }

                south_vila.close();

                QMessageBox *m=new QMessageBox();
                m->setIcon(QMessageBox::Information);
                m->setText("درخواست خرید برای مدیر ارسال شد");
                m->exec();
            }

        }

        if(ui->comboBox->currentIndex()==4 || ui->comboBox->currentIndex()==5)
        {
            int a1=s1.toInt()-1,a2=s2.toInt()-1;
            int k4;
            k4=A1[a1].get_vahed()[a2].get_price(A1[a1].get_asansor(),A1[a1].get_value_of_per_square());
            if(STOCK<k4)
            {
                QMessageBox *m=new QMessageBox();
                m->setIcon(QMessageBox::Warning);
                m->setText("موجودی کافی نیست");
                m->exec();
            }
            else
            {
                QString name=A1[a1].get_id();
                string n;
                n=name.toStdString();
                A1[a1].set_request(1);

                string h1,h2,h3,h4;
                long long int x1,x2,x3;

                ofstream aparteman_file;
                aparteman_file.open("aparteman_file.txt",ios::trunc);

                for (int i=0;i<A1.size();i++)
                {
                    h1=A1[i].get_masahat_kol().toStdString();
                    x1=A1[i].get_value_of_per_square();
                    x2=A1[i].get_asansor();
                    x3=A1[i].get_number_of_floor();
                    h2=A1[i].get_adress().toStdString();
                    h3=A1[i].get_id().toStdString();
                    h4=A1[i].get_admin_name().toStdString();

                    aparteman_file<<h1<<" "<<x1<<" "<<x2<<" "<<x3<<" "<<" "<<h2<<" "<<h3<<" "<<h4<<" ";

                    int t;
                    t=A1[i].get_parvande();
                    if(t==1)
                    {
                        QString g;
                        int u1,u2;
                        g=A1[i].get_foroosh().get_building_id();
                        string j=g.toStdString();
                        u1=A1[i].get_foroosh().get_comision();
                        u2=A1[i].get_foroosh().get_selling_situation().toInt();
                        int f1,f2;
                        f1=A1[i].get_request();
                        f2=A1[i].get_sell_maskan();
                        aparteman_file<<t<<" "<<j<<" "<<u1<<" "<<u2<<" "<<f1<<" "<<f2<<"\n";
                    }
                    if(t==2)
                    {
                        QString g;
                        g=A1[i].get_ejare().get_building_id();
                        string j=g.toStdString();
                        int u1,u2,u3,u4;
                        u1=A1[i].get_ejare().get_comision();
                        u2=A1[i].get_ejare().get_reahn().toInt();
                        u3=A1[i].get_ejare().get_cost_rent().toInt();
                        u4=A1[i].get_ejare().get_time_rent();
                        int f1,f2;
                        f1=A1[i].get_request();
                        f2=A1[i].get_sell_maskan();
                        aparteman_file<<t<<" "<<j<<" "<<u1<<" "<<u2<<" "<<u3<<" "<<u4<<" "<<f1<<" "<<f2<<"\n";
                    }
                }

                aparteman_file.close();

                string m1,m2,m3,m4,m5;
                int z1,z2,z3,z4,z5;
                ofstream myfile;
                myfile.open(n+".txt",ios::trunc);

                A1[a1].get_vahed()[a2].set_request(1);
                A1[a1].get_vahed()[a2].set_buyer(username);

                for (int i=0;i<A1[a1].get_vahed().size();i++)
                {
                    z1=A1[a1].get_vahed()[i].get_floors_number();
                    z2=A1[a1].get_vahed()[i].get_room_number();
                    z3=A1[a1].get_vahed()[i].get_home_area();
                    z4=A1[a1].get_vahed()[i].get_request();
                    z5=A1[a1].get_vahed()[i].get_sell_maskan();

                    myfile<<z1<<" "<<z2<<" "<<z3<<" "<<z4<<" "<<z5;
                    if(z4==1)
                    {
                        string O;
                        QString kh=A1[a1].get_vahed()[i].get_buyer();
                        O=kh.toStdString();
                        myfile<<" "<<O<<"\n";
                    }
                    else
                    {
                        myfile<<"\n";
                    }
                }
                myfile.close();

                QMessageBox *m=new QMessageBox();
                m->setIcon(QMessageBox::Information);
                m->setText("درخواست خرید برای مدیر ارسال شد");
                m->exec();
            }

        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void request_maskan::on_pushButton_clicked()
{
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

        m="index \t masahat sakht \t\t  masahat kol \t tedad otagh \t address \t\t gheymat";
        ui->textEdit->append(m);

        for (int i=0;i<N.size();i++)
        {
           if(N[i].get_sell_maskan()==0 && N[i].get_parvande()==1)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=N[i].get_masahat_sakht()+"\t\t"+N[i].get_masahat_kol()+"\t\t"+QString::number(N[i].get_number_of_rooms())+"\t\t"+
                       N[i].get_adress()+"\t\t"+QString::number(N[i].get_foroosh().get_final_price(N[i].get_all_cost()));

               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        northfile.close();
        N1=N;
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

        m="index \t masahat sakht \t\t  masahat kol \t tedad otagh \t address \t\t gheymat ejare";
        ui->textEdit->append(m);

        for (int i=0;i<N.size();i++)
        {
           if(N[i].get_sell_maskan()==0 && N[i].get_parvande()==2)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=N[i].get_masahat_sakht()+"\t\t"+N[i].get_masahat_kol()+"\t\t"+QString::number(N[i].get_number_of_rooms())+"\t\t"+
                       N[i].get_adress()+"\t\t"+QString::number(N[i].get_ejare().get_final_ejare(N[i].get_all_cost()));


               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        northfile.close();
        N1=N;
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
        m="index \t masahat sakht \t\t  masahat kol \t tedad otagh \t address \t\t gheymat";

        ui->textEdit->append(m);

        for (int i=0;i<S.size();i++)
        {
           if(S[i].get_sell_maskan()==0 && S[i].get_parvande()==1)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=S[i].get_masahat_sakht()+"\t\t"+S[i].get_masahat_kol()+"\t\t"+QString::number(S[i].get_number_of_rooms())+"\t\t"+
                       S[i].get_adress()+"\t\t"+QString::number(S[i].get_foroosh().get_final_price(S[i].get_all_cost()));

               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        myfile.close();
        S1=S;
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
        m="index \t masahat sakht \t\t  masahat kol \t tedad otagh \t address \t\t gheymat ejare";

        ui->textEdit->append(m);

        for (int i=0;i<S.size();i++)
        {
           if(S[i].get_sell_maskan()==0 && S[i].get_parvande()==2)
           {
               int x=i+1;
               QString l=QString::number(x);

               QString f=S[i].get_masahat_sakht()+"\t\t"+S[i].get_masahat_kol()+"\t\t"+QString::number(S[i].get_number_of_rooms())+"\t\t"+
                       S[i].get_adress()+"\t\t"+QString::number(S[i].get_ejare().get_final_ejare(S[i].get_all_cost()));

               ui->textEdit->append(l+"\t\t"+f);
            }
        }

        myfile.close();
        S1=S;
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

        QString m1,m2;


        for(int i=0;i<A.size();i++)
        {
           if(A[i].get_sell_maskan()==0 && A[i].get_parvande()==1)
           {
               m1="index aparteman \t asansor  \t\t address";
               ui->textEdit->append(m1);

               int x=i+1;
               QString l=QString::number(x);

               QString f1=QString::number(A[i].get_asansor())+"\t\t"+A[i].get_adress();
               ui->textEdit->append(l+"\t\t"+f1);

               string name;
               name=A[i].get_id().toStdString();

               QVector <apartmant_home> AH;

               ifstream myfile;
               myfile.open(name+".txt",ios::in);

               while (myfile.eof()==false)
               {
                   string h1,h2,h3,h4,h5;
                   QString n1,n2,n3,n4,n5;

                   myfile>>h1>>h2>>h3>>h4>>h5;

                   n1=QString::fromStdString(h1);
                   n2=QString::fromStdString(h2);
                   n3=QString::fromStdString(h3);
                   n4=QString::fromStdString(h4);
                   n5=QString::fromStdString(h5);

                   apartmant_home ah;

                   ah.set_floors_number(n1.toInt());
                   ah.set_room_number(n2.toInt());
                   ah.set_home_area(n3.toInt());
                   ah.set_request(n4.toInt());
                   ah.set_sell_maskan(n5.toInt());

                   if(n4.toInt()==1)
                   {
                       string gg;
                       myfile>>gg;
                       QString jj;
                       jj=QString::fromStdString(gg);
                       ah.set_buyer(jj);
                   }
                   AH.push_back(ah);
               }
               AH.pop_back();
               A[i].set_apartmant_home(AH);
               myfile.close();

                m2="\t \t index vahed \t shomare tabaghe \t tedad otagh \t masahat vahed \t gheymat";
                ui->textEdit->append(m2);

                for (int j=0;j<A[i].get_vahed().size();j++)
                {
                    if(A[i].get_vahed()[j].get_sell_maskan()==0)
                    {
                        int y=j+1;
                        QString q=QString::number(y);
                        QString k1,k2,k3,k4;
                        k1=QString::number(A[i].get_vahed()[j].get_floors_number());
                        k2=QString::number(A[i].get_vahed()[j].get_room_number());
                        k3=QString::number(A[i].get_vahed()[j].get_home_area());
                        k4=QString::number(A[i].get_vahed()[j].get_price(A[i].get_asansor(),A[i].get_value_of_per_square()));

                        QString f2="\t \t"+k1+"\t\t"+k2+"\t\t"+k3+"\t\t"+k4;
                        ui->textEdit->append("\t\t"+q+f2);
                    }
                }
            }
        }

        aparteman_file.close();
        A1=A;
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

        QString m1,m2;


        for(int i=0;i<A.size();i++)
        {
           if(A[i].get_sell_maskan()==0 && A[i].get_parvande()==2)
           {
               m1="index aparteman \t asansor  \t\t address";
               ui->textEdit->append(m1);

               int x=i+1;
               QString l=QString::number(x);

               QString f1=QString::number(A[i].get_asansor())+"\t\t"+A[i].get_adress();
               ui->textEdit->append(l+"\t\t"+f1);

               string name;
               name=A[i].get_id().toStdString();

               ifstream myfile;
               myfile.open(name+".txt",ios::in);
               QVector <apartmant_home> AH;

               while (myfile.eof()==false)
               {
                   string h1,h2,h3,h4,h5;
                   QString n1,n2,n3,n4,n5;

                   myfile>>h1>>h2>>h3>>h4>>h5;

                   n1=QString::fromStdString(h1);
                   n2=QString::fromStdString(h2);
                   n3=QString::fromStdString(h3);
                   n4=QString::fromStdString(h4);
                   n5=QString::fromStdString(h5);

                   apartmant_home ah;

                   ah.set_floors_number(n1.toInt());
                   ah.set_room_number(n2.toInt());
                   ah.set_home_area(n3.toInt());
                   ah.set_request(n4.toInt());
                   ah.set_sell_maskan(n5.toInt());

                   if(n4.toInt()==1)
                   {
                       string gg;
                       myfile>>gg;
                       QString jj;
                       jj=QString::fromStdString(gg);
                       ah.set_buyer(jj);
                   }
                   AH.push_back(ah);
               }
               AH.pop_back();
               A[i].set_apartmant_home(AH);
               myfile.close();

                m2="\t \t index vahed \t shomare tabaghe \t tedad otagh \t masahat vahed \t gheymat ejare";
                ui->textEdit->append(m2);

                for (int j=0;j<A[i].get_vahed().size();j++)
                {
                    if(A[i].get_vahed()[j].get_sell_maskan()==0)
                    {
                        int y=j+1;
                        QString q=QString::number(y);
                        QString k1,k2,k3,k4;
                        k1=QString::number(A[i].get_vahed()[j].get_floors_number());
                        k2=QString::number(A[i].get_vahed()[j].get_room_number());
                        k3=QString::number(A[i].get_vahed()[j].get_home_area());
                        k4=QString::number(A[i].get_vahed()[j].get_price(A[i].get_asansor(),A[i].get_value_of_per_square()));

                        QString f2="\t \t"+k1+"\t\t"+k2+"\t\t"+k3+"\t\t"+k4;
                        ui->textEdit->append("\t\t"+q+f2);
                    }
                }

            }
        }

        aparteman_file.close();
        A1=A;
    }
}




void request_maskan::on_pushButton_2_clicked()
{
    user_page *p=new user_page();
    close();
    p->show();
}






