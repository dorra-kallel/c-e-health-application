#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QString>
#include<QSqlQueryModel>

class medicament
{
public:
    medicament();

   medicament(QString,QString,QString,QString,int,int);
   QString code_med,frequence,mode,libelle;
   int qts,id_visite;
bool ajouter();
 QSqlQueryModel * afficher();
 bool supprimer(QString);
 bool modifier();
};







#endif // MEDICAMENT_H
