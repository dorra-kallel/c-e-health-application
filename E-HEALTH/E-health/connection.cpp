#include "connection.h"

Connection::Connection()
{

}



bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("e-health");
    db.setUserName("moatez");
    db.setPassword("esprit");
    if(db.open())
        test=true;
    return test;

}
