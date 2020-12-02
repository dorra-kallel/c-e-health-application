#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"chambre.h"
#include"machine.h"
#include <QMainWindow>
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
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_13_clicked();









    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged( );


    void on_pushButton_14_clicked();


 void on_comboBox_currentIndexChanged(int );

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_7_clicked();
    void print(QPrinter *printer);

    void on_pushButton_8_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    chambre tmp;
    machine tm;
};
#endif // MAINWINDOW_H
