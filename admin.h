#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include <apartmant.h>
#include <north_vila.h>
#include <south_vila.h>
#include <QVector>
#include <foroosh.h>
#include <ejare.h>

class admin: public person
{
private:
    QVector <apartmant> APARTEMAN;
    QVector <north_vila> NORTH_VILA;
    QVector <south_vila> SOUTH_VILA;

    QVector <foroosh> FOROOSH;
    QVector <ejare> EJARE;

public:
    admin();
    void insert_aparteman(apartmant A);
    void insert_north(north_vila N);
    void insert_south(south_vila S);
    void insert_foroosh(foroosh F);
    void insert_ejare(ejare E);

    QVector <apartmant>& get_aparteman();
    QVector <north_vila>& get_north();
    QVector <south_vila>& get_south();
    QVector <foroosh>& get_foroosh();
    QVector <ejare>& get_ejare();
};


#endif // ADMIN_H


