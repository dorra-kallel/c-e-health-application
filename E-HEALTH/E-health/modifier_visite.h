#ifndef MODIFIER_VISITE_H
#define MODIFIER_VISITE_H

#include <QDialog>
#include"visite.h"
#include <QDate>

namespace Ui {
class modifier_visite;
}

class modifier_visite : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_visite(QWidget *parent = nullptr);
    void set_nom_patient(QString);
    void set_prenom_patient(QString);
    void set_date_naiss_patient(QDate);
    void set_observation(QString);
    void set_diagnostic(QString);
    void set_id_visite(int);
    ~modifier_visite();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::modifier_visite *ui;

};

#endif // MODIFIER_VISITE_H
