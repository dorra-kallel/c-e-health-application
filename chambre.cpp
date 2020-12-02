
#include "chambre.h"


chambre::chambre(int code,int etage,int numero)
{
this->code=code;
    this->etage=etage;
    this->numero=numero;
}

int chambre::get_code(){return code;}
int chambre::get_etage(){return etage;}
int chambre::get_numero(){return numero;}


bool chambre::ajouter()
{
    QSqlQuery query;

   query.prepare("INSERT INTO table1(code,etage,numero)"
                 "VALUES(:code,:etage,:numero)");
   query.bindValue(":code",code);
     query.bindValue(":etage",etage);
       query.bindValue(":numero",numero);
       return query.exec();
}
QSqlQueryModel *chambre::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select *from table1");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("etage"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("numero"));
    return model;
}
bool chambre::supprimer(int code)
{

  QSqlQuery query ;
QString res=QString::number(code) ;
query.prepare("delete from table1 where CODE= :code");
query.bindValue(":code",res);
return query.exec();



}
QSqlQueryModel *chambre ::chercher(const QString &code){
QSqlQuery query;
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from table1 where (code LIKE '"+code+"%')");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etage"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero"));


    return model;
}
QSqlQueryModel * chambre:: afficher_tri_code()
 {
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM table1 order by code");
       q->exec();
       model->setQuery(*q);
       return model;
 }
QSqlQueryModel * chambre:: afficher_tri_etage()
 {
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM table1 order by etage");
       q->exec();
       model->setQuery(*q);
       return model;
 }
QSqlQueryModel * chambre:: afficher_tri_numero()
 {
    QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model = new  QSqlQueryModel ();
       q->prepare("SELECT * FROM table1 order by numero");
       q->exec();
       model->setQuery(*q);
       return model;
 }


