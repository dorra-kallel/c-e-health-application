#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include "C:/Users/hadil/Desktop/Qt-Table-Printer-master/Qt-Table-Printer-master/tableprinter.h"
#include <QPrinter>
#include <QPrintPreviewDialog>
#include <QPainter>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
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

ui->comboBox->setModel(modal);
}




void MainWindow::on_comboBox_currentIndexChanged(int )
{

    QString code=ui->comboBox->currentText();
  QSqlQuery query;
  query.prepare("select* from table2 where code='"+code+"'");
  if(query.exec())
  {

      while(query.next()){
          ui->lineEdit->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_4->setText(query.value(2).toString());
             ui->lineEdit_3->setText(query.value(2).toString());


  }
  }
}




void MainWindow::on_pushButton_3_clicked()
{
    QString nom,mode_aquisation,code,reference;
    code=ui->lineEdit->text();
     nom=ui->lineEdit_2->text();
      reference=ui->lineEdit_4->text();
       mode_aquisation=ui->lineEdit_3->text();
      QSqlQuery query;
      query.prepare("update table2 set code='"+code+"',nom='"+nom+"',reference='"+reference+"',mode_aquisation='"+mode_aquisation+"'where code='"+code+"'");
      if(query.exec()){
               ui->tableView->setModel(tm.afficher());
          QMessageBox::information(nullptr, QObject::tr("supression èffectué"),
                      QObject::tr("modification èffectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
  }
      else
          QMessageBox::critical(nullptr, QObject::tr("supression non èffectuè"),
                      QObject::tr("modification non èffectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


      }



void MainWindow::on_pushButton_5_clicked()
{
    QString etage,numero,code;
    code=ui->lineEdit_6->text();
     etage=ui->lineEdit_7->text();
      numero=ui->lineEdit_8->text();

      QSqlQuery query;
      query.prepare("update table1 set code='"+code+"',etage='"+etage+"',numero='"+numero+"'where code='"+code+"'");
      if(query.exec()){
          ui->tabchambre->setModel(tmp.afficher());

          QMessageBox::information(nullptr, QObject::tr("supression èffectué"),
                      QObject::tr("modification èffectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
  }
      else
          QMessageBox::critical(nullptr, QObject::tr("supression non èffectuè"),
                      QObject::tr("modification non èffectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_11_clicked()
{
    QString code= ui->lineEdit_5->text();
   ui->tabchambre->setModel(tmp.chercher(code));



}





void MainWindow::on_pushButton_7_clicked()
{
    ui->tabchambre->setModel(tmp.trier());

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
        if(!tablePrinter.printTable(ui->tableView->model(), columnStretch)) {
            qDebug() << tablePrinter.lastError();
        }
        // print second table
        painter.translate(0, 100);
        if(!tablePrinter.printTable(ui->tableView->model(), columnStretch)) {
            qDebug() << tablePrinter.lastError();
        }
        painter.end();
}






void MainWindow::on_pushButton_12_clicked()
{


    QPrintPreviewDialog dialog;
          connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));
          dialog.exec();
}

void MainWindow::on_pushButton_8_clicked()
{  ui->tableView->setModel(tm.afficher());

}
