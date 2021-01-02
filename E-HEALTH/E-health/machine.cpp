#include "machine.h"


machine::machine(int code,QString nom,int reference,QString mode_aquisation)
{

    this->code=code;
        this->nom=nom;
        this->reference=reference;
    this->mode_aquisation=mode_aquisation;
    }


int machine::get_code(){return code;}
QString machine::get_nom(){return nom;}
int machine::get_reference(){return reference;}
QString machine::get_mode(){return mode_aquisation;}
bool machine::ajouter()
{
    QSqlQuery query;

   query.prepare("INSERT INTO machine(code,nom,reference,mode_aquisation)"
                 "VALUES(:code,:nom,:reference,:mode_aquisation)");
   query.bindValue(":code",code);
     query.bindValue(":nom",nom);
       query.bindValue(":reference",reference);
      query.bindValue(":mode_aquisation",mode_aquisation);
       return query.exec();
}
QSqlQueryModel *machine::afficher1()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from machine");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mode_aquisation"));
    return model;
}
bool machine::supprimer1(int code)
{

  QSqlQuery query ;
QString res=QString::number(code) ;
query.prepare("delete from machine where CODE= :code");
query.bindValue(":code",res);
return query.exec();



}
