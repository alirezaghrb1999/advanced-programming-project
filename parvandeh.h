#pragma once
#include <QString>

class parvandeh
{
protected:
    QString type_of_building;
    QString building_id;
    int comision=25;
    int final_price;
public:
    parvandeh();
    void set_type_building(QString tb);
    void set_building_id(QString bi);
    void set_comision(int c);
    void set_final_price(int fp);
    QString get_type_building();
    QString get_building_id();
    int get_comision();
    int get_final_price(long long building_cost);
};




