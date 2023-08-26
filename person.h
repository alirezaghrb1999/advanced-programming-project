#ifndef PERSON_H
#define PERSON_H
#include<QString>


class person
{
protected:
    QString name;
    QString last_name;
    QString date;
    int position_of_person;
    QString username;
    QString password;
    long long int stock;

public:
    person();
    void set_name(QString n);
    void set_lastname(QString ln);
    void set_date(QString D);
    void set_position_of_person(int Po);
    void set_username(QString User);
    void set_password(QString Pa);
    void set_stock(long long int st);
    QString get_name();
    QString get_lastname();
    QString & get_date();
    int get_position_of_person();
    QString get_username();
    QString get_password();
    long long int get_stock();
};


#endif // PERSON_H
