#pragma once
#include"vila.h"
#include <foroosh.h>
#include <ejare.h>

class north_vila:public Vila
{
    QString area_of_back_yard;
    QString area_of_front_yard;

public:
    north_vila();
    void set_area_of_back_yard(QString arbackyard);
    void set_area_of_front_yard(QString arfrontyard);
    QString get_area_of_back_yard();
    QString get_area_of_front_yard();
    long long int get_all_cost();
};




