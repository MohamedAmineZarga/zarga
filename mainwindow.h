#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menu.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QtDebug>
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
    void on_identifier_clicked();

private:
    Ui::MainWindow *ui;
    menu *Menu;
    QMediaPlayer *playmusic;
    QPropertyAnimation *animation,*animationimg;
};
#endif // MAINWINDOW_H
