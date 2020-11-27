#include "mainwindow.h"
#include<QMessageBox>
#include<QApplication>
#include <QDebug>
#include"connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
    bool test=c.createconnection();
    if(test)
        qDebug()<<"connexion reussite";
    else
        qDebug()<<"pas de connexion";
    if(test)
    {    w.show();
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("connection successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);




 return a.exec();

}
