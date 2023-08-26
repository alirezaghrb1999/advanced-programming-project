#ifndef VILA_H
#define VILA_H
#include"maskan.h"
#include<QString>
#include<QImage>


class Vila: public maskan
{
protected:
    QString masahat_sakht;
    int number_of_rooms;
    QImage imag;
public:
    Vila();
    void set_masahat_sakht(QString msakht);
    void set_number_of_rooms(int number_room);
    void set_image_of_vila(QImage imag);
    QString get_masahat_sakht();
    int get_number_of_rooms();
    QImage get_image_vila();

};




#endif // VILA_H
