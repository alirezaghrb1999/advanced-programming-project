#include "admin_page.h"
#include "ui_admin_page.h"
#include <insert_maskan.h>
#include <observe_edit_maskan.h>
#include <fstream>
#include <parvande_page.h>
#include<accept_page.h>
using namespace std;

admin_page::admin_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_page)
{
    ui->setupUi(this);
    ifstream current_admin;
    current_admin.open("current_admin.txt",ios::in);
    string l;
    current_admin>>l;
    USERNAME=QString::fromStdString(l);
}

admin_page::~admin_page()
{
    delete ui;
}

void admin_page::on_pushButton_6_clicked()
{
    close();
}

void admin_page::on_pushButton_2_clicked()
{
    insert_maskan *obj=new insert_maskan();
    close();
    obj->show();
}



void admin_page::on_pushButton_1_clicked()
{
    observe_edit_maskan *o=new observe_edit_maskan();
    connect(this,SIGNAL(send(QString)),o,SLOT(get(QString)));
    emit send(USERNAME);
    close();
    o->show();
}

void admin_page::get_username(QString x)
{
    USERNAME=x;
}



void admin_page::on_pushButton_5_clicked()
{
    close();
}

void admin_page::on_pushButton_3_clicked()
{
    parvande_page *o=new parvande_page();
    close();
    o->show();
}




void admin_page::on_pushButton_4_clicked()
{
    accept_page *o=new accept_page();
    close();
    o->show();
}







