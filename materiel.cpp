#include "materiel.h"

materiel::materiel(QString type,  int quantite_t ,int prix_u ,   int quantite_p, QString fournisseur  )
{
this->type=type;
    this->quantite_t=quantite_t;

    this->prix_u=prix_u;
    this->quantite_p=quantite_p;
    this->fournisseur=fournisseur;

}
bool materiel::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(prix_u);
    QString res1=QString::number(quantite_p);
    QString res2=QString::number(quantite_t);

    query.prepare("INSERT INTO materiel (TYPE,QUANTITE_T, PRIX_U, QUANTITE_P,FOURNISSEUR) "
                        "VALUES (:type, :quantite_t, :prix_u, :quantite_p, :fournisseur)");
    query.bindValue(":prix_u", res);
    query.bindValue(":quantite_p", res1);
    query.bindValue(":quantite_t", res2);


    query.bindValue(":type", type);
    query.bindValue(":fournisseur", fournisseur);




    return    query.exec();

}



bool materiel::supprimer(QString idd)
{

    QSqlQuery query;
    query.prepare("Delete from materiel where type = :type ");
    query.bindValue(":type", idd);
    return    query.exec();
}



QSqlQueryModel * materiel::afficher()
{
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from materiel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("quantite_t"));

    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_u"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite_p"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("fournisseur"));
        return model;
    }
}
