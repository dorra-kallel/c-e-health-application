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
#include"modifier_visite.h"
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include "acte.h"
#include <QMediaPlayer>
#include "patient.h"
#include"rendez_vous.h"
#include"fournisseur.h"
#include"commande.h"
#include"chambre.h"
#include"machine.h"
#include "employee.h"
#include<arduino.h>


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


    void on_comboBox_currentIndexChanged(int );


    void print(QPrinter *printer);


    void on_hadilajouter1_clicked();

    void on_hadilsupprimer1_clicked();

    void on_hadilrechercher1_clicked();


    void on_radioButton_hadil_clicked();

    void on_radioButton_2_hadil_clicked();

    void on_radioButton_3_hadil_clicked();


    void on_hadilbox1_currentIndexChanged(int index);

    void on_hadildata1_clicked();

    void on_hadilafficher1_clicked();

    void on_hadilmodifier1_clicked();

    void on_hadilajouter_clicked();

    void on_hadilafficher_clicked();

    void on_hadilsupprimer_clicked();

    void on_hadilmodifier_clicked();

    void on_hadil_12_clicked();

    void on_hadil_14_clicked();


    void on_nouvelle_visite_clicked();

    void on_exit_clicked();

    void on_retour_clicked();

    void on_ordenance_clicked();

    void on_retour_ord_clicked();


    void on_ajouter_ord_clicked();


    void on_valider_clicked();

    void on_afficher_visite_clicked();



    void on_supprimer_ord_clicked();

    void on_retour_aff_clicked();

    void on_modifier_ord_clicked();

    void on_pdf_clicked();

    void on_supprimer_visite_clicked();


    void clear_ordonnace();
    void clear_visite();
    void ajouter_visite();


    void on_nom_chercher_textChanged(const QString &arg1);

    void on_tab_medicament_doubleClicked(const QModelIndex &index);

    void on_tab_visite_doubleClicked(const QModelIndex &index);




    void on_tab_ord_doubleClicked(const QModelIndex &index);

    void on_conf_modif_ord_clicked();

    void on_supp_ord_clicked();



    void on_radioButton_clicked();


    void on_radioButton_6_clicked();



    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_4_clicked();

    void on_excel_clicked();

    void on_modif_visite_clicked();

    void on_pushButton_8_clicked();

    void on_libelle_med_currentIndexChanged(const QString &arg1);

    void on_demande_acte_clicked();

    void on_acte_currentIndexChanged(const QString &arg1);

    void on_valider_acte_clicked();

    void on_supprimer_acte_clicked();

    void on_retour_3_clicked();

    void on_act_ord_clicked();

    void on_ord_acte_clicked();

    void on_supp_acte_clicked();

    void on_anglais_clicked();

    void on_francais_clicked();


    void on_retour_2_clicked();

    void on_page_visite_clicked();

    void on_page_rdv_clicked();

    void on_retour_menu_clicked();

    void on_retour_menu_2_clicked();


    void on_patient_2_clicked();
      void on_rendez_vous_clicked();
    void on_ajouter_patient_2_clicked();
        void on_ajouter_pat_2_clicked();

       void on_lineEdit_7_textChanged(const QString &arg1);

   void on_supprimer_patient_2_clicked();
   void on_modifier_patient_2_clicked();

       void on_modifier_pat_2_clicked();


   void on_ajouter_rdv_2_clicked();
   void on_imprimer_patient_2_clicked();

        void on_modifier_rdv_2_clicked();



       void on_alpha_2_clicked();

       void on_adresse_2_clicked();


         void on_cin_2_clicked();

   void on_suivant_2_clicked();

      void on_ajouter_rendez_2_clicked();

       void on_ajouterr_2_clicked();

   void on_modifier_rendez_2_clicked();
      void on_supprimer_rdv_2_clicked();

   void on_trie_patient_2_clicked();

   void on_date_2_clicked();
      void on_docteur_2_clicked();


       void on_lineEdit_12_textChanged(const QString &arg1);

      void on_imprimer_rdv_2_clicked();

       void on_tableView_5_doubleClicked(const QModelIndex &index);


       void on_ajoutercommande_clicked();

       void on_retour_menu_1_clicked();

       void on_trier_commande_clicked();

       void on_rechercher_commande_clicked();

       void on_supprimer_commande_clicked();

       void on_ok_modifier_commande_clicked();

       void on_modifier_commande_clicked();

       void on_ajouter_fournisseur_clicked();

       void on_retour_fournisseur_clicked();

       void on_trier_fournisseur_clicked();

       void on_pdf_fournisseur_clicked();

       void on_supprimer_fournisseur_clicked();

       void on_ok_fournisseur_clicked();

       void on_modifier_fournisseur_clicked();


       void on_fournisseur_clicked();



       void on_rendez_vous_3_clicked();

       void on_cin_patient_visite_currentIndexChanged(const QString &arg1);

       void on_exit_2_clicked();

       void on_pec_commande_clicked();


       void on_commande_2_clicked();

       void on_annuler_clicked();

       void on_connect_clicked();


       void on_affiche_mdp_clicked(bool checked);

       void on_chambre_machine_clicked();

       void on_retour_menu_3_clicked();
       void on_pushButton_modiffier_clicked();



       void on_pushButton_trier_clicked();

       void on_L_search_clicked();

       void on_pushButton_pdf_clicked();

       void on_bouton_afficher_emp_clicked();

       void on_pushButton_ajouter_emp_clicked();

       void on_pushButton_modifier_emp_clicked();

       void on_pushButton_supprimer_emp_clicked();

       void on_ajouter_service_clicked();

       void on_pushButton_modiffier_service_clicked();

       void on_pushButton_supprimer_service_clicked();

       void on_pushButton_afficher_service_clicked();

       void on_retour_menu_4_clicked();

       void on_employe_service_clicked();

       void on_deconnecter_clicked();


       void on_exit_3_clicked();

       void on_exit_4_clicked();

       void on_ajouter_compte_clicked();


       void on_retour_menu_5_clicked();

       void on_new_account_clicked();


       void update_label();



       void on_show_mdp_clicked(bool checked);

       void on_temp_clicked();

       void on_retour_ord_2_clicked();

private:
    Ui::MainWindow *ui;
    visite tmpvisite;
    medicament tmpmedicament;
    acte tmpacte;
    modifier_visite *modif;
  QPropertyAnimation *animation1;
  QMediaPlayer *click;
  QString lng="fr";
  QParallelAnimationGroup *animationGroup;
  int a=0;
  int h=0;
  patient p;
  rendez_vous rdv;
  commande tmpcommande;
     fournisseur tmpfournisseur;
     chambre tmp;
     machine tm;
      employee Etmp;
      arduino A;
      QByteArray data;
      QString temp="";

};
#endif // MAINWINDOW_H
