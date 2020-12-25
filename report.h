#ifndef REPORT_H
#define REPORT_H

#include <QDialog>

#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include "ui_report.h"

namespace Ui {
class Report;
}

class Report : public QDialog
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = nullptr);
    ~Report();

private slots:
    void sendMail();
    void mailSent(QString);

private:
    Ui::Report *ui;
};



#endif // REPORT_H
