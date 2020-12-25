#include "salles.h"


salles::salles()
{
    IDSALLE=0;
    NOMSALLE=" ";
    VILLE="";
    ZIP_CODE = 0;
    ADRESSE = "";
    SURFACE = 0;
    CAPACITE = 0;
    TYPESALLE = "";
    FORFAIT = "";
    NOMBRESALLERECEPTION = 0;

}
salles::salles(int IDSALLE , QString NOMSALLE, QString VILLE, int ZIP_CODE, QString ADRESSE, int SURFACE , int CAPACITE , QString TYPESALLE , QString FORFAIT , int NOMBRESALLERECEPTION)
{
    this->IDSALLE = IDSALLE;
    this->NOMSALLE = NOMSALLE;
    this->VILLE = VILLE;
    this->ZIP_CODE = ZIP_CODE;
    this->ADRESSE = ADRESSE  ;
    this->SURFACE = SURFACE;
    this->CAPACITE = CAPACITE;
   this->TYPESALLE = TYPESALLE;
   this->FORFAIT = FORFAIT;
    this->NOMBRESALLERECEPTION = NOMBRESALLERECEPTION;


}


// Ajout des salles


bool salles::ajouter()
{
    QSqlQuery query;
    QString IDSALLE_String = QString::number(IDSALLE);
    QString ZIP_CODE_String = QString::number(ZIP_CODE);
     QString SURFACE_String = QString::number(SURFACE);
      QString CAPACITE_String = QString::number(CAPACITE);
      QString NOMBRESALLERECEPTION_String = QString::number(NOMBRESALLERECEPTION);
    query.prepare("INSERT INTO SALLES (IDSALLE, NOMSALLE, VILLE, ZIP_CODE, ADRESSE, SURFACE, CAPACITE , TYPESALLE , FORFAIT , NOMBRESALLERECEPTION)"
                   "VALUES (:id, :nom , :ville , :zip , :adresse , :surface , :capacite , :type , :forfait , :nbr)");
    query.bindValue(":id",IDSALLE_String);
    query.bindValue(":nom",NOMSALLE);
    query.bindValue(":ville",VILLE);
    query.bindValue(":zip",ZIP_CODE_String);
    query.bindValue(":adresse",ADRESSE);
    query.bindValue(":surface",SURFACE_String);
    query.bindValue(":capacite",CAPACITE_String);
    query.bindValue(":type",TYPESALLE);
    query.bindValue(":forfait",FORFAIT);
     query.bindValue(":nbr",NOMBRESALLERECEPTION_String);

    return  query.exec();

}



// Affichage des salles

QSqlQueryModel* salles::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();

  // QString ID;
  // ID = QString::number(IDSALLE);

   model->setQuery("SELECT* FROM SALLES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
   model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

  return  model;
}


// Suppression des salles
bool salles::supprimer(int id)
{
    QSqlQuery query;

         query.prepare(" Delete From SALLES where IDSALLE=:id");
         query.bindValue(0, id);

        return query.exec();


}

// Modifier les salles

bool salles::modifier()

{
    QSqlQuery query;

            query.prepare("update SALLES set NOMSALLE=:nomsalle,VILLE=:ville,ADRESSE=:adresse,SURFACE=:surface,CAPACITE=:capacite,TYPESALLE=:type , FORFAIT=:forfait , NOMBRESALLERECEPTION=:nbr where IDSALLE=:id");
            query.bindValue(":id",IDSALLE);
            query.bindValue(":nomsalle",NOMSALLE);
            query.bindValue(":ville",VILLE);
            query.bindValue(":adresse", ADRESSE);
            query.bindValue(":surface", SURFACE);
            query.bindValue(":capacite", CAPACITE);
            query.bindValue(":type", TYPESALLE);
            query.bindValue(":forfait", FORFAIT);
            query.bindValue(":nbr",NOMBRESALLERECEPTION);
            return    query.exec();
}




