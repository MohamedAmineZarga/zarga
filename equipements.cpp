#include "equipements.h"

equipements::equipements()
{
    ID = 0 ;
    NOM = "";
    QUANTITE = 0;
    AUTRE = "";
    IDSALLEEq = 0;

}
equipements::equipements(int ID, QString NOM , int QUANTITE , QString AUTRE , int IDSALLE )
{
    this->ID = ID;
    this->NOM = NOM;
    this->QUANTITE = QUANTITE;
    this->AUTRE = AUTRE;
    this->IDSALLEEq = IDSALLE;

}


// Ajout des equipements


bool equipements::ajouter_equipements()
{
    QSqlQuery query;
    QString IDSALLEEq_String = QString::number(IDSALLEEq);
    QString ID_String= QString::number(ID);
    QString QUANTITE_String = QString::number(QUANTITE);
    query.prepare("INSERT INTO EQUIPEMENTS (ID, NOM, QUANTITE , AUTRE , IDSALLE)"
                   "VALUES (:id, :nom , :quantite , :autre , :IDSALLE)");
    query.bindValue(":id",ID_String);
    query.bindValue(":nom",NOM);
    query.bindValue(":quantite",QUANTITE_String);
    query.bindValue(":autre",AUTRE);
    query.bindValue(":IDSALLE",IDSALLEEq_String);


    return  query.exec();

}

// Affichage des equip

QSqlQueryModel* equipements::afficher_equipements()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM EQUIPEMENTS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id de l equipement"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l equipement "));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Autre"));

  return  model;
}

// Suppression des equipements
bool equipements::supprimer_equipements(int id)
{
    QSqlQuery query;

         query.prepare(" Delete From EQUIPEMENTS where ID=:id");
         query.bindValue(0, id);

        return query.exec();


}

// Modification des equipements
bool equipements::modifier_equipements()

{
    QSqlQuery query;

            query.prepare("update EQUIPEMENTS set NOM=:nom,QUANTITE=:quantite,AUTRE=:autre ,IDSALLE=:idsalle    where ID=:id");
            query.bindValue(":id",ID);
            query.bindValue(":nom",NOM);
            query.bindValue(":quantite",QUANTITE);
            query.bindValue(":autre",AUTRE);
            query.bindValue(":idsalle",IDSALLEEq);
            return    query.exec();
}


QSqlQueryModel* equipements::afficher_equipements_trier(QString y)
{
  QSqlQueryModel* model=new QSqlQueryModel();

   if(y=="Nom Equipement Croissant"){
   model->setQuery("SELECT * FROM EQUIPEMENTS order by NOM ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id de l equipement"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l equipement "));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Autre"));


   }
   else if(y=="Quantite Croissant")
   {
       model->setQuery("SELECT * FROM EQUIPEMENTS order by QUANTITE ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id de l equipement"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l equipement "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Autre"));


   }
   else if (y=="Nom Equipement Decroissant")
   {
       model->setQuery("SELECT * FROM EQUIPEMENTS order by NOM desc");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id de l equipement"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l equipement "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Autre"));


   }
   else if(y=="Quantite Decroissant")
   {
       model->setQuery("SELECT * FROM EQUIPEMENTS order by QUANTITE desc ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id de l equipement"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l equipement "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Autre"));


   }
   else if(y=="Nom et quantite")
   {
       model->setQuery("SELECT * FROM EQUIPEMENTS order by NOM,QUANTITE ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id de l equipement"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l equipement "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Autre"));



   }

   else if (y=="Nom et quantite decroissant")
   {

       model->setQuery("SELECT * FROM EQUIPEMENTS order by NOM,QUANTITE desc");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id de l equipement"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l equipement "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Autre"));


   }


   return  model;
}

QSqlQueryModel * equipements::chercher_equipements_par_nom(QString n)

 {
           QSqlQuery query;
       QSqlQueryModel *model = new QSqlQueryModel;
       model->setQuery("select * from EQUIPEMENTS where NOM = '"+n+"'   ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id de l equipement"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l equipement "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Autre"));




            return model ;
   }

bool equipements::verifierNomEquip(QString nomEq)
{
    int i=0;
    QSqlQuery query;
    query.prepare("select * from EQUIPEMENTS where NOM= ?");
    query.addBindValue(nomEq);
    if(query.exec())
    {
        while(query.next()) {i++;}}
        if(i!=0)
            return  true;
        else return false;

 }



