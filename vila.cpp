#include "vila.h"

Vila::Vila()
{

}

void Vila::set_masahat_sakht(QString msakht)
{
    masahat_sakht=msakht;
}

void Vila::set_number_of_rooms(int number_room)
{
    number_of_rooms=number_room;
}

void Vila::set_image_of_vila(QImage imagee)
{
    imag=imagee;
}

QString Vila::get_masahat_sakht()
{
 return masahat_sakht;
}

int Vila::get_number_of_rooms()
{
    return  number_of_rooms;
}

QImage Vila::get_image_vila()
{
    return imag;
}

