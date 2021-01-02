#ifndef MACHINE_H
#define MACHINE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class machine
{
private:
    QString mode_aquisation,nom;

    int code,reference;


public:
    machine(){}
    machine(int,QString,int,QString);
    int get_code();
        QString get_nom();
    int get_reference();
       QString get_mode();
bool ajouter();
    QSqlQueryModel * afficher1();



    bool supprimer1(int);
    bool modifier();
    void setCode(int c){code=c;}
    void setnom(QString n){nom=n;}
    void setreference(int r){reference=r;}
    void setmode(QString m){mode_aquisation=m;}






};
#endif // MACHINE_H
