#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class connection
{
private:
    QSqlDatabase db;
public:
    connection();
    bool createconnection();
void closeConnection();
~connection(){closeConnection();}
};

#endif // CONNECTION_H
