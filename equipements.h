#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include <QString>
#include <QSqlQueryModel>
#include <QtSql>
#include <QDebug>
class equipements
{

private  :
    int ID;
    QString NOM;
    int QUANTITE;
    QString AUTRE;
    int IDSALLEEq;




public:

     // Constructeur par défaut
    equipements();

     // Constructeur paramétré
    equipements(int , QString , int , QString , int);
    equipements(QString);


    // Les getters
    int getID() {return ID;}
    QString getNOM() {return NOM;}
    int getQUANTITE() {return QUANTITE;}
    QString getAUTRE() {return AUTRE;}
    int getIDSALLE() {return IDSALLEEq;}


    // les setters
     void setID(int ID){this->ID=ID;}
     void setNOM(QString NOM) {this->NOM = NOM;}
     void setQUANTITE(int QUANTITE) {this->QUANTITE=QUANTITE;}
     void setAUTRE(QString AUTRE) {this->AUTRE= AUTRE;}
     void setIDSALLE(int IDSALLEEq) {this->IDSALLEEq = IDSALLEEq;}


     // Les methodes CRUD ( Ajouter , Modifier , Supprimer , Afficher )
    bool ajouter_equipements();
    QSqlQueryModel* afficher_equipements();
    bool supprimer_equipements(int);
    bool modifier_equipements();

    // Les methodes Metiers

     // Trie
     QSqlQueryModel* afficher_equipements_trier(QString y);

     // Recherche
     bool verifierNomEquip(QString);
     QSqlQueryModel * chercher_equipements_par_nom(QString n );

};

#endif // EQUIPEMENTS_H
