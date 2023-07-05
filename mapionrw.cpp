#include "mapionrw.h"

MapIoNrw::MapIoNrw()
{
}

MapIoNrw::~MapIoNrw()
{
}

void MapIoNrw::fillMap(AbstractMap &map)
{
    City* aachen = new City("Aachen", -100, 100);
    City* bonn = new City("Bonn", 0,200);
    City* koeln = new City("Köln", 0,0);
    City* duesseldorf = new City("Düsseldorf", 50,-100);

    street* aachenKoeln = new street(aachen, koeln);
    street* bonnKoeln = new street(bonn, koeln);
    street* ddorfKoeln = new street(duesseldorf, koeln);

    map.addCity(aachen);
    map.addCity(bonn);
    map.addCity(koeln);
    map.addCity(duesseldorf);

    map.addstreet(aachenKoeln);
    map.addstreet(bonnKoeln);
    map.addstreet(ddorfKoeln);
}
