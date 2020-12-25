#include "gestiondessalles.h"
#include "ui_gestiondessalles.h"
#include "salles.h"
#include "equipements.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextTableCell>
#include <QPainter>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QDesktopServices>
#include<QFileDialog>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QTranslator>
#include "smtp.h"
#include "report.h"

gestiondessalles::gestiondessalles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestiondessalles)
{
    ui->setupUi(this);

    ui->id->setValidator(new QIntValidator(100, 999, this));
        ui->zipcode->setValidator(new QIntValidator(1000 ,9999, this));
         ui->surface->setValidator(new QIntValidator(100, 9999, this));
          ui->capacite->setValidator(new QIntValidator(100, 999, this));
            ui->ideq->setValidator(new QIntValidator(100, 999, this));

          /*
          // Playing Background Music
          QMediaPlayer * bgmusic = new QMediaPlayer();
          bgmusic->setMedia(QUrl("qrc:/sounds/img/bgmusic.mp3"));
          bgmusic->play();
         */
}

gestiondessalles::~gestiondessalles()
{
    delete ui;
}

void gestiondessalles::on_Add_2_clicked()
{
    int ID = ui->ideq->text().toInt();
     int QUANTITE = ui->quantite->text().toInt();
     QString NOM ;
     QString AUTRE = ui->autre->text();
     int IDSALLEEq = ui->idddd->text().toInt();


       if (ui->checkBox_cuisine->isChecked())
       { NOM = "cuisine" ; }
       if (ui->checkBox_BA->isChecked())
       { NOM = "Salle backstage pour le troupe " ; }
       if (ui->checkBox_51->isChecked())
       { NOM = "Salle backstage pour les mariees	" ; }
       if (ui->checkBox_52->isChecked())
       { NOM = "Tables " ; }
       if (ui->checkBox_53->isChecked())
       { NOM = "Rubans" ; }
       if (ui->checkBox_54->isChecked())
       { NOM = "Déco florale" ; }
       if (ui->checkBox_57->isChecked())
       { NOM = "Chaises" ; }
       if (ui->checkBox_55->isChecked())
       { NOM = "Caméra de surveillance" ; }
       if (ui->checkBox_56->isChecked())
       { NOM = "Les caméras robotisées, helicopteres" ; }
       if (ui->checkBox_60->isChecked())
       { NOM = "Piano " ; }
       if (ui->checkBox_58 ->isChecked())
       { NOM = "Guitar " ; }
       if (ui->checkBox_59 ->isChecked())
       { NOM = "Baffle " ; }


       equipements E(ID , NOM, QUANTITE , AUTRE , IDSALLEEq);
   if (ui->EqqBoxx->isChecked())
   {
        bool test2;
        test2 = E.ajouter_equipements();

       if(test2)
       {    QMessageBox::information(nullptr, QObject::tr("Equipement ajoute"),
                                     QObject::tr("ajouter avec  success.\n""Click Cancel to exit."), QMessageBox::Cancel);}

        }

       int IDSALLE=ui->id->text().toInt();
       QString NOMSALLE = ui->nomsalle->text();
       QString VILLE = ui->ville->text();
       int ZIP_CODE = ui->zipcode->text().toInt();
       QString ADRESSE = ui->adresse->text();
       int SURFACE = ui->surface->text().toInt();
       int CAPACITE = ui->capacite->text().toInt();
       QString TYPESALLE ;
       QString FORFAIT ;
       int NOMBRESALLERECEPTION;
       int x = 0 ;

       // Choix de type de la salle
       if (ui->checkBox->isChecked())
       { TYPESALLE = "Chateau" ;
           x = 1;
       }


        else if (ui->fete->isChecked())
         {   TYPESALLE = "Fetes" ;
           x = 1;
       }
        else if (ui->gite->isChecked())
        { TYPESALLE = "Gite" ;
           x = 1;
       }
        else if (ui->hotel->isChecked())
             { TYPESALLE = "Hotel" ;
           x = 1;
       }

           if (x == 0 && ui->Bbbox->isChecked())
           {
              QMessageBox::critical(nullptr, QObject::tr("TYPE MISSING!!!"),
               QObject::tr("Veuiller Saisir le type.\n""Click Cancel to exit."), QMessageBox::Cancel);

           }


               // Choix de forfait de cette salle

          if(  ui->radio_bronze->isChecked() )
          { FORFAIT = "Bronze" ; }
          if(  ui->radio_argent->isChecked() )
          { FORFAIT = "Argent" ; }
          if(  ui->radio_or->isChecked() )
          { FORFAIT = "Or" ; }
          if(  ui->radio_platine->isChecked() )
          { FORFAIT = "Platine" ; }


          // Nbre de salles de reception
          if(  ui->checkBox_45->isChecked() )
          { NOMBRESALLERECEPTION = 1 ; }
          if(  ui->checkBox_46->isChecked() )
          { NOMBRESALLERECEPTION = 2 ; }
          if(  ui->checkBox_47->isChecked() )
          { NOMBRESALLERECEPTION = 3 ; }

   salles S(IDSALLE , NOMSALLE ,VILLE , ZIP_CODE , ADRESSE, SURFACE  , CAPACITE , TYPESALLE , FORFAIT , NOMBRESALLERECEPTION );

   if (ui->Bbbox->isChecked())
    { bool test=S.ajouter();
    QMessageBox msgBox;

    if(test and x == 1)
      {
        msgBox.setText("Ajout avec succes.");
        ui->tableView->setModel(S.afficher());
        ui->tableViewEq->setModel(E.afficher_equipements());

    }
    else
       // msgBox.setText("Echec d'ajout");
        msgBox.exec();

   }
}

