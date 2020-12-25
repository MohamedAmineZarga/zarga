#ifndef SALLES_H
#define SALLES_H
#include <QString>
#include <QSqlQueryModel>
#include <QtSql>
#include <QDebug>
class salles
{
       private :
       int IDSALLE;
       QString NOMSALLE;
       QString VILLE;
       int ZIP_CODE;
       QString ADRESSE;
       int SURFACE;
       int CAPACITE;
       QString TYPESALLE;
       QString FORFAIT;
       int NOMBRESALLERECEPTION;



public:
       // Constructeur par defaut
             salles();

    // Constructeur paramétré

    salles(int , QString , QString , int , QString , int , int , QString  , QString , int );

    // Les getters
    int getIDSALLE() {return IDSALLE;}
    QString getNOMSALLE(){return NOMSALLE;}
    QString getVILLE(){return VILLE;}
    int getZIP_CODE(){return ZIP_CODE;}
    QString getADRESSE(){return ADRESSE;}
    int getSURFACE(){return SURFACE;}
    int getCAPACITE(){return CAPACITE;}
    QString getTYPESALLE(){return TYPESALLE;}
    QString getFORFAIT(){return FORFAIT;}
    int getNOMBRESALLERECEPTION(){return NOMBRESALLERECEPTION;}

    // Les setters
    void setIDSALLE(int IDSALLE){this->IDSALLE=IDSALLE;}
    void setNOMSALLE(QString NOMSALLE){this->NOMSALLE=NOMSALLE;}
    void setVILLE(QString VILLE){this->VILLE=VILLE;}
    void setZIP_CODE(int ZIP_CODE){this->ZIP_CODE=ZIP_CODE;}
    void setADRESSE(QString ADRESSE){this->ADRESSE=ADRESSE;}
    void setSURFACE(int SURFACE){this->SURFACE=SURFACE;}
    void setCAPACITE(int CAPACITE){this->CAPACITE=CAPACITE;}
    void setTYPESALLE(QString TYPESALLE){this->TYPESALLE=TYPESALLE;}
    void setFORFAIT(QString FORFAIT ){this->FORFAIT=FORFAIT;}
    void setNOMBRESALLERECEPTION(int NOMBRESALLERECEPTION ){this->NOMBRESALLERECEPTION=NOMBRESALLERECEPTION;}

     // ##### Les methodes CRUD ( Ajouter , Modifier , Supprimer , Afficher ) ##### //

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();


  // #####Les methodes Metiers  ##### //


   // ##### Trie Avancée sur nom/ville/forfait ##### //
    QSqlQueryModel* afficher_sallestrier(QString x);


 // ##### Recherche Avancée  ##### //

    // Recherche par Nom
    bool verifierExnom(QString);
     QSqlQueryModel * chercher_salles_par_nom(QString m);

     // Recherche par ID
     bool verifierID(int);
      QSqlQueryModel * chercher_salles_par_id(int id);

      // Recherche par ville
      bool verifierVille(QString);
       QSqlQueryModel * chercher_salles_par_ville(QString v);

       // Recherche selon 3 critéres
       bool verifierForfait(QString);
       QSqlQueryModel * chercher_salles_avancee(QString m , QString v , QString f );





};

#endif // SALLES_H
