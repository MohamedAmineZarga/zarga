#include "menu.h"
#include "ui_menu.h"
#include <QPropertyAnimation>
#include <QStateMachine>
#include <QSignalTransition>
#include "gestiondessalles.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{QEasingCurve curve;
    ui->setupUi(this);
    animation = new QPropertyAnimation(ui->widget,"geometry");
    animation->setDuration(1000);
    animation->setStartValue(ui->widget->geometry());
    animation->setEndValue(QRect(90,50,571,581));
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    animation->setLoopCount(1);
    animation->start();
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButtongr_clicked()
{   gr = new gestiondereservation(this);
    gr->show();
}

void menu::on_pushButtongsalles_clicked()
{
    gs = new gestiondessalles(this);
    gs -> show();

}
