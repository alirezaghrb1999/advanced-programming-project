#include "person.h"

person::person()
{

}

void person::set_name(QString n)
{
    name=n;
}

void person::set_lastname(QString ln)
{
    last_name=ln;
}

void person::set_date(QString D)
{
    date=D;
}

void person::set_position_of_person(int Po)
{
  position_of_person=Po;
}

void person::set_username(QString User)
{
    username=User;
}

void person::set_password(QString Pa)
{
 password=Pa;
}

void person::set_stock(long long st)
{
    stock=st;
}

QString person::get_name()
{
    return name;

}

QString person::get_lastname()
{
    return last_name;
}

QString &person::get_date()
{
    return date;
}

int person::get_position_of_person()
{
    return position_of_person;
}

QString person::get_username()
{
    return username;
}

QString person::get_password()
{
    return password;
}

long long person::get_stock()
{
    return stock;
}


