#include "south_vila.h"

south_vila::south_vila()
{

}

void south_vila::set_area_of_yard(QString areay)
{
    area_of_yard=areay;
}

void south_vila::set_area_of_parking(QString park)
{
    area_of_parking=park;
}

QString south_vila::get_area_of_yard()
{
    return area_of_yard;
}

QString south_vila::get_area_of_parking()
{
    return area_of_parking;
}

long long south_vila::get_all_cost()
{
    all_cost_of_build=value_of_per_square*masahat_sakht.toInt()+(value_of_per_square*area_of_yard.toInt()*3)/10+
                                (value_of_per_square*area_of_parking.toInt()*15)/100;

    return all_cost_of_build;
}








