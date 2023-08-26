#ifndef USER_H
#define USER_H
#include <person.h>
#include <ejare.h>
#include <foroosh.h>
#include <QVector>


class user:public person
{
private:
    QVector <ejare> Ejare;
    QVector <foroosh> Foroosh;
public:
    user();
    void insert_ejare(ejare E);
    void insert_foroosh(foroosh F);
     QVector <ejare>& get_ejare();
     QVector <foroosh>& get_foroosh();
};

#endif // USER_H