void gestiondessalles::on_tableView_activated(const QModelIndex &index)
{
    QString val;QSqlQuery query;


           val=ui->tableView->model()->data(index).toString();
            query.prepare("select * from SALLES where IDSALLE='"+val+"' or NOMSALLE='"+val+"' or VILLE='"+val+"'   or ZIP_CODE='"+val+"'  or ADRESSE='"+val+"' or SURFACE='"+val+"' or CAPACITE='"+val+"'   or TYPESALLE='"+val+"' or FORFAIT='"+val+"' or NOMBRESALLERECEPTION = '"+val+"'     ");
           // query.bindValue(":val",val);
            if (query.exec())
            {
                while (query.next())
                {

                    ui->ID_2->setText(query.value(0).toString());
                    //ui->lineEdit->setText(query.value(0).toString());
                    ui->NOM_2->setText(query.value(1).toString());
                    ui->VILLE_2->setText(query.value(2).toString());
                    ui->ZIP_2->setText(query.value(3).toString());
                    ui->ADRESSE_2->setText(query.value(4).toString());
                    ui->SURFACE_2->setText(query.value(5).toString());
                    ui->CAPACITE_2->setText(query.value(6).toString());

                    // Type de salles
                    if (ui->fete->isChecked())
                    { ui->fete2->setChecked(true); }
                    else if (ui->gite->isChecked())
                    { ui->gite2->setChecked(true); }
                    else if (ui->hotel->isChecked())
                    { ui->hotel2->setChecked(true); }
                    else if (ui->checkBox->isChecked())
                                     { ui->box2->setChecked(true); }


                    // Forfait des salles
                    if (ui->radio_bronze->isChecked())
                    { ui->radiobronze2->setChecked(true); }
                    else if (ui->radio_argent->isChecked())
                    { ui->radioargent2->setChecked(true); }
                    else if (ui->radio_or->isChecked())
                    { ui->radio_or2->setChecked(true); }
                    else if (ui->radio_platine->isChecked())
                                     { ui->radioPlatine2->setChecked(true); }

                   // choix de nbre de salle de reception

                    if (ui->checkBox_45->isChecked())
                    { ui->checkBox_65->setChecked(true);}
                    else if (ui->checkBox_46->isChecked())
                    {  ui->checkBox_66->setChecked(true); }
                    else if (ui->checkBox_47->isChecked())
                    { ui->checkBox_67->setChecked(true);}

                }
            }
            else
            {
                QMessageBox::critical(this ,tr("error::"),query.lastError().text());
            }
}

