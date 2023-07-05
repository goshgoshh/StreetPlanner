#include "dialog.h"
#include "ui_dialog.h"
#include "map.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

City* Dialog::neueStadt()
{
    gorad = ui->StadtName->text();
    qDebug() << gorad;
    bool ok;

    x_koordinate = ui->xKoordinate->text().toInt(&ok);

    if (ok == false)
    {
        qDebug() << "please inter a valid integer!";
    }
    qDebug() << x_koordinate;

    y_koordinate = ui->yKoordinate->text().toInt(&ok);
    if (ok == false)
    {
        qDebug() << "please inter a valid integer!";
    }
    qDebug() << y_koordinate;

    return  new City(gorad, x_koordinate, y_koordinate);
}

QString Dialog::getgorad1Name()
{
    gorad1Name = ui->stadt1->text();

    return gorad1Name;
}

QString Dialog::getgorad2Name()
{
    gorad2Name = ui->stadt2->text();

    return gorad2Name;
}
