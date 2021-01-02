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
#include <QGraphicsOpacityEffect>
#include <QCompleter>
#include <QKeyEvent>
#include "acte.h"
#include <QMediaPlayer>
#include<QGraphicsOpacityEffect>
#include"chambre.h"
#include"machine.h"
#include<QMessageBox>
#include"machine.h"
#include <QCoreApplication>
#include <QPdfWriter>
#include <QPainter>
#include <QPdfWriter>
#include <QUrl>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QSqlRelationalTableModel>
#include "tableprinter.h"
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include"services.h"
#include "employee.h"
#include"QMessageBox"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPushButton>
#include<QFileInfo>
class PrintBorder : public PagePrepare {
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter) { // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    
    employee Etmp;
    services m;
    ui->stackedWidget->setCurrentIndex(9);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->stacked_modif_fournisseur->setCurrentIndex(1);
    ui->tab_visite->setModel(tmpvisite.afficher());
    ui->hadiltab1->setModel(tmp.afficher());
     ui->hadiltab->setModel(tm.afficher1());

    ui->password->setEchoMode(QLineEdit::Password);

        click = new QMediaPlayer();
        click->setMedia(QUrl::fromLocalFile("C:/Users/Pavillion/Desktop/E-HEALTH/photo/click.mp3"));

        QSqlQueryModel *model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare("select des_art from medicament");
        qry.exec();
        model->setQuery(qry);
        ui->libelle_med->setModel(model);
        ui->libelle_med->setCurrentIndex(-1);
        ui->tableView_5->setModel(p.afficher());
        ui->tableView_4->setModel(rdv.afficher());
        ui->lineEdit_34->setMaxLength(8);
        ui->lineEdit_38->setMaxLength(8);
        ui->lineEdit_44->setMaxLength(8);
        ui->lineEdit_29->setMaxLength(25);
        ui->lineEdit_32->setMaxLength(25);
        ui->lineEdit_35->setMaxLength(20);
        ui->lineEdit_36->setMaxLength(20);
        ui->lineEdit_40->setMaxLength(20);
        ui->lineEdit_41->setMaxLength(20);

        ui->tableView_afficher_emp->setModel(Etmp.afficher());
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z ' ']+"),this);
            ui->tableView_afficher_emp->setModel(m.afficher());
                ui->ajouter_id_emp->setValidator(new QIntValidator(10000000, 99999999, this));
                ui->id_service->setValidator(new QIntValidator(10000000, 99999999, this));
                ui->ajouter_nom_emp->setValidator(validator_String);
                ui->ajouter_prenom_emp->setValidator(validator_String);
        /*animation1 =new QPropertyAnimation (ui->connect,"geometry");
            animation1->setDuration(2000);
            animation1->setStartValue(ui->connect->geometry());
             animation1->setEndValue(QRect(748,480,91,31));
            animationGroup =new QParallelAnimationGroup;
            animationGroup->addAnimation(animation1);

                animationGroup =new QParallelAnimationGroup;
                animationGroup->addAnimation(animation1);

                animationGroup->start();*/
}
void MainWindow::clear_visite()
{

  ui->nom_patient_2->clear();
    ui->prenom_patient->clear();
   ui->date_naiss_patient->clear();
   ui->observation->clear();
    ui->diagnostic->clear();
}

