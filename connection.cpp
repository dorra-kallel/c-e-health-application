#include "connection.h"
#include"QSqlDatabase"
//test Tutoriel Git

connection::connection()
{

}
bool connection::createconnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("esprit");
    db.setUserName("esprit");
    db.setPassword("esprit");
    if(db.open())
        test=true;
    return test;
}
void connection::closeConnection()
{  db.close();}
