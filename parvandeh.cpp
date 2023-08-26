#include "parvandeh.h"

parvandeh::parvandeh()
{

}

void parvandeh::set_type_building(QString tb)
{
    type_of_building=tb;
}

void parvandeh::set_building_id(QString bi)
{
    building_id=bi;
}

void parvandeh::set_comision(int c)
{
    comision=c;
}

void parvandeh::set_final_price(int fp)
{
    final_price=fp;
}

QString parvandeh::get_type_building()
{
    return type_of_building;
}

QString parvandeh::get_building_id()
{
    return building_id;
}

int parvandeh::get_comision()
{
    return  comision;
}

int parvandeh::get_final_price(long long int building_cost)
{   
    final_price=building_cost+(comision*building_cost);


    return final_price;
}