void gestiondessalles::on_DeleteButton_clicked()
{
    QMediaPlayer * del = new QMediaPlayer();

        salles S1; S1.setIDSALLE(ui->ID_2->text().toInt());
        bool test=S1.supprimer(S1.getIDSALLE());
        QMessageBox msgBox;

        if(test)
           {
                 ui->tableView->setModel(S1.afficher());
                    del->setMedia(QUrl("qrc:/sounds/img/del.mp3"));
                    del->play();
                    msgBox.setText("suppression avec success");

        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
}

void gestiondessalles::on_loadButton_clicked()
{
    salles S;
       ui->tableView->setModel(S.afficher());

       QMediaPlayer * table = new QMediaPlayer();
        table->setMedia(QUrl("qrc:/sounds/img/ttblel.mp3"));
                    table->play();
}

void gestiondessalles::on_ChercherButt_clicked()
{
    QString nom= ui->chercherLINE->text();
            QString ville = ui->chercherVILLE->text();
            QString forfait = ui->chercherFORFAIT->text();
            salles s;
            int id=ui->chercherID->text().toInt();

        if (ui->chercherLINE->text()!="")
        {


                if(s.verifierExnom(nom)==false)
                {QMessageBox::warning(this,"ERREUR","Salles n'existe pas");}
                else
                ui->tableView->setModel(s.chercher_salles_par_nom(nom));

        }

        else if (ui->chercherID->text()!="")
        {
            if(s.verifierID(id)==false)
            {QMessageBox::warning(this,"ERREUR","Salles n'existe pas");}
            else
            ui->tableView->setModel(s.chercher_salles_par_id(id));

        }

        else if (ui->chercherVILLE->text()!="")
        {
            if(s.verifierVille(ville)==false)
            {QMessageBox::warning(this,"ERREUR","Salles n'existe pas");}
            else
            ui->tableView->setModel(s.chercher_salles_par_ville(ville));

        }

        else if (ui->chercherVILLE->text()!="")
        {

            if(s.verifierForfait(forfait)==false)
            {QMessageBox::warning(this,"ERREUR","Salles n'existe pas");}
            else
            ui->tableView->setModel(s.chercher_salles_avancee(nom,ville,forfait));

        }

        else {

            QMessageBox::warning(this,"ERREUR","Veuillez saisir les informations a rechercher ");
        }
}

void gestiondessalles::on_comboBox_activated(const QString &arg1)
{
    salles s;
            if(arg1=="")
            {
                ui->tableView->setModel(s.afficher());
            }
            else
            ui->tableView->setModel(s.afficher_sallestrier(arg1));
}

void gestiondessalles::on_imprimButt_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
                   printer->setOutputFormat(QPrinter::NativeFormat);
                   printer->setPageSize(QPrinter::A4);
                   printer->setOrientation(QPrinter::Portrait);
                   printer->setFullPage(true);


               QPrintDialog *printDialog = new QPrintDialog(printer,this);
               printDialog->setWindowTitle("Impression PDF");
               if(printDialog->exec())
               {
                  QPainter painter;
                  if(painter.begin(printer))
                  {
                      double xscale = double(ui->tableView->width() / 65);
                      double yscale = double(ui->tableView->height() / 65);
                      painter.scale(xscale, yscale);
                      ui->tableView->render(&painter);
                      painter.end();
                  }
                  else
                  {
                      qWarning("failed to open file");
                     QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
                  }
               }

}

void gestiondessalles::on_DeleteEq_clicked()
{
    QMediaPlayer * del2 = new QMediaPlayer();
        equipements E1; E1.setID(ui->ideqED->text().toInt());
        bool test=E1.supprimer_equipements(E1.getID());
        QMessageBox msgBox;

        if(test)
           {
        ui->tableViewEq->setModel(E1.afficher_equipements());

                      del2->setMedia(QUrl("qrc:/sounds/img/del.mp3"));
                      del2->play();

        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
}

void gestiondessalles::on_tableViewEq_activated(const QModelIndex &index)
{
    QString val;QSqlQuery query;


            val=ui->tableViewEq->model()->data(index).toString();
             query.prepare("select * from EQUIPEMENTS where ID='"+val+"' or NOM='"+val+"' or QUANTITE='"+val+"'   or AUTRE='"+val+"' ");

             //query.bindValue(":val",val);
             if (query.exec())
             {
                 while (query.next())
                 {

                     ui->ideqED->setText(query.value(0).toString());
                     ui->selected->setText(query.value(1).toString());
                     ui->quantiteEDIT->setText(query.value(2).toString());
                     ui->lineEdit_33->setText(query.value(3).toString());
                     ui->IDE->setText(query.value(4).toString());
          }
             }
             else
             {
                 QMessageBox::critical(this ,tr("error::"),query.lastError().text());
             }
}

void gestiondessalles::on_loadEq_clicked()
{
    equipements E;
        ui->tableViewEq->setModel(E.afficher_equipements());
        QMediaPlayer * tableLL = new QMediaPlayer();
         tableLL->setMedia(QUrl("qrc:/sounds/img/ttblel.mp3"));
                     tableLL->play();
}

void gestiondessalles::on_ImprrimEq_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
                   printer->setOutputFormat(QPrinter::NativeFormat);
                   printer->setPageSize(QPrinter::A4);
                   printer->setOrientation(QPrinter::Portrait);
                   printer->setFullPage(true);


               QPrintDialog *printDialog = new QPrintDialog(printer,this);
               printDialog->setWindowTitle("Impression PDF");
               if(printDialog->exec())
               {
                  QPainter painter;
                  if(painter.begin(printer))
                  {
                      double xscale = double(ui->tableViewEq->width() / 65);
                      double yscale = double(ui->tableViewEq->height() / 65);
                      painter.scale(xscale, yscale);
                      ui->tableViewEq->render(&painter);
                      painter.end();
                  }
                  else
                  {
                      qWarning("failed to open file");
                     QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
                  }
               }
}

