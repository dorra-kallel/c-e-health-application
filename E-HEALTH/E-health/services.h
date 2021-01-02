
#ifndef services_H
#define services_H
#include<QtSql/QSqlQueryModel>
#include<QString>
#include <QtSql/QSqlQuery>


class services
{
    private:
    QString type;
    int id ;
public:
    //constructeurs
    services(){}
    services(int,QString);
    // getters
    QString getTYPE(){return type;}
    int getid(){return id;}

    //setters
    void setType(QString n ){type=n;}
    void setid(int d){id=d;}
    //fonctions de base relative a l'entite services
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(QString,int);
    bool supprimer(QString);



};



#endif // services_H
