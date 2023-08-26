#pragma once
#include"maskan.h"
#include"apartmant_home.h"
#include<QVector>
#include <foroosh.h>
#include <ejare.h>


class apartmant :public maskan
{
    int is_asansor;
    int number_of_floors;
    QVector<apartmant_home> home;
    QString id;
public:
    apartmant();
    void set_is_asansor(int a);
    void set_number_of_floors(int nof);
    void set_apartmant_home(QVector<apartmant_home> &h);
    QVector<apartmant_home>& get_vahed();
    void set_id(QString i);
    QString get_id();
    int get_asansor();
    int get_number_of_floor();
    long long int get_all_cost();
};


