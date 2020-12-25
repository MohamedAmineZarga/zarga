#ifndef CADMIN_H
#define CADMIN_H

#include <QString>
#include <QSqlDatabase>
#include "QSqlQueryModel"
#include "QSqlQuery"

class cadmin
{
public:

      int authentification();
      void SetPassword(QString s){Password=s;}
      void SetUsername(QString u){Username=u;}

private:
    QString Username;
    QString Password;
};

#endif // CADMIN_H
