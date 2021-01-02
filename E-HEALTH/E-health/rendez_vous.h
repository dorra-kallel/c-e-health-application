#ifndef RENDEZ_VOUS_H
#define RENDEZ_VOUS_H

#include <QString>
#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include<QSqlQueryModel>
#include<QAbstractItemModel>
#include <QDate>

class rendez_vous
{
private:
    int id;
    int cin_patient;
    QString nom;
    QString prenom;
    QDateTime  date_rdv;
    QString docteur;
    public:
    rendez_vous();
    rendez_vous(int,QString,QString,QDateTime ,QString);
    int get_id(){  return id;}
    int get_cin_patient(){  return cin_patient;}
    QString get_nom_patient(){  return nom;}
    QString get_prenom_patient(){  return prenom;}
    QDateTime  get_date_rdv(){  return date_rdv;}
    QString get_nom_docteur(){  return docteur;}
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier(int,QString,QString,QDateTime,QString);
    bool supprimer(QString);
    QSqlQueryModel * triePatient();
    QSqlQueryModel * trieDocteur();
      QSqlQueryModel * trieDocteurr();
    QSqlQueryModel * trieDate();
    QSqlQueryModel * trieDatee();

    QSqlQueryModel* triePatientt();
    QSqlQueryModel *recherche (const QString &aux);
bool controlsaisiechar(QString,QString);
bool controlSaisieCharVide (QString,QString);


    };


#endif // RENDEZ_VOUS_H
