#include "patient.h"
#include <QSqlQuery>
#include <QString>
#include "QSqlQueryModel"
#include "QMessageBox"
#include <QDate>
#include "QLocale"

patient::patient(){
 cin=0;
 nom="";
prenom="";
adresse="";
QDate date_de_naissance(1995, 5, 17);
email="";
numero=0;
}
patient::patient( int cin,QString nom, QString prenom,QDate date_de_naissance, QString adresse,int numero,QString email){

           email=email.toLower();
                  email[0]=email[0].toUpper();

    nom=nom.toLower();
           nom[0]=nom[0].toUpper();
            prenom=prenom.toLower();
                   prenom[0]= prenom[0].toUpper();
                    adresse=adresse.toLower();
                           adresse[0]=adresse[0].toUpper();
this->cin=cin;
this->nom=nom;
this->prenom=prenom;
this->adresse=adresse;
  this->date_de_naissance=date_de_naissance;
   this->numero=numero;
              this->email=email;
}
bool patient::ajouter()
{
    QString res=QString::number(numero);
     QString ress=QString::number(cin);
   QSqlQuery Query;
   Query.prepare("INSERT INTO patient(cin,nom,prenom,date_de_naissance,adresse,tel,email)"
                 "values(:cin,:nom,:prenom,:date_de_naissance,:adresse,:tel,:email)");
   Query.bindValue(":cin",ress);
   Query.bindValue(":nom",nom);
   Query.bindValue(":prenom",prenom);
   Query.bindValue(":date_de_naissance",date_de_naissance);
   Query.bindValue(":adresse",adresse);
    Query.bindValue(":tel",res);
     Query.bindValue(":email",email);
   return Query.exec();
}
QSqlQueryModel * patient::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from patient");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_de_naissance"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
    return model;
}
QSqlQueryModel * patient ::recherche (const QString &aux)

{

    QSqlQueryModel * model = new QSqlQueryModel();
 model->setQuery("select * from patient where ((cin || nom || prenom || adresse || date_de_naissance) LIKE '%"+aux+"%')");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_de_naissance"));


    return model;
}
bool patient::supprimer(QString cinn)
{
QSqlQuery query;
query.prepare("Delete from patient where cin = :cin ");
query.bindValue(":cin", cinn);
return    query.exec();
}


bool patient::modifier(int cinn ,QString nomm,QString prenomm,QDate date_de_naissancee,QString adressee,int numeroo,QString emaill)
{

    QSqlQuery qry;

           emaill=emaill.toLower();
                  emaill[0]=emaill[0].toUpper();

    nomm=nomm.toLower();
           nomm[0]=nomm[0].toUpper();
            prenomm=prenomm.toLower();
                   prenomm[0]= prenomm[0].toUpper();
                    adressee=adressee.toLower();
                           adressee[0]=adressee[0].toUpper();
        qry.prepare("UPDATE patient set nom=(?),prenom=(?),date_de_naissance=(?),adresse=(?),tel=(?),email=(?)  where cin=(?)");
        qry.addBindValue(nomm);
        qry.addBindValue(prenomm);
        qry.addBindValue(date_de_naissancee);
        qry.addBindValue(adressee);
         qry.addBindValue(numeroo);
          qry.addBindValue(emaill);
        qry.addBindValue(cinn);

   return  qry.exec();
}
QSqlQueryModel* patient::trieAlphaa()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM patient ORDER BY nom DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_de_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
    return model;
}

QSqlQueryModel* patient::trieAlpha()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM patient ORDER BY nom ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_de_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
    return model;
}
QSqlQueryModel * patient::trieCinn(){
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM patient ORDER BY cin DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_de_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
    return model;

}
QSqlQueryModel * patient::trieCin(){
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM patient ORDER BY cin ASC ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_de_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
    return model;

}
QSqlQueryModel * patient::trieAdressee(){
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM patient ORDER BY adresse DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_de_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
    return model;
}
QSqlQueryModel * patient::trieAdresse(){
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM patient ORDER BY adresse ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_de_naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("tel"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
    return model;
}
bool patient::controlsaisieMail(QString saisi){
    int i,test1=0,test2=0;


            for (i=0;i<saisi.length();i++)
            {
     if( saisi[i]=="@")
          test1=1;
     if( saisi[i]==".")
         test2=1;
            }
    if((test1==1)&&(test2==1)){
        return true;
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("email"),
                    QObject::tr("L'adresse mail non valid.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }


}
bool patient::controlsaisiechar(QString saisi,QString type){
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
bool patient::controlSaisieNumVide(int tel,QString tell){

       if(std::to_string(tel).length()==8)
               {
         return true;
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("numero"),
                    QObject::tr("Le %1 doit avoir 8 chiffre .\n"
                                "Click Cancel to exit.").arg(tell), QMessageBox::Cancel);
        return false;
    }

}

bool patient::controlSaisieCharVide(QString prenom,QString prenomm){

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
