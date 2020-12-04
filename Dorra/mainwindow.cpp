#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include"services.h"
#include "employee.h"
#include"QMessageBox"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    employee Etmp;
    services m;

    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());

        ui->tableView->setModel(m.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_supprimer_clicked()
{
    employee Etmp;
    Etmp.setId(ui->lineEdit_12->text().toInt());
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
      {ui->tableView->setModel(Etmp.afficher());}

  }
  else
      QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
  msgBox.exec();

}
}


void MainWindow::on_pushButton_2_clicked() /*boutton afficher*/
{
    employee Etmp;

    {ui->tableView->setModel(Etmp.afficher());}

}

void MainWindow::on_pushButton_3_clicked() /*boutton moddifier*/
{
    employee p;
        int id = ui->lineEdit_ID_2->text().toInt();
        int salaire= ui->lineEdit_SAL_2->text().toInt();
        QString nom = ui->lineEdit_NOM_2->text();
        QString prenom = ui->lineEdit_PRENOM_2->text();
        QString adresse= ui->lineEdit_DEP_2->text();


        employee  (nom,prenom,adresse,id,salaire) ;
        bool test =p.modifier(id,salaire,nom,prenom,adresse);
        if(test)
        {ui->tableView->setModel(p.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                     QObject::tr("employe  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

/*void MainWindow::on_pushButton_aj_clicked()
{
    int id=ui->lineEdit_prix->text().toInt();

    QString type=ui->lineEdit_type->text();




services E(id,type);
bool test=E.ajouter();
if(test)
{
    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
}



}*/

void MainWindow::on_pushButton_modiffier_clicked()
{
    services m;


    int id = ui->lineEdit_prix_2->text().toInt();

    QString type = ui->lineEdit_type_2->text();






        /*services (id,type) ;*/
        bool test =m.modifier(type,id);
        if(test)
        {ui->tableView_2->setModel(m.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                     QObject::tr("employe  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_2_clicked()
{

    services m;
    m.setType(ui->lineEdit_mt->text());
  bool test=m.supprimer(m.getTYPE());
  QMessageBox msgBox;

  if(test)
  {
      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
      {ui->tableView->setModel(Etmp.afficher());}

  }
  else
      QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
  msgBox.exec();

}

void MainWindow::on_pushButton_afficher_clicked()
{
    services m;

    {ui->tableView_2->setModel(m.afficher());}
}



void MainWindow::on_pushButton_trier_clicked()
{
    employee e;
    /*QString critere=ui->cb_historique->currentText();*/
        QString mode;
         if (ui->rb_asc_historique->isChecked()==true)
    {
             ui->tableView->setModel(e.trie());


    }
         else if(ui->rb_desc_historique->isChecked()==true)

             ui->tableView->setModel(e.trie2());






}

void MainWindow::on_L_search_clicked()
{
    employee e;
    QString text;
    if (ui->radioButton_ID->isChecked()==true)
{
text=ui->lineEdit_idstock->text();
     if(text == "")

     {

         ui->tableView->setModel(e.afficher());

     }

     else

     {



         ui->tableView->setModel(e.chercher_emp(text));

     }
    }
     if(ui->radioButton_salaire->isChecked()==true)
    {
        text=ui->lineEdit_idstock->text();
             if(text == "")

             {

                 ui->tableView->setModel(e.afficher());

             }

             else

             {



                 ui->tableView->setModel(e.chercher_emp1(text));

             }

    }
     else if     (ui->radioButton_nom->isChecked()==true)
     {

         text=ui->lineEdit_idstock->text();
              if(text == "")

              {

                  ui->tableView->setModel(e.afficher());

              }

              else

              {



                  ui->tableView->setModel(e.chercher_emp2(text));

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
    ui->tableView_2->render(&printer);
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    {
        employee h;
        int id=ui->lineEdit_ID->text().toInt();
        int salaire=ui->lineEdit_SAL->text().toInt();
        QString nom=ui->lineEdit_NOM->text();
        QString prenom=ui->lineEdit_PRENOM->text();
        QString adresse=ui->lineEdit_DEP->text();

    employee E(nom,prenom,adresse,id,salaire);
    bool test=E.ajouter();
    if(test)
    {
        ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
    }

    }
}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->lineEdit_prix->text().toInt();

    QString type=ui->lineEdit_type->text();




services E(id,type);
bool test=E.ajouter();

if(test)
{
    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::information(nullptr,QObject::tr("noot"),QObject::tr("ajout  \n click cancel to exit."), QMessageBox::Cancel);






}





