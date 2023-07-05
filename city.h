#ifndef CITY_H
#define CITY_H
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>


class City
{
protected:
    QString name;
    int x;
    int y;
    const QColor COLOR = QColor(255, 0, 0);
public:
    City(QString name, int x, int y);
    ~City();
    void draw(QGraphicsScene &scene) const;
    QString getName();
    int getX();
    int getY();
};

#endif // CITY_H
