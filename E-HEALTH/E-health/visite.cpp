#include "visite.h"
#include<QMessageBox>
#include <QDebug>
#include<QSqlQuery>
visite::visite()
{

  nom_patient="";
  prenom_patient="";
  acte_medical="";
  observation="";
  diagnostic="";
  date_naiss_patient="";
}

visite::visite(QString nom_patient,QString prenom_patient ,QString acte_medical,QString observation,QString diagnostic ,QString date_naiss_patient)
{

 this->nom_patient=nom_patient;
 this->prenom_patient=prenom_patient;
 this->acte_medical=acte_medical;
 this->observation=observation;
 this->diagnostic=diagnostic;
 this->date_naiss_patient=date_naiss_patient;
}



QString visite ::get_nom_patient(){return nom_patient;}
QString visite:: get_prenom_patient(){return  prenom_patient;}
QString  visite:: get_date_naiss_patient(){return date_naiss_patient;}
QString visite:: get_acte_medical(){return acte_medical;}
QString visite:: get_observation(){return  observation;}
QString visite:: get_diagnostic(){return  diagnostic;}




bool visite :: ajouter()
{
QSqlQuery query;
query.prepare("insert into visite(DATE_VISITE,NOM_PATIENT,PRENOM_PATIENT,DATE_NAISS_PATIENT,ACTE_MEDICAL,OBSERVATION,DIAGNOSTIC)values(sysdate,:nom_patient,:prenom_patient,:date_naiss_patient,:acte_medical,:observation,:diagnostic)");

query.bindValue(":nom_patient",nom_patient);
query.bindValue(":prenom_patient",prenom_patient);
query.bindValue(":date_naiss_patient",date_naiss_patient);
query.bindValue(":acte_medical",acte_medical);
query.bindValue(":observation",observation);
query.bindValue(":diagnostic",diagnostic);
return  query.exec();
}

QSqlQueryModel *  visite::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from visite");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VISITE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VISITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISS_PATIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ACTE_MEDICAL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("OBSERVATION"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DIAGNOSTIC"));
    return model;


}
bool visite::supprimer(QString id_visite)
{
    QSqlQuery query;
    QString res= id_visite;
    query.prepare("Delete from visite where id_visite = '"+res+"' ");

    return    query.exec();
}
QSqlQueryModel *  visite::afficher_asc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from visite order by id_visite");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VISITE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VISITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISS_PATIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ACTE_MEDICAL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("OBSERVATION"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DIAGNOSTIC"));
    return model;


}
QSqlQueryModel *  visite::afficher_desc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from visite order by id_visite desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VISITE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VISITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISS_PATIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ACTE_MEDICAL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("OBSERVATION"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DIAGNOSTIC"));
    return model;


}
QSqlQueryModel *  visite::afficher_rechrerche(QString q)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from visite where nom_patient like '%"+q+"%' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_VISITE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_VISITE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISS_PATIENT"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ACTE_MEDICAL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("OBSERVATION"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DIAGNOSTIC"));
    return model;


}
