#ifndef GESTIONDERESERVATION_H
#define GESTIONDERESERVATION_H

#include <QDialog>
#include "arduino.h"
namespace Ui {
class gestiondereservation;
}

class gestiondereservation : public QDialog
{
    Q_OBJECT

public:
    explicit gestiondereservation(QWidget *parent = nullptr);
    ~gestiondereservation();
void par_defaut();

private slots:
    void on_pushButtonajouter_clicked();
    void updatelabel();

    void on_pushButtonsupprimerclient_clicked();




    void on_tabWidget_4_currentChanged(int index);

    void on_pushButton_2_clicked();



    void on_tableView_2_activated(const QModelIndex &index);



    void on_pushButtonchercher_clicked();


    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    QString on_checkBox_2_clicked();



    void on_pushButtonajouterreservation_clicked();

    void on_pushButtonsupprimerclient_2_clicked();

    void on_pushButton_5_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButtonchercher_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_modifierreservation_clicked();

    void on_pushButtonsupprimerreservation_2_clicked();

    void on_pushButton_enregistrerreservation_clicked();

    void on_pushButton_imprimerreservation_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_lineEditnom_7_cursorPositionChanged(int arg1, int arg2);

    void on_lineEditprenom_8_cursorPositionChanged(int arg1, int arg2);

    void on_lineEditidreservation_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButtonactiver_clicked();

    void on_pushButtondeactiver_clicked();

private:
    Ui::gestiondereservation *ui;
    QByteArray data;
    Arduino A ;

};

#endif // GESTIONDERESERVATION_H
