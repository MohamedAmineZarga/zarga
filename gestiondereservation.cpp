#include "gestiondereservation.h"
#include "ui_gestiondereservation.h"
#include "client.h"
#include "reservation.h"
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QSqlError>



gestiondereservation::gestiondereservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestiondereservation)
{client c1;reservation r1;
    ui->setupUi(this);
    ui->tableView_2->setModel(c1.afficher_client());
    ui->tableView_3->setModel(r1.afficher_reservation());
    int ret =A.connect_arduino();//lancer la connection to arduino
    switch (ret) {

    case(0):qDebug()<<"arduino is available and connect to : "<<A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available and not  connect to : "<<A.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available ";
        break;

    }
    QObject::connect(A.getserial(),SIGNAL(readyRead),this,SLOT(update_label()));

}
void gestiondereservation::updatelabel()
{
    data=A.read_from_arduino();

    if (data=="1")

        ui->label_6->setText("il ya une quantite importante de gaz dans la salle s'il vous palit activer le sonor");//afficher on si les données reçues par arduino est 1

    else if(data=="0")

           ui->label_6->setText("il n'y a pas de gas dans la salle");
}
gestiondereservation::~gestiondereservation()
{
    delete ui;
}

void gestiondereservation::on_pushButtonajouter_clicked()
{QMessageBox msgBox;
    int id;
    id=ui->lineEditcin->text().toInt();
    QString nom=ui->lineEditnom->text();
    QString prenom=ui->lineEditprenom->text();
    QString date=ui->dateEdit_2->text();
    QString adresse=ui->lineEditadresse->text();
    int  numero=ui->lineEditnumero->text().toInt();
    QString email=ui->lineEditemail->text();
    QString sexe=ui->lineeditsexe->text();
    QString nums=QString::number(numero);
    client c(id,nom,prenom,date,adresse,email,numero,sexe);
    if(ui->lineEditcin->text().size()==8){
    if(nums.size()==8)
    {
 if((sexe=="male"||sexe=="female" )){
 bool test=c.ajouter_client();
if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tableView_2->setModel(c.afficher_client());
 }
 else
     msgBox.setText("Echec d'ajout");
}else
     msgBox.setText("svp verifier votre sexe : male ou female");
}
    else msgBox.setText("svp verifier votre numero de telephone");
}
    else msgBox.setText("svp verifier votre numero de carte d'identite");
 msgBox.exec();
}


void gestiondereservation::on_pushButtonsupprimerclient_clicked()
{
    client c1;
    if(ui->lineeditcinsup->text()!="")
    {    c1.setcin(ui->lineeditcinsup->text().toInt());
    bool test=c1.supprimer_client(c1.getcin());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
        ui->tableView_2->setModel(c1.afficher_client());

    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}
}



void gestiondereservation::on_pushButton_2_clicked()
{bool test; QMessageBox msgBox;
    if(ui->lineeditcinsup->text()!=""){
    int cin=ui->lineeditcinsup->text().toInt();
    QString nom=ui->lineEditnom_6->text();
    QString prenom=ui->lineEditprenom_7->text();
    QString date=ui->lineEditdate_7->text();
    int numero=ui->lineEditnumero_7->text().toInt();
    QString sexe=ui->lineeditsexe_7->text();
    QString email=ui->lineEditemail_7->text();
    QString adresse=ui->lineEditadresse_7->text();


    client c(cin,nom,prenom,date,adresse,email,numero,sexe);
     test=c.modifier_client();

     if(test)
       {  msgBox.setText("Modifier avec succes.");
         ui->tableView_2->setModel(c.afficher_client());
     }
     else
         msgBox.setText("Echec de modification");}
    else
    msgBox.setText("s'il vous plait remplir les champs à modifier");
     msgBox.exec();
}

