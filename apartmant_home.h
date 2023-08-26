#ifndef APARTMANT_HOME_H
#define APARTMANT_HOME_H
#include"maskan.h"



class apartmant_home
{
    int floors_number;
    int home_area;
    int number_of_room;
    int price;
    int sell_maskan=0;
    int request=0;
    QString buyer_username;
public:
    apartmant_home();
    void set_floors_number(int fn);
    int get_floors_number();
    void set_home_area(int hm);
    int get_home_area();
    void set_room_number(int nr);
    int get_room_number();
    int get_price(int elevator, long long gheymat_paye);
    void set_sell_maskan(int sel);
    int get_sell_maskan();
    void set_request(int r);
    int get_request();

    void set_buyer(QString s);
    QString get_buyer();
};



#endif // APARTMANT_HOME_H
