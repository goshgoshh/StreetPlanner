#include "street.h"

street::street(City* stadt1, City* stadt2):
    stadt1(stadt1), stadt2(stadt2)
{

}
street::~street()
{

}
void street::draw(QGraphicsScene &scene)
{
    int x1 = (stadt1)->getX();
    int y1 = (stadt1)->getY();
    int x2 = (stadt2)->getX();
    int y2 = (stadt2)->getY();

    QPen Pen;
    Pen.setColor(Qt::blue);
    Pen.setWidth(2);
    scene.addLine(x1, y1, x2, y2, Pen);
}
City* street::getStadt2() const
{
    return stadt2;
}
City* street::getStadt1() const
{
    return stadt1;
}


void street::strassen_id()
{
    qDebug() << "Verbindung zwischen " << stadt1->getName() << " und " << stadt2->getName();
}


void street::drawRed(QGraphicsScene &scene)
{
    int x1 = (stadt1)->getX();
    int y1 = (stadt1)->getY();
    int x2 = (stadt2)->getX();
    int y2 = (stadt2)->getY();

    QPen Pen;
    Pen.setColor(Qt::red);
    Pen.setWidth(3);
    scene.addLine(x1, y1, x2, y2, Pen);
}