void gestiondessalles::on_Edited_clicked()
{
    bool test; QMessageBox msgBox;
        int x = 0;
       int IDSALLE=ui->ID_2->text().toInt();
       QString NOMSALLE = ui->NOM_2->text();
       QString VILLE = ui->VILLE_2->text();
       int ZIP_CODE = ui->ZIP_2->text().toInt();
       QString ADRESSE = ui->ADRESSE_2->text();
       int SURFACE = ui->SURFACE_2->text().toInt();
       int CAPACITE = ui->CAPACITE_2->text().toInt();
       QString TYPESALLE ;
       QString FORFAIT ;
       int NOMBRESALLERECEPTION;

       // Choix de forfait de cette salle

    if(  ui->radiobronze2->isChecked() )
    { FORFAIT = "Bronze" ; }
    if(  ui->radioargent2->isChecked() )
    { FORFAIT = "Argent" ; }
    if(  ui->radio_or2->isChecked() )
    { FORFAIT = "Or" ; }
    if(  ui->radioPlatine2->isChecked() )
    { FORFAIT = "Platine" ; }



    // Nbre de salles de reception
    if(  ui->checkBox_65->isChecked() )
    { NOMBRESALLERECEPTION = 1 ; }
    if(  ui->checkBox_66->isChecked() )
    { NOMBRESALLERECEPTION = 2 ; }
    if(  ui->checkBox_67->isChecked() )
    { NOMBRESALLERECEPTION = 3 ; }


    if (ui->box2->isChecked())
    { TYPESALLE = "Chateau" ;
        x = 1;
    }


     else if (ui->fete2->isChecked())
      {   TYPESALLE = "Fetes" ;
        x = 1;
    }
     else if (ui->gite2->isChecked())
     { TYPESALLE = "Gite" ;
        x = 1;
    }
     else if (ui->hotel2->isChecked())
          { TYPESALLE = "Hotel" ;
        x = 1;
    }

        if (x == 0 && ui->ID_2->text()!="")
        {
           QMessageBox::critical(nullptr, QObject::tr("TYPE MISSING!!!"),
            QObject::tr("Veuiller Saisir le type.\n""Click Cancel to exit."), QMessageBox::Cancel);

        }




        salles S(IDSALLE , NOMSALLE ,VILLE , ZIP_CODE , ADRESSE, SURFACE  , CAPACITE , TYPESALLE , FORFAIT , NOMBRESALLERECEPTION );
        test=S.modifier();
    // Pour les equipements

        int ID=ui->ideqED->text().toInt();
        QString NOM = ui->selected->text();
        int QUANTITE=ui->quantiteEDIT->text().toInt();
        QString AUTRE = ui->lineEdit_33->text();
        int IDSALLEEq = ui->IDE->text().toInt();
        equipements E(ID,NOM,QUANTITE,AUTRE,IDSALLEEq);
        bool test2 ;
        test2 = E.modifier_equipements();
        if(test2  )
              {  msgBox.setText(" Modifie avec sucess");
                ui->tableViewEq->setModel(E.afficher_equipements());

            }
            else
               // msgBox.setText("Echec");
            msgBox.exec();


    // Pour les salles
        if(test )
              {  msgBox.setText("Modifie avec sucess ");
                ui->tableView->setModel(S.afficher());

            }
            else
                msgBox.setText("Echec de modification");
            msgBox.exec();
}

