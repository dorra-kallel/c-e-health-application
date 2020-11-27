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

   query.prepare("INSERT INTO table2(code,nom,reference,mode_aquisation)"
                 "VALUES(:code,:nom,:reference,:mode_aquisation)");
   query.bindValue(":code",code);
     query.bindValue(":nom",nom);
       query.bindValue(":reference",reference);
      query.bindValue(":mode_aquisation",mode_aquisation);
       return query.exec();
}
QSqlQueryModel *machine::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from table2");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_aquisation"));
    return model;
}
bool machine::supprimer(int code)
{

  QSqlQuery query ;
QString res=QString::number(code) ;
query.prepare("delete from table2 where CODE= :code");
query.bindValue(":code",res);
return query.exec();



}
