#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"chambre.h"
#include"machine.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
       ui(new Ui::MainWindow)


{
    ui->setupUi(this);
    ui->tabchambre->setModel(tmp.afficher());
     ui->tableView->setModel(tm.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_4_clicked()
{
    int code = ui->lineEdit_6->text().toInt();
    int etage =ui->lineEdit_7->text().toInt();
     int numero =ui->lineEdit_8->text().toInt();
     chambre c(code,etage,numero);
   bool test=c.ajouter();
     if(test)
     {
         ui->tabchambre->setModel(tmp.afficher());

                 QMessageBox::information(nullptr, QObject::tr("ajout èffectué"),
                             QObject::tr("ajout èffectuè.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
         }
             else
                 QMessageBox::critical(nullptr, QObject::tr("ajout non èffectuè"),
                             QObject::tr("ajout non èffectuè.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_6_clicked()
{
    int code=ui->lineEdit_6->text().toInt();
    bool test=tmp.supprimer(code);
    if(test)
    {
     ui->tabchambre->setModel(tmp.afficher());
                QMessageBox::information(nullptr, QObject::tr("supression èffectué"),
                            QObject::tr("supression èffectuè.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr, QObject::tr("suprssion non èffectuè"),
                            QObject::tr("supression non èffectuè.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}















void MainWindow::on_pushButton_clicked()
{
    {
       int code = ui->lineEdit->text().toInt();
       QString nom=ui->lineEdit_2->text();
        int reference=ui->lineEdit_4->text().toInt();

       QString mode_aquisation=ui->lineEdit_3->text();

         machine m(code,nom,reference,mode_aquisation);
       bool test=m.ajouter();
         if(test)
         {
             ui->tableView->setModel(tm.afficher());

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



void MainWindow::on_pushButton_2_clicked()
{
    int code=ui->lineEdit->text().toInt();
    bool test=tm.supprimer(code);
    if(test)
    {
     ui->tableView->setModel(tm.afficher());
                QMessageBox::information(nullptr, QObject::tr("supression èffectué"),
                            QObject::tr("supression èffectuè.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }
            else
                QMessageBox::critical(nullptr, QObject::tr("supression non èffectuè"),
                            QObject::tr("supression non èffectuè.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_pushButton_13_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
  query->prepare("select code from table1");
  query->exec();
  modal->setQuery(*query);
 ui->listView->setModel(modal);
ui->comboBox_2->setModel(modal);



}


void MainWindow::on_comboBox_2_currentIndexChanged()

{
  QString code=ui->comboBox_2->currentText();
QSqlQuery query;
query.prepare("select* from table1 where code='"+code+"'");
if(query.exec())
{

    while(query.next()){
        ui->lineEdit_6->setText(query.value(0).toString());
          ui->lineEdit_7->setText(query.value(1).toString());
          ui->lineEdit_8->setText(query.value(2).toString());


}
}
}



void MainWindow::on_pushButton_14_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery* query=new QSqlQuery();
  query->prepare("select code from table2");
  query->exec();
  modal->setQuery(*query);
 ui->listView_2->setModel(modal);
ui->comboBox->setModel(modal);
}



