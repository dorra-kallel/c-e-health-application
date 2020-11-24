#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connection.h"
#include "medicament.h"
#include"visite.h"
#include <windows.h>
#include <QFile>
#include <QPrinter>
#include <QPrintDialog>
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
    void on_nouvelle_visite_clicked();

    void on_exit_clicked();

    void on_retour_clicked();

    void on_ordenance_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_clicked();


    void on_valider_clicked();

    void on_afficher_visite_clicked();

    void on_retour_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pdf_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();
    void clear_ordonnace();
    void clear_visite();

    void on_resh_visite_clicked();

    void on_nom_chercher_textChanged(const QString &arg1);

    void on_tab_medicament_doubleClicked(const QModelIndex &index);

    void on_tab_visite_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    visite tmpvisite;
    medicament tmpmedicament;
    int id_visite_o;

    enum colonnes
        {
            CODE_MED , LIBELLE  , QTE , FREQUENCE ,  MODE


        };

};
#endif // MAINWINDOW_H
