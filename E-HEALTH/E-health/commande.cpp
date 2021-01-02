#include "commande.h"
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
commande::commande()
{ code=0;
    datecommande=" ";
    type=" ";
    quantite=0;
    nom=" ";
    id_four=0;

}
commande::commande(int code,QString datecommande,QString type,int quantite,QString nom,int id_four)
{ this->code=code;
  this->datecommande=datecommande;
  this->type=type;
 this->quantite=quantite;
  this->nom=nom;
    this->id_four=id_four;

}
 int commande ::get_code()
 {return code;}
 int commande::get_id_four()
 {return id_four;}
 QString commande ::get_date_commande()
 {return datecommande;}
 QString commande ::get_type()
 {return type;}
 int commande ::get_quantite()
 {return quantite;}
 QString commande ::get_nom()
 {return nom;}

 bool commande ::ajouter()
 {
     QSqlQuery query;

     query .prepare("INSERT INTO commande(CODE,DATECOMMANDE,TYPE,QUANTITE,NOM,ID_FOUR)VALUES(:code,:datecommande,:type,:quantite,:nom,:id_four)");
     query.bindValue(":code",code);
     query.bindValue(":datecommande",datecommande);
     query.bindValue(":type",type);
     query.bindValue(":quantite",quantite);
     query.bindValue(":nom",nom);
     query.bindValue(":id_four",id_four);


     return query .exec();

 }

 QSqlQueryModel * commande ::afficher()
 {QSqlQueryModel * model =new QSqlQueryModel();
     model ->setQuery("select * from commande");
     model->setHeaderData(0,Qt::Horizontal,QObject ::tr("code"));
     model->setHeaderData(1,Qt::Horizontal,QObject ::tr("datecommande"));
     model->setHeaderData(2,Qt::Horizontal,QObject ::tr("type"));
     model->setHeaderData(3,Qt::Horizontal,QObject ::tr("quantite"));
     model->setHeaderData(4,Qt::Horizontal,QObject ::tr("nom"));
     return model;


 }
 QSqlQueryModel * commande ::affichertri()
 {QSqlQueryModel * model =new QSqlQueryModel();
     model ->setQuery("select * from commande order by code");
     model->setHeaderData(0,Qt::Horizontal,QObject ::tr("code"));
     model->setHeaderData(1,Qt::Horizontal,QObject ::tr("datecommande"));
     model->setHeaderData(2,Qt::Horizontal,QObject ::tr("type"));
     model->setHeaderData(3,Qt::Horizontal,QObject ::tr("quantite"));
     model->setHeaderData(4,Qt::Horizontal,QObject ::tr("nom"));
     return model;


 }


 bool commande ::supprimer(int co)
 {QSqlQuery query;
  QString res =QString ::number(co);
  query .prepare("delete from commande where code =:code ");
  query .bindValue(":code",res);
  return query .exec();
}

bool commande:: modifier(int,int ,QString,QString,QString)
{
QSqlQuery qry;
        qry.prepare("UPDATE commande set QUANTITE=(?),TYPE=(?),NOM=(?),DATECOMMANDE=(?) where CODE=(?) ");
        qry.addBindValue(quantite);
        qry.addBindValue(type);
        qry.addBindValue(nom);
        qry.addBindValue(datecommande);
        qry.addBindValue(code);
return  qry.exec();

}

QSqlQueryModel * commande :: recherche (const QString &aux)

{

    QSqlQueryModel * model = new QSqlQueryModel();
         model->setQuery("select * from commande where ((code) LIKE '%"+aux+"%')");
         model->setHeaderData(0,Qt::Horizontal,QObject ::tr("code"));
         model->setHeaderData(1,Qt::Horizontal,QObject ::tr("datecommande"));
         model->setHeaderData(2,Qt::Horizontal,QObject ::tr("type"));
         model->setHeaderData(3,Qt::Horizontal,QObject ::tr("quantite"));
         model->setHeaderData(4,Qt::Horizontal,QObject ::tr("nom"));
         return model;



            return model;



    return model;
}







