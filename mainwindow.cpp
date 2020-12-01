#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"fournisseur.h"
#include"commande.h"
#include<QMessageBox>
#include<QString>
#include<QPainter>
#include<QtPrintSupport/QPrinter>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabcommande->setModel(tmpcommande.afficher());
    ui->tabaffich->setModel(tmpfournisseur.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{  ui->page->show();
    ui->page->hide();
    ui->page_2->show();
    ui->page_4->hide();



}

void MainWindow::on_pushButton_5_clicked()
{
    ui->page_2->hide();
    ui->page->show();

}

void MainWindow::on_pushButton_4_clicked()
{

    int code =ui->lineEdit->text().toInt();
    QString datecommande =ui->lineEdit_2->text();
    QString type =ui->lineEdit_3->text();
    int quantite =ui->lineEdit_45->text().toInt();
    QString nom =ui->lineEdit_5->text();
    commande c(code,datecommande,type,quantite,nom);

    bool test =c.ajouter();
    if (test)
    {ui->tabcommande->setModel(tmpcommande.afficher());
        QMessageBox :: information(nullptr,QObject::tr("ajouter une commande "),
                         QObject::tr("commande ajouter\n"
                                     "click cancel to exit "),QMessageBox ::Cancel          );
    }
    else
       {  QMessageBox :: critical(nullptr,QObject::tr("ajouter une commande "),
                                     QObject::tr("erreur\n"
                                                 "click cancel to exit "),QMessageBox ::Cancel          );



    }
}

void MainWindow::on_pushButton_6_clicked()
{

    int   code =ui->lineEdit_6->text().toInt();
    bool test =tmpcommande.supprimer(code);
    if(test)
    {ui->tabcommande->setModel(tmpcommande.afficher());
        QMessageBox ::information(nullptr,QObject::tr("suprimer une commande"),
                                  QObject::tr("commande supprmier \n"
                                              "click cancel to exit"),QMessageBox::Cancel);

}
    else {
        QMessageBox ::critical(nullptr,QObject::tr("suprimer une commande"),
                                  QObject::tr("erreur \n"
                                              "click cancel to exit"),QMessageBox::Cancel);


    }
}

void MainWindow::on_pushButton_7_clicked()
{
    int id =ui->lineEdit_7->text().toInt();
    QString nom =ui->lineEdit_4->text();
    QString specialite =ui->lineEdit_8->text();
    int num_tel =ui->lineEdit_10->text().toInt();
    QString adresse =ui->lineEdit_9->text();
    fournisseur f(nom,id,specialite,adresse,num_tel);
    bool test =f.ajouter();
    if (test)
    {ui->tabaffich->setModel(tmpfournisseur.afficher());
        QMessageBox :: information(nullptr,QObject::tr("ajouter fournisseur "),
                         QObject::tr("fournisseur ajouter\n"
                                     "click cancel to exit "),QMessageBox ::Cancel          );
    }
    else
       {  QMessageBox :: critical(nullptr,QObject::tr("ajouter un fournisseur "),
                                     QObject::tr("erreur\n"
                                                 "click cancel to exit "),QMessageBox ::Cancel          );



    }

}

void MainWindow::on_pushButton_9_clicked()
{

    int   id =ui->lineEdit_11->text().toInt();
    bool test =tmpfournisseur.supprimer(id);
    if(test)
    {ui->tabaffich->setModel(tmpfournisseur.afficher());
        QMessageBox ::information(nullptr,QObject::tr("suprimer un fournisseur"),
                                  QObject::tr("fournissuer supprmier \n"
                                              "click cancel to exit"),QMessageBox::Cancel);

}
    else {
        QMessageBox ::critical(nullptr,QObject::tr("suprimer un fournisseur"),
                                  QObject::tr("erreur \n"
                                              "click cancel to exit"),QMessageBox::Cancel);


    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->page->hide();
    ui->page_3->show();
    ui->page_6->hide();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->page_3->hide();
    ui->page->show();
}

void MainWindow::on_pushButton_10_clicked()
{
ui->tabaffich->setModel(tmpfournisseur.affichertri());
}

void MainWindow::on_pushButton_11_clicked()
{ui->tabcommande->setModel(tmpcommande.affichertri());
}

void MainWindow::on_pushButton_12_clicked()
{  ui->page_4->hide();
    ui->page_4->show();

}

void MainWindow::on_pushButton_13_clicked()
{
    int code=ui->lineEdit_12->text().toInt();
    int quantite=ui->lineEdit_16->text().toInt();
       QString nom = ui->lineEdit_13->text();
       QString type = ui->lineEdit_15->text();
       QString datecommande = ui->lineEdit_14->text();
       commande c(code,nom,type,quantite,datecommande);
         bool test=c.modifier( code,quantite,nom, type,datecommande);
        if(test)
        { ui->tabcommande->setModel(tmpcommande.afficher());

            QMessageBox ::information(nullptr,QObject::tr("modifier une commande"),
                                              QObject::tr("commande  modifié.\n"
                                                  "click ok to exit"),QMessageBox::Ok);

        }
        else
        {
            QMessageBox ::critical(nullptr,QObject::tr("modifier une commande"),
                                              QObject::tr("Erreur.\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);

        }
        ui->tabcommande->setModel(tmpcommande.afficher());
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->page_6->show();
}

void MainWindow::on_pushButton_15_clicked()
{
    int id=ui->lineEdit_17->text().toInt();
    int num_tel=ui->lineEdit_19->text().toInt();
       QString specialite = ui->lineEdit_20->text();
       QString nom = ui->lineEdit_21->text();
       QString adresse = ui->lineEdit_18->text();
       fournisseur f(nom,id,adresse,specialite,num_tel);
         bool test=f.modifier( id,num_tel,adresse,specialite,nom);
        if(test)
        { ui->tabaffich->setModel(tmpfournisseur.afficher());

            QMessageBox ::information(nullptr,QObject::tr("modifier un fournissuer"),
                                              QObject::tr("fournisseur  modifié.\n"
                                                  "click ok to exit"),QMessageBox::Ok);

        }
        else
        {
            QMessageBox ::critical(nullptr,QObject::tr("modifier un fournisseur"),
                                              QObject::tr("Erreur.\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);

        }
        ui->tabcommande->setModel(tmpcommande.afficher());
}

void MainWindow::on_pushButton_16_clicked()
{

    QString text;

    text=ui->lineEdit_22->text();

    if(text == "")

    {

        ui->tabcommande->setModel(tmpcommande.afficher());

    }

    else

    {



        ui->tabcommande->setModel(tmpcommande.recherche(text));

    }
}

void MainWindow::on_pushButton_17_clicked()
{
    QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:\\Users\\ASUS\\Desktop\\2A5\\fournisseur.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
            QPainter painter;

            if (! painter.begin(&printer)) { // failed to open file
                qWarning("failed to open file, is it writable?");
            }

            QSqlQuery   query ;
            qDebug() << query.prepare("select sysdate from dual  ");
            if ( query.exec() )
            {

                //QString S= QDate::currentDate().toString();
                //painter.drawText(850,50,S);
                QPen penred(Qt::black);

                painter.setFont(QFont("Arial", 30));
                penred.setWidth(1);
                painter.setPen(penred);

                painter.drawText(330,100," fournisseur ");
                painter.setFont(QFont("Arial",30));
                painter.setPen(Qt::black);

            }

            QString id,nom,specialite,num_tel,adresse;
            QSqlQuery   qry ;
            int i =50;
            int k=0;
            qDebug() << qry.prepare("select * from fournisseur where id=(select max(id) from fournisseur) ");

            if ( qry.exec() )
            {

                while(qry.next())
                {

                    if ( k % 13 ==0)
                    {   i=250;
                        painter.setFont(QFont("Arial",10));
                        QPen penblack(Qt::black);

                        painter.setPen(penblack);
        painter.drawText (0,200,"specialite");
        painter.drawText (120,200,"id");
        painter.drawText (300,200,"nom");
        painter.drawText (540,200,"num_tel");
        painter.drawText (920,200,"adresse");

                    }

                    painter.setFont(QFont("Arial",10));
                    QPen penblack(Qt::black);

                    painter.setPen(penblack);
                    int j=0;
                    specialite= qry.value(0).toString();
                    painter.drawText(j*20,i,specialite);
                    j++;
                    id=qry.value(1).toString();
                    painter.drawText(j*120,i,id);
                    j++;
                    nom=qry.value(2).toString();
                    painter.drawText(j*150,i,nom);
                    j++;
                    num_tel=qry.value(2).toString();
                    painter.drawText(j*180,i,num_tel);
                    j++;
                    adresse=qry.value(2).toString();
                    painter.drawText(j*230,i,adresse);
                    j++;

                    i+=80;
                    k++;

                }
            }

            painter.end();

}
