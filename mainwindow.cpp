#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_clicked()
{
    singup *o=new singup();
    this->close();
    o->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    signin *o=new signin();
    this->close();
    o->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}
