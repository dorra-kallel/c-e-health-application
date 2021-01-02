#ifndef COMMANDE_H
#define COMMANDE_H

#include<QString>
#include<QSqlQuery>

#include<QSqlQueryModel>

class commande
{
public:
    commande();
    commande( int,QString,QString,int,QString,int);
    int get_code();
    QString get_date_commande();
    QString get_type();
    int get_quantite();
    QString get_nom();
    int get_id_four();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * affichertri();
    bool modifier(int,int ,QString,QString,QString);
    QSqlQueryModel * recherche (const QString & aux);

private:
    QString nom,datecommande,type;
    int quantite,code,id_four;
};

#endif // COMMANDE_H
