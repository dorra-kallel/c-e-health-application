#include "fournisseur.h"
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
fournisseur::fournisseur()
{ id=0;
    nom=" ";
    specialite="";
    num_tel=0;
    adresse=" ";

}
fournisseur::fournisseur(QString nom,int id,QString specialite,QString adresse,int num_tel)
{ this->nom=nom;
  this->id=id;
  this->specialite=specialite;
  this->adresse=adresse;
  this->num_tel=num_tel;
}

int fournisseur::get_id()
{return id;}
QString fournisseur::get_nom()
{return nom;}
QString fournisseur::get_adresse()
{return adresse;}
int fournisseur ::get_num_tel()
{return num_tel;}
QString fournisseur::get_specialite()
{return specialite;}

bool fournisseur ::ajouter()
{
    QSqlQuery query;

    query .prepare("INSERT INTO fournisseur(NOM,ID,SPECIALITE,ADRESSE,NUM_TEL)VALUES(:nom,:id,:specialite,:adresse,:num_tel)");
    query.bindValue(":nom",nom);
    query.bindValue(":id",id);
    query.bindValue(":specialite",specialite);
    query.bindValue(":adresse",adresse);
    query.bindValue(":num_tel",num_tel);


    return query .exec();

}

QSqlQueryModel * fournisseur ::afficher()
{QSqlQueryModel * model =new QSqlQueryModel();
    model ->setQuery("select * from fournissuer");
    model->setHeaderData(0,Qt::Horizontal,QObject ::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject ::tr("id"));
    model->setHeaderData(2,Qt::Horizontal,QObject ::tr("specialite"));
    model->setHeaderData(3,Qt::Horizontal,QObject ::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject ::tr("num_tel"));
    return model;
}

QSqlQueryModel * fournisseur ::affichertri()
{QSqlQueryModel * model =new QSqlQueryModel();
    model ->setQuery("select * from fournisseur order by id");
    model->setHeaderData(0,Qt::Horizontal,QObject ::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject ::tr("id"));
    model->setHeaderData(2,Qt::Horizontal,QObject ::tr("specialite"));
    model->setHeaderData(3,Qt::Horizontal,QObject ::tr("adresse"));
    model->setHeaderData(4,Qt::Horizontal,QObject ::tr("num_tel"));
    return model;


}



bool fournisseur ::supprimer(int idd)
{QSqlQuery query;
 QString res =QString ::number(idd);
 query .prepare("delete from fournisseur where id =:id ");
 query .bindValue(":id",res);
 return query .exec();
}


bool fournisseur:: modifier(int,int ,QString,QString,QString)
{
QSqlQuery qry;
        qry.prepare("UPDATE fournisseur set SPECIALITE=(?),NUM_TEL=(?),NOM=(?),ADRESSE=(?) where ID=(?) ");
        qry.addBindValue(specialite);
        qry.addBindValue(num_tel);
        qry.addBindValue(nom);
        qry.addBindValue(adresse);
        qry.addBindValue(id);
return  qry.exec();

}









