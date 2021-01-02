#include "employee.h"

employee::employee(QString nom,QString prenom,QString adresse,int id,int salaire )
{
this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->id=id;
    this->salaire=salaire;
}
bool employee::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(salaire);

     query.prepare("INSERT INTO employee (ID,SALAIRE, NOM, PRENOM,ADRESSE) "
                        "VALUES (:id, :salaire, :nom, :prenom, :adresse)");
    query.bindValue(":id", res);
    query.bindValue(":salaire", res1);

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);



    return    query.exec();

}



QSqlQueryModel * employee::afficher()
{
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employee");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("salaire"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse "));

        return model;
    }
}
bool employee::supprimer(int idd)
{

    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from employee where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

bool employee::modifier(int id,int salaire ,QString nom, QString prenom,QString adresse )
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(salaire);

    query.prepare("update employee set salaire=:salaire,nom=:nom,prenom=:prenom, adresse=:adresse where id=:id");
    query.bindValue(":id", res);
    query.bindValue(":salaire",res1 );
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse", adresse);
    return query.exec();
}
QSqlQueryModel* employee::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from employee ORDER BY ID asc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" NOM"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));


    return model;
}

QSqlQueryModel* employee::trie2()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from employee ORDER BY ID desc");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("SALAIRE"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr(" NOM"));

         model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));


    return model;
}

QSqlQueryModel * employee::chercher_emp(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from employee where ((id ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("SALAIRE"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("ADRESSE"));

    return model;
}


QSqlQueryModel * employee::chercher_emp1(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from employee where ((salaire ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("SALAIRE"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("ADRESSE"));

    return model;
}

QSqlQueryModel * employee::chercher_emp2(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from employee where ((nom ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("SALAIRE"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("PRENOM"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("ADRESSE"));

    return model;
}
