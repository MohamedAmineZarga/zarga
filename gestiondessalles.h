#ifndef GESTIONDESSALLES_H
#define GESTIONDESSALLES_H

#include <QDialog>

namespace Ui {
class gestiondessalles;
}

class gestiondessalles : public QDialog
{
    Q_OBJECT

public:
    explicit gestiondessalles(QWidget *parent = nullptr);
    ~gestiondessalles();

private slots:
    void on_loadEq_clicked();

    void on_Add_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_DeleteButton_clicked();

    void on_loadButton_clicked();

    void on_ChercherButt_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_imprimButt_clicked();

    void on_DeleteEq_clicked();

    void on_tableViewEq_activated(const QModelIndex &index);

    void on_ImprrimEq_clicked();

    void on_editButton_clicked();

    void on_EditEqq_clicked();

    void on_Edited_clicked();

    void on_PDF_BUTT_clicked();

    void on_NomCheckBox_clicked();

    void on_IDCheckBox_stateChanged(int arg1);

    void on_IDCheckBox_clicked();

    void on_VilleCheckBox_clicked();

    void on_FORFAITCheckBox_stateChanged(int arg1);

    void on_FORFAITCheckBox_clicked();

    void on_NomEqCheckBox_clicked();

    void on_comboBoxEq_activated(const QString &arg1);

    void on_Bbbox_clicked();

    void on_EqqBoxx_clicked();

    void on_PdfEq_clicked();

    void on_RecherchEq_clicked();

    void on_ReportButt_clicked();

    void on_EqqBoxx_stateChanged(int arg1);

private:
    Ui::gestiondessalles *ui;
};

#endif // GESTIONDESSALLES_H
