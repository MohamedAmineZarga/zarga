#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
client::client()
{

}
client::client(int a,QString b,QString c,QString d,QString e,QString x,int f,QString g)
{
    this->cin=a;
    this->nom=b;
    this->prenom=c;
    this->date=d;
    this->adresse=e;
    this->email=x;
    this->numero=f;
    this->sexe=g;
}
QString client::getemail()
{
    return email;
}
int client::getcin()
{
    return cin;
}
QString client::getnom()
{
    return nom;
}
QString client::getprenom()
{
    return prenom;
}
QString client::getadresse()
{
    return  adresse;
}
QString client::getdate()
{
    return date;
}
int client::getnumero()
{
    return numero;
}
QString client::getsexe()
{
    return sexe;
}
void client::setcin(int a)
{
    this->cin=a;
}
void client::setadresse(QString a)
{
    this->adresse=a;
}
void client::setdate(QString a)
{
    this->date=a;
}
void client::setnom(QString a)
{
    this->nom=a;
}
void client::setemail(QString a)
{
    this->email=a;
}
void client::setnumero(int a)
{
    this->numero=a;
}
void client::setprenom(QString a)
{
    this->prenom=a;
}
void client::setsexe(QString a)
{
    this->sexe=a;
}
bool client::ajouter_client()
{

    QSqlQuery query;
  QString cin_string= QString::number(cin);
  QString numero_string= QString::number(numero);

         query.prepare("INSERT INTO client (cin, nom, prenom,datee,adresse,email,numero,sexe) "
                       "VALUES (:cin, :forename, :surname,:date,:adresse,:email,:numero,:sexe)");
         query.bindValue(":cin",cin_string);
         query.bindValue(":forename", nom);
         query.bindValue(":surname", prenom);
         query.bindValue(":date", date);
         query.bindValue(":adresse", adresse);
         query.bindValue(":numero", numero_string);
         query.bindValue(":email", email);
         query.bindValue(":sexe", sexe);
        return query.exec();
}
bool client::supprimer_client(int cin)
{
    QSqlQuery query;
         query.prepare(" Delete from client where cin=:cin");
         query.bindValue(0, cin);

        return query.exec();


}

