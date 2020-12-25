#include "reservation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
reservation::reservation()
{
    id=0;
    cinc=0;
    date="";
    idsalle=0;
    idcol=0;
    nbinvite=0;
    budget=0;
    note="";
}
reservation::reservation(int a,int b,QString c,int d,int e,int f,int j,QString h)
{
    id=a;
    cinc=b;
    date=c;
    idsalle=d;
    idcol=e;
    nbinvite=f;
    budget=j;
    note=h;
}
int reservation::getid()
{
    return id;
}
int reservation::getcinc()
{
    return cinc;
}
QString reservation::getdate()
{
    return date;
}
int reservation::getidsalle()
{
    return idsalle;
}
int reservation::getidcol()
{
    return idcol;
}
int reservation::getnbinvite()
{
    return nbinvite;
}
int reservation::getbudget()
{
    return budget;
}
QString reservation::getnote()
{
    return note;
}
void reservation::setid(int a)
{
    id=a;
}
void reservation::setcinc(int a)
{
    cinc=a;
}
void reservation::setdate(QString a)
{
    date=a;
}
void reservation::setidsalle(int a)
{
    idsalle=a;
}
void reservation::setidcol(int a)
{
    idcol=a;
}
void reservation::setnbinvite(int a)
{
    nbinvite=a;
}
void reservation::setbudget(int a)
{
    budget=a;
}
void reservation::setnote(QString a)
{
    note=a;
}
bool reservation::ajouter_reservation()
{

    QSqlQuery query;
        QString id_string= QString::number(id);
         QString idsalle_string= QString::number(idsalle);
         QString idcol_string= QString::number(idcol);
         QString nbinvite_string= QString::number(nbinvite);
        QString budget_string= QString::number(budget);
        QString cinc_string= QString::number(cinc);
        query.prepare("INSERT INTO reservation (id,cinc,datee,idsalle,idcol,nbinvite,budget,note) "
                       "VALUES (:ids, :cincs, :date,:idsalle,:idcol,:nbinvite,:budget,:note)");
         query.bindValue(":ids",id_string);
         query.bindValue(":cincs",cinc_string);
         query.bindValue(":date", date);
         query.bindValue(":idsalle",idsalle_string);
         query.bindValue(":idcol", idcol_string);
         query.bindValue(":nbinvite",nbinvite_string);
         query.bindValue(":budget", budget_string);
         query.bindValue(":note", note);
        return query.exec();
}
QSqlQueryModel* reservation::afficher_reservation()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM reservation ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));

   return  model;
}
bool reservation::supprimer_reservation(int id)
{
    QSqlQuery query;
         query.prepare(" Delete from reservation where id=:id");
         query.bindValue(0,id);

        return query.exec();


}
bool reservation::modifier_reservation()
{

        QSqlQuery query;

        query.prepare("update reservation set cinc=:cinc,datee=:date,idsalle=:idsalle,idcol=:idcol,nbinvite=:nbinvite,budget=:budget,note=:note where id=:id ");
        query.bindValue(":id",id);
        query.bindValue(":cinc",cinc);
        query.bindValue(":date",date);
        query.bindValue(":idsalle", idsalle);
        query.bindValue(":idcol", idcol);
        query.bindValue(":nbinvite", nbinvite);
        query.bindValue(":budget", budget);
        query.bindValue(":note",note);
        return    query.exec();

}
bool reservation::chercher_reservationid(int ids)
{QSqlQuery query1;
    query1.prepare("select * from reservation where id=:id ");

    query1.bindValue(":id",ids);
    query1.exec();
    while(query1.next())
    {
    id=query1.value(0).toInt();
    cinc = query1.value(1).toInt();
    date = query1.value(2).toString();
    idsalle= query1.value(3).toInt();
    idcol=query1.value(4).toInt();
    nbinvite=query1.value(5).toInt();
    budget=query1.value(6).toInt();
    note=query1.value(7).toString();
    }
    return query1.exec();
}
QSqlQueryModel* reservation::afficher_reservationid(QString id)
{
    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM reservation where id='"+id+"' ");
     //model->query().bindValue(":id",id);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));

     return  model;
}
QSqlQueryModel* reservation::afficher_reservationcinc(QString cinc)
{
    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM reservation where cinc='"+cinc+"' ");
     //model->query().bindValue(":cinc",cinc);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));

     return  model;
}

