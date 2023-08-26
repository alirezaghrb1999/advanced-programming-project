#include "apartmant.h"

apartmant::apartmant()
{

}

void apartmant::set_is_asansor(int a)
{
    is_asansor=a;

}

void apartmant::set_number_of_floors(int nof)
{
    number_of_floors=nof;

}

void apartmant::set_apartmant_home(QVector<apartmant_home> &h)
{
    home=h;
}

QVector<apartmant_home> &apartmant::get_vahed()
{
    return home;
}

void apartmant::set_id(QString i)
{
    id=i;
}

QString apartmant::get_id()
{
    return id;
}

int apartmant::get_asansor()
{
    return is_asansor;
}

int apartmant::get_number_of_floor()
{
    return number_of_floors;
}

long long apartmant::get_all_cost()
{



    return all_cost_of_build;
}





