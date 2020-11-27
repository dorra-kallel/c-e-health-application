#ifndef CHAMBRE_H
#define CHAMBRE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
class chambre
{


public:
    chambre(){}
    chambre(int,int,int);
    int get_code();
        int get_etage();
    int get_numero();

bool ajouter();
    QSqlQueryModel * afficher();

    bool supprimer(int);
    bool modifier();
    void setCode(int c){code=c;}
    void setEtage(int e){etage=e;}
    void setNumero( int n){numero=n;}


private:
    int etage,numero;
int code;

};

#endif // CHAMBRE_H