/* Recherche par ID
void salles::chercherID_salles (int x , QString n , QString v)
{

    QSqlQuery query1;
    query1.prepare("select * from SALLES where IDSALLE=:x and NOMSALLE=:n and VILLE=:v ");
    query1.bindValue(":x",x);
    query1.bindValue(":n",n);
    query1.bindValue(":v",v);
    query1.exec();
    while(query1.next())
    {
    IDSALLE=query1.value(0).toInt();
    NOMSALLE = query1.value(1).toString();
    VILLE = query1.value(2).toString();
    ZIP_CODE= query1.value(3).toInt();
    ADRESSE=query1.value(4).toString();
    SURFACE=query1.value(5).toInt();
    CAPACITE=query1.value(6).toInt();
    TYPESALLE=query1.value(7).toString();
    FORFAIT=query1.value(8).toString();
    NOMBRESALLERECEPTION=query1.value(9).toInt();
    }




}  */


// Trie
QSqlQueryModel* salles::afficher_sallestrier(QString x)
{
  QSqlQueryModel* model=new QSqlQueryModel();

   if(x=="Nom Croissant"){
   model->setQuery("SELECT * FROM SALLES order by NOMSALLE ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
  model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
  model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
  model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
   model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

   }
   else if(x=="Ville Croissant")
   {
       model->setQuery("SELECT * FROM SALLES order by VILLE ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

   }
   else if (x=="Forfait Croissant")
   {
       model->setQuery("SELECT * FROM SALLES order by FORFAIT ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

   }
   else if(x=="Nom Decroissant")
   {
       model->setQuery("SELECT * FROM SALLES order by NOMSALLE desc ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

   }
   else if(x=="Ville Decroissant")
   {
       model->setQuery("SELECT * FROM SALLES order by VILLE desc ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

   }
   else if(x=="Forfait Decroissant ")
   {
       model->setQuery("SELECT * FROM SALLES order by FORFAIT desc ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));


   }

   else if(x=="Nom , ville et forfait")
   {
       model->setQuery("SELECT * FROM SALLES order by NOMSALLE,VILLE,FORFAIT");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
      model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
      model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));
   }

   return  model;
}


bool salles::verifierExnom(QString nom)
{
    int i=0;
    QSqlQuery query;
    query.prepare("select * from SALLES where NOMSALLE= ?");
    query.addBindValue(nom);
    if(query.exec())
    {
        while(query.next()) {i++;}}
        if(i!=0)
            return  true;
        else return false;

 }





 QSqlQueryModel * salles::chercher_salles_par_nom(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("select * from SALLES where NOMSALLE = '"+m+"'");



        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

             return model ;
    }

 }

 bool salles::verifierID(int id)
 {
     int i=0;
     QSqlQuery query;
     query.prepare("select * from SALLES where IDSALLE= ?");
     query.addBindValue(id);
     if(query.exec())
     {
         while(query.next()) {i++;}}
         if(i!=0)
             return  true;
         else return false;

  }

 QSqlQueryModel * salles::chercher_salles_par_id(int id)

  {
            QSqlQuery query;
            QString xs;
             xs= QString::number(id);
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("select * from SALLES where IDSALLE = '"+xs+"'");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

             return model ;
    }

 bool salles::verifierVille(QString ville)
 {
     int i=0;
     QSqlQuery query;
     query.prepare("select * from SALLES where VILLE= ?");
     query.addBindValue(ville);
     if(query.exec())
     {
         while(query.next()) {i++;}}
         if(i!=0)
             return  true;
         else return false;

  }

 QSqlQueryModel * salles::chercher_salles_par_ville(QString v)

  {
            QSqlQuery query;
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("select * from SALLES where VILLE = '"+v+"'");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

             return model ;
    }

 bool salles::verifierForfait(QString forfait)
 {
     int i=0;
     QSqlQuery query;
     query.prepare("select * from SALLES where FORFAIT= ?");
     query.addBindValue(forfait);
     if(query.exec())
     {
         while(query.next()) {i++;}}
         if(i!=0)
             return  true;
         else return false;

  }

 QSqlQueryModel * salles::chercher_salles_avancee(QString m, QString v, QString f)

  {
            QSqlQuery query;
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("select * from SALLES where VILLE = '"+v+"' and NOMSALLE = '"+m+"'and FORFAIT='"+f+"'             ");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de la salle "));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Ville"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Zip Code"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Surface"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Capacite"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Type de salle"));
       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Forfait"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("Nombre de salle de reception"));

             return model ;
    }
