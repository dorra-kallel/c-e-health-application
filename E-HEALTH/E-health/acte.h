#ifndef ACTE_H
#define ACTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "QDate"
class acte{
public:
    acte();
    acte(QString,QString);
QString get_code_act();
QString get_des_acte();
bool ajouter();
bool supprimer(QString);
QSqlQueryModel * afficher();
QSqlQueryModel *affiche1(QString);

private:
QString code_acte;
QString des_acte;


};


#endif // ACTE_H
