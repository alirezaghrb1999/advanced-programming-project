#pragma once
#include <parvandeh.h>

class foroosh:public parvandeh
{
    QString selling_sitation;
public:
    foroosh();
    void set_selling_situation(QString ss);
    QString get_selling_situation();
};


