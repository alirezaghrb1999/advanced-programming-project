#include "user.h"

user::user()
{

}

void user::insert_ejare(ejare E)
{
    Ejare.push_back(E);
}

void user::insert_foroosh(foroosh F)
{
    Foroosh.push_back(F);
}

QVector<ejare> &user::get_ejare()
{
    return Ejare;
}

QVector<foroosh> &user::get_foroosh()
{
    return Foroosh;
}
