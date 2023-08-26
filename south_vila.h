#pragma once

#include"vila.h"
#include <QString>

class south_vila:public Vila
{
    QString area_of_yard;
    QString area_of_parking;   
public:
    south_vila();
    void set_area_of_yard(QString areay);
    void set_area_of_parking(QString park);
    QString get_area_of_yard();
    QString get_area_of_parking();
    long long int get_all_cost();
};





