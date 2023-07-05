#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "city.h"
#include "street.h"
#include "abstractmap.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    City* neueStadt();
    QString getgorad1Name();
    QString getgorad2Name();


private:
    Ui::Dialog *ui;
    QString gorad;
    QString strasse;
    QString gorad1Name;
    QString gorad2Name;
    int x_koordinate;
    int y_koordinate;
};

#endif // DIALOG_H
