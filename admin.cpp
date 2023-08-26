#include "admin.h"

admin::admin()
{

}

void admin::insert_aparteman(apartmant A)
{
    APARTEMAN.push_back(A);
}

void admin::insert_north(north_vila N)
{
    NORTH_VILA.push_back(N);
}

void admin::insert_south(south_vila S)
{
    SOUTH_VILA.push_back(S);
}

void admin::insert_foroosh(foroosh F)
{
    FOROOSH.push_back(F);
}

void admin::insert_ejare(ejare E)
{
    EJARE.push_back(E);
}

QVector<apartmant> &admin::get_aparteman()
{
    return APARTEMAN;
}

QVector<north_vila> &admin::get_north()
{
    return NORTH_VILA;
}

QVector<south_vila> &admin::get_south()
{
    return SOUTH_VILA;
}

QVector<foroosh> &admin::get_foroosh()
{
    return FOROOSH;
}

QVector<ejare> &admin::get_ejare()
{
    return EJARE;
}



