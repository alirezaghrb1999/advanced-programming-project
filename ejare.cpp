#include "ejare.h"

ejare::ejare()
{

}

void ejare::setrahn(QString r)
{
    rahn=r;
}

void ejare::set_cost_rent(QString cr)
{
    cost_of_rent=cr;
}

void ejare::set_time_rent(int tr)
{
    time_of_rent=tr;
}

QString ejare::get_reahn()
{
    return rahn;
}

QString ejare::get_cost_rent()
{
    return cost_of_rent;
}

int ejare::get_time_rent()
{
    return time_of_rent;
}

int ejare::get_final_ejare(long long int building_cost)
{
    rahn=QString::number((building_cost*5));
    cost_of_rent=QString::number(building_cost);

    final_ejare=cost_of_rent.toInt()*time_of_rent+rahn.toInt()+comision*rahn.toInt();
    return final_ejare;
}




