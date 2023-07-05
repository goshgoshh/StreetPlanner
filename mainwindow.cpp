#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QRandomGenerator>
#include <QMessageBox>
#include "city.h"
#include "map.h"
#include "street.h"
#include "dialog.h"
//#include "./ui_dialog.h"
#include "mapio.h"
#include"mapionrw.h"
#include "dijkstra.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    mapio = new MapIoNrw;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_teste_was_clicked()
{
    //beytala3 message fel console
    //beytala3 e; text el given fel search box
    QString str ="hi u are testing";
    qDebug()<<str;
    qDebug() << QString("LineEdit-Content: %1").arg(ui->lineEdit_teste_was->text());
    //law el user da5al rakam fa haye3mello +4
    bool ok = false;

    int val = ui->lineEdit_teste_was->text().toInt(&ok);
    //checks if it is a number or not
    if(ok)
    {
        val += 4;
        qDebug() << QString("Die Zahl um 4 erhöht: %1").arg(val);
    }
    // bey generate a random box to be added to the map
    // el numbers genrated between 0 and 9
    int pos_x = QRandomGenerator::global()->bounded(10);
    int pos_y = QRandomGenerator::global()->bounded(10);
    //bye3mel add lel moraba3
    scene.addRect(pos_x, pos_y, 10, 10);

    ui->graphicsView->show();

}


void MainWindow::on_actionExit_triggered()
{
    //option +e bye2fel el app
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    //clear scene
    // bey erase el map
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    //streetplanner
    // bye3mel messageBox feeh info 3an el app
    QMessageBox::about(this, "About", "Hi, das ist Praktikum Info 1");
}


void MainWindow::on_Test_draw_city_clicked()
{
    //bne3mel 2 cities el awal
    City stadt1 = City("Dortmund", 100, 100);
    City stadt2 = City("Aachen", 50, 150);
    //then we draw the city on the map
    stadt1.draw(scene);
    stadt2.draw(scene);
}


void MainWindow::on_test_Map_clicked()
{
    //also bne3mel 2 cities
    City Kairo("Kairo", 100, 100);
    City Aachen("Aachen", 50, 150);
    //ben add them le map vector (zay el student, gowah matr
    map.addCity(&Kairo);
    map.addCity(&Aachen);
    // then we draw them
    Kairo.draw(scene);
    Aachen.draw(scene);
    //then we update el combobox
    updateCombo();
}


void MainWindow::on_test_street_clicked()
{
    //also bne3mel 2 cities
    City Kairo("Kairo", 0, 0);
    City Aachen("Aachen", 20, 50);
    //hena bene3mel benhom street
    street street1(&Kairo, &Aachen);
     //ben add them le map vector (zay el student, gowah matr
    map.addCity(&Kairo);
    map.addCity(&Aachen);
    //then we drwa them
    Kairo.draw(scene);
    Aachen.draw(scene);
    //then we draw the dteet
    street1.draw(scene);
    //update combobox
    updateCombo();

}


void MainWindow::on_addStreet_clicked()
{
    Dialog dialog;
    int i = dialog.exec();
    qDebug() << "Der Rückgabewert: " << i;


    if (i == 1)
    {
        QString Name1 = dialog.getgorad1Name();
        QString Name2 = dialog.getgorad2Name();

        if(map.findCity(Name1) == nullptr || map.findCity(Name2) == nullptr)
        {
            qDebug() << "please enter valid cities!";
            return;
        }

        City* gorad1 = map.findCity(Name1);
        City* gorad2 = map.findCity(Name2);

        street* strasse = new street(gorad1, gorad2);
        //qDebug() << "street adition succedded!";
        if(map.addstreet(strasse))
        {
            //qDebug() << "Street has been found";
            strasse->draw(scene);
        }
    }

    else
    {
        qDebug() << "No new street has been added!";
    }

}


void MainWindow::on_addcity_clicked()
{
    Dialog dialog;
    int i = dialog.exec();
    qDebug() << "Der Rückgabewert: " << i;

        if (i == 1)
    {
        City* gorad = dialog.neueStadt();
        map.addCity(gorad);
        gorad->draw(scene);
    }

    else
    {
        qDebug() << "No new city has been added!";
    }
    updateCombo();

}


void MainWindow::on_checkBox_clicked()
{
    if (ui->checkBox->isChecked()==true)
    {
        ui->test_street->hide();
        ui->test_Map->hide();
        ui->Test_draw_city->hide();
    }

    else if(ui->checkBox->isChecked()==false)
    {
        ui->test_street->show();
        ui->test_Map->show();
        ui->Test_draw_city->show();
    }


}


void MainWindow::on_FillMap_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
    updateCombo();
}


void MainWindow::on_TestAbsMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    street *s = new street(a, b);
    street *s2 = new street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addstreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addstreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addstreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<street*> streetList1 = testMap.getStreetList(a);
        QVector<street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";

}


void MainWindow::on_testDij_clicked()
{
    Map testMap;

    City *start = new City("start", 0, 0);
    City *transit = new City("transit", 50, 50);
    City *target = new City("target", 0, 100);
    testMap.addCity(start);
    testMap.addCity(transit);
    testMap.addCity(target);

    street *testStreet1 = new street(start, transit);
    street *testStreet2 = new street(transit, target);
    testMap.addstreet(testStreet1);
    testMap.addstreet(testStreet2);

    testMap.draw(scene);

    QVector<street*> shortest_path = Dijkstra::search(testMap, start->getName(), target->getName());

    for(auto it = shortest_path.begin(); it != shortest_path.end(); it++)
    {
        (*it)->strassen_id();
    }

    for(auto it = shortest_path.begin(); it != shortest_path.end(); it++)
    {
        (*it)->drawRed(scene);
    }

}
void MainWindow::updateCombo()
{
    QVector<City*> temp = map.getCityList();

    ui->comboBox->clear();
    ui->comboBox_2->clear();

    for(auto it = temp.begin(); it != temp.end(); it++)
    {
        ui->comboBox->addItem((*it)->getName());
        ui->comboBox_2->addItem((*it)->getName());
    }
}




void MainWindow::on_FindShortestPath_clicked()
{
        QString start = ui->comboBox->currentText();
        QString target = ui->comboBox_2->currentText();

        if (start == target)
        {
            qDebug() << "please enter a valid destination";
            return;
        }


        QVector<street*> shortest_path = Dijkstra::search(map, start, target);

        for(auto it = shortest_path.begin(); it != shortest_path.end(); it++)
        {
            (*it)->strassen_id();
        }

        for(auto it = shortest_path.begin(); it != shortest_path.end(); it++)
        {
            (*it)->drawRed(scene);
        }
    }



