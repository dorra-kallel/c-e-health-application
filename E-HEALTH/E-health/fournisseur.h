#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include<QString>
#include<QSqlQuery>

#include<QSqlQueryModel>

class fournisseur
       { public:
            fournisseur();
            fournisseur( QString,int,QString,QString,int);
            int get_id();
            QString get_nom();
            QString get_specialite();
            int get_num_tel();
            QString get_adresse();
            bool ajouter();
            QSqlQueryModel * afficher();
            bool supprimer(int);
            QSqlQueryModel * affichertri();
            bool modifier(int,int ,QString,QString,QString);
        private:
            QString nom,specialite,adresse;
            int num_tel,id;
};

#endif // FOURNISSEUR_H
