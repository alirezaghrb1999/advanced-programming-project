#pragma once
#include <parvandeh.h>

class ejare :public parvandeh
{
    QString rahn;
    QString cost_of_rent;
    int time_of_rent;
    long int final_ejare;
public:
    ejare();
    void setrahn(QString r);
    void set_cost_rent(QString cr);
    void set_time_rent(int tr);
    QString get_reahn();
    QString get_cost_rent();
    int get_time_rent();
    int get_final_ejare(long long building_cost);
};