QSqlQueryModel* client::afficher_client()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM client ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

   model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));

   return  model;
}
QSqlQueryModel* client::afficher_unclient()
{
  QSqlQueryModel* model=new QSqlQueryModel();


    QString xs;
  xs= QString::number(cin);

   model->setQuery("SELECT* FROM client where cin='"+xs+"' and nom='"+nom+"' and prenom='"+prenom+"' ");

   //model->setQuery(*query);
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

   model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));

   return  model;
}
 QSqlQueryModel* client::afficher_client(QString p)
{
    QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM client where prenom='"+p+"' ");

     //model->setQuery(*query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

     model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));

     return  model;
}
 QSqlQueryModel* client::afficher_clientn(QString n)
{
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM client where nom='"+n+"' ");

     //model->setQuery(*query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));

     return  model;
}
 QSqlQueryModel* client::afficher_clientnp(QString n,QString p)
{
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM client where nom='"+n+"' and prenom='"+p+"' ");

     //model->setQuery(*query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));

     return  model;
}
 QSqlQueryModel* client::afficher_clientc(QString c)
{
    QSqlQueryModel* model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM client where cin='"+c+"' ");

     //model->setQuery(*query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));

     return  model;
}
bool client::modifier_client()
{

        QSqlQuery query;

        query.prepare("update client set nom=:nom,prenom=:prenom,datee=:date,adresse=:adresse,email=:email,numero=:numero,sexe=:sexe where cin=:cin");
        query.bindValue(":cin",cin);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":date", date);
        query.bindValue(":adresse", adresse);
        query.bindValue(":numero", numero);
        query.bindValue(":email", email);
        query.bindValue(":sexe", sexe);
        return    query.exec();

}
bool client::chercher_client(int x)
{    QSqlQuery query1;

    query1.prepare("select * from client where cin=:x ");

    query1.bindValue(":x",x);
    query1.exec();
    while(query1.next())
    {
    cin=query1.value(0).toInt();
    nom = query1.value(1).toString();
    prenom = query1.value(2).toString();
    date= query1.value(3).toString();
    adresse=query1.value(4).toString();
    email=query1.value(5).toString();
    numero=query1.value(6).toInt();
    sexe=query1.value(7).toString();
    }
    return query1.exec();
}
bool client::chercher_client(QString n)
{QSqlQuery query1;
    query1.prepare("select * from client where nom=:n ");
    query1.bindValue(":n",n);
    query1.exec();
    while(query1.next())
    {
    cin=query1.value(0).toInt();
    nom = query1.value(1).toString();
    prenom = query1.value(2).toString();
    date= query1.value(3).toString();
    adresse=query1.value(4).toString();
    email=query1.value(5).toString();
    numero=query1.value(6).toInt();
    sexe=query1.value(7).toString();
    }
    return query1.exec();
}
bool client::chercher_clientp(QString p)
{QSqlQuery query1;
    query1.prepare("select * from client where prenom=:p ");
    query1.bindValue(":p",p);
    query1.exec();
    while(query1.next())
    {
    cin=query1.value(0).toInt();
    nom = query1.value(1).toString();
    prenom = query1.value(2).toString();
    date= query1.value(3).toString();
    adresse=query1.value(4).toString();
    email=query1.value(5).toString();
    numero=query1.value(6).toInt();
    sexe=query1.value(7).toString();
    }
    return query1.exec();
}
bool client::chercher_clientnp(QString n,QString p)
{QSqlQuery query1;
    query1.prepare("select * from client where nom=:n and prenom=:p ");
    query1.bindValue(":p",p);
    query1.bindValue(":n",n);
    query1.exec();
    while(query1.next())
    {
    cin=query1.value(0).toInt();
    nom = query1.value(1).toString();
    prenom = query1.value(2).toString();
    date= query1.value(3).toString();
    adresse=query1.value(4).toString();
    email=query1.value(5).toString();
    numero=query1.value(6).toInt();
    sexe=query1.value(7).toString();
    }
    return query1.exec();
}
bool client::chercher_client (int x,QString n,QString p)
{

    QSqlQuery query1;

            query1.prepare("select * from client where cin=:x and nom=:n and prenom=:p ");
            query1.bindValue(":n",n);
            query1.bindValue(":p",p);
            query1.bindValue(":x",x);
            query1.exec();
            while(query1.next())
            {
            cin=query1.value(0).toInt();
            nom = query1.value(1).toString();
            prenom = query1.value(2).toString();
            date= query1.value(3).toString();
            adresse=query1.value(4).toString();
            email=query1.value(5).toString();
            numero=query1.value(6).toInt();
            sexe=query1.value(7).toString();
            }
            return query1.exec();


}

QSqlQueryModel* client::afficher_clienttrier(QString x)
{
  QSqlQueryModel* model=new QSqlQueryModel();

   if(x=="cin croissant"){
   model->setQuery("SELECT * FROM client order by cin ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));
   }
   else if(x=="nom croissant")
   {
       model->setQuery("SELECT * FROM client order by nom ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de naissance"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numero de telephone"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Email"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Sexe"));
   }
   else if (x=="prenom croissant")
   {
       model->setQuery("SELECT * FROM client order by prenom ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));
   }
   else if(x=="cin decroissant")
   {
       model->setQuery("SELECT * FROM client order by cin desc ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));
   }
   else if(x=="nom decroissant")
   {
       model->setQuery("SELECT * FROM client order by nom desc ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));
   }
   else if(x=="prenom decroissant")
   {
       model->setQuery("SELECT * FROM client order by prenom desc ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));

   }

   else if(x=="sexe et nom et prenom")
   {
       model->setQuery("SELECT * FROM client order by sexe,nom,prenom");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));
   }/*
   else if(x=="sexe et nom et prenom decroissant")
   {
       model->setQuery("SELECT * FROM client order by sexe,nom,prenom desc");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date de naissance"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("numero de telephone"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));
   }*/

   return  model;
}

QSqlQueryModel* client::rechercherdynamique(QString input,QString filter)
{
    QSqlQueryModel * model= new QSqlQueryModel ();
       QSqlQuery query;
       query.prepare("SELECT *FROM client WHERE "+filter+" LIKE '%' || :inputValue || '%' ");
       query.bindValue(":inputValue",input);
       query.exec();
       model->setQuery(query);
       return model;
}

