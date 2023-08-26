#include "user_page.h"
#include "ui_user_page.h"
#include <request_maskan.h>
#include <my_maskan.h>
#include <search_maskan.h>

user_page::user_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::user_page)
{
    ui->setupUi(this);
}

user_page::~user_page()
{
    delete ui;
}

void user_page::on_pushButton_2_clicked()
{
    request_maskan *obj=new request_maskan();
    close();
    obj->show();
}


void user_page::on_pushButton_1_clicked()
{
    close();
}



void user_page::on_pushButton_4_clicked()
{
    my_maskan *o=new my_maskan();
    close();
    o->show();
}

void user_page::on_pushButton_3_clicked()
{
    search_maskan *o=new search_maskan();
    close();
    o->show();
}





