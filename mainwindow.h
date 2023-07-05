#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "mapio.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_Test_draw_city_clicked();

    void on_test_Map_clicked();

    void on_test_street_clicked();

    void on_addStreet_clicked();

    void on_addcity_clicked();

    void on_checkBox_clicked();

    void on_FillMap_clicked();

    void on_TestAbsMap_clicked();

    void on_testDij_clicked();

    void on_FindShortestPath_clicked();

    //void on_amr_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    void updateCombo();
    MapIo* mapio;
};
#endif // MAINWINDOW_H
