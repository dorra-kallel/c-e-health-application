#include "connection.h"

//Test tutoriel Git

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet2A");//inserer le nom de la source de données ODBC
db.setUserName("dorra");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closeConnection(){db.close();}