void MainWindow::clear_ordonnace()
{
   ui->code_med->clear();
    ui->libelle_med->setCurrentIndex(-1);
ui->mode->clear();
ui->frequence->clear();
 ui->quantite->setValue(0);}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ajouter_visite()
{
    QString nom_patient=ui->nom_patient_2->text();
    QString prenom_patient=ui->prenom_patient->text();
    QString date_naiss_patient=ui->date_naiss_patient->date().toString("dd/MM/yyyy");
    QString observation=ui->observation->toPlainText();
    QString diagnostic=ui->diagnostic->toPlainText();

    if(nom_patient.isEmpty()|| prenom_patient.isEmpty()||nom_patient.contains(QRegExp("^[a-z+$+A-Z]"))==0||prenom_patient.contains(QRegExp("^[a-z+$+A-Z]"))==0||date_naiss_patient.isEmpty()||observation.isEmpty()||diagnostic.isEmpty())
      {


        QMessageBox::information(nullptr, QObject::tr("erreur"),
                          QObject::tr("Vérifier vos champs.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
 {
        visite v( nom_patient, prenom_patient , observation, diagnostic ,date_naiss_patient);
        bool test=v.ajouter();
    if(test)
    {
       if(lng=="ang")
       {
           QMessageBox::information(nullptr, QObject::tr("Add visit"),
                             QObject::tr("Visit added.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
           clear_visite();
       }
       else
           if(lng=="fr")
       {

        QMessageBox::information(nullptr, QObject::tr("Ajouter une visite"),
                          QObject::tr("Visite ajoutée.\n"
                                      "Cliquez sur  cancel Pour Quitter."), QMessageBox::Cancel);
        clear_visite();
 }

    }
    }
}
void MainWindow::on_nouvelle_visite_clicked()
{
click->play();
    clear_ordonnace();
    QSqlQueryModel *model_cin=new QSqlQueryModel();
    QSqlQuery qury;
    qury.prepare("select cin from patient,rendezvous where patient.cin=rendezvous.cin_patient and to_char(date_rdv,'YYYY-MM-DD')=to_char(sysdate, 'YYYY-MM-DD')");
    qury.exec();
    model_cin->setQuery(qury);
    ui->cin_patient_visite->setModel(model_cin);
    ui->cin_patient_visite->setCurrentIndex(-1);
   clear_visite();
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_exit_clicked()
{
      _exit(EXIT_FAILURE);
}

void MainWindow::on_retour_clicked()
{
    click->play();

    clear_ordonnace();

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ordenance_clicked()

{click->play();


    QString nom_patient=ui->nom_patient_2->text();
    QString prenom_patient=ui->prenom_patient->text();
    QString date_naiss_patient=ui->date_naiss_patient->date().toString("dd/MM/yyyy");
    QString observation=ui->observation->toPlainText();
    QString diagnostic=ui->diagnostic->toPlainText();

    if(nom_patient.isEmpty()|| prenom_patient.isEmpty()||nom_patient.contains(QRegExp("^[a-z+$+A-Z]"))==0||prenom_patient.contains(QRegExp("^[a-z+$+A-Z]"))==0||date_naiss_patient.isEmpty()||observation.isEmpty()||diagnostic.isEmpty())
      {
        if(lng=="ang")
        {

        QMessageBox::information(nullptr, QObject::tr("error"),
                          QObject::tr("Check your fields.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            if(lng=="fr")
            {QMessageBox::information(nullptr, QObject::tr("erreur"),
                                      QObject::tr("Vérifier vos champs.\n"
                                                  "Cliquez sur  Cancel pour quitter."), QMessageBox::Cancel);}
    }
    else
 {
        visite v(nom_patient, prenom_patient , observation, diagnostic ,date_naiss_patient);
        bool test=v.ajouter();
    if(test)
    {


        QMessageBox::information(nullptr, QObject::tr("Ajouter une visite"),
                          QObject::tr("Visite ajoutée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_medicament->setModel(tmpmedicament.afficher());


       clear_ordonnace();

        ui->stackedWidget->setCurrentIndex(3);
    }
    }





}

void MainWindow::on_retour_ord_clicked()
{click->play();
    ui->stackedWidget_2->setCurrentIndex(0);

    ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_ajouter_ord_clicked()
{click->play();


      QString  code_med = ui->code_med->text();
      QString libelle= ui->libelle_med->currentText();
      QString mode= ui->mode->text();
      QString frequence=ui->frequence->text();
      int qts=ui->quantite->value();

if(code_med.isEmpty()|| libelle.isEmpty() || mode.isEmpty() || mode.isEmpty()|| frequence.isEmpty() || qts==0)
   {if(lng=="ang")
    {

    QMessageBox::information(nullptr, QObject::tr("error"),
                      QObject::tr("Check your fields.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        if(lng=="fr")
        {QMessageBox::information(nullptr, QObject::tr("erreur"),
                                  QObject::tr("Vérifier vos champs.\n"
                                              "Cliquez sur  Cancel pour quitter."), QMessageBox::Cancel);}
}
else
{

    medicament m (code_med,libelle,mode,frequence,qts);
    bool test=m.ajouter();
    if(test)
    {
     ui->tab_medicament->setModel(tmpmedicament.afficher());
     ui->tab_medicament->setColumnWidth(1,300);
     QMessageBox::information(nullptr, QObject::tr("Ajouter Médicament"),
                              QObject::tr("Médicament  ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
     clear_ordonnace();

    }





}

}




void MainWindow::on_valider_clicked()
{click->play();


   ajouter_visite();
}


void MainWindow::on_afficher_visite_clicked()
{  click->play();

    ui->tab_visite->setModel(tmpvisite.afficher());
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_retour_2_clicked()
{click->play();

    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_supprimer_ord_clicked()
{click->play();

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
        ui->tab_medicament->setColumnWidth(1,300);

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



void MainWindow::on_retour_aff_clicked()
{click->play();

    ui->stackedWidget->setCurrentIndex(5);

}


void MainWindow::on_modifier_ord_clicked()
{click->play();

    QString  code_med = ui->code_med_modif->text();
    QString libelle= ui->libelle__modif->text();
    QString mode= ui->mode_modif->text();
    QString frequence=ui->freq__modif->text();
    int qts=ui->qts_modif->value();
    int x=ui->tab_medicament->model()->rowCount();

    if(code_med.isEmpty()|| libelle.isEmpty() || mode.isEmpty() || mode.isEmpty()|| frequence.isEmpty() || qts==0 || x==0)
       {QMessageBox::warning(nullptr, QObject::tr("warning"),
                                 QObject::tr("remplissez touts les champs pour modifier/tableau de médicament vide.\n"
                                             "Click ok to exit."), QMessageBox::Ok);}
    else
    {
        medicament m(code_med,libelle,mode,frequence,qts);
        bool test=m.modifier();
        if(test)
        {
         ui->tab_medicament->setModel(tmpmedicament.afficher());
         ui->tab_medicament->setColumnWidth(1,300);

         QMessageBox::information(nullptr, QObject::tr("Modifier Médicament"),
                                  QObject::tr("Médicament modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
         ui->code_med_modif->clear();
           ui->libelle__modif->clear();
          ui->mode_modif->clear();
         ui->freq__modif->clear();
        ui->qts_modif->setValue(0);
        }



    }



}

void MainWindow::on_pdf_clicked()
{click->play();

    QString strStream;
                           QTextStream out(&strStream);
                           const int rowCount = ui->tab_medicament->model()->rowCount();
                           const int columnCount =ui->tab_medicament->model()->columnCount();

                           out <<  "<html>\n"
                                   "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                   <<  QString("<title>%1</title>\n").arg("Ordonnance")
                                   <<  "</head>\n"
                                   "<body bgcolor=#ffffff link=#5000A0>\n"
                                       "<img src='C:/Users/Pavillion/Desktop/E-HEALTH/photo/logo' width='100' height='100'>\n"
                                       "<h1>ORDONNANCE </h1>"



                                       "<table border=1 cellspacing=0 cellpadding=2>\n";


                           // headers
                               out << "<thead><tr bgcolor=#f0f0f0>";
                               for (int column = 0; column < columnCount; column++)
                                   if (!ui->tab_medicament->isColumnHidden(column))
                                       out << QString("<th>%1</th>").arg(ui->tab_medicament->model()->headerData(column, Qt::Horizontal).toString());
                               out << "</tr></thead>\n";
                               // data table
                                  for (int row = 0; row < rowCount; row++) {
                                      out << "<tr>";
                                      for (int column = 0; column < columnCount; column++) {
                                          if (!ui->tab_medicament->isColumnHidden(column)) {
                                              QString data = ui->tab_medicament->model()->data(ui->tab_medicament->model()->index(row, column)).toString().simplified();
                                              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                          }
                                      }
                                      out << "</tr>\n";
                                  }
                                  out <<  "</table>\n"
                                      "</body>\n"
                                      "</html>\n";
                                  QTextDocument * document = new  QTextDocument ();

                       document->setHtml(strStream);



                       QPrinter printer(QPrinter::PrinterResolution);

                                                   document-> setHtml (strStream);

                                                   QPrinter QPrinter;

                                                   QPrintDialog * dialog = new  QPrintDialog (& QPrinter, NULL );
                                                   if (dialog-> exec () == QDialog::Accepted) {
                                                       document-> print (& QPrinter);}



}

void MainWindow::on_supprimer_visite_clicked()
{click->play();

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
         ui->libelle__modif->setText(query.value(1).toString());
         ui->mode_modif->setText(query.value(2).toString());
         ui->freq__modif->setText(query.value(3).toString());
         ui->qts_modif->setValue(query.value(4).toInt());


        }
   }
}

void MainWindow::on_tab_visite_doubleClicked(const QModelIndex &index)
{
    QString val=ui->tab_visite->model()->data(index).toString();
    ui->tab_ord->setModel(tmpmedicament.afficher_ord_visite(val));
    ui->acte_visitie->setModel(tmpacte.affiche1(val));
    int row=ui->tab_ord->model()->rowCount();
    int row1=ui->acte_visitie->model()->rowCount();

    if(row==0 && row1==0)
    {QMessageBox::warning(nullptr, QObject::tr("Ordonnance/acte medical"),
                              QObject::tr("cette visite n'a pas ni une ordonnance ni un acte.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {

    ui->stackedWidget->setCurrentIndex(6);
    }

}





void MainWindow::on_tab_ord_doubleClicked(const QModelIndex &index)
{
    ui->stackedWidget_3->setCurrentIndex(1);

    QString val=ui->tab_ord->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from ordonnance where code_med='"+val+"'");

    if(query.exec())
    {
        while(query.next())
        {ui->code_med_modif_2->setText(query.value(0).toString());
         ui->libelle__modif_2->setText(query.value(1).toString());
         ui->mode_modif_2->setText(query.value(2).toString());
         ui->freq__modif_2->setText(query.value(3).toString());
         ui->qts_modif_2->setValue(query.value(4).toInt());


        }
   }

}

void MainWindow::on_conf_modif_ord_clicked()
{click->play();

    QString  code_med = ui->code_med_modif_2->text();
    QString libelle= ui->libelle__modif_2->text();
    QString mode= ui->mode_modif_2->text();
    QString frequence=ui->freq__modif_2->text();
    int qts=ui->qts_modif_2->value();
    int x=ui->tab_ord->model()->rowCount();

    if(code_med.isEmpty()|| libelle.isEmpty() || mode.isEmpty() || mode.isEmpty()|| frequence.isEmpty() || qts==0 || x==0)
       {QMessageBox::warning(nullptr, QObject::tr("warning"),
                                 QObject::tr("remplissez touts les champs pour modifier/tableau de médicament vide.\n"
                                             "Click ok to exit."), QMessageBox::Ok);}
    else
    {
        medicament m(code_med,libelle,mode,frequence,qts);
        bool test=m.modifier();
        if(test)
        {
         ui->tab_ord->setModel(tmpmedicament.afficher());
         ui->tab_medicament->setColumnWidth(1,300);

         QMessageBox::information(nullptr, QObject::tr("Modifier Médicament"),
                                  QObject::tr("Médicament modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        }

}
     ui->code_med_modif_2->clear();
      ui->libelle__modif_2->clear();
       ui->mode_modif_2->clear();
      ui->freq__modif_2->clear();
      ui->qts_modif_2->setValue(0);
}

void MainWindow::on_supp_ord_clicked()
{click->play();

    int row =ui->tab_ord->selectionModel()->currentIndex().row();
    QString code_med=ui->tab_ord->model()->index(row,0).data().toString();

    bool test =tmpmedicament.supprimer(code_med);
    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("Supprimer un médicament"),
                            QObject::tr("Erreur ! selectionnez médicament que vous voulez le supprimer !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
    if(test)
    {
        ui->tab_ord->setModel(tmpmedicament.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un médicament"),
                    QObject::tr("médicament  supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
                ui->tab_ord->setModel(tmpmedicament.afficher());
                ui->tab_medicament->setColumnWidth(1,300);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un médicament"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}



void MainWindow::on_radioButton_clicked()
{
   ui->tab_visite->setModel(tmpvisite.afficher_desc());
}

void MainWindow::on_radioButton_6_clicked()
{
 ui->tab_visite->setModel(tmpvisite.afficher_asc());
}

void MainWindow::on_radioButton_2_clicked()
{
   ui->tab_visite->setModel(tmpvisite.afficher_desc_nom());
}

void MainWindow::on_radioButton_3_clicked()
{
  ui->tab_visite->setModel(tmpvisite.afficher_desc_date());
}

void MainWindow::on_radioButton_5_clicked()
{
  ui->tab_visite->setModel(tmpvisite.afficher_asc_nom());
}

void MainWindow::on_radioButton_4_clicked()
{
  ui->tab_visite->setModel(tmpvisite.afficher_asc_date());
}

void MainWindow::on_excel_clicked()
{click->play();

    QTableView *table;
            table = ui->tab_visite;

            QString filters("CSV files (.csv);;All files (.*)");
            QString defaultFilter("CSV files (*.csv)");
            QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                               filters, &defaultFilter);
            QFile file(fileName);

            QAbstractItemModel *model =  table->model();
            if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                QTextStream data(&file);
                QStringList strList;
                for (int i = 0; i < model->columnCount(); i++) {
                    if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                        strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                    else
                        strList.append("");
                }
                data << strList.join(";") << "\n";
                for (int i = 0; i < model->rowCount(); i++) {
                    strList.clear();
                    for (int j = 0; j < model->columnCount(); j++) {

                        if (model->data(model->index(i, j)).toString().length() > 0)
                            strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                        else
                            strList.append("");
                    }
                    data << strList.join(";") + "\n";
                }
                file.close();
                QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                          QObject::tr("Export avec succes .\n"
                                                      "Click OK to exit."), QMessageBox::Ok);
            }

}

void MainWindow::on_modif_visite_clicked()
{click->play();

    int row =ui->tab_visite->selectionModel()->currentIndex().row();
    int id_visite=ui->tab_visite->model()->index(row,0).data().toInt();
    QSqlQuery query;
    query.prepare("select to_date(date_naiss_patient,'dd-mm-yyyy') from visite where id_visite=:id_visite");
query.bindValue(":id_visite",id_visite);
    if(query.exec())
    {
        while(query.next())
        {
            QString nom=ui->tab_visite->model()->index(row,2).data().toString();
            QString prenom=ui->tab_visite->model()->index(row,3).data().toString();
             QDate  date_naiss=query.value(0).toDate();

            QString observation=ui->tab_visite->model()->index(row,5).data().toString();
            QString diagnostic=ui->tab_visite->model()->index(row,6).data().toString();





  modif=new modifier_visite(this);
  modif->set_nom_patient(nom);
  modif->set_prenom_patient(prenom);
  modif->set_date_naiss_patient(date_naiss);
  modif->set_observation(observation);
  modif->set_diagnostic(diagnostic);
  modif->set_id_visite(id_visite);
        }
    }

  modif->show();
}

void MainWindow::on_pushButton_8_clicked()
{click->play();

    ui->stackedWidget_2->setCurrentIndex(0);

}


void MainWindow::on_libelle_med_currentIndexChanged(const QString &arg1)
{
    QString nom=arg1;
    QSqlQuery qry;
    qry.prepare("select cod_art from medicament where des_art ='"+nom+"'");
if(qry.exec())
{while(qry.next())
    {

    ui->code_med->setText(qry.value(0).toString());
}
}
    }

void MainWindow::on_demande_acte_clicked()
{
    click->play();

     QString nom_patient=ui->nom_patient_2->text();
     QString prenom_patient=ui->prenom_patient->text();
     QString date_naiss_patient=ui->date_naiss_patient->date().toString("dd/MM/yyyy");
     QString observation=ui->observation->toPlainText();
     QString diagnostic=ui->diagnostic->toPlainText();

     if(nom_patient.isEmpty()|| prenom_patient.isEmpty()||nom_patient.contains(QRegExp("^[a-z+$+A-Z]"))==0||prenom_patient.contains(QRegExp("^[a-z+$+A-Z]"))==0||date_naiss_patient.isEmpty()||observation.isEmpty()||diagnostic.isEmpty())
       {  QMessageBox::information(nullptr, QObject::tr("erreur"),
                           QObject::tr("Vérifier vos champs.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
  {
         visite v( nom_patient, prenom_patient , observation, diagnostic ,date_naiss_patient);
         bool test=v.ajouter();
     if(test)
     {


         QMessageBox::information(nullptr, QObject::tr("Ajouter une visite"),
                           QObject::tr("Visite ajoutée.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
         clear_visite();
         QSqlQueryModel *model=new QSqlQueryModel();
         QSqlQuery qry;
         qry.prepare("select des_acte from acte");
         qry.exec();
         model->setQuery(qry);
         ui->acte->setModel(model);
         ui->acte->setCurrentIndex(-1);
         ui->Code_acte->clear();
         ui->stackedWidget->setCurrentIndex(2);



     }
     }

}



void MainWindow::on_valider_acte_clicked()
{click->play();

  QString code_acte=ui->Code_acte->text();
   QString des_acte=ui->acte->currentText();
if(ui->Code_acte->text().isEmpty()|| des_acte.isEmpty())
  {  QMessageBox::information(nullptr, QObject::tr("erreur"),
                      QObject::tr("Vérifier vos champs.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}
else
{
    acte a(code_acte,des_acte);
    bool test=a.ajouter();
if(test)
{
    ui->tab_acte_visite->setModel(tmpacte.afficher());
    ui->tab_acte_visite->setColumnWidth(1,1270);
    ui->Code_acte->clear();
    ui->acte->setCurrentIndex(-1);

   QMessageBox::information(nullptr, QObject::tr("Ajouter d'un acte "),
                      QObject::tr("acte ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}
}

}

void MainWindow::on_supprimer_acte_clicked()
{click->play();

    int row =ui->tab_acte_visite->selectionModel()->currentIndex().row();
    QString code_act=ui->tab_acte_visite->model()->index(row,0).data().toString();

    bool test =tmpacte.supprimer(code_act);
    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("Supprimer un acte"),
                            QObject::tr("Erreur selectionnez acte que vous voulez le supprimer !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
    if(test)
    {
    ui->tab_acte_visite->setModel(tmpacte.afficher());
    QMessageBox::information(nullptr, QObject::tr("Supprimer un acte"),
    QObject::tr("acte  supprimé.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un médicament"),
    QObject::tr("Erreur !.\n"
    "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_retour_3_clicked()
{click->play();

     ui->Code_acte->clear();
     ui->acte->setCurrentIndex(-1);
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_act_ord_clicked()
{click->play();
    ui->tab_medicament->setModel(tmpmedicament.afficher());

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select des_art from medicament");
    qry.exec();
    model->setQuery(qry);
    ui->libelle_med->setModel(model);
    ui->libelle_med->setCurrentIndex(-1);
   clear_ordonnace();

    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_ord_acte_clicked()
{click->play();

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("select des_acte from acte");
    qry.exec();
    model->setQuery(qry);
    ui->acte->setModel(model);
    ui->acte->setCurrentIndex(-1);
    ui->Code_acte->clear();
    ui->stackedWidget->setCurrentIndex(2);

}
void MainWindow::on_acte_currentIndexChanged(const QString &arg1)
{
    QString nom=arg1;
    QSqlQuery qry;
    qry.prepare("select cod_acte from acte where des_acte =:nom");
    qry.bindValue(":nom", nom);

if(qry.exec())
{while(qry.next())
    {

    ui->Code_acte->setText(qry.value(0).toString());
}
}
}

void MainWindow::on_supp_acte_clicked()
{click->play();

    int row =ui->acte_visitie->selectionModel()->currentIndex().row();
    QString code_act=ui->acte_visitie->model()->index(row,0).data().toString();

    bool test =tmpacte.supprimer(code_act);
    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("Supprimer un acte"),
                            QObject::tr("Erreur ! selectionnez l'acte que vous voulez le supprimer !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
    if(test)
    {
        ui->acte_visitie->setModel(tmpacte.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un acte"),
                    QObject::tr("acte  supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
                ui->acte_visitie->setModel(tmpacte.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un acte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_anglais_clicked()
{
    lng="ang";
    // page d'acceuil
    ui->titre->setText("Medical visit");
    ui->titre->setStyleSheet("QLabel{color: rgb(255, 255, 255); font: 75 24pt MS Shell Dlg 2;text-decoration:underline;font-weight:600; color:#ffffff;}");
    ui->nouvelle_visite->setText("New visit");
    ui->afficher_visite->setText("Consult the visits");
    //----------------------------------//
    //Page nouvelle visite
    ui->nom_patient->setText("patient's name");
    ui->nom_patient->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-weight:600; color:#ffffff;}");
    ui->prenom_patient_2->setText("patient's first name");
    ui->prenom_patient_2->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-weight:600; color:#ffffff;}");

    ui->date_naiss_patient_2->setText("date of birth");
    ui->date_naiss_patient_2->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-weight:600; color:#ffffff;}");

    ui->observation_2->setText("observation");
    ui->observation_2->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-weight:600; color:#ffffff;}");

    ui->diagnostic_2->setText("Diagnostic");
    ui->diagnostic_2->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-weight:600; color:#ffffff;}");

    ui->demande_acte->setText("Medical act");
    ui->demande_acte->setStyleSheet("QPushButton {border:none;background-color:#0000FF;background-position: left center;background-repeat: no-repeat;border-radius: 5px;border:1px solid transparent;color:rgb(255, 255, 255);text-align: center; border-left:4px solid #0000FF;}QPushButton:hover {background-color:rgb(0, 0, 128);}QPushButton:pressed { border:2px solid rgb(0, 0, 128); }");

    ui->ordenance->setText("Prescription");
    ui->ordenance->setStyleSheet("QPushButton {border:none;background-color:#0000FF;background-position: left center;background-repeat: no-repeat;border-radius: 5px;border:1px solid transparent;color:rgb(255, 255, 255);text-align: center; border-left:4px solid #0000FF;}QPushButton:hover {background-color:rgb(0, 0, 128);}QPushButton:pressed { border:2px solid rgb(0, 0, 128); }");

    ui->valider->setText("Validate");
    ui->valider->setStyleSheet("QPushButton {border:none;background-color:#0000FF;background-position: left center;background-repeat: no-repeat;border-radius: 5px;border:1px solid transparent;color:rgb(255, 255, 255);text-align: center; border-left:4px solid #0000FF;}QPushButton:hover {background-color:rgb(0, 0, 128);}QPushButton:pressed { border:2px solid rgb(0, 0, 128); }");

    ui->retour->setText("Return");
    ui->retour->setStyleSheet("QPushButton {border:none;background-color:#0000FF;background-position: left center;background-repeat: no-repeat;border-radius: 5px;border:1px solid transparent;color:rgb(255, 255, 255);text-align: center; border-left:4px solid #0000FF;}QPushButton:hover {background-color:rgb(0, 0, 128);}QPushButton:pressed { border:2px solid rgb(0, 0, 128); }");
    //--------------------------------------//


}

void MainWindow::on_francais_clicked()
{
    lng="fr";
    // page d'acceuil
    ui->titre->setText("Visite Medical");
    ui->titre->setStyleSheet("QLabel{color: rgb(255, 255, 255); font: 75 24pt MS Shell Dlg 2;text-decoration:underline;font-weight:600; color:#ffffff;}");
    ui->nouvelle_visite->setText("Novelle visite");
    ui->afficher_visite->setText("Consulter les visites");
    //----------------------------------//
    //Page nouvelle visite
    ui->nom_patient->setText("nom patient");
    ui->nom_patient->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-size:10pt; font-weight:600; color:#ffffff;}");
    ui->prenom_patient_2->setText("prenom patient");
    ui->prenom_patient_2->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-weight:600; color:#ffffff;}");

    ui->date_naiss_patient_2->setText("date_naiss_patient");
    ui->date_naiss_patient_2->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-weight:600; color:#ffffff;}");

    ui->date_naiss_patient_2->setText("observation");
    ui->date_naiss_patient_2->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-weight:600; color:#ffffff;}");

    ui->diagnostic_2->setText("Diagnostic");
    ui->diagnostic_2->setStyleSheet("QLabel{color: rgb(255, 255, 255);font: 81 8pt Rockwell Extra Bold;font-weight:600; color:#ffffff;}");

    ui->demande_acte->setText("Demande d'acte");
    ui->demande_acte->setStyleSheet("QPushButton {border:none;background-color:#0000FF;background-position: left center;background-repeat: no-repeat;border-radius: 5px;border:1px solid transparent;color:rgb(255, 255, 255);text-align: center; border-left:4px solid #0000FF;}QPushButton:hover {background-color:rgb(0, 0, 128);}QPushButton:pressed { border:2px solid rgb(0, 0, 128); }");

    ui->ordenance->setText("ordonnance");
    ui->ordenance->setStyleSheet("QPushButton {border:none;background-color:#0000FF;background-position: left center;background-repeat: no-repeat;border-radius: 5px;border:1px solid transparent;color:rgb(255, 255, 255);text-align: center; border-left:4px solid #0000FF;}QPushButton:hover {background-color:rgb(0, 0, 128);}QPushButton:pressed { border:2px solid rgb(0, 0, 128); }");

    ui->valider->setText("Valider");
    ui->valider->setStyleSheet("QPushButton {border:none;background-color:#0000FF;background-position: left center;background-repeat: no-repeat;border-radius: 5px;border:1px solid transparent;color:rgb(255, 255, 255);text-align: center; border-left:4px solid #0000FF;}QPushButton:hover {background-color:rgb(0, 0, 128);}QPushButton:pressed { border:2px solid rgb(0, 0, 128); }");

    ui->retour->setText("Retour");
    ui->retour->setStyleSheet("QPushButton {border:none;background-color:#0000FF;background-position: left center;background-repeat: no-repeat;border-radius: 5px;border:1px solid transparent;color:rgb(255, 255, 255);text-align: center; border-left:4px solid #0000FF;}QPushButton:hover {background-color:rgb(0, 0, 128);}QPushButton:pressed { border:2px solid rgb(0, 0, 128); }");
    //--------------------------------------//


}






void MainWindow::on_page_visite_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);



}

void MainWindow::on_page_rdv_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_retour_menu_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_retour_menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_patient_clicked()
{


QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
        ui->stackedWidget_6->setGraphicsEffect(eff);
        QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
        a->setDuration(150);
        a->setStartValue(0);
        a->setEndValue(1);
        a->setEasingCurve(QEasingCurve::InBack);
        a->start(QPropertyAnimation::DeleteWhenStopped);


    ui->stackedWidget_6->setCurrentIndex(3);

    ui->patient->setStyleSheet("		background-image: url(C:/Users/HP/Downloads/Integration/E-HEALTH/icons/16x16/cil-PEOPLE.png);"
                                   " background-position: left center;"
                                    "background-repeat: no-repeat;"
                                    "border: none;"
                                    "border-left: 32px solid #25283b;"
                                    "background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79);border-right: 5px solid #3d50eb; ");

    ui->rendez_vous_2->setStyleSheet("QPushButton{ 	background-image: url(C:/Users/HP/Downloads/Integration/E-HEALTH/icons/16x16/cil-clipboard.png);"
    "background-position: left center;"
    "background-repeat: no-repeat;"
    "border: none;"
    "border-left: 32px solid #25283b;"
    "border-right: 5px solid transparent;"
    "background-color:#25283b;"
    "text-align: left;}"
     "QPushButton:hover{ background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79); }");


}

void MainWindow::on_rendez_vous_clicked()
{

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->stackedWidget_6->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
            a->setDuration(150);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);

     ui->stackedWidget_6->setCurrentIndex(0);
      ui->stackedWidget_7->setCurrentIndex(0);
      ui->tableView_4->setModel(rdv.afficher());
      ui->lineEdit_12->clear();

      ui->rendez_vous->setStyleSheet( " background-image: url(C:/Users/Pavillion/Desktop/Integration/E-HEALTH/icons/16x16/16x16/cil-clipboard.png);background-position: left center;"
                                      "background-repeat: no-repeat;"
                                        "border: none;"
                                       "border-left: 32px solid #25283b;"
                                         "border-right: 5px solid transparent;"
                                             "background-color:#25283b;"
                                               "text-align: left;"
                                      "background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79);border-right: 5px solid #3d50eb; }");

      ui->patient->setStyleSheet("QPushButton{background-image: url(C:/Users/HP/Documents/health-app/icons/16x16/cil-PEOPLE.png);"
                                    " background-position: left center;"
                                     "background-repeat: no-repeat;"
                                     "border: none;"
                                     "border-left: 32px solid #25283b; }"
                                      ":hover:background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79);border-right: 5px solid #3d50eb; }"

                                       "QPushButton:hover{ background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79); }");





}

void MainWindow::on_ajouter_patient_2_clicked()
{



    ui->lineEdit_34->clear();
                ui->lineEdit_35->clear();
               ui->lineEdit_36->clear();
              ui->lineEdit_37->clear();

                        ui->lineEdit_38->clear();
                        ui->lineEdit_39->clear();
a=0;

     ui->stackedWidget_6->setCurrentIndex(4);



}



void MainWindow::on_ajouter_pat_2_clicked()
{

    int cin =ui->lineEdit_34->text().toInt();

     QString nom =ui->lineEdit_35->text();
      QString prenom =ui->lineEdit_36->text();
       QString adresse =ui->lineEdit_37->text();
       QDate date_de_naissance =ui->dateEdit_3->date();
       int numero =ui->lineEdit_38->text().toInt();
       QString email =ui->lineEdit_39->text();
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

       ui->tableView_5->setModel(p.afficher());
       ui->tableView_4->setModel(p.afficher());

if (a==0){
       ui->stackedWidget_6->setCurrentIndex(3);
}
else
     {
    ui->stackedWidget_6->setCurrentIndex(0);
    ui->stackedWidget_7->setCurrentIndex(1);

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





void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
    QString text;
    text=ui->lineEdit_7->text();
    if(text == "")
    {
        ui->tableView_5->setModel(p.afficher());
    }
    else
    {
text=text.toLower();
    text[0]=text[0].toUpper();
        ui->tableView_5->setModel(p.recherche(text));
    }
}

void MainWindow::on_supprimer_patient_2_clicked()
{

    int row =ui->tableView_5->selectionModel()->currentIndex().row();
        QString code=ui->tableView_5->model()->index(row,0).data().toString();

        if(row==-1)
        {    const int DeltaPos = 10;

            QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
            animation->setDuration(500);


               /* Animation mainwindow*/
                int oldX = pos().x();
                animation->setEasingCurve(QEasingCurve(static_cast<QEasingCurve::Type>(10)));
                animation->setKeyValueAt(0.0, QPoint(oldX - DeltaPos, pos().y()));
                animation->setKeyValueAt(0.1, QPoint(oldX + DeltaPos, pos().y()));
                animation->setKeyValueAt(0.2, QPoint(oldX - DeltaPos, pos().y()));
                animation->setKeyValueAt(0.3, QPoint(oldX + DeltaPos, pos().y()));
                animation->setKeyValueAt(0.4, QPoint(oldX - DeltaPos, pos().y()));
                animation->setKeyValueAt(0.5, QPoint(oldX + DeltaPos, pos().y()));
                animation->setKeyValueAt(0.6, QPoint(oldX - DeltaPos, pos().y()));
                animation->setKeyValueAt(0.7, QPoint(oldX + DeltaPos, pos().y()));
                animation->setKeyValueAt(0.8, QPoint(oldX - DeltaPos, pos().y()));
                animation->setKeyValueAt(0.9, QPoint(oldX + DeltaPos, pos().y()));
                animation->setKeyValueAt(1.0, QPoint(oldX, pos().y()));


            animation->start(QAbstractAnimation::DeleteWhenStopped);


            QMessageBox::critical(nullptr, QObject::tr("Supprimer un patient"),
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

            ui->tableView_5->setModel(p.afficher());

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
                ui->tableView_5->setModel(p.afficher());
            }
    }
}

void MainWindow::on_modifier_patient_2_clicked()
{

    int row =ui->tableView_5->selectionModel()->currentIndex().row();
    QString code=ui->tableView_5->model()->index(row,0).data().toString();
    QString nom=ui->tableView_5->model()->index(row,1).data().toString();
    QString prenom=ui->tableView_5->model()->index(row,2).data().toString();
    QDate date=ui->tableView_5->model()->index(row,3).data().toDate();
    QString adresse=ui->tableView_5->model()->index(row,4).data().toString();
    QString numero=ui->tableView_5->model()->index(row,5).data().toString();
    QString email=ui->tableView_5->model()->index(row,6).data().toString();

    if(row==-1)
    {    const int DeltaPos = 10;

        QPropertyAnimation *animation = new QPropertyAnimation(this, "pos");
        animation->setDuration(500);


           /* Animation mainwindow*/
            int oldX = pos().x();
            animation->setEasingCurve(QEasingCurve(static_cast<QEasingCurve::Type>(10)));
            animation->setKeyValueAt(0.0, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.1, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(0.2, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.3, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(0.4, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.5, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(0.6, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.7, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(0.8, QPoint(oldX - DeltaPos, pos().y()));
            animation->setKeyValueAt(0.9, QPoint(oldX + DeltaPos, pos().y()));
            animation->setKeyValueAt(1.0, QPoint(oldX, pos().y()));


        animation->start(QAbstractAnimation::DeleteWhenStopped);



        QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                            QObject::tr("Selectionnez  que vous voulez le modifier !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
   ui->lineEdit_43->setText(code);
   ui->lineEdit_40->setText(nom);
   ui->lineEdit_41->setText(prenom);
    ui->dateEdit_4->setDate(date);
   ui->lineEdit_42->setText(adresse);
    ui->lineEdit_44->setText(numero);
     ui->lineEdit_45->setText(email);
     ui->stackedWidget_6->setCurrentIndex(5);





    }
     }


void MainWindow::on_modifier_pat_2_clicked()
{


    int row =ui->tableView_5->selectionModel()->currentIndex().row();
        int code=ui->tableView_5->model()->index(row,0).data().toInt();
        QString nom=ui->lineEdit_40->text();
        QString prenom = ui->lineEdit_41->text();
        QString adresse  = ui->lineEdit_42->text();
        QDate date_de_naissance=ui->dateEdit_4->date();
        int numero=ui->lineEdit_44->text().toInt();
            QString email=ui->lineEdit_45->text();
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
        { ui->tableView_5->setModel(p.afficher());
            ui->stackedWidget_6->setCurrentIndex(3);
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
                             ui->stackedWidget_6->setCurrentIndex(5);
                        }

}

}}}}}



void MainWindow::on_imprimer_patient_2_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tableView_5->model()->rowCount();
            const int columnCount =ui->tableView_5->model()->columnCount();

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
                    if (!ui->tableView_5->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_5->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";
                // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tableView_5->isColumnHidden(column)) {
                               QString data = ui->tableView_5->model()->data(ui->tableView_5->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_ajouter_rdv_2_clicked()
{

    ui->lineEdit_29->clear();
            QDateTime date=QDateTime::currentDateTime();
              ui->dateTimeEdit_3->setDateTime(date);

    ui->stackedWidget_7->setCurrentIndex(1);
    ui->tableView_4->setModel(p.afficher());
}

void MainWindow::on_modifier_rdv_2_clicked()
{

    int row =ui->tableView_4->selectionModel()->currentIndex().row();
    QString cin=ui->tableView_4->model()->index(row,1).data().toString();
    QString nom=ui->tableView_4->model()->index(row,2).data().toString();

    QString prenom=ui->tableView_4->model()->index(row,3).data().toString();
    QDateTime date=ui->tableView_4->model()->index(row,4).data().toDateTime();
    QString docteur=ui->tableView_4->model()->index(row,5).data().toString();


    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                            QObject::tr("Selectionnez rendez-vous que vous voulez le modifier !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
   ui->lineEdit_33->setText(cin);
   ui->lineEdit_30->setText(nom);
   ui->lineEdit_31->setText(prenom);
    ui->dateTimeEdit_4->setDateTime(date);
   ui->lineEdit_32->setText(docteur);
     ui->stackedWidget_6->setCurrentIndex(2);





    }

}





void MainWindow::on_alpha_2_clicked()
{
    if(h==0)
    {
        ui->tableView_5->setModel( p.trieAlpha());
h=1;
    }
    else
    {
    ui->tableView_5->setModel( p.trieAlphaa());
    h=0;
    }

}

void MainWindow::on_adresse_2_clicked()
{
    if(h==0){

    ui->tableView_5->setModel( p.trieAdresse());
    h=1;
    }
    else
    {
    ui->tableView_5->setModel( p.trieAdressee());
    h=0;}

}

void MainWindow::on_cin_2_clicked()
{
    if(h==0)
    {
        ui->tableView_5->setModel( p.trieCin());
        h=1;
    }
    else{
          ui->tableView_5->setModel( p.trieCinn());
          h=0;
    }
}

void MainWindow::on_suivant_2_clicked()
{

    int row =ui->tableView_4->selectionModel()->currentIndex().row();
    QString cin=ui->tableView_4->model()->index(row,0).data().toString();
    QString nom=ui->tableView_4->model()->index(row,1).data().toString();
    QString prenom=ui->tableView_4->model()->index(row,2).data().toString();


    if(row==-1)
    { QMessageBox::critical(nullptr, QObject::tr("modifier un patient"),
                            QObject::tr("Selectionnez le patient que vous voullez le fixer un rendez-vous !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {
   ui->lineEdit_17->setText(cin);
   ui->lineEdit_21->setText(nom);
   ui->lineEdit_28->setText(prenom);
   ui->stackedWidget_7->setCurrentIndex(0);
   ui->stackedWidget_6->setCurrentIndex(1);
}

}

void MainWindow::on_ajouter_rendez_2_clicked()
{

    int cin =ui->lineEdit_17->text().toInt();
     QString nom =ui->lineEdit_21->text();
      QString prenom =ui->lineEdit_28->text();
       QString docteur =ui->lineEdit_29->text();
       QDateTime date =ui->dateTimeEdit_3->dateTime();
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
       ui->tableView_4->setModel(rdv.afficher());

       ui->stackedWidget_6->setCurrentIndex(0);

}
   else
       {

       QMessageBox::critical(nullptr, QObject::tr("rendez-vous n'est pas ajouter"),
                   QObject::tr("Le id existe deja.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
}}

void MainWindow::on_ajouterr_2_clicked()
{

    ui->lineEdit_34->clear();
    ui->lineEdit_35->clear();
   ui->lineEdit_36->clear();
  ui->lineEdit_37->clear();
    ui->dateEdit_4->clear();
            ui->lineEdit_38->clear();
            ui->lineEdit_39->clear();
a=1;
ui->stackedWidget_6->setCurrentIndex(4);



}




void MainWindow::on_modifier_rendez_2_clicked()
{

    int cin=ui->lineEdit_33->text().toInt();
           QString nom = ui->lineEdit_30->text();
           QString prenom  = ui->lineEdit_31->text();
           QDateTime date=ui->dateTimeEdit_4->dateTime();
           QString docteur=ui->lineEdit_32->text();
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
           { ui->tableView_4->setModel(rdv.afficher());
               ui->stackedWidget_6->setCurrentIndex(0);
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
                                ui->stackedWidget_6->setCurrentIndex(2);
                           }
}}

void MainWindow::on_supprimer_rdv_2_clicked()
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Pavillion/Desktop/E-HEALTH/photo/click.mp3"));
    player->setVolume(50);
    player->play();
    int row =ui->tableView_4->selectionModel()->currentIndex().row();
        QString code=ui->tableView_4->model()->index(row,0).data().toString();

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

            ui->tableView_4->setModel(rdv.afficher());

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
                ui->tableView_4->setModel(rdv.afficher());
            }
    }
}

void MainWindow::on_trie_patient_2_clicked()
{

    if(h==0)
    {
    ui->tableView_4->setModel( rdv.triePatient());
    h=1;
    }
else
     {
         ui->tableView_4->setModel( rdv.triePatientt());
         h=0;
     }

}

void MainWindow::on_date_2_clicked()
{
    if(h==0)
    {
    ui->tableView_4->setModel( rdv.trieDate());
    h=1;
}
    else
    {ui->tableView_4->setModel( rdv.trieDatee());
        h=0;
    }
}

void MainWindow::on_docteur_2_clicked()
{
    if (h==0)
    {
    ui->tableView_4->setModel( rdv.trieDocteur());
    h=1;}
    else {
        ui->tableView_4->setModel( rdv.trieDocteurr());
        h=0;

    }

}

void MainWindow::on_lineEdit_12_textChanged(const QString &arg1)
{
    QString text;
    text=ui->lineEdit_12->text();
    if(text == "")
    {
        ui->tableView_4->setModel(rdv.afficher());
    }
    else
    {
text=text.toLower();
    text[0]=text[0].toUpper();
        ui->tableView_4->setModel(rdv.recherche(text));
    }
}

void MainWindow::on_imprimer_rdv_2_clicked()
{
    QString strStream;
            QTextStream out(&strStream);
            const int rowCount = ui->tableView_4->model()->rowCount();
            const int columnCount =ui->tableView_4->model()->columnCount();

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
                    if (!ui->tableView_4->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_4->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";
                // data table
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tableView_4->isColumnHidden(column)) {
                               QString data = ui->tableView_4->model()->data(ui->tableView_4->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_tableView_5_doubleClicked(const QModelIndex &index)
{
        int row =ui->tableView_5->selectionModel()->currentIndex().row();
        QString code=ui->tableView_5->model()->index(row,0).data().toString();
        ui->stackedWidget_6->setCurrentIndex(0);
        ui->lineEdit_12->setText(code);

}








void MainWindow::on_rendez_vous_2_clicked()
{
    ui->stackedWidget_7->setCurrentIndex(0);

    ui->stackedWidget_6->setCurrentIndex(0);
    ui->rendez_vous_2->setStyleSheet("			background-image: url(C:/Users/HP/Downloads/Integration/E-HEALTH/icons/16x16/cil-clipboard.png);"
                                    "background-repeat: no-repeat;"
                                      "background-position: left center;"
                                    "border: none;"
                                    "border-left: 32px solid #25283b;"
                                    "background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79);border-right: 5px solid #3d50eb; ");

    ui->patient->setStyleSheet("QPushButton{ 	background-image: url(C:/Users/HP/Downloads/Integration/E-HEALTH/icons/16x16/cil-PEOPLE.png);"
                                   " background-position: left center;"
    "background-position: left center;"
    "background-repeat: no-repeat;"
    "border: none;"
    "border-left: 32px solid #25283b;"
    "border-right: 5px solid transparent;"
    "background-color:#25283b;"
    "text-align: left;}"
     "QPushButton:hover{ background-color: #25283b;background-color:rgb(50, 54, 79); border-left: 32px solid rgb(50, 54, 79); }");


}

void MainWindow::on_cin_patient_visite_currentIndexChanged(const QString &arg1)
{
    QString cin=arg1;
        QSqlQuery qry;
        qry.prepare("select nom,prenom,date_de_naissance from patient where cin='"+cin+"'");
    if(qry.exec())
    {while(qry.next())
        {

        ui->nom_patient_2->setText(qry.value(0).toString());
        ui->prenom_patient->setText(qry.value(1).toString());
        ui->date_naiss_patient->setDate(qry.value(2).toDate());

    }
    }
}

void MainWindow::on_exit_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void MainWindow::on_pec_commande_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->stackedWidget_gestion_commande->setCurrentIndex(1);

}


void MainWindow::on_ajoutercommande_clicked()
{
    click->play();


        int code =ui->lineEdit_code_commande->text().toInt();
        QString datecommande =ui->lineEdit_2_date_commande->text();
        QString type =ui->lineEdit_3_type_commande->text();
        int quantite =ui->lineEdit_45_quantite_commande->text().toInt();
        int  id_fournisseur=ui->liste_four_com->currentText().toInt();
        QString nom =ui->lineEdit_5_nom_commande->text();
        commande c(code,datecommande,type,quantite,nom,id_fournisseur);

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

void MainWindow::on_retour_menu_1_clicked()
{
    click->play();

        ui->stackedWidget_gestion_commande->setCurrentIndex(1);

}

void MainWindow::on_trier_commande_clicked()
{
    click->play();

        ui->tabcommande->setModel(tmpcommande.affichertri());
}

void MainWindow::on_rechercher_commande_clicked()
{click->play();


        QString text;

        text=ui->lineEdit_22_rechercher_avec_code_commande->text();

        if(text == "")

        {

            ui->tabcommande->setModel(tmpcommande.afficher());

        }

        else

        {



            ui->tabcommande->setModel(tmpcommande.recherche(text));

        }
}

void MainWindow::on_supprimer_commande_clicked()
{
    click->play();


       int   code =ui->lineEdit_6_supprimer_avec_code_commande->text().toInt();
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

void MainWindow::on_ok_modifier_commande_clicked()
{click->play();
    ui->stacked_modif_commande->setCurrentIndex(0);

}

void MainWindow::on_modifier_commande_clicked()
{
    click->play();

        int code=ui->lineEdit_12_modifier_avec_code_commande->text().toInt();
        int quantite=ui->lineEdit_16_quantite_modifie_commande->text().toInt();
           QString nom = ui->lineEdit_13_nom_modifie_commande->text();
           QString type = ui->lineEdit_15_type_modifie_commande->text();
           QString datecommande = ui->lineEdit_14_date_modifie_commande->text();
           int id_four=ui->liste_four_com_2->currentText().toInt();
           commande c(code,nom,type,quantite,datecommande,id_four);
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

void MainWindow::on_ajouter_fournisseur_clicked()
{
    click->play();

       int id =ui->lineEdit_7_id_fournisseur->text().toInt();
       QString nom =ui->lineEdit_4_nom_fournisseur->text();
       QString specialite =ui->lineEdit_8_specialite_fournisseur->text();
       int num_tel =ui->lineEdit_10_numtel_fournisseur->text().toInt();
       QString adresse =ui->lineEdit_9_adresse_fournisseur->text();
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

void MainWindow::on_retour_fournisseur_clicked()
{

    click->play();

    ui->stackedWidget_gestion_commande->setCurrentIndex(1);


}

void MainWindow::on_trier_fournisseur_clicked()
{
    click->play();

ui->tabaffich->setModel(tmpfournisseur.affichertri());
}

void MainWindow::on_pdf_fournisseur_clicked()
{
    click->play();



        QPrinter printer;
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName("C:\\Users\\Pavillion\\Desktop\\Integration\\fournisseur.pdf");//badel i chemin win t7eb t7ot il fichier ya2melek creation
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

void MainWindow::on_supprimer_fournisseur_clicked()
{
    click->play();


        int   id =ui->lineEdit_11_supprimer_avec_id_fournisseur->text().toInt();
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

void MainWindow::on_ok_fournisseur_clicked()
{
    click->play();

      ui->stacked_modif_fournisseur->setCurrentIndex(0);
}

void MainWindow::on_modifier_fournisseur_clicked()
{
    click->play();

        int id=ui->lineEdit_17_id_fournisseur_modifie->text().toInt();
        int num_tel=ui->lineEdit_19_numtel_modifie_fournisseur->text().toInt();
           QString specialite = ui->lineEdit_20_specialite_modifie_fournisseur->text();
           QString nom = ui->lineEdit_21_nom_modifie_fournisseur->text();
           QString adresse = ui->lineEdit_18_adresse_modifie_fournisseur->text();
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



void MainWindow::on_commande_2_clicked()
{
    click->play();

        QSqlQueryModel *model=new QSqlQueryModel();
        QSqlQuery qry;
        qry.prepare("select id from fournisseur ");
        qry.exec();
        model->setQuery(qry);
        ui->liste_four_com->setModel(model);
        ui->liste_four_com->setCurrentIndex(-1);
        ui->stackedWidget_gestion_commande->setCurrentIndex(0);

}

void MainWindow::on_fournisseur_clicked()
{
    click->play();

        ui->stackedWidget_gestion_commande->setCurrentIndex(0);

}








void MainWindow::on_annuler_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_connect_clicked()
{
    QString login=ui->login->text();
    QString mdp=ui->password->text();
    QSqlQuery qry;
    qry.prepare("select * from compte where login=:login and MDP=:mdp");
     qry.bindValue(":login",login);
     qry.bindValue(":mdp",mdp);
    qry.exec();
qry.next();
if(login.isEmpty()&& mdp.isEmpty())
{QMessageBox :: critical(nullptr,QObject::tr("Erreur "),
                         QObject::tr("Vérifier votre login ou mot de passe\n"
                                     "click cancel to exit "),QMessageBox ::Cancel);}
else
{
if(login==qry.value(0).toString() && mdp==qry.value(1).toString())
{
    if(qry.value(0).toString()=="admin")
    {
        ui->stackedWidget->setCurrentIndex(4);
        ui->login->clear();
        ui->password->clear();
        ui->page_visite->setEnabled(1);
        ui->page_rdv->setEnabled(1);
        ui->pec_commande->setEnabled(1);
        ui->chambre_machine->setEnabled(1);
        ui->employe_service->setEnabled(1);



    }
    else
        if(qry.value(0).toString()=="medecin")
{

        ui->stackedWidget->setCurrentIndex(4);
        ui->page_visite->setEnabled(1);
        ui->page_rdv->setEnabled(1);
        ui->pec_commande->setDisabled(1);
        ui->pec_commande->setStyleSheet("border: 1px solid white");
        ui->chambre_machine->setDisabled(1);
        ui->chambre_machine->setStyleSheet("border: 1px solid white");
        ui->employe_service->setDisabled(1);
        ui->employe_service->setStyleSheet("border: 1px solid white");

        ui->login->clear();
        ui->password->clear();
        }
    else if(qry.value(0).toString()=="secretaire")
        {   ui->stackedWidget->setCurrentIndex(4);
            ui->page_visite->setDisabled(1);
            ui->page_visite->setStyleSheet("border: 1px solid white");
            ui->page_rdv->setEnabled(1);
            ui->pec_commande->setDisabled(1);
            ui->pec_commande->setStyleSheet("border: 1px solid white");
            ui->chambre_machine->setDisabled(1);
            ui->chambre_machine->setStyleSheet("border: 1px solid white");


            ui->employe_service->setDisabled(1);
            ui->employe_service->setStyleSheet("border: 1px solid white");
            ui->login->clear();
            ui->password->clear();}
    else if(qry.value(0).toString()=="res_mach")
        {ui->stackedWidget->setCurrentIndex(4);
            ui->page_visite->setDisabled(1);
            ui->page_visite->setStyleSheet("border: 1px solid white");
            ui->page_rdv->setDisabled(1);
            ui->page_rdv->setStyleSheet("border: 1px solid white");
            ui->pec_commande->setDisabled(1);
            ui->pec_commande->setStyleSheet("border: 1px solid white");
            ui->chambre_machine->setEnabled(1);
            ui->employe_service->setDisabled(1);
            ui->employe_service->setStyleSheet("border: 1px solid white");
            ui->login->clear();
            ui->password->clear();}
else if(qry.value(0).toString()=="rh")
        {ui->stackedWidget->setCurrentIndex(4);
            ui->page_visite->setDisabled(1);
            ui->page_visite->setStyleSheet("border: 1px solid white");
            ui->page_rdv->setDisabled(1);
            ui->page_rdv->setStyleSheet("border: 1px solid white");
            ui->pec_commande->setDisabled(1);
            ui->pec_commande->setStyleSheet("border: 1px solid white");
            ui->chambre_machine->setDisabled(1);
            ui->chambre_machine->setStyleSheet("border: 1px solid white");
            ui->employe_service->setEnabled(1);
            ui->login->clear();
            ui->password->clear();}
    else if(qry.value(0).toString()=="res_commande")
        {ui->stackedWidget->setCurrentIndex(4);
            ui->page_visite->setDisabled(1);
            ui->page_visite->setStyleSheet("border: 1px solid white");
            ui->page_rdv->setDisabled(1);
            ui->page_rdv->setStyleSheet("border: 1px solid white");
            ui->pec_commande->setEnabled(1);
            ui->chambre_machine->setDisabled(1);
            ui->chambre_machine->setStyleSheet("border: 1px solid white");
            ui->employe_service->setDisabled(1);
            ui->employe_service->setStyleSheet("border: 1px solid white");
            ui->login->clear();
            ui->password->clear();}


}

    else
    { QMessageBox :: critical(nullptr,QObject::tr("Erreur "),
                              QObject::tr("Vérifier votre login ou mot de passe\n"
                                          "click cancel to exit "),QMessageBox ::Cancel);}



}
}



void MainWindow::on_affiche_mdp_clicked(bool checked)
{
    if(checked)
    {        ui->password->setEchoMode(QLineEdit::EchoMode(0));
}
    else
    {       ui->password->setEchoMode(QLineEdit::EchoMode(2));
}
}
void MainWindow::on_hadilajouter1_clicked()
{
    int code = ui->hadil_code->text().toInt();
    int etage =ui->hadil_etage->text().toInt();
     int numero =ui->hadil_numero->text().toInt();
     chambre c(code,etage,numero);
   bool test=c.ajouter();
     if(test)
     {
         ui->hadiltab1->setModel(tmp.afficher());

                 QMessageBox::information(nullptr, QObject::tr("ajout èffectué"),
                             QObject::tr("ajout èffectuè.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
         }
             else
                 QMessageBox::critical(nullptr, QObject::tr("ajout non èffectuè"),
                             QObject::tr("ajout non èffectuè.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_hadilsupprimer1_clicked()
{
    int code=ui->hadil_code->text().toInt();
    bool test=tmp.supprimer(code);
    if(test)
    {
     ui->hadiltab1->setModel(tmp.afficher());
                QMessageBox::information(nullptr, QObject::tr("supression èffectué"),
                            QObject::tr("supression èffectuè.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr, QObject::tr("suprssion non èffectuè"),
                            QObject::tr("supression non èffectuè.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}



























void MainWindow::on_comboBox_currentIndexChanged(int )
{

    QString code=ui->comboBox->currentText();
  QSqlQuery query;
  query.prepare("select * from machine where code='"+code+"'");
  if(query.exec())
  {

      while(query.next()){
          ui->hadilcode1_2->setText(query.value(0).toString());
            ui->hadilnom->setText(query.value(1).toString());
            ui->hadilreference->setText(query.value(2).toString());
             ui->hadilmode->setText(query.value(3).toString());


  }
  }
}

















void MainWindow::print(QPrinter *printer)
{
    QPainter painter;
        if(!painter.begin(printer)) {
            qWarning() << "can't start printer";
            return;
        }
        // print table
        TablePrinter tablePrinter(&painter, printer);
        QVector<int> columnStretch = QVector<int>() << 10 << 15 << 20  <<25;
        if(!tablePrinter.printTable(ui->hadiltab1->model(), columnStretch)) {
            qDebug() << tablePrinter.lastError();
        }
        // print second table
        painter.translate(0, 100);
        if(!tablePrinter.printTable(ui->hadiltab1->model(), columnStretch)) {
            qDebug() << tablePrinter.lastError();
        }
        painter.end();
}
















void MainWindow::on_radioButton_hadil_clicked()
{
    ui->hadiltab1->setModel(tmp.afficher_tri_code());
}


void MainWindow::on_radioButton_2_hadil_clicked()
{
    ui->hadiltab1->setModel(tmp.afficher_tri_etage());
}

void MainWindow::on_radioButton_3_hadil_clicked()
{


        ui->hadiltab1->setModel(tmp.afficher_tri_numero());

}

void MainWindow::on_hadildata1_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
  query->prepare("select code from chambre");
  query->exec();


  modal->setQuery(*query);

ui->hadilbox1->setModel(modal);

}


void MainWindow::on_hadilafficher1_clicked()
{
     ui->hadiltab1->setModel(tmp.afficher());
}

void MainWindow::on_hadilbox1_currentIndexChanged(int )
{

    QString code=ui->hadilbox1->currentText();
  QSqlQuery query;
  query.prepare("select* from chambre where code='"+code+"'");
  if(query.exec())
  {

      while(query.next()){
          ui->hadil_code->setText(query.value(0).toString());
            ui->hadil_etage->setText(query.value(1).toString());
            ui->hadil_numero->setText(query.value(2).toString());




  }
  }
}

void MainWindow::on_hadilrechercher1_clicked()
{
    QString code= ui->hadil_5->text();
   ui->hadiltab1->setModel(tmp.chercher(code));
}

void MainWindow::on_hadilajouter_clicked()
{
    {
       int code = ui->hadilcode1_2->text().toInt();
       QString nom=ui->hadilnom->text();
        int reference=ui->hadilreference->text().toInt();

       QString mode_aquisation=ui->hadilmode->text();

         machine m(code,nom,reference,mode_aquisation);
       bool test=m.ajouter();
         if(test)
         {
             ui->hadiltab1->setModel(tm.afficher1());

                     QMessageBox::information(nullptr, QObject::tr("ajout èffectué"),
                                 QObject::tr("ajout èffectuè.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("ajout non èffectuè"),
                                 QObject::tr("ajout non èffectuè.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


    }
}

void MainWindow::on_hadilmodifier_clicked()
{
    QString code,nom,reference,mode_aquisation;
    code=ui->hadilcode1_2->text().toInt();;
     nom=ui->hadilnom->text();
      reference=ui->hadilreference->text().toInt();;
       mode_aquisation=ui->hadilmode->text();
      QSqlQuery query;
      query.prepare("update machine set code='"+code+"',nom='"+nom+"',reference='"+reference+"',mode_aquisation='"+mode_aquisation+"'where code='"+code+"'");
      if(query.exec()){
               ui->hadiltab->setModel(tm.afficher1());
          QMessageBox::information(nullptr, QObject::tr("supression èffectué"),
                      QObject::tr("modification èffectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
  }
      else
          QMessageBox::critical(nullptr, QObject::tr("supression non èffectuè"),
                      QObject::tr("modification non èffectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_hadilmodifier1_clicked()
{
    QString code,etage,numero;
    code=ui->hadil_code->text().toInt();
     etage=ui->hadil_etage->text().toInt();
      numero=ui->hadil_numero->text().toInt();;

      QSqlQuery query;
      query.prepare("update chambre set code='"+code+"',etage='"+etage+"',numero='"+numero+"'where code='"+code+"'");
      if(query.exec()){
               ui->hadiltab1->setModel(tmp.afficher());
          QMessageBox::information(nullptr, QObject::tr("supression èffectué"),
                      QObject::tr("modification èffectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
  }
      else
          QMessageBox::critical(nullptr, QObject::tr("supression non èffectuè"),
                      QObject::tr("modification non èffectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_hadilafficher_clicked()
{
    ui->hadiltab->setModel(tm.afficher1());
}



void MainWindow::on_hadilsupprimer_clicked()
{
    int code=ui->hadilcode1_2->text().toInt();
    bool test=tm.supprimer1(code);
    if(test)
    {
     ui->hadiltab->setModel(tm.afficher1());
                QMessageBox::information(nullptr, QObject::tr("supression èffectué"),
                            QObject::tr("supression èffectuè.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr, QObject::tr("suprssion non èffectuè"),
                            QObject::tr("supression non èffectuè.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_hadil_12_clicked()
{

    QPrintPreviewDialog dialog;
          connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));
          dialog.exec();
}

void MainWindow::on_hadil_14_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
  query->prepare("select code from machine");
  query->exec();
  modal->setQuery(*query);

ui->comboBox->setModel(modal);
}


void MainWindow::on_chambre_machine_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void MainWindow::on_retour_menu_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}
void MainWindow::on_pushButton_supprimer_emp_clicked()
{
    employee Etmp;
    Etmp.setId(ui->supprimer_id_emp->text().toInt());
    QMessageBox msgbox;
        msgbox.setWindowTitle("supprimer");
        msgbox.setText("voulez_vous supprimer cette réclamation?");
        msgbox.setStandardButtons(QMessageBox ::Yes);
        msgbox.addButton(QMessageBox::No);
        if(msgbox.exec()==QMessageBox::Yes)
        {
  bool test=Etmp.supprimer(Etmp.getID());
  QMessageBox msgBox;

  if(test)
  {
      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
      {ui->tableView_afficher_emp->setModel(Etmp.afficher());}

  }
  else
      QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
  msgBox.exec();

}
}




void MainWindow::on_pushButton_modifier_emp_clicked() /*boutton moddifier*/
{
    employee p;
        int id = ui->modifier_id_emp->text().toInt();
        int salaire= ui->modifier_salaire_emp->text().toInt();
        QString nom = ui->modifier_nom_emp->text();
        QString prenom = ui->modifier_prenom_emp->text();
        QString adresse= ui->modifier_adresse_emp->text();


        employee  (nom,prenom,adresse,id,salaire) ;
        bool test =p.modifier(id,salaire,nom,prenom,adresse);
        if(test)
        {ui->tableView_afficher_emp->setModel(p.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                     QObject::tr("employe  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_modiffier_clicked()
{
    services m;


    int id = ui->lineEdit_prix_2->text().toInt();

    QString type = ui->lineEdit_type_2->text();






        /*services (id,type) ;*/
        bool test =m.modifier(type,id);
        if(test)
        {ui->table_affich_service->setModel(m.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                     QObject::tr("employe  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}






void MainWindow::on_pushButton_trier_clicked()
{
    employee e;
    /*QString critere=ui->cb_historique->currentText();*/
        QString mode;
         if (ui->rb_asc_historique->isChecked()==true)
    {
             ui->tableView_afficher_emp->setModel(e.trie());


    }
         else if(ui->rb_desc_historique->isChecked()==true)

             ui->tableView_afficher_emp->setModel(e.trie2());






}

void MainWindow::on_L_search_clicked()
{
    employee e;
    QString text;
    if (ui->radioButton_ID->isChecked()==true)
{
text=ui->recherche_critere->text();
     if(text == "")

     {

         ui->tableView_afficher_emp->setModel(e.afficher());

     }

     else

     {



         ui->tableView_afficher_emp->setModel(e.chercher_emp(text));

     }
    }
     if(ui->radioButton_salaire->isChecked()==true)
    {
        text=ui->recherche_critere->text();
             if(text == "")

             {

                 ui->tableView_afficher_emp->setModel(e.afficher());

             }

             else

             {



                 ui->tableView_afficher_emp->setModel(e.chercher_emp1(text));

             }

    }
     else if     (ui->radioButton_nom->isChecked()==true)
     {

         text=ui->recherche_critere->text();
              if(text == "")

              {

                  ui->tableView_afficher_emp->setModel(e.afficher());

              }

              else

              {



                  ui->tableView_afficher_emp->setModel(e.chercher_emp2(text));

              }
     }
     }



void MainWindow::on_pushButton_pdf_clicked()
{
    QPrinter printer;
    printer.setPrinterName ("le nom de l'imprimante");
    QPrintDialog dialog(&printer,this);
    if (dialog.exec()== QDialog::Rejected)
        return;
    ui->table_affich_service->render(&printer);
}

void MainWindow::on_pushButton_ajouter_emp_clicked()
{
    {
        employee h;
        int id=ui->ajouter_id_emp->text().toInt();
        int salaire=ui->ajouter_sal_emp->text().toInt();
        QString nom=ui->ajouter_nom_emp->text();
        QString prenom=ui->ajouter_prenom_emp->text();
        QString adresse=ui->ajouter_adresse_emp->text();

    employee E(nom,prenom,adresse,id,salaire);
    bool test=E.ajouter();
    if(test)
    {
        ui->tableView_afficher_emp->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
    }

    }
}








void MainWindow::on_bouton_afficher_emp_clicked()
{
    employee Etmp;

    {ui->tableView_afficher_emp->setModel(Etmp.afficher());}
}








void MainWindow::on_ajouter_service_clicked()
{
    int id=ui->id_service->text().toInt();

    QString type=ui->type_service->text();




services E(id,type);
bool test=E.ajouter();

if(test)
{
    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::information(nullptr,QObject::tr("noot"),QObject::tr("ajout  \n click cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_modiffier_service_clicked()
{
    services m;


    int id = ui->lineEdit_prix_2->text().toInt();

    QString type = ui->lineEdit_type_2->text();






        /*services (id,type) ;*/
        bool test =m.modifier(type,id);
        if(test)
        {ui->table_affich_service->setModel(m.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                     QObject::tr("employe  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_service_clicked()
{
    {

        services m;
        m.setType(ui->supprimer_id->text());
      bool test=m.supprimer(m.getTYPE());
      QMessageBox msgBox;

      if(test)
      {
          QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
          {ui->tableView_afficher_emp->setModel(Etmp.afficher());}

      }
      else
          QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
      msgBox.exec();

    }
}

void MainWindow::on_pushButton_afficher_service_clicked()
{
    services m;

    {ui->table_affich_service->setModel(m.afficher());}
}


void MainWindow::on_retour_menu_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_employe_service_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);



}


void MainWindow::on_deconnecter_clicked()
{
      ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_exit_3_clicked()
{
 ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_exit_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}
