#include "north_vila.h"

north_vila::north_vila()
{

}

void north_vila::set_area_of_back_yard(QString arbackyard)
{
    area_of_back_yard=arbackyard;
}

void north_vila::set_area_of_front_yard(QString arfrontyard)
{
    area_of_front_yard=arfrontyard;
}

QString north_vila::get_area_of_back_yard()
{
    return area_of_back_yard;
}

QString north_vila::get_area_of_front_yard()
{
    return area_of_front_yard;
}

long long north_vila::get_all_cost()
{
    all_cost_of_build=value_of_per_square*masahat_sakht.toInt()+(value_of_per_square*area_of_front_yard.toInt()*3)/10+
                                (value_of_per_square*area_of_back_yard.toInt()*15)/100;


    return all_cost_of_build;
}


