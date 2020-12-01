#include "rendez_vous.h"
#include <QSqlQuery>
#include <QString>
#include "QSqlQueryModel"
#include "QMessageBox"
#include <QDate>
#include "QLocale"

rendez_vous::rendez_vous()
{

     cin_patient=0;
     nom="";
     prenom="";
    QDate date_rdv(1995, 5, 17);
    docteur="";
}

rendez_vous::rendez_vous(int cin,QString nom,QString prenom,QDateTime date,QString docteur){



nom=nom.toLower();
      nom[0]=nom[0].toUpper();
     prenom=prenom.toLower();
     prenom[0]= prenom[0].toUpper();
        docteur=docteur.toLower();
              docteur[0]=docteur[0].toUpper();
              cin_patient=cin;
              this->nom=nom;
              this->prenom=prenom;
               date_rdv=date;
                 this->docteur=docteur;
}

bool rendez_vous::ajouter()
{

     QString ress=QString::number(cin_patient);
   QSqlQuery Query;
   Query.prepare("INSERT INTO rendezvous(cin_patient,nom,prenom,date_rdv,docteur)"
                 "values(:cin_patient,:nom,:prenom,:date_rdv,:docteur)");
   Query.bindValue(":cin_patient",ress);
   Query.bindValue(":nom",nom);
   Query.bindValue(":prenom",prenom);
   Query.bindValue(":date_rdv",date_rdv);
   Query.bindValue(":docteur",docteur);
   return Query.exec();
}
QSqlQueryModel * rendez_vous::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from rendezvous");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin_patient"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_rdv"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("docteur"));
    return model;
}
bool rendez_vous::modifier(int cin_patientt,QString nomm,QString prenomm,QDateTime date_rdvv,QString docteurr)
{

    QSqlQuery qry;

           docteurr=docteurr.toLower();
                  docteurr[0]=docteurr[0].toUpper();



        qry.prepare("UPDATE rendezvous set nom=(?),prenom=(?),date_rdv=(?),docteur=(?) where cin_patient=(?)");

        qry.addBindValue(nomm);
        qry.addBindValue(prenomm);

        qry.addBindValue(date_rdvv);
         qry.addBindValue(docteurr);
        qry.addBindValue(cin_patientt);

   return  qry.exec();
}
bool rendez_vous::supprimer(QString idd)
{
QSqlQuery query;
query.prepare("Delete from rendezvous where id = :id");
query.bindValue(":id", idd);
return    query.exec();
}
QSqlQueryModel* rendez_vous::trieDocteurr()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM rendezvous ORDER BY docteur DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin_patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_rdv"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("docteur"));
    return model;
}
QSqlQueryModel* rendez_vous::trieDocteur()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM rendezvous ORDER BY docteur ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin_patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_rdv"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("docteur"));
    return model;
}
QSqlQueryModel* rendez_vous::trieDatee()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM rendezvous ORDER BY date_rdv DESC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin_patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_rdv"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("docteur"));
    return model;
}
QSqlQueryModel* rendez_vous::trieDate()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM rendezvous ORDER BY date_rdv ASC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin_patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_rdv"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("docteur"));
    return model;
}
QSqlQueryModel* rendez_vous::triePatient()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM rendezvous ORDER BY nom ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin_patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_rdv"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("docteur"));
    return model;
}
QSqlQueryModel* rendez_vous::triePatientt()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM rendezvous ORDER BY nom DESC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin_patient"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_rdv"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("docteur"));
    return model;
}
QSqlQueryModel * rendez_vous ::recherche (const QString &aux)

{

    QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("select * from rendezvous where ((id || cin_patient || nom || prenom || date_rdv || docteur) LIKE '%"+aux+"%')");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin_patient"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_rdv"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("docteur"));



    return model;
}
bool rendez_vous::controlSaisieCharVide(QString prenom,QString prenomm){

 if(prenom.length()!=0)
 {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Cin"),
                    QObject::tr("Le champs de %1 est vide.\n"
                                "Click Cancel to exit.").arg(prenomm), QMessageBox::Cancel);
        return false;
    }

}
bool rendez_vous::controlsaisiechar(QString saisi,QString type){
    if(saisi.contains(QRegExp("^[A-Za-z ]+$")))
    {
        return true;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Cin"),
                    QObject::tr("Le %1 contient un caractaire non valid.\n"
                                "Click Cancel to exit.").arg(type), QMessageBox::Cancel);
        return false;
    }

}
