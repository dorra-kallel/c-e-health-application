#include "compte.h"

compte::compte()
{

 login="";
 mdp="";
 type="";
}

compte::compte(QString login,QString mdp,QString type)
{

 this->login=login;
 this->mdp=mdp;
    this->type=type;
}



QString  compte ::get_login(){return login;}
QString compte:: get_mdp(){return  mdp;}
QString compte:: get_type(){return  type;}
bool compte :: ajouter()
{
QSqlQuery query;
query.prepare("INSERT INTO compte(login,mdp,type_compte)values(:login,:mdp,:type)");
query.bindValue(":login",login);
query.bindValue(":mdp",mdp);
query.bindValue(":type",type);
return  query.exec();
}
