#include "acte.h"
acte::acte()
{

 code_acte="";
 des_acte="";
}

acte::acte(QString code_acte,QString des_acte)
{

 this->code_acte=code_acte;
 this->des_acte=des_acte;
}



QString  acte ::get_code_act(){return code_acte;}
QString acte:: get_des_acte(){return  des_acte;}

bool acte :: ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO acte_visite (CODE_ACT,DES_ACT,ID_VISITE_ACTE)values(:code_act,:des_acte, (select max(id_visite)from visite))");

query.bindValue(":code_act",code_acte);
query.bindValue(":des_acte",des_acte);

return  query.exec();
}
QSqlQueryModel *  acte::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from acte_visite where id_visite_acte=(select max(id_visite) from visite)");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code_acte"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("des_acte"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_visite"));
    return model;


}
bool acte::supprimer(QString code_act)
{
QSqlQuery query;
QString res= code_act;
query.prepare("Delete from acte_visite where code_act = '"+res+"' ");

return    query.exec();
}
QSqlQueryModel * acte ::affiche1(QString val)
{
     QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
     model->setQuery("select * from acte_visite where id_visite_acte='"+val+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("code_acte"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("des_acte"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_visite_acte"));
    return model;
}
