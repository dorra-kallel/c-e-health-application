#include "services.h"

services::services(int id , QString type  )
{
    this->id=id;

this->type=type;


}
bool services::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);

     query.prepare("INSERT INTO services(ID,TYPE) "
                        "VALUES (:id,:type)");
    query.bindValue(":id", res);

    query.bindValue(":type", type);



    return    query.exec();

}

bool services::modifier(QString typee , int idd )
{
    QSqlQuery qry;
    qry.prepare("UPDATE services set type=(?) where id=(?)");
            qry.addBindValue(typee);
            qry.addBindValue(idd);

    return qry.exec();
}

bool services::supprimer(QString idd)
{

    QSqlQuery query;
    query.prepare("Delete from services where type = :type ");
    query.bindValue(":type", idd);
    return    query.exec();
}



QSqlQueryModel * services::afficher()
{
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from services");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        return model;
    }
}