void gestiondereservation::on_tableView_2_activated(const QModelIndex &index)
{QString val;QSqlQuery query;


    val=ui->tableView_2->model()->data(index).toString();
   int  x=ui->tableView_2->model()->data(index).toInt();

     query.prepare("select * from client where cin=:x or nom =:val or prenom=:val or datee=:val or adresse=:val or email=:val or numero=:x or sexe=:val ");
     query.bindValue(":val",val);
     query.bindValue(":x",x);

     if (query.exec())
     {
         while (query.next())
         {
             ui->lineeditcinsup->setText(query.value(0).toString());
             ui->lineEditnom_6->setText(query.value(1).toString());
             ui->lineEditprenom_7->setText(query.value(2).toString());
             ui->lineEditdate_7->setText(query.value(3).toString());
             ui->lineEditadresse_7->setText(query.value(4).toString());
             ui->lineEditemail_7->setText(query.value(5).toString());
             ui->lineEditnumero_7->setText(query.value(6).toString());
             ui->lineeditsexe_7->setText(query.value(7).toString());


         }
     }
     else
     {
         QMessageBox::critical(this ,tr("error::"),query.lastError().text());
     }
}





void gestiondereservation::on_pushButtonchercher_clicked()
{QMessageBox m;
        client c;
        if(ui->lineeditcinsup_2->text()!="" && ui->lineEditnom_7->text()!="" && ui->lineEditprenom_8->text()!="")
        {
        c.chercher_client(ui->lineeditcinsup_2->text().toInt(),ui->lineEditnom_7->text(),ui->lineEditprenom_8->text());
        ui->tableView_2->setModel(c.afficher_unclient());
        }
       else if(ui->lineeditcinsup_2->text()=="" && ui->lineEditnom_7->text()!="" and ui->lineEditprenom_8->text()!="")
        { c.chercher_clientnp(ui->lineEditnom_7->text(),ui->lineEditprenom_8->text());
            ui->tableView_2->setModel(c.afficher_clientnp(ui->lineEditnom_7->text(),ui->lineEditprenom_8->text()));}
        else if (ui->lineeditcinsup_2->text()!="" && ui->lineEditnom_7->text()=="" && ui->lineEditprenom_8->text()=="")
        { c.chercher_client(ui->lineeditcinsup_2->text().toInt());
            ui->tableView_2->setModel(c.afficher_clientc(ui->lineeditcinsup_2->text()));}
        else if (ui->lineeditcinsup_2->text()=="" && ui->lineEditnom_7->text()!="" && ui->lineEditprenom_8->text()=="")
        { c.chercher_client(ui->lineEditnom_7->text());
            ui->tableView_2->setModel(c.afficher_clientn(ui->lineEditnom_7->text()));}
        else if (ui->lineeditcinsup_2->text()=="" && ui->lineEditnom_7->text()=="" && ui->lineEditprenom_8->text()!="")
        { c.chercher_clientp(ui->lineEditprenom_8->text());
            ui->tableView_2->setModel(c.afficher_client(ui->lineEditprenom_8->text()));}
        else if(ui->lineeditcinsup_2->text()=="" && ui->lineEditnom_7->text()=="" && ui->lineEditprenom_8->text()=="")
        {
            m.setText("s'il vous plait ecrire le cin et le nom et le prenom du client à chercher");
            m.exec();}

}





void gestiondereservation::on_comboBox_activated(const QString &arg1)
{client c;
    if(arg1=="")
    {
        ui->tableView_2->setModel(c.afficher_client());
    }
    else
    ui->tableView_2->setModel(c.afficher_clienttrier(arg1));
}

void gestiondereservation::on_pushButton_7_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)
            return;
}

