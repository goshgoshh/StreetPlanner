#include "city.h"
#include <QGraphicsScene>
#include <QPen>
#include <QBrush>
City::City(QString name, int x, int y): name(name), x(x), y(y)
{

}
City::~City()
{
}

void City::draw(QGraphicsScene &scene) const
{
    // Draw the dot
    //scene.addEllipse(x - 4, y - 4, 2 * 4, 2 * 4, QPen(COLOR), QBrush(COLOR));
    QPen Pen;
    QString Stadt = this->name;
    Pen.setColor(Qt::red);
    Pen.setWidth(2);
    scene.addEllipse(x-6, y-6, 12, 12, Pen, QBrush(Qt::yellow, Qt::SolidPattern));

    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setPos(x, y);
    text->setPlainText(Stadt);
    scene.addItem(text);
}
QString City::getName()
{
    return name;
}

int City::getX()
{
    return x;
}

int City::getY()
{
    return y;
}
