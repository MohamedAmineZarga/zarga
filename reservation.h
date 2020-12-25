#ifndef RESERVATION_H
#define RESERVATION_H
#include<QString>
#include <QSqlQueryModel>
class reservation
{
    int id,cinc,idsalle,idcol,nbinvite,budget;
    QString date,note;
public:
    reservation();
    reservation(int,int,QString,int,int,int,int,QString);
    int getid();
    int getcinc();
    QString getdate();
    int getidsalle();
    int getidcol();
    int getnbinvite();
    int getbudget();
    QString getnote();
    void setid(int);
    void setcinc(int);
    void setdate(QString);
    void setidsalle(int);
    void setidcol(int);
    void setnbinvite(int);
    void setbudget(int);
    void setnote(QString);
    bool ajouter_reservation();
    QSqlQueryModel* afficher_reservation();
    bool modifier_reservation();
    bool supprimer_reservation(int);
    bool chercher_reservationid(int);
    bool chercher_reservationcinc(int);
    bool chercher_reservationdate(QString);
    bool chercher_reservationidcin(int,int);
    bool chercher_reservationiddate(int,QString);
    bool chercher_reservationcindate(int ,QString);
    bool cherhcer_reservationidcindate(int,int,QString);
    QSqlQueryModel* trie(QString x);
    QSqlQueryModel* afficher_reservationidcindate(int id,int cin,QString date);
    QSqlQueryModel* afficher_reservationcindate(int cin,QString date);
    QSqlQueryModel* afficher_reservationiddate(int id,QString date);
    QSqlQueryModel* afficher_reservationidcin(int id,int cin);
    QSqlQueryModel* afficher_reservationdate(QString date);
    QSqlQueryModel* afficher_reservationid(QString id);
     QSqlQueryModel* afficher_reservationcinc(QString cinc);

};

#endif // RESERVATION_H
