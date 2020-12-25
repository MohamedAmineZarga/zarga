#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadmin.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QStateMachine>
#include <QSignalTransition>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   QEasingCurve curve,curve1;
    ui->setupUi(this);

    //playmusic = new QMediaPlayer(this);
    playmusic = new QMediaPlayer;
    connect(playmusic, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    playmusic->setMedia(QUrl::fromLocalFile("/Users/Firas CHKOUNDALI/Documents/projet/welcome.mp3"));
    playmusic->setVolume(50);
    playmusic->play();
    animation = new QPropertyAnimation(ui->identifier,"geometry");
    animationimg = new QPropertyAnimation(ui->widget,"geometry");
    animation->setDuration(1000);
    animationimg->setDuration(1000);
    animation->setStartValue(ui->identifier->geometry());
    animationimg->setStartValue(ui->widget->geometry());
    animation->setEndValue(QRect(300,310,131,31));
    animationimg->setEndValue(QRect(20,110,711,351));
    curve.setType(QEasingCurve::OutBounce);
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    animationimg->setEasingCurve(curve1);
    animation->setLoopCount(3);
    animationimg->setLoopCount(1);
    animation->start();
    animationimg->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_identifier_clicked()
{   cadmin c;
    c.SetPassword(ui->Pass->text());
    c.SetUsername(ui->User->text());

    //QMediaPlayer * connected = new QMediaPlayer();
    //QMediaPlayer * failed = new QMediaPlayer();

    if(c.authentification()==1)
          {
             //connected->setMedia(QUrl("qrc:/sounds/img/connected.mp3"));
             //connected->play();
             QMessageBox::information(this,"identifier","nom d'utilisateur et mot de passe sont correct");


            Menu = new menu(this);
        Menu->show();

       }

       else if(c.authentification()<1)
        {
       //failed->setMedia(QUrl("qrc:/sounds/img/failed.mp3"));
        // failed->play();
            QMessageBox::information(this,"identifier","nom d'utilisateur et mot de passe ne sont pas correct");


        }
}
