#include "signup.h"
#include "ui_signup.h"

singup::singup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::singup)
{
    ui->setupUi(this);
}

singup::~singup()
{
    delete ui;
}

void singup::on_pushButton_3_clicked()
{
    MainWindow *o=new MainWindow();
    close();
    o->show();
}

void singup::on_pushButton_1_clicked()
{
    modirregister *o=new modirregister();
    close();
    o->show();
}

void singup::on_pushButton_2_clicked()
{
    userregister *o=new userregister;
    close();
    o->show();
}


