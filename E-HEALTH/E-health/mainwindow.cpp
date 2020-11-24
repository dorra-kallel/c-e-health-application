 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include"medicament.h"
#include <QMessageBox>
#include "string.h"
#include"visite.h"
#include <QDateTime>
#include <QCalendarWidget>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QCompleter>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);


         ui->tab_visite->setModel(tmpvisite.afficher());

         ui->tab_medicament->setModel(tmpmedicament.afficher());



}
void MainWindow::clear_visite()
{

    ui->id_visite->clear();
  ui->nom_patient_2->clear();
    ui->prenom_patient->clear();
   ui->date_naiss_patient->clear();
    ui->actes_medicaux->setCurrentIndex(0);
   ui->observation->clear();
    ui->diagnostic->clear();
}

void MainWindow::clear_ordonnace()
{
   ui->code_med->clear();
    ui->libelle->clear();
ui->mode->clear();
ui->frequence->clear();
 ui->quantite->setValue(0);
    ui->id_visite->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nouvelle_visite_clicked()
{
    clear_visite();

    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_exit_clicked()
{
      _exit(EXIT_FAILURE);
}

void MainWindow::on_retour_clicked()
{
    clear_ordonnace();

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ordenance_clicked()

{
    int id_visite=ui->id_visite->text().toInt();
    QString nom_patient=ui->nom_patient_2->text();
    QString prenom_patient=ui->prenom_patient->text();
    QString date_naiss_patient=ui->date_naiss_patient->date().toString("dd-MM-yyyy");
    QString acte_medical=ui->actes_medicaux->currentText();
    QString observation=ui->observation->toPlainText();
    QString diagnostic=ui->diagnostic->toPlainText();

    if(acte_medical.compare("Choisissez l'acte")==0||ui->id_visite->text().isEmpty()||nom_patient.isEmpty()|| prenom_patient.isEmpty()||date_naiss_patient.isEmpty()||observation.isEmpty()||diagnostic.isEmpty())
      {  QMessageBox::information(nullptr, QObject::tr("erreur"),
                          QObject::tr("Remplissez touts les champs.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
 {
        visite v( id_visite , nom_patient, prenom_patient , acte_medical, observation, diagnostic ,date_naiss_patient);
        bool test=v.ajouter();
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("Ajouter une visite"),
                          QObject::tr("Visite ajoutée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget->setCurrentIndex(2);
    }
    //clear_ordonnace();

    }





}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_pushButton_clicked()
{


      QString  code_med = ui->code_med->text();
      QString libelle= ui->libelle->text();
      QString mode= ui->mode->text();
      QString frequence=ui->frequence->text();
      int qts=ui->quantite->value();
      int id_visite=ui->id_visite->text().toInt();


if(code_med.isEmpty()|| libelle.isEmpty() || mode.isEmpty() || mode.isEmpty()|| frequence.isEmpty() || qts==0)
   {QMessageBox::information(nullptr, QObject::tr("warning"),
                             QObject::tr("remplissez touts les champs.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
else
{
    medicament m (code_med,libelle,mode,frequence,qts,id_visite);
    bool test=m.ajouter();
    if(test)
    {
     ui->tab_medicament->setModel(tmpmedicament.afficher());
     QMessageBox::information(nullptr, QObject::tr("Ajouter Médicament"),
                              QObject::tr("Médicament  ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }





}

}




void MainWindow::on_valider_clicked()
{

   int id_visite=ui->id_visite->text().toInt();
   QString nom_patient=ui->nom_patient_2->text();
   QString prenom_patient=ui->prenom_patient->text();
   QString date_naiss_patient=ui->date_naiss_patient->date().toString("dd-MM-yyyy");
   QString acte_medical=ui->actes_medicaux->currentText();
   QString observation=ui->observation->toPlainText();
   QString diagnostic=ui->diagnostic->toPlainText();

   if(acte_medical.compare("Choisissez l'acte")==0||ui->id_visite->text().isEmpty()||nom_patient.isEmpty()|| prenom_patient.isEmpty()||date_naiss_patient.isEmpty()||observation.isEmpty()||diagnostic.isEmpty())
     {  QMessageBox::information(nullptr, QObject::tr("erreur"),
                         QObject::tr("Remplissez touts les champs.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
{
       visite v( id_visite , nom_patient, prenom_patient , acte_medical, observation, diagnostic ,date_naiss_patient);
       bool test=v.ajouter();
   if(test)
   {


       QMessageBox::information(nullptr, QObject::tr("Ajouter une visite"),
                         QObject::tr("Visite ajoutée.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

   }
   //clear_visite();
   }

   }


void MainWindow::on_afficher_visite_clicked()
{   ui->tab_visite->setModel(tmpvisite.afficher());
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_pushButton_3_clicked()
{
    int row =ui->tab_medicament->selectionModel()->currentIndex().row();
    QString code_med=ui->tab_medicament->model()->index(row,0).data().toString();

    bool test =tmpmedicament.supprimer(code_med);
    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("Supprimer un médicament"),
                            QObject::tr("Erreur selectionnez médicament que vous voulez le supprimer !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
    if(test)
    {
        ui->tab_medicament->setModel(tmpmedicament.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un médicament"),
                    QObject::tr("médicament  supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un médicament"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}



void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);

}


void MainWindow::on_pushButton_5_clicked()
{
    QString  code_med = ui->code_med_modif->text();
    QString libelle= ui->libelle__modif->text();
    QString mode= ui->mode_modif->text();
    QString frequence=ui->freq__modif->text();
    int qts=ui->qts_modif->value();
    int id_visite=ui->id_visite->text().toInt();
    int x=ui->tab_medicament->model()->rowCount();

    if(code_med.isEmpty()|| libelle.isEmpty() || mode.isEmpty() || mode.isEmpty()|| frequence.isEmpty() || qts==0 || x==0)
       {QMessageBox::information(nullptr, QObject::tr("warning"),
                                 QObject::tr("remplissez touts les champs pour modifier/tableau de médicament vide.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
        medicament m(code_med,libelle,mode,frequence,qts,id_visite);
        bool test=m.modifier();
        if(test)
        {
         ui->tab_medicament->setModel(tmpmedicament.afficher());
         QMessageBox::information(nullptr, QObject::tr("Ajouter Médicament"),
                                  QObject::tr("Médicament modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }



    }
   ui->code_med_modif->clear();
     ui->libelle__modif->clear();
    ui->mode_modif->clear();
   ui->freq__modif->clear();
  ui->qts_modif->setValue(0);


}

void MainWindow::on_pdf_clicked()
{
    QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:\\Users\\Pavillion\\Desktop\\E-HEALTH\\ordonnance.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
        QPainter painter;

        if (! painter.begin(&printer)) { // failed to open file
            qWarning("failed to open file, is it writable?");
        }

        QSqlQuery   query ;
        qDebug() << query.prepare("select sysdate from dual  ");
        if ( query.exec() )
        {

            QString S= QDate::currentDate().toString();
            painter.drawText(850,50,S);
            QPen penred(Qt::black);

            painter.setFont(QFont("Arial", 30));
            penred.setWidth(1);
            painter.setPen(penred);

            painter.drawText(330,100," Ordonnance ");
            painter.setFont(QFont("Arial",30));
            painter.setPen(Qt::black);

        }

        QString code_med,libelle,mode,frequence,qts;
        QSqlQuery   qry ;
        int i =50;
        int k=0;
        qDebug() << qry.prepare("select * from ordonnance where id_visite_o=(select max(id_visite) from visite) ");

        if ( qry.exec() )
        {

            while(qry.next())
            {

                if ( k % 13 ==0)
                {   i=250;
                    painter.setFont(QFont("Arial",10));
                    QPen penblack(Qt::black);

                    painter.setPen(penblack);
    painter.drawText (0,200,"code_med");
    painter.drawText (120,200,"libelle");
    painter.drawText (300,200,"mode");
    painter.drawText (540,200,"frequence");
    painter.drawText (920,200,"qts");
                }

                painter.setFont(QFont("Arial",10));
                QPen penblack(Qt::black);

                painter.setPen(penblack);
                int j=0;
                code_med= qry.value(0).toString();
                painter.drawText(j*20,i, code_med);
                j++;
                libelle=qry.value(1).toString();
                painter.drawText(j*120,i, libelle);
                j++;
               mode=qry.value(2).toString();
                painter.drawText(j*150,i, mode);
                j++;
                frequence=qry.value(3).toString();
                painter.drawText(j*180,i, frequence);
                j++;
               qts=qry.value(4).toString();
                painter.drawText(j*230,i, qts);
                j++;
                i+=80;
                k++;

            }
        }

        painter.end();
}

void MainWindow::on_pushButton_6_clicked()
{
int row =ui->tab_visite->selectionModel()->currentIndex().row();
QString id_visite=ui->tab_visite->model()->index(row,0).data().toString();

bool test =tmpvisite.supprimer(id_visite);
if(row==-1)
{ QMessageBox::critical(nullptr, QObject::tr("Supprimer une visite"),
                        QObject::tr("Erreur selectionnez visite que vous voulez le supprimer!.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
else
{
if(test)
{
    ui->tab_visite->setModel(tmpvisite.afficher());
    QMessageBox::information(nullptr, QObject::tr("Supprimer une visite"),
                QObject::tr("visite supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une visite"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void MainWindow::on_pushButton_8_clicked()
{
   ui->tab_visite->setModel(tmpvisite.afficher_asc());
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->tab_visite->setModel(tmpvisite.afficher_desc());
}

void MainWindow::on_resh_visite_clicked()
{

    QString q=ui->nom_chercher->text();


    ui->tab_visite->setModel(tmpvisite.afficher_rechrerche(q)) ;


}

void MainWindow::on_nom_chercher_textChanged(const QString &arg1)
{
    QString q = arg1;

        if (q=="")
        {
            ui->tab_visite->setModel(tmpvisite.afficher());
        }
        else {
          ui->tab_visite->setModel(tmpvisite.afficher_rechrerche(q)) ;


        }
}



void MainWindow::on_tab_medicament_doubleClicked(const QModelIndex &index)
{
    ui->stackedWidget_2->setCurrentIndex(2);

    QString val=ui->tab_medicament->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from ordonnance where code_med='"+val+"'");

    if(query.exec())
    {
        while(query.next())
        {ui->code_med_modif->setText(query.value(0).toString());

        }
   }
}

void MainWindow::on_tab_visite_doubleClicked(const QModelIndex &index)
{

}
