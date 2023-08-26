#include "insert_maskan.h"
#include "ui_insert_maskan.h"
#include <vila_shomal_page.h>

#include <admin_page.h>
#include <apartemani_page.h>

insert_maskan::insert_maskan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insert_maskan)
{
    ui->setupUi(this);
}

insert_maskan::~insert_maskan()
{
    delete ui;
}

void insert_maskan::on_pushButton_clicked()
{
    vila_shomal_page *obj=new vila_shomal_page();
    close();
    obj->show();
}

void insert_maskan::on_pushButton_4_clicked()
{
    admin_page *obj=new admin_page();
    close();
    obj->show();
}

void insert_maskan::on_pushButton_2_clicked()
{
    vila_jonoob_page *obj=new vila_jonoob_page();
    close();
    obj->show();
}


void insert_maskan::on_pushButton_3_clicked()
{
    apartemani_page *o=new apartemani_page();
    close();
    o->show();
}


