#include "mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    bool test=c.ouvrirconnexion();
    if(test)
    {w.show();}
    return a.exec();
}