void gestiondessalles::on_PDF_BUTT_clicked()
{
    QString strStream;
                         QTextStream out(&strStream);


                         const int rowCount = ui->tableView->model()->rowCount();
                         const int columnCount = ui->tableView->model()->columnCount();

                         out <<  "<html>\n"
                             "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg("strTitle")
                             <<  "</head>\n"
                            "<body bgcolor=#FFB6C1 link=#5000A0>\n"


                            //     "<align='right'> " << datefich << "</align>"
                             "<center> <H1>Liste des salles  </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
                         out <<  "   <img src=':/img/img/LOGO.png' height='45' width='45'/>  ";
                            out << " <p><strong>Our Email : contact@weeding_wishes.com </strong><br>  " ;





                         // headers
                         out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tableView->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tableView->isColumnHidden(column)) {
                                     QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table> </center>\n"
                             "</body>\n"
                             "</html>\n";

                   QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                    QPrinter printer (QPrinter::PrinterResolution);
                     printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setPaperSize(QPrinter::A4);
                   printer.setOutputFileName(fileName);

                    QTextDocument doc;
                     doc.setHtml(strStream);
                     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                     doc.print(&printer);
}

void gestiondessalles::on_NomCheckBox_clicked()
{
    if (ui->NomCheckBox->isChecked())
        ui->chercherLINE->setReadOnly(false);
        else
        ui->chercherLINE->setReadOnly(true);
}

void gestiondessalles::on_IDCheckBox_clicked()
{
    if (ui->IDCheckBox->isChecked())
      { ui->chercherID->setReadOnly(false); }
       else
           ui->chercherID->setReadOnly(true);
}

void gestiondessalles::on_VilleCheckBox_clicked()
{
    if (ui->VilleCheckBox->isChecked())
      { ui->chercherVILLE->setReadOnly(false) ; }
       else
           ui->chercherVILLE->setReadOnly(true);
}

void gestiondessalles::on_FORFAITCheckBox_clicked()
{
    if (ui->FORFAITCheckBox->isChecked())
      { ui->chercherFORFAIT->setReadOnly(false); }
       else
           ui->chercherFORFAIT->setReadOnly(true);
}

void gestiondessalles::on_editButton_clicked()
{
    ui->tabWidget->setCurrentWidget(ui->tab_8);
}


void gestiondessalles::on_NomEqCheckBox_clicked()
{
    if (ui->NomEqCheckBox->isChecked())
        { ui->Nomeqline->setReadOnly(false) ; }
        else
            ui->Nomeqline->setReadOnly(true);
}

void gestiondessalles::on_comboBoxEq_activated(const QString &arg1)
{
    equipements e;
       if(arg1=="")
       {
           ui->tableViewEq->setModel(e.afficher_equipements());
       }
       else
       ui->tableViewEq->setModel(e.afficher_equipements_trier(arg1));
}

void gestiondessalles::on_Bbbox_clicked()
{
    if(ui->Bbbox->isChecked())
        {
            QMediaPlayer * salle = new QMediaPlayer();
             salle->setMedia(QUrl("qrc:/sounds/img/Vouspouvez.mp3"));
                         salle->play();
         ui->id->setReadOnly(false);
        ui->nomsalle->setReadOnly(false);
        ui->ville->setReadOnly(false);
        ui->zipcode->setReadOnly(false);
        ui->adresse->setReadOnly(false);
        ui->surface->setReadOnly(false);
        ui->capacite->setReadOnly(false);
        ui->checkBox->setCheckable(true);
        ui->fete->setCheckable(true);
        ui->gite->setCheckable(true);
        ui->hotel->setCheckable(true);
        ui->checkBox_45->setCheckable(true);
        ui->checkBox_46->setCheckable(true);
        ui->checkBox_47->setCheckable(true);
        ui->radio_bronze->setCheckable(true);
        ui->radio_argent->setCheckable(true);
        ui->radio_or->setCheckable(true);
        ui->radio_platine->setCheckable(true);
        }
        else {

             ui->id->setReadOnly(true);
              ui->nomsalle->setReadOnly(true);
              ui->ville->setReadOnly(true);
              ui->zipcode->setReadOnly(true);
              ui->adresse->setReadOnly(true);
              ui->surface->setReadOnly(true);
              ui->capacite->setReadOnly(true);
              ui->checkBox->setCheckable(false);
              ui->fete->setCheckable(false);
              ui->gite->setCheckable(false);
              ui->hotel->setCheckable(false);
              ui->checkBox_45->setCheckable(false);
              ui->checkBox_46->setCheckable(false);
              ui->checkBox_47->setCheckable(false);
              ui->radio_bronze->setCheckable(false);
              ui->radio_argent->setCheckable(false);
              ui->radio_or->setCheckable(false);
              ui->radio_platine->setCheckable(false);


        }
}

