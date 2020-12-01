#include "dialog.h"
#include "ui_dialog.h"
#include "dialog.h"
#include"string"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{

    QString code= ui->lineEdit_12->text();
   ui->tabrechercher->setModel(tmp.chercher(code));
}