void gestiondereservation::on_pushButton_3_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView_2->model()->rowCount();
                     const int columnCount = ui->tableView_2->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des clients </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_2->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_2->isColumnHidden(column)) {
                                 QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
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


//   reservation :
void gestiondereservation::on_pushButtonajouterreservation_clicked()
{
    QMessageBox msgBox;
     int id=ui->lineEditidreservation->text().toInt();
     int cinc=ui->lineEditcinclient->text().toInt();
     QString date=ui->dateEdit->text();
     int idsalle=ui->lineEditsalle->text().toInt();
     int idcol=ui->lineEditcol->text().toInt();
     int nbinvite=ui->lineEditnbinvite->text().toInt();
     float budget=ui->lineEditbudget->text().toFloat();
     QString note=ui->lineEditnote->text();
     reservation r(id,cinc,date,idsalle,idcol,nbinvite,budget,note);
     client c;
     bool test2=c.chercher_client(cinc);

     bool test=r.ajouter_reservation();
    if(test&&test2==true)
       {  msgBox.setText("Ajout avec succes.");
         ui->tableView_3->setModel(r.afficher_reservation());
     }
     else{
         msgBox.setText("Echec d'ajout");
         msgBox.setText("il n y a pas de client avec ce cin");}
     msgBox.exec();

}



void gestiondereservation::on_tableView_3_activated(const QModelIndex &index)
{QString val;QSqlQuery query;

     val=ui->tableView_3->model()->data(index).toString();
     query.prepare("select * from reservation where id=:val or cinc=:val ");
     query.bindValue(":val",val);
     if (query.exec())
     {
         while (query.next())
         {
             ui->lineEditidreservation_3->setText(query.value(0).toString());
             ui->lineEditcinclient_3->setText(query.value(1).toString());
             ui->lineEdit->setText(query.value(2).toString());
             ui->lineEditsalle_2->setText(query.value(3).toString());
             ui->lineEditcol_2->setText(query.value(4).toString());
             ui->lineEditnbinvite_2->setText(query.value(5).toString());
             ui->lineEditbudget_2->setText(query.value(6).toString());
             ui->lineEditnote_2->setText(query.value(7).toString());


         }
     }
     else
     {
         QMessageBox::critical(this ,tr("error::"),query.lastError().text());
     }
}

void gestiondereservation::on_pushButtonchercher_2_clicked()
{reservation r;QMessageBox msgBox;bool test;
    if((ui->lineEditidreservation_2->text()!="" )&& (ui->lineEditcinclient_2->text()=="") && (ui->dateEdit_3->text()=="01/01/2000")){
        test=r.chercher_reservationid(ui->lineEditidreservation_2->text().toInt());
        if(test==false){ui->tableView_3->setModel(r.afficher_reservationid(ui->lineEditidreservation_2->text()));}
        else msgBox.setText("il n'existe pas de reservation avec ce identifiant");
    }else if((ui->lineEditidreservation_2->text()=="") && (ui->lineEditcinclient_2->text()!="")&& (ui->dateEdit_3->text()=="01/01/2000"))
    {
        test=r.chercher_reservationcinc(ui->lineEditcinclient_2->text().toInt());
        if(test==false){ui->tableView_3->setModel(r.afficher_reservationcinc(ui->lineEditcinclient_2->text()));}
        else msgBox.setText("il n'existe pas des reservation avec ce cin");
    }
    else if ((ui->lineEditidreservation_2->text()=="") && (ui->lineEditcinclient_2->text()=="")&& (ui->dateEdit_3->text()!="01/01/2000"))
    {
        test=r.chercher_reservationdate(ui->dateEdit_3->text());
        if(test==false){ui->tableView_3->setModel(r.afficher_reservationdate(ui->dateEdit_3->text()));}
        else msgBox.setText("il n'existe pas des reservation avec cette date");
    }else if((ui->lineEditidreservation_2->text()!="") && (ui->lineEditcinclient_2->text()!="")&& (ui->dateEdit_3->text()=="01/01/2000"))
    {
        test=r.chercher_reservationidcin(ui->lineEditidreservation_2->text().toInt(),ui->lineEditcinclient_2->text().toInt());
        if(test==false){ui->tableView_3->setModel(r.afficher_reservationidcin(ui->lineEditcinclient_2->text().toInt(),ui->lineEditcinclient_2->text().toInt()));}
        else msgBox.setText("il n'existe pas des reservation avec cet id et ce cin ");
    }else if((ui->lineEditidreservation_2->text()!="") && (ui->lineEditcinclient_2->text()=="")&& (ui->dateEdit_3->text()!="01/01/2000"))
    {
        test=r.chercher_reservationiddate(ui->lineEditidreservation_2->text().toInt(),ui->dateEdit_3->text());
        if(test==false){ui->tableView_3->setModel(r.afficher_reservationiddate(ui->lineEditidreservation_2->text().toInt(),ui->dateEdit_3->text()));}
        else msgBox.setText("il n'existe pas des reservation avec cet id et cette date");
    }else if ((ui->lineEditidreservation_2->text()=="") && (ui->lineEditcinclient_2->text()!="")&& (ui->dateEdit_3->text()!="01/01/2000"))
    {
        test=r.chercher_reservationcindate(ui->lineEditcinclient_2->text().toInt(),ui->dateEdit_3->text());
        if(test==false){ui->tableView_3->setModel(r.afficher_reservationcindate(ui->lineEditcinclient_2->text().toInt(),ui->dateEdit_3->text()));}
        else msgBox.setText("il n'existe pas des reservation avec ce cin et cette date");
    }else if ((ui->lineEditidreservation_2->text()!="") && (ui->lineEditcinclient_2->text()!="")&& (ui->dateEdit_3->text()!="01/01/2000"))
    {
        test=r.cherhcer_reservationidcindate(ui->lineEditidreservation_2->text().toInt(),ui->lineEditcinclient_2->text().toInt(),ui->dateEdit_3->text());
        if(test==false){ui->tableView_3->setModel(r.afficher_reservationidcindate(ui->lineEditidreservation_2->text().toInt(),ui->lineEditcinclient_2->text().toInt(),ui->dateEdit_3->text()));}
        else msgBox.setText("il n'existe pas des reservation avec cet id et ce cin et cette date");
    }else
     msgBox.setText("s'il vous donne moi au mois l'identifiant ou le cin de client ou la date");
        msgBox.exec();
}


void gestiondereservation::on_pushButton_modifierreservation_clicked()
{
    bool test,test2; QMessageBox msgBox;

        if(ui->lineEditidreservation_3->text()!=""){

        int id=ui->lineEditidreservation_3->text().toInt();
        int cinc=ui->lineEditcinclient_3->text().toInt();
        int idsalle=ui->lineEditsalle_2->text().toInt();
        int idcol=ui->lineEditcol_2->text().toInt();
        int nbinvite=ui->lineEditnbinvite_2->text().toInt();
        int budget=ui->lineEditbudget_2->text().toInt();
        QString note=ui->lineEditnote_2->text();
        QString date=ui->lineEdit->text();
        client c;
        test2=c.chercher_client(cinc);

        reservation r1(id,cinc,date,idsalle,idcol,nbinvite,budget,note);
         test=r1.modifier_reservation();

         if(test&&test2==true)
           {  msgBox.setText("Modifier avec succes.");
             ui->tableView_3->setModel(r1.afficher_reservation());
         }
         else{
             //msgBox.setText("Echec de modification");
             msgBox.setText("il n y a pas de client avec ce cin");}
         }else
             msgBox.setText("s'il vous plait donner l'identifiant de reservation à modifier");
         msgBox.exec();
}

void gestiondereservation::on_pushButtonsupprimerreservation_2_clicked()
{
    QMessageBox msgBox; reservation r1;
     if(ui->lineEditidreservation_3->text()!="")
     {    r1.setid(ui->lineEditidreservation_3->text().toInt());
     bool test=r1.supprimer_reservation(r1.getid());


     if(test)
        { msgBox.setText("Suppression avec succes.");
         ui->tableView_3->setModel(r1.afficher_reservation());

     }
     else
         msgBox.setText("Echec de suppression");
     }else
         msgBox.setText("s'il vous plait donner l'identifiant de reservation à supprimer");
     msgBox.exec();
}

void gestiondereservation::on_pushButton_enregistrerreservation_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView_3->model()->rowCount();
                     const int columnCount = ui->tableView_3->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des reservation </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_3->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_3->isColumnHidden(column)) {
                                 QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
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
void gestiondereservation::on_pushButton_imprimerreservation_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)
            return;
}



void gestiondereservation::on_comboBox_3_activated(const QString &arg1)
{
    reservation r1;
        if(arg1==""){
            ui->tableView_3->setModel(r1.afficher_reservation());}
         else{
            ui->tableView_3->setModel(r1.trie(arg1));

        }
}



void gestiondereservation::on_lineEditnom_7_cursorPositionChanged(int arg1, int arg2)
{
    client c;
                QString inputValue,filterChecked;
                inputValue=ui->lineEditnom_7->text();
                ui->tableView_2->setModel(c.rechercherdynamique(inputValue,"nom"));
}

void gestiondereservation::on_lineEditprenom_8_cursorPositionChanged(int arg1, int arg2)
{
    client c;
                QString inputValue,filterChecked;
                inputValue=ui->lineEditprenom_8->text();
                ui->tableView_2->setModel(c.rechercherdynamique(inputValue,"prenom"));
}
void gestiondereservation::on_pushButtonactiver_clicked()
{
    A.write_to_arduino("1");
}

void gestiondereservation::on_pushButtondeactiver_clicked()
{
    A.write_to_arduino("0");
}
