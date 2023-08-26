#ifndef MASKAN_H
#define MASKAN_H

#include<QString>
#include <foroosh.h>
#include <ejare.h>


class maskan
{
protected:
    QString masahat_kol;
    long long int value_of_per_square;
    QString ADDRESS;
    long long int all_cost_of_build;
    QString admin_name;
    int parvandeh;
    foroosh FOROOSH;
    ejare EJARE;
    int sell_maskan=0;
    int request=0;
    QString buyer_username;
public:
    maskan();
    void set_masahat_kol(QString mk);
    void set_value_of_per_square(long long int vops);
    void set_adress(QString c);
    void set_all_costs(long long int cob);
    QString get_masahat_kol();
    long long int get_value_of_per_square();
    QString get_adress();
    virtual long long int get_all_cost()=0;
    void set_admin_name(QString a);
    QString get_admin_name();
    void set_parvande(int p);
    int get_parvande();
    void set_ejare(ejare x);
    ejare& get_ejare();
    foroosh& get_foroosh();
    void set_foroosh(foroosh);

    void set_sell_maskan(int x);
    int get_sell_maskan();

    void set_request(int x);
    int get_request();

    void set_buyer(QString s);
    QString get_buyer();
};


#endif



