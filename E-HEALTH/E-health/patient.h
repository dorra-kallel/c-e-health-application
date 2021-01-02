#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include<QSqlQueryModel>
#include<QAbstractItemModel>
#include <QDate>

class patient
{
 private :
int cin;
QString nom;
QString prenom;
QDate date_de_naissance;
QString adresse;
QString email;
int numero;


public :
patient();
patient(int, QString, QString, QDate, QString, int, QString);
int get_cin(){  return cin;}
QString get_nom_patient(){  return nom;}
QString get_prenom_patient(){  return prenom;}
QString get_adresse_patient(){  return adresse;}
QDate get_date_naissance(){  return date_de_naissance;}
QString get_email_patient(){  return email;}
int get_numero_patient(){  return numero;}
bool ajouter();
QSqlQueryModel *afficher();
QSqlQueryModel * recherche (const QString &aux);
bool supprimer(QString);
bool modifier(int, QString, QString, QDate,QString,int,QString);
QSqlQueryModel * trieAlpha();
QSqlQueryModel * trieAlphaa();

QSqlQueryModel * trieCin();
QSqlQueryModel * trieCinn();

QSqlQueryModel * trieAdresse();
QSqlQueryModel * trieAdressee();

bool controlsaisiechar(QString,QString);
bool controlSaisieNumVide(int,QString);
bool controlSaisieCharVide (QString,QString);
bool controlsaisieMail(QString saisi);

};


#endif // PATIENT_H