void gestiondessalles::on_EqqBoxx_clicked()
{
    if (ui->EqqBoxx->isChecked())
        {
            QMediaPlayer * eq = new QMediaPlayer();
             eq->setMedia(QUrl("qrc:/sounds/img/Vouspouvezeq.mp3"));
                         eq->play();

        ui->ideq->setReadOnly(false);
        ui->quantite->setReadOnly(false);
        ui->autre->setReadOnly(false);
        ui->idddd->setReadOnly(false);

        ui->checkBox_cuisine->setCheckable(true);
        ui->checkBox_BA->setCheckable(true);
        ui->checkBox_51->setCheckable(true);
        ui->checkBox_52->setCheckable(true);
        ui->checkBox_53->setCheckable(true);
        ui->checkBox_54->setCheckable(true);
        ui->checkBox_57->setCheckable(true);
        ui->checkBox_55->setCheckable(true);
        ui->checkBox_56->setCheckable(true);
        ui->checkBox_60->setCheckable(true);
        ui->checkBox_58->setCheckable(true);
        ui->checkBox_59->setCheckable(true);

        }


        else {

            ui->ideq->setReadOnly(true);
            ui->quantite->setReadOnly(true);
            ui->autre->setReadOnly(true);
            ui->idddd->setReadOnly(true);
            ui->checkBox_cuisine->setCheckable(false);
            ui->checkBox_BA->setCheckable(false);
            ui->checkBox_51->setCheckable(false);
            ui->checkBox_52->setCheckable(false);
            ui->checkBox_53->setCheckable(false);
            ui->checkBox_54->setCheckable(false);
            ui->checkBox_57->setCheckable(false);
            ui->checkBox_55->setCheckable(false);
            ui->checkBox_56->setCheckable(false);
            ui->checkBox_60->setCheckable(false);
            ui->checkBox_58->setCheckable(false);
            ui->checkBox_59->setCheckable(false);


        }
}

void gestiondessalles::on_EditEqq_clicked()
{
    ui->tabWidget->setCurrentWidget(ui->tab_8);
}

void gestiondessalles::on_PdfEq_clicked()
{
    QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->tableViewEq->model()->rowCount();
                        const int columnCount = ui->tableViewEq->model()->columnCount();

                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#FFB6C1 link=#5000A0>\n"

                            "<center> <H1>Liste des equipements  </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
                        out <<  "   <img src=':/img/img/LOGO.png' height='45' width='45'/>  ";
                           out << " <p><strong>Our Email : contact@weeding_wishes.com </strong><br>  " ;





                        // headers
                        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableViewEq->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableViewEq->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->tableView->isColumnHidden(column)) {
                                    QString data = ui->tableViewEq->model()->data(ui->tableViewEq->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                }
                            }
                            out << "</tr>\n";
                        }
                        out <<  "</table> </center>\n"
                            "</body>\n"
                            "</html>\n";

                  QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                   if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                   QPrinter printer (QPrinter::PrinterResolution);
                    printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                  printer.setOutputFileName(fileName);

                   QTextDocument doc;
                    doc.setHtml(strStream);
                    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                    doc.print(&printer);
}

void gestiondessalles::on_RecherchEq_clicked()
{
    QString nomEq= ui->Nomeqline->text();
       equipements e;

        if (ui->Nomeqline->text()!="")

       {
           if (e.verifierNomEquip(nomEq)==false)
           {QMessageBox::warning(this,"ERREUR","Equipement n'existe pas");}
                   else
                   ui->tableViewEq->setModel(e.chercher_equipements_par_nom(nomEq));


       }
}

void gestiondessalles::on_ReportButt_clicked()
{
    Report R;
       R.setModal(true);
       R.exec();
}

