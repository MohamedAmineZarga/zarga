#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include <QSqlQueryModel>
class client
{
public:
    client();
    client(int,QString,QString,QString,QString,QString,int,QString);
    int getcin();
    int getnumero();
    QString getnom();
    QString getprenom();
    QString getdate();
    QString getadresse();
    QString getsexe();
    QString getemail();
    void setcin(int);
    void setemail(QString);
    void setnumero(int);
    void setnom(QString);
    void setprenom(QString);
    void setdate(QString);
    void setadresse(QString);
    void setsexe(QString);
    bool ajouter_client();
    QSqlQueryModel* afficher_client();
    QSqlQueryModel* afficher_client(QString p);
    QSqlQueryModel* afficher_clientn(QString n);
    QSqlQueryModel* afficher_clientc(QString c);
    QSqlQueryModel* afficher_clientnp(QString n,QString p);
    bool supprimer_client(int);
    bool modifier_client();
    bool chercher_client(int x);
    bool chercher_client(QString n);
    bool chercher_clientp(QString p);
    bool chercher_clientnp(QString n,QString p);
    QSqlQueryModel * rechercherdynamique(QString input,QString filter);
    bool chercher_client (int x,QString n,QString p);
    QSqlQueryModel* afficher_clienttrier(QString x);
    QSqlQueryModel* afficher_unclient();
private :
    int cin,numero;
    QString nom,prenom,date,adresse,sexe,email;

};

#endif // CLIENT_H
