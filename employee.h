#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>
#include<QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>

class employee
{
private:
    QString nom, prenom , adresse;
    int id , salaire;
public:
    //constructeurs
    employee(){};
    employee(QString,QString,QString,int,int);
    // getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getadresse(){return adresse;}
    int getID(){return id;}
    int getSalaire(){return salaire;}
    //setters
    void setNom(QString n ){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setadresse(QString d){adresse=d;}
    void setId(int id){this->id=id;}
    void setSalaire(int salaire){this->salaire=salaire;}
    //fonctions de base relative a l'entite employee
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int, int , QString ,QString , QString );
    bool supprimer(int);
    QSqlQueryModel* trie();
    QSqlQueryModel* trier(const QString, const QString);
    QSqlQueryModel* trie2();
    QSqlQueryModel *chercher_emp(const QString &aux);
    QSqlQueryModel *chercher_emp1(const QString &aux);
    QSqlQueryModel *chercher_emp2(const QString &aux);







};

#endif // EMPLOYEE_H
