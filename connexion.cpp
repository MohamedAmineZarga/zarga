#include "connexion.h"
#include <QMessageBox>
connexion::connexion()
{

}
bool connexion::ouvrirconnexion()
{bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("zarga_projet2A");
    db.setUserName("zarga");
    db.setPassword("zarga2020");

  if(db.open())
  {
      test=true;
  }
  return test;

}

void connexion::fermerconnexion()
{
    db.close();
}
