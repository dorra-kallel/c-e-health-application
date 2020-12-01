#include "mainwindow.h"

#include <QApplication>
#include"connection2.h"

#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection2 c;

    bool test =c.createconnection();
if (test)
    qDebug () <<"connection reussite";
else
    qDebug ()<<"pas de connection";

    w.show();
    return a.exec();
}
