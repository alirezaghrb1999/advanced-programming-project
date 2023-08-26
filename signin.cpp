#include "signin.h"
#include "ui_signin.h"
#include <fstream>
#include <QMessageBox>
#include <QVector>
#include <admin.h>
#include <user.h>
#include <admin_page.h>
#include <user_page.h>

using namespace std;

signin::signin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_1->setPlaceholderText("نام کاربری خود را وارد کنید");
    ui->lineEdit_2->setPlaceholderText("رمز ورود خود را وارد کنید");
}

signin::~signin()
{
    delete ui;
}

void signin::on_pushButton_1_clicked()
{
    MainWindow *o=new MainWindow();
    close();
    o->show();
}

void signin::on_pushButton_2_clicked()

{
    QString s1,s2;
    s1=ui->lineEdit_1->text();
    s2=ui->lineEdit_2->text();

    if(ui->comboBox->currentIndex()==0)
    {
        ifstream adminfile;
        adminfile.open("adminfile.txt",ios::in);
        QVector <admin> A;
        admin ad;

        string l1,l2,l3,l4,l5;
        long long int x1,x2;
        QString a1,a2,a3,a4,a5;

        while (adminfile.eof()==false)
        {
           adminfile>>l1>>l2>>l3>>x1>>l4>>l5>>x2;
           a1=QString::fromStdString(l1);
           a2=QString::fromStdString(l2);
           a3=QString::fromStdString(l3);
           a4=QString::fromStdString(l4);
           a5=QString::fromStdString(l5);

           ad.set_name(a1);
           ad.set_lastname(a2);
           ad.set_date(a3);
           ad.set_position_of_person(x1);
           ad.set_username(a4);
           ad.set_password(a5);
           ad.set_stock(x2);

           A.push_back(ad);
        }

        int f=0;

        for (int i=0;i<A.size();i++)
        {
            if(s1==A[i].get_username() && s2==A[i].get_password())
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            QMessageBox *M=new QMessageBox();
           M->setIcon(QMessageBox::Warning);
           M->setText("این مدیر وحود ندارد.");
           M->exec();
        }
        if(f==1)
        {
            QMessageBox *m=new QMessageBox();
            m->setIcon(QMessageBox::Information);
            m->setText("شما به عنوان مدیر وارد شدید");
            m->exec();

            A.clear();

            close();
            admin_page *obj=new admin_page();

            ofstream current_admin;
            current_admin.open("current_admin.txt",ios::trunc);
            current_admin<<s1.toStdString()<<"\n";
            current_admin.close();
            obj->show();
        }
    }

    if(ui->comboBox->currentIndex()==1)
    {
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
        int K=0;

        for (int i=0;i<U.size();i++)
        {
            if(s1==U[i].get_username() && s2==U[i].get_password())
            {
                K=1;
                break;
            }
        }

        if(K==0)
        {
            QMessageBox *M=new QMessageBox();
           M->setIcon(QMessageBox::Warning);
           M->setText("این کاربر وحود ندارد.");
           M->exec();
        }
        if(K==1)
        {
            QMessageBox *M=new QMessageBox();
           M->setIcon(QMessageBox::Information);
           M->setText("شما به عنوان کاربر وارد شدید");
           M->exec();


           U.clear();

           user_page *obj=new user_page();

           ofstream current_user;
           current_user.open("current_user.txt",ios::trunc);
           current_user<<s1.toStdString()<<"\n";
           current_user.close();

           close();
           obj->show();

        }
    }

}


