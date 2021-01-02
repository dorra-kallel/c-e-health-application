#include "modifier_visite.h"
#include "ui_modifier_visite.h"
#include<QSqlQuery>
#include <QSqlQueryModel>
#include"visite.h"
#include <QMessageBox>
#include"visite.h"
#include <QDateTime>
#include<QDateEdit>
#include<QDate>



modifier_visite::modifier_visite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier_visite)
{
    ui->setupUi(this);

}
void modifier_visite::set_nom_patient(QString n)
{
  ui->nom_patient_2->setText(n) ;
}
void modifier_visite::set_prenom_patient(QString n)
{
  ui->prenom_patient->setText(n) ;
}
void modifier_visite::set_date_naiss_patient(QDate date_naiss)
{

ui->date_naiss_patient->setDate(date_naiss);
}
void modifier_visite::set_diagnostic(QString n)
{ui->diagnostic->setText(n);}
void modifier_visite::set_observation(QString n)
{ui->observation->setText(n);}

void modifier_visite::set_id_visite(int id)
{QString code=QString::number(id);
    ui->id->setText(code);}
modifier_visite::~modifier_visite()
{
    delete ui;
}

void modifier_visite::on_pushButton_clicked()
{
    QString code=ui->id->text();
    QString  nom_patient = ui->nom_patient_2->text();
    QString prenom_patient= ui->prenom_patient->text();
    QString date_naiss= ui->date_naiss_patient->date().toString("dd/MM/yyyy");
    QString observation=ui->observation->toPlainText();
    QString diagnostic =ui->diagnostic->toPlainText();

    if(nom_patient.isEmpty()|| prenom_patient.isEmpty() || date_naiss.isEmpty() || observation.isEmpty()|| diagnostic.isEmpty())
       {QMessageBox::warning(nullptr, QObject::tr("warning"),
        QObject::tr("remplissez touts les champs pour modifier.\n"
        "Click ok to exit."), QMessageBox::Ok);}
    else
    {
        visite v(nom_patient, prenom_patient , observation, diagnostic ,date_naiss);
        bool test=v.modifier(code);
        if(test)
        {
         QMessageBox::information(nullptr, QObject::tr("Modifier Visite"),
                                  QObject::tr("visite modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
   ui->id->clear();
   ui->prenom_patient->clear();
   ui->nom_patient_2->clear();
   ui->date_naiss_patient->clear();
   ui->observation->clear();
   ui->diagnostic->clear();
}

void modifier_visite::on_pushButton_2_clicked()
{
close();
}
