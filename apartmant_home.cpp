#include "apartmant_home.h"

apartmant_home::apartmant_home()
{

}

void apartmant_home::set_floors_number(int fn)
{
    floors_number=fn;
}

int apartmant_home::get_floors_number()
{
    return floors_number;
}

void apartmant_home::set_home_area(int hm)
{
    home_area=hm;
}

int apartmant_home::get_home_area()
{
    return home_area;
}

void apartmant_home::set_room_number(int nr)
{
    number_of_room=nr;
}

int apartmant_home::get_room_number()
{
    return number_of_room;
}

int apartmant_home::get_price(int elevator,long long int gheymat_paye)
{
    int y=0;
    if(elevator==1)
    {
        y=1;
    }

    price=home_area*gheymat_paye+(floors_number*5)/100+(number_of_room*8)/100+(y*2)/100;

    return price;
}

void apartmant_home::set_sell_maskan(int sel)
{
    sell_maskan=sel;
}

int apartmant_home::get_sell_maskan()
{
    return  sell_maskan;
}

void apartmant_home::set_request(int r)
{
    request=r;
}

int apartmant_home::get_request()
{
    return request;
}

void apartmant_home::set_buyer(QString s)
{
    buyer_username=s;
}

QString apartmant_home::get_buyer()
{
    return buyer_username;
}


