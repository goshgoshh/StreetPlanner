#ifndef MAP_H
#define MAP_H

#include "city.h"
#include <QDebug>
#include <QVector>
#include "abstractmap.h"
#include "street.h"
class Map: public AbstractMap
{
public:
    Map();
    ~Map();
    void addCity(City*);
    bool addstreet(street*);
    void draw(QGraphicsScene &scene);
    City* findCity(const QString gorad) const;
    QVector<street*> getStreetList(const City* city) const;
    QVector<City*> getCityList();
    City* getOppositeCity(const street* street, const City* city) const;
    double getLength(const street* street) const;
private:
     QVector <City*> staedte_Liste;
     QVector <street*> strassen_Liste;


};

#endif // MAP_H
