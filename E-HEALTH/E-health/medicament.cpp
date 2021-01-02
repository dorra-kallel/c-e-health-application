#include "medicament.h"
#include<QMessageBox>
#include <QDebug>
#include<QSqlQuery>
#include"visite.h"
#include "visite.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
// gerer ordonnance


medicament::medicament()
{
code_med="";
libelle="";
mode="";
frequence="";
qts=0;
}

medicament :: medicament(QString code_med,QString libelle ,QString mode,QString frequence,int qts)
{

 this->code_med=code_med;
 this->libelle=libelle;
 this->mode=mode;
 this->frequence=frequence;
 this->qts=qts;
}

bool medicament::ajouter()
{
QSqlQuery query;
 query.prepare("INSERT INTO ordonnance(CODE_MED,LIBELLE,MODE_U,FREQUENCE,QTS,ID_VISITE_O) VALUES (:code_med,:libelle,:mode,:frequence,:qts, (select max(id_visite)from visite))");
 query.bindValue(":code_med", code_med);
 query.bindValue(":libelle", libelle);
 query.bindValue(":mode", mode);
 query.bindValue(":frequence",frequence);
 query.bindValue(":qts",qts);

 return    query.exec();
}
bool medicament::modifier()
{
 QSqlQuery query;
 query.prepare("update ordonnance set CODE_MED=:code_med, LIBELLE= :libelle , MODE_U= :mode,FREQUENCE= :frequence,QTS= :qts where CODE_MED=:code_med");
 query.bindValue(":code_med", code_med);
 query.bindValue(":libelle", libelle);
 query.bindValue(":mode", mode);
 query.bindValue(":frequence",frequence);
 query.bindValue(":qts",qts);

 return    query.exec();
}
QSqlQueryModel *  medicament::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();




    model->setQuery("select * from ordonnance where id_visite_o=(select max(id_visite) from visite)");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_MED"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODE_U"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("FREQUENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("QTS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_VISITE"));
    return model;
}
bool medicament::supprimer(QString code_med)
{
QSqlQuery query;
QString res= code_med;
query.prepare("Delete from ordonnance where code_med = '"+res+"' ");

return    query.exec();
}
QSqlQueryModel * medicament ::afficher_ord_visite(QString val)
{
     QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
     model->setQuery("select * from ordonnance where id_visite_o='"+val+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CODE_MED"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MODE_U"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("FREQUENCE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("QTS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_VISITE"));
    return model;
}
