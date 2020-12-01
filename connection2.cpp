#include "connection2.h"
#include"QSqlDatabase"
// test tutoriel git

connection2::connection2()
{

}
bool connection2 ::createconnection()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase ::addDatabase("QODBC");

    db.setDatabaseName("projet_2a");
    db.setUserName("moetez");
    db.setPassword("moetez");

    if(db.open())
        test =true;
    return test;


}
