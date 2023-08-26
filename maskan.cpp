#include "maskan.h"

maskan::maskan()
{

}

void maskan::set_masahat_kol(QString mk)
{
    masahat_kol=mk;
}

void maskan::set_value_of_per_square(long long vops)
{
    value_of_per_square=vops;
}

void maskan::set_adress(QString c)
{
    ADDRESS=c;
}


void maskan::set_all_costs(long long cob)
{
    all_cost_of_build=cob;
}

QString maskan::get_masahat_kol()
{
    return masahat_kol;
}


long long int maskan::get_value_of_per_square()
{
    return value_of_per_square;
}

QString maskan::get_adress()
{
    return ADDRESS;
}

void maskan::set_admin_name(QString a)
{
    admin_name=a;
}

QString maskan::get_admin_name()
{
    return admin_name;
}

void maskan::set_parvande(int p)
{
    parvandeh=p;
}

int maskan::get_parvande()
{
    return parvandeh;
}


void maskan::set_ejare(ejare x)
{
    EJARE=x;
}

void maskan::set_foroosh(foroosh x)
{
    FOROOSH=x;
}

void maskan::set_sell_maskan(int x)
{
    sell_maskan=x;
}

int maskan::get_sell_maskan()
{
    return sell_maskan;
}

void maskan::set_request(int x)
{
    request=x;
}

int maskan::get_request()
{
    return request;
}

void maskan::set_buyer(QString s)
{
    buyer_username=s;
}

QString maskan::get_buyer()
{
    return buyer_username;
}

foroosh& maskan::get_foroosh()
{
    return FOROOSH;
}

ejare& maskan::get_ejare()
{
    return EJARE;
}





