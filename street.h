#ifndef STREET_H
#define STREET_H

#include "city.h"
class street
{
public:
    street(City* stadt1, City* stadt2);
    ~street();
    void draw(QGraphicsScene &scene);
    City* getStadt1() const;
    City* getStadt2() const;
    void drawRed(QGraphicsScene &scene);
    void strassen_id();

private:
    City* stadt1;
    City* stadt2;
};

#endif // STREET_H
