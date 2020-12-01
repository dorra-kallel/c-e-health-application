#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "patient.h"
#include <QString>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextStream>
#include "QLocale"
#include <QHeaderView>
#include "patient.h"
#include "rendez_vous.h"
#include <QSound>
#include <QMediaPlayer>
#include<QGraphicsOpacityEffect>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(p.afficher());
    ui->tableView_3->setModel(rdv.afficher());
    ui->lineEdit_3->setMaxLength(8);
  ui->lineEdit_24->setMaxLength(8);
 ui->lineEdit_26->setMaxLength(8);
  ui->lineEdit_18->setMaxLength(25);
   ui->lineEdit_22->setMaxLength(25);
    ui->lineEdit_4->setMaxLength(20);
     ui->lineEdit_5->setMaxLength(20);
        ui->lineEdit_9->setMaxLength(20);
         ui->lineEdit_10->setMaxLength(20);



}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_2_clicked()
{
QMediaPlayer *player = new QMediaPlayer;
player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
player->setVolume(50);
player->play();

QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        ui->stackedWidget->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
        a->setDuration(150);
        a->setStartValue(0);
        a->setEndValue(1);
        a->setEasingCurve(QEasingCurve::InBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);


    ui->stackedWidget->setCurrentIndex(3);

    ui->pushButton_2->setStyleSheet("	background-image: url(C:/Users/HP/Documents/health-app/icons/16x16/cil-PEOPLE.png);"
                                   " background-position: left center;"
                                    "background-repeat: no-repeat;"
                                    "border: none;"
                                    "border-left: 32px solid #25283b;"
                                    "background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79);border-right: 5px solid #3d50eb; ");

    ui->pushButton->setStyleSheet("QPushButton{  background-image: url(C:/Users/HP/Documents/health-app/icons/16x16/cil-clipboard.png);"
    "background-position: left center;"
    "background-repeat: no-repeat;"
    "border: none;"
    "border-left: 32px solid #25283b;"
    "border-right: 5px solid transparent;"
    "background-color:#25283b;"
    "text-align: left;}"
     "QPushButton:hover{ background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79); }");


}

void MainWindow::on_pushButton_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(150);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);

     ui->stackedWidget->setCurrentIndex(0);
      ui->stackedWidget_2->setCurrentIndex(0);
      ui->tableView_3->setModel(rdv.afficher());
      ui->lineEdit_8->clear();

      ui->pushButton->setStyleSheet( " background-image: url(C:/Users/HP/Documents/health-app/icons/16x16/cil-clipboard.png);background-position: left center;"
                                      "background-repeat: no-repeat;"
                                        "border: none;"
                                       "border-left: 32px solid #25283b;"
                                         "border-right: 5px solid transparent;"
                                             "background-color:#25283b;"
                                               "text-align: left;"
                                      "background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79);border-right: 5px solid #3d50eb; }");

      ui->pushButton_2->setStyleSheet("QPushButton{background-image: url(C:/Users/HP/Documents/health-app/icons/16x16/cil-PEOPLE.png);"
                                    " background-position: left center;"
                                     "background-repeat: no-repeat;"
                                     "border: none;"
                                     "border-left: 32px solid #25283b; }"
                                      ":hover:background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79);border-right: 5px solid #3d50eb; }"

                                       "QPushButton:hover{ background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79); }");





}

void MainWindow::on_pushButton_4_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    ui->lineEdit_3->clear();
                ui->lineEdit_4->clear();
               ui->lineEdit_5->clear();
              ui->lineEdit_6->clear();

                        ui->lineEdit_24->clear();
                        ui->lineEdit_25->clear();
a=0;

     ui->stackedWidget->setCurrentIndex(4);



}



