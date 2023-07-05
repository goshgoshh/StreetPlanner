#include "map.h"
#include "street.h"
#include "city.h"

Map::Map()
{

}
Map::~Map()
{

}
void Map::addCity(City* stadt)
{
    staedte_Liste.append(stadt);
    qDebug() << stadt->getName() << "wurde in die Karte hinzugefügt.";
}
City* Map::findCity(const QString cityName) const
{
    for(QVector<City*>::const_iterator it = staedte_Liste.begin(); it != staedte_Liste.end(); it++)
    {
        if ((*it)->getName() == cityName)
        {
            return *it;
        }
    }

    return nullptr;
}
QVector<street*> Map::getStreetList(const City* city) const
{
    QVector <street*> CityStreetList;
    for(QVector<street*>::const_iterator it = strassen_Liste.begin(); it != strassen_Liste.end(); it++)
    {
        if(city == (*it)->getStadt1() || city == (*it)->getStadt2())
        {
            CityStreetList.append(*it);
        }
    }

    return CityStreetList;
}
QVector<City*> Map::getCityList()
{
    return staedte_Liste;
}

City* Map::getOppositeCity(const street* street1, const City* city) const
{
    if (city == street1->getStadt1())
    {
        return street1->getStadt2();
    }

    else if (city == street1->getStadt2())
    {
        return street1->getStadt1();
    }

    else
    {
        return nullptr;
    }
}

double Map::getLength(const street* street1) const
{
    double x1 = street1->getStadt1()->getX();
    double x2 = street1->getStadt2()->getX();
    double y1 = street1->getStadt1()->getY();
    double y2 = street1->getStadt2()->getY();

    double x_laenge = abs(x2 - x1);
    double y_laenge = abs(y2 - y1);

    double length = sqrt(x_laenge*x_laenge + y_laenge*y_laenge);

    return length;
}
void Map::draw(QGraphicsScene &scene)
{
    for(QVector<City*>::iterator it = staedte_Liste.begin(); it != staedte_Liste.end(); it++)
    {
        QPen Pen;
        QString stadt = (*it)->getName();
        int x = (*it)->getX();
        int y = (*it)->getY();
        Pen.setColor(Qt::red);
        Pen.setWidth(2);
        scene.addEllipse(x, y, 12, 12, Pen, QBrush(Qt::yellow, Qt::SolidPattern));

        QGraphicsTextItem* text = new QGraphicsTextItem;
        text->setPos(x, y);
        text->setPlainText(stadt);
        scene.addItem(text);
    }
}
bool Map::addstreet(street* strasse)
{
    City* gorad1 = strasse->getStadt1();
    City* gorad2 = strasse->getStadt2();

    if (findCity(gorad1->getName()) != nullptr && findCity(gorad2->getName()) != nullptr)
    {
        strassen_Liste.append(strasse);
        return true;
    }

    else
    {
        return false;
    }
}

