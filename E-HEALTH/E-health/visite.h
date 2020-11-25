#ifndef VISTIE_H
#define VISTIE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "QDate"
class visite
{
public:
    visite();
    visite(QString,QString,QString,QString,QString,QString);
QString get_nom_patient();
QString get_prenom_patient();
QString get_date_naiss_patient();
QString get_acte_medical();
QString get_observation();
QString get_diagnostic();
bool ajouter();
bool supprimer(QString);
QSqlQueryModel * afficher();
QSqlQueryModel * afficher_asc();
QSqlQueryModel * afficher_desc();
QSqlQueryModel * afficher_rechrerche(QString);
private:

QString nom_patient,prenom_patient,acte_medical,observation,diagnostic;
QString date_naiss_patient;
};


#endif // VISTIE_H