void MainWindow::on_pushButton_5_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    int cin =ui->lineEdit_3->text().toInt();

     QString nom =ui->lineEdit_4->text();
      QString prenom =ui->lineEdit_5->text();
       QString adresse =ui->lineEdit_6->text();
       QDate date_de_naissance =ui->dateEdit->date();
       int numero =ui->lineEdit_24->text().toInt();
       QString email =ui->lineEdit_25->text();
      bool cinn, nomm,prenomm,adressee,numeroo,emaill;
      cinn= p.controlSaisieNumVide(cin,"cin");
       if(cinn==true)
       {
         nomm= p.controlSaisieCharVide(nom,"nom");
          if (nomm==true)
               {nomm= p.controlsaisiechar(nom,"nom");}
            if (nomm==true){
                 prenomm= p.controlSaisieCharVide(prenom,"prenom");
                  if (prenomm==true)
                       {prenomm= p.controlsaisiechar(prenom,"prenom");}
                   if (prenomm==true) {
                  adressee= p.controlSaisieCharVide(adresse,"adresse");
                  if(adressee==true){

                   numeroo= p.controlSaisieNumVide(numero,"numero");
                   if(numeroo==true){
                   emaill= p.controlsaisieMail(email);

       if(emaill==true){
       patient p(cin,nom,prenom,date_de_naissance,adresse,numero,email);
       bool test;
       test=p.ajouter();
       if(test){
       QMessageBox::information(nullptr, QObject::tr("Patient ajouter"),
                   QObject::tr("connection successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

       ui->tableView_2->setModel(p.afficher());
       ui->tableView_3->setModel(p.afficher());

if (a==0){
       ui->stackedWidget->setCurrentIndex(3);
}
else
     {
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(1);

}
}
   else
       {

       QMessageBox::critical(nullptr, QObject::tr("patient n'est pas ajouter"),
                   QObject::tr("Le cin existe deja.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
                }

            }
                  }
                  }}}}





void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString text;
    text=ui->lineEdit_2->text();
    if(text == "")
    {
        ui->tableView_2->setModel(p.afficher());
    }
    else
    {
text=text.toLower();
    text[0]=text[0].toUpper();
        ui->tableView_2->setModel(p.recherche(text));
    }
}

void MainWindow::on_pushButton_18_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    int row =ui->tableView_2->selectionModel()->currentIndex().row();
        QString code=ui->tableView_2->model()->index(row,0).data().toString();

        if(row==-1)
        { QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                                QObject::tr("selectionnez patient que vous voullez le supprimer !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}
        else

        {QMessageBox msgbox;
            msgbox.setWindowTitle("Supprimer");
            msgbox.setText("Voulez-vous supprimer ce patient");
            msgbox.setStandardButtons(QMessageBox::Yes)  ;
            msgbox.addButton(QMessageBox::No);
            if(msgbox.exec()== QMessageBox::Yes)
                  {

            bool test =p.supprimer(code);

        if(test)
        {

            ui->tableView_2->setModel(p.afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un patient"),
                        QObject::tr("patient supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else{
                ui->tableView_2->setModel(p.afficher());
            }
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    int row =ui->tableView_2->selectionModel()->currentIndex().row();
    QString code=ui->tableView_2->model()->index(row,0).data().toString();
    QString nom=ui->tableView_2->model()->index(row,1).data().toString();

    QString prenom=ui->tableView_2->model()->index(row,2).data().toString();
    QDate date=ui->tableView_2->model()->index(row,3).data().toDate();
    QString adresse=ui->tableView_2->model()->index(row,4).data().toString();
    QString numero=ui->tableView_2->model()->index(row,5).data().toString();
    QString email=ui->tableView_2->model()->index(row,6).data().toString();

    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                            QObject::tr("Selectionnez  que vous voulez le modifier !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
   ui->lineEdit_13->setText(code);
   ui->lineEdit_9->setText(nom);
   ui->lineEdit_10->setText(prenom);
    ui->dateEdit_2->setDate(date);
   ui->lineEdit_11->setText(adresse);
    ui->lineEdit_26->setText(numero);
     ui->lineEdit_27->setText(email);
     ui->stackedWidget->setCurrentIndex(5);





    }

}

void MainWindow::on_pushButton_10_clicked()
{

    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    int row =ui->tableView_2->selectionModel()->currentIndex().row();
        int code=ui->tableView_2->model()->index(row,0).data().toInt();
        QString nom=ui->lineEdit_9->text();
        QString prenom = ui->lineEdit_10->text();
        QString adresse  = ui->lineEdit_11->text();
        QDate date_de_naissance=ui->dateEdit_2->date();
        int numero=ui->lineEdit_26->text().toInt();
            QString email=ui->lineEdit_27->text();
            bool nomm,prenomm,adressee,numeroo,emaill;

               nomm= p.controlSaisieCharVide(nom,"nom");
                if (nomm==true)
                     {nomm= p.controlsaisiechar(nom,"nom");}
                  if (nomm==true){
                       prenomm= p.controlSaisieCharVide(prenom,"prenom");
                        if (prenomm==true)
                             {prenomm= p.controlsaisiechar(prenom,"prenom");}
                         if (prenomm==true) {
                        adressee= p.controlSaisieCharVide(adresse,"adresse");
                        if(adressee==true){

                         numeroo= p.controlSaisieNumVide(numero,"numero");
                         if(numeroo==true){
                         emaill= p.controlsaisieMail(email);

             if(emaill==true){
            QMessageBox msgbox;
                        msgbox.setWindowTitle("Modifier");
                        msgbox.setText("Voulez-vous modifier ce patient");
                        msgbox.setStandardButtons(QMessageBox::Yes)  ;
                        msgbox.addButton(QMessageBox::No);
                        if(msgbox.exec()== QMessageBox::Yes)
                              {
        bool test=p.modifier(code,nom,prenom,date_de_naissance,adresse,numero,email);
        if(test)
        { ui->tableView_2->setModel(p.afficher());
            ui->stackedWidget->setCurrentIndex(3);
            QMessageBox ::information(nullptr,QObject::tr("modifier un patient"),
                                              QObject::tr("patient modifié.\n"
                                                  "click ok to exit"),QMessageBox::Ok);

        }
        else
        {
            QMessageBox ::critical(nullptr,QObject::tr("modifier un patient"),
                                              QObject::tr("Erreur.\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);

        }
                        }
                        else
                        {
                             ui->stackedWidget->setCurrentIndex(5);
                        }

}

}}}}}



void MainWindow::on_pushButton_11_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tableView_2->model()->rowCount();
            const int columnCount =ui->tableView_2->model()->columnCount();

            out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("eleve")
                    <<  "</head>\n"
                    "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                        "<img src='C:/Users/ksemt/Desktop/final/icon/logo.webp' width='100' height='100'>\n"
                        "<h1>Liste des patient</h1>"



                        "<table border=1 cellspacing=0 cellpadding=2>\n";


            // headers
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableView_2->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";
                // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tableView_2->isColumnHidden(column)) {
                               QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table>\n"
                       "</body>\n"
                       "</html>\n";

                   QTextDocument *document = new QTextDocument();
                   document->setHtml(strStream);

                   QPrinter printer;

                   QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                   if (dialog->exec() == QDialog::Accepted) {
                       document->print(&printer);
                }
}

void MainWindow::on_pushButton_8_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    ui->lineEdit_18->clear();
            QDateTime date=QDateTime::currentDateTime();
              ui->dateTimeEdit->setDateTime(date);

    ui->stackedWidget_2->setCurrentIndex(1);
    ui->tableView_3->setModel(p.afficher());
}

void MainWindow::on_pushButton_20_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    int row =ui->tableView_3->selectionModel()->currentIndex().row();
    QString cin=ui->tableView_3->model()->index(row,1).data().toString();
    QString nom=ui->tableView_3->model()->index(row,2).data().toString();

    QString prenom=ui->tableView_3->model()->index(row,3).data().toString();
    QDateTime date=ui->tableView_3->model()->index(row,4).data().toDateTime();
    QString docteur=ui->tableView_3->model()->index(row,5).data().toString();


    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                            QObject::tr("Selectionnez rendez-vous que vous voulez le modifier !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
   ui->lineEdit_23->setText(cin);
   ui->lineEdit_19->setText(nom);
   ui->lineEdit_20->setText(prenom);
    ui->dateTimeEdit_2->setDateTime(date);
   ui->lineEdit_22->setText(docteur);
     ui->stackedWidget->setCurrentIndex(2);





    }

}





void MainWindow::on_pushButton_15_clicked()
{
    if(h==0)
    {
        ui->tableView_2->setModel( p.trieAlpha());
h=1;
    }
    else
    {
    ui->tableView_2->setModel( p.trieAlphaa());
    h=0;
    }

}

void MainWindow::on_pushButton_16_clicked()
{
    if(h==0){

    ui->tableView_2->setModel( p.trieAdresse());
    h=1;
    }
    else
    {
    ui->tableView_2->setModel( p.trieAdressee());
    h=0;}

}

void MainWindow::on_pushButton_21_clicked()
{
    if(h==0)
    {
        ui->tableView_2->setModel( p.trieCin());
        h=1;
    }
    else{
          ui->tableView_2->setModel( p.trieCinn());
          h=0;
    }
}

void MainWindow::on_pushButton_22_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    int row =ui->tableView_3->selectionModel()->currentIndex().row();
    QString cin=ui->tableView_3->model()->index(row,0).data().toString();
    QString nom=ui->tableView_3->model()->index(row,1).data().toString();
    QString prenom=ui->tableView_3->model()->index(row,2).data().toString();


    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                            QObject::tr("Selectionnez le patient que vous voullez le fixer un rendez-vous !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
   ui->lineEdit_14->setText(cin);
   ui->lineEdit_15->setText(nom);
   ui->lineEdit_16->setText(prenom);
   ui->stackedWidget_2->setCurrentIndex(0);
   ui->stackedWidget->setCurrentIndex(1);
}

}

void MainWindow::on_pushButton_13_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    int cin =ui->lineEdit_14->text().toInt();
     QString nom =ui->lineEdit_15->text();
      QString prenom =ui->lineEdit_16->text();
       QString docteur =ui->lineEdit_18->text();
       QDateTime date =ui->dateTimeEdit->dateTime();
       rendez_vous rdv(cin,nom,prenom,date,docteur);
      int docteurr;
       docteurr= rdv.controlSaisieCharVide(docteur,"docteur");
        if (docteurr==true)
             {docteurr= rdv.controlsaisiechar(docteur,"docteur");}
          if (docteurr==true){
       bool test;
       test=rdv.ajouter();
       if(test){
       QMessageBox::information(nullptr, QObject::tr("rendez vous ajouter"),
                   QObject::tr("connection successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tableView_3->setModel(rdv.afficher());

       ui->stackedWidget->setCurrentIndex(0);

}
   else
       {

       QMessageBox::critical(nullptr, QObject::tr("rendez-vous n'est pas ajouter"),
                   QObject::tr("Le id existe deja.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
}}

void MainWindow::on_pushButton_23_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
   ui->lineEdit_5->clear();
  ui->lineEdit_6->clear();
    ui->dateEdit_2->clear();
            ui->lineEdit_24->clear();
            ui->lineEdit_25->clear();
a=1;
ui->stackedWidget->setCurrentIndex(4);



}




void MainWindow::on_pushButton_50_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    int cin=ui->lineEdit_23->text().toInt();
           QString nom = ui->lineEdit_19->text();
           QString prenom  = ui->lineEdit_20->text();
           QDateTime date=ui->dateTimeEdit_2->dateTime();
           QString docteur=ui->lineEdit_22->text();
           int docteurr;
            docteurr= rdv.controlSaisieCharVide(docteur,"docteur");
             if (docteurr==true)
                  {docteurr= rdv.controlsaisiechar(docteur,"docteur");}
               if (docteurr==true){
               QMessageBox msgbox;
                           msgbox.setWindowTitle("Modifier");
                           msgbox.setText("Voulez-vous modifier ce rendez-vous");
                           msgbox.setStandardButtons(QMessageBox::Yes)  ;
                           msgbox.addButton(QMessageBox::No);

                           if(msgbox.exec()== QMessageBox::Yes)
                                 {
           bool test=rdv.modifier(cin,nom,prenom,date,docteur);
           if(test)
           { ui->tableView_3->setModel(rdv.afficher());
               ui->stackedWidget->setCurrentIndex(0);
               QMessageBox ::information(nullptr,QObject::tr("modifier un rendez-vous"),
                                                 QObject::tr("rendez-vous modifié.\n"
                                                     "click ok to exit"),QMessageBox::Ok);

           }
           else
           {
               QMessageBox ::critical(nullptr,QObject::tr("modifier un rendez-vous"),
                                                 QObject::tr("Erreur.\n"
                                                     "click cancel to exit"),QMessageBox::Cancel);

           }
                           }
                           else
                           {
                                ui->stackedWidget->setCurrentIndex(2);
                           }
}}

void MainWindow::on_pushButton_19_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
    int row =ui->tableView_3->selectionModel()->currentIndex().row();
        QString code=ui->tableView_3->model()->index(row,0).data().toString();

        if(row==-1)
        { QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
                                QObject::tr("selectionnez patient que vous voullez le supprimer !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);}
        else

        {QMessageBox msgbox;
            msgbox.setWindowTitle("Supprimer");
            msgbox.setText("Voulez-vous supprimer ce rendez_vous");
            msgbox.setStandardButtons(QMessageBox::Yes)  ;
            msgbox.addButton(QMessageBox::No);
            if(msgbox.exec()== QMessageBox::Yes)
                  {

            bool test =rdv.supprimer(code);

        if(test)
        {

            ui->tableView_3->setModel(rdv.afficher());

            QMessageBox::information(nullptr, QObject::tr("Supprimer un rendez vous"),
                        QObject::tr("rendez_vous supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un rendez vous"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else{
                ui->tableView_3->setModel(rdv.afficher());
            }
    }
}

void MainWindow::on_pushButton_24_clicked()
{

    if(h==0)
    {
    ui->tableView_3->setModel( rdv.triePatient());
    h=1;
    }
else
     {
         ui->tableView_3->setModel( rdv.triePatientt());
         h=0;
     }

}

void MainWindow::on_pushButton_26_clicked()
{
    if(h==0)
    {
    ui->tableView_3->setModel( rdv.trieDate());
    h=1;
}
    else
    {ui->tableView_3->setModel( rdv.trieDatee());
        h=0;
    }
}

void MainWindow::on_pushButton_25_clicked()
{
    if (h==0)
    {
    ui->tableView_3->setModel( rdv.trieDocteur());
    h=1;}
    else {
        ui->tableView_3->setModel( rdv.trieDocteurr());
        h=0;

    }

}

void MainWindow::on_lineEdit_8_textChanged(const QString &arg1)
{
    QString text;
    text=ui->lineEdit_8->text();
    if(text == "")
    {
        ui->tableView_3->setModel(rdv.afficher());
    }
    else
    {
text=text.toLower();
    text[0]=text[0].toUpper();
        ui->tableView_3->setModel(rdv.recherche(text));
    }
}

void MainWindow::on_pushButton_12_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tableView_3->model()->rowCount();
            const int columnCount =ui->tableView_3->model()->columnCount();

            out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("eleve")
                    <<  "</head>\n"
                    "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                        "<img src='C:/Users/ksemt/Desktop/final/icon/logo.webp' width='100' height='100'>\n"
                        "<h1>Liste des rendez vous</h1>"



                        "<table border=1 cellspacing=0 cellpadding=2>\n";


            // headers
                out << "<thead><tr bgcolor=#f0f0f0>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableView_3->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";
                // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tableView_3->isColumnHidden(column)) {
                               QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                           }
                       }
                       out << "</tr>\n";
                   }
                   out <<  "</table>\n"
                       "</body>\n"
                       "</html>\n";

                   QTextDocument *document = new QTextDocument();
                   document->setHtml(strStream);

                   QPrinter printer;

                   QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                   if (dialog->exec() == QDialog::Accepted) {
                       document->print(&printer);
                }
}

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    int row =ui->tableView_2->selectionModel()->currentIndex().row();
        QString code=ui->tableView_2->model()->index(row,0).data().toString();
        ui->stackedWidget->setCurrentIndex(0);
        ui->lineEdit_8->setText(code);

}





void MainWindow::on_pushButton_7_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/HP/Documents/Health-application/button.mp3"));
    player->setVolume(50);
    player->play();
}