bool reservation::chercher_reservationcinc(int cin)
{QSqlQuery query1;
    query1.prepare("select * from reservation where cinc=:cinc ");

    query1.bindValue(":cinc",cin);
    query1.exec();
    while(query1.next())
    {
    id=query1.value(0).toInt();
    cinc = query1.value(1).toInt();
    date = query1.value(2).toString();
    idsalle= query1.value(3).toInt();
    idcol=query1.value(4).toInt();
    nbinvite=query1.value(5).toInt();
    budget=query1.value(6).toInt();
    note=query1.value(7).toString();
    }
    return query1.exec();
}
bool reservation::chercher_reservationdate(QString date)
{
    QSqlQuery query1;
        query1.prepare("select * from reservation where datee=:date ");

        query1.bindValue(":date",date);
        query1.exec();
        while(query1.next())
        {
        id=query1.value(0).toInt();
        cinc = query1.value(1).toInt();
        date = query1.value(2).toString();
        idsalle= query1.value(3).toInt();
        idcol=query1.value(4).toInt();
        nbinvite=query1.value(5).toInt();
        budget=query1.value(6).toInt();
        note=query1.value(7).toString();
        }
        return query1.exec();
}
QSqlQueryModel* reservation::afficher_reservationdate(QString date)
{
    QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM reservation where datee='"+date+"' ");
     //model->query().bindValue(":cinc",cinc);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));

     return  model;
}
bool reservation::chercher_reservationidcin(int id,int cin)
{
    QSqlQuery query1;
        query1.prepare("select * from reservation where id=:id and cinc=:cin ");

        query1.bindValue(":id",id);
        query1.bindValue(":cin",cin);
        query1.exec();
        while(query1.next())
        {
        id=query1.value(0).toInt();
        cinc = query1.value(1).toInt();
        date = query1.value(2).toString();
        idsalle= query1.value(3).toInt();
        idcol=query1.value(4).toInt();
        nbinvite=query1.value(5).toInt();
        budget=query1.value(6).toInt();
        note=query1.value(7).toString();
        }
        return query1.exec();
}
QSqlQueryModel* reservation::afficher_reservationidcin(int id, int cin)
{
    QSqlQueryModel* model=new QSqlQueryModel();

      QString ids= QString::number(id);
      model->setQuery("SELECT* FROM reservation where id='"+ids+"' and cinc='"+cin+"' ");
     //model->query().bindValue(":cinc",cinc);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));

     return  model;
}
bool reservation::chercher_reservationiddate(int id,QString date)
{
    QSqlQuery query1;
        query1.prepare("select * from reservation where id=:id and datee=:date ");

        query1.bindValue(":id",id);
        query1.bindValue(":date",date);
        query1.exec();
        while(query1.next())
        {
        id=query1.value(0).toInt();
        cinc = query1.value(1).toInt();
        date = query1.value(2).toString();
        idsalle= query1.value(3).toInt();
        idcol=query1.value(4).toInt();
        nbinvite=query1.value(5).toInt();
        budget=query1.value(6).toInt();
        note=query1.value(7).toString();
        }
        return query1.exec();
}
QSqlQueryModel* reservation::afficher_reservationiddate(int id,QString date)
{
    QSqlQueryModel* model=new QSqlQueryModel();

      QString ids= QString::number(id);
     model->setQuery("SELECT* FROM reservation where id='"+ids+"' and datee='"+date+"' ");
     //model->query().bindValue(":cinc",cinc);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));

     return  model;
}
bool reservation::chercher_reservationcindate(int cin,QString date)
{
    QSqlQuery query1;
        query1.prepare("select * from reservation where cinc=:cin and datee=:date ");

        query1.bindValue(":cin",cin);
        query1.bindValue(":date",date);
        query1.exec();
        while(query1.next())
        {
        id=query1.value(0).toInt();
        cinc = query1.value(1).toInt();
        date = query1.value(2).toString();
        idsalle= query1.value(3).toInt();
        idcol=query1.value(4).toInt();
        nbinvite=query1.value(5).toInt();
        budget=query1.value(6).toInt();
        note=query1.value(7).toString();
        }
        return query1.exec();
}
QSqlQueryModel* reservation::afficher_reservationcindate(int cin,QString date)
{
    QSqlQueryModel* model=new QSqlQueryModel();

      QString cins= QString::number(cin);
     model->setQuery("SELECT* FROM reservation where cinc='"+cins+"' and datee='"+date+"' ");
     //model->query().bindValue(":cinc",cinc);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));

     return  model;
}
bool reservation::cherhcer_reservationidcindate(int ids,int cin,QString dates)
{
    QSqlQuery query1;
        query1.prepare("select * from reservation where id=:ids and cinc=:cin and datee=:date ");
        query1.bindValue(":ids",ids);
        query1.bindValue(":cin",cin);
        query1.bindValue(":date",dates);
        query1.exec();
        while(query1.next())
        {
        id=query1.value(0).toInt();
        cinc = query1.value(1).toInt();
        date = query1.value(2).toString();
        idsalle= query1.value(3).toInt();
        idcol=query1.value(4).toInt();
        nbinvite=query1.value(5).toInt();
        budget=query1.value(6).toInt();
        note=query1.value(7).toString();
        }
        return query1.exec();
}
QSqlQueryModel* reservation::afficher_reservationidcindate(int id,int cin,QString date)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QString ids= QString::number(id);
      QString cins= QString::number(cin);
     model->setQuery("SELECT* FROM reservation where id='"+ids+"' and cinc='"+cins+"' and datee='"+date+"' ");
     //model->query().bindValue(":cinc",cinc);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));

     return  model;
}
QSqlQueryModel* reservation::trie(QString x)
{    QSqlQueryModel* model=new QSqlQueryModel();

    if(x=="id et cin et budget")
    {
    model->setQuery("SELECT* FROM reservation order by id,cinc,budget");
    //model->query().bindValue(":cinc",cinc);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));
    }
    else if(x=="id")
    {
        model->setQuery("SELECT* FROM reservation order by id");
        //model->query().bindValue(":cinc",cinc);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));

    } else if(x=="cin")
    {
    model->setQuery("SELECT* FROM reservation order by cinc");
    //model->query().bindValue(":cinc",cinc);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));
    }else if(x=="budget")
    {
    model->setQuery("SELECT* FROM reservation order by budget");
    //model->query().bindValue(":cinc",cinc);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID reservation"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID salle à reserver"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID collaborateur à reserver"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre d'invites"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("budget"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("note"));
    }
    return model;
}

