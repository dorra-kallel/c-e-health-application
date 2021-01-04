#ifndef COMPTE_H
#define COMPTE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class compte{
public:
    compte();
    compte(QString,QString,QString);
QString get_login();
QString get_mdp();
QString get_type();
bool ajouter();

private:
QString login;
QString mdp;
QString type;


};


#endif // COMPTE_H
