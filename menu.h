#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "gestiondereservation.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QtDebug>
#include "gestiondessalles.h"
namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButtongr_clicked();

    void on_pushButtongsalles_clicked();

private:
    Ui::menu *ui;
    gestiondereservation *gr;
    gestiondessalles *gs;
    QPropertyAnimation *animation;
};

#endif // MENU_H
