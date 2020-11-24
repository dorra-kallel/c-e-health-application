/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *exit;
    QPushButton *afficher_visite;
    QPushButton *nouvelle_visite;
    QLabel *label;
    QWidget *page_3;
    QLineEdit *id_visite;
    QDateEdit *date_naiss_patient;
    QComboBox *actes_medicaux;
    QLineEdit *nom_patient_2;
    QLineEdit *prenom_patient;
    QTextEdit *observation;
    QTextEdit *diagnostic;
    QPushButton *valider;
    QPushButton *ordenance;
    QPushButton *retour;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *page_4;
    QLabel *label_2;
    QLineEdit *code_med;
    QLineEdit *libelle;
    QLineEdit *mode;
    QLineEdit *frequence;
    QSpinBox *quantite;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tab_medicament;
    QWidget *page_2;
    QWidget *page_5;
    QTableView *tab_visite;
    QPushButton *retour_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1147, 982);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 20, 1141, 1111));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 90, 371, 411));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        exit = new QPushButton(layoutWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setStyleSheet(QLatin1String(" QPushButton{\n"
"    font: 20pt \"MS Shell Dlg 2\";\n"
" }\n"
"QPushButton:hover:!pressed\n"
"{\n"
"	 border: 1px solid yellow;\n"
"color:  rgb(0, 255,0);\n"
"background-color: rgb(255, 255, 127);\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover::pressed\n"
"{\n"
"	 border: 1px solid green;\n"
"color:rgb(255,255,127);\n"
"background-color: rgb(0, 255,0);\n"
"}\n"
""));

        gridLayout->addWidget(exit, 2, 0, 1, 1);

        afficher_visite = new QPushButton(layoutWidget);
        afficher_visite->setObjectName(QStringLiteral("afficher_visite"));
        afficher_visite->setStyleSheet(QLatin1String(" QPushButton{\n"
"    font: 20pt \"MS Shell Dlg 2\";\n"
" }\n"
"QPushButton:hover:!pressed\n"
"{\n"
"	 border: 1px solid yellow;\n"
"color:  rgb(0, 255,0);\n"
"background-color: rgb(255, 255, 127);\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover::pressed\n"
"{\n"
"	 border: 1px solid green;\n"
"color:rgb(255,255,127);\n"
"background-color: rgb(0, 255,0);\n"
"}\n"
""));

        gridLayout->addWidget(afficher_visite, 1, 0, 1, 1);

        nouvelle_visite = new QPushButton(layoutWidget);
        nouvelle_visite->setObjectName(QStringLiteral("nouvelle_visite"));
        nouvelle_visite->setStyleSheet(QLatin1String("\n"
" \n"
"QPushButton{\n"
"\n"
"   font: 20pt \"MS Shell Dlg 2\";\n"
"\n"
"\n"
" }\n"
"\n"
"\n"
"QPushButton:hover:!pressed\n"
"{\n"
"\n"
"	 border: 1px solid yellow;\n"
"	color: rgb(0, 255, 0);\n"
"	\n"
"background-color: rgb(255, 255, 127);\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover::pressed\n"
"{\n"
"\n"
"	 border: 1px solid green;\n"
"	color:rgb(255,255,127);\n"
"background-color: rgb(0, 255,0);\n"
"}\n"
"\n"
"\n"
"\n"
""));

        gridLayout->addWidget(nouvelle_visite, 0, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(420, 30, 261, 31));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        id_visite = new QLineEdit(page_3);
        id_visite->setObjectName(QStringLiteral("id_visite"));
        id_visite->setGeometry(QRect(390, 140, 221, 41));
        date_naiss_patient = new QDateEdit(page_3);
        date_naiss_patient->setObjectName(QStringLiteral("date_naiss_patient"));
        date_naiss_patient->setGeometry(QRect(390, 320, 221, 41));
        actes_medicaux = new QComboBox(page_3);
        actes_medicaux->setObjectName(QStringLiteral("actes_medicaux"));
        actes_medicaux->setGeometry(QRect(390, 380, 221, 41));
        nom_patient_2 = new QLineEdit(page_3);
        nom_patient_2->setObjectName(QStringLiteral("nom_patient_2"));
        nom_patient_2->setGeometry(QRect(390, 200, 221, 41));
        prenom_patient = new QLineEdit(page_3);
        prenom_patient->setObjectName(QStringLiteral("prenom_patient"));
        prenom_patient->setGeometry(QRect(390, 260, 221, 41));
        observation = new QTextEdit(page_3);
        observation->setObjectName(QStringLiteral("observation"));
        observation->setGeometry(QRect(390, 440, 391, 161));
        diagnostic = new QTextEdit(page_3);
        diagnostic->setObjectName(QStringLiteral("diagnostic"));
        diagnostic->setGeometry(QRect(390, 640, 391, 161));
        valider = new QPushButton(page_3);
        valider->setObjectName(QStringLiteral("valider"));
        valider->setGeometry(QRect(390, 830, 161, 71));
        valider->setStyleSheet(QLatin1String(" QPushButton{\n"
"    font: 20pt \"MS Shell Dlg 2\";\n"
" }\n"
"QPushButton:hover:!pressed\n"
"{\n"
"\n"
"	 border: 1px solid yellow;\n"
"background-color: rgb(255, 255, 127);\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover::pressed\n"
"{\n"
"\n"
"	 border: 1px solid green;\n"
"background-color: rgb(0, 255,0);\n"
"}\n"
""));
        ordenance = new QPushButton(page_3);
        ordenance->setObjectName(QStringLiteral("ordenance"));
        ordenance->setGeometry(QRect(580, 830, 201, 71));
        ordenance->setStyleSheet(QLatin1String(" QPushButton{\n"
"    font: 20pt \"MS Shell Dlg 2\";\n"
" }\n"
"QPushButton:hover:!pressed\n"
"{\n"
"\n"
"	 border: 1px solid yellow;\n"
"background-color: rgb(255, 255, 127);\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover::pressed\n"
"{\n"
"\n"
"	 border: 1px solid green;\n"
"background-color: rgb(0, 255,0);\n"
"}\n"
""));
        retour = new QPushButton(page_3);
        retour->setObjectName(QStringLiteral("retour"));
        retour->setGeometry(QRect(10, 10, 101, 41));
        retour->setStyleSheet(QStringLiteral(""));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 150, 131, 20));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 210, 131, 20));
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(140, 270, 131, 20));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(140, 330, 231, 20));
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(140, 390, 171, 20));
        label_13 = new QLabel(page_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(140, 440, 131, 20));
        label_14 = new QLabel(page_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(150, 640, 131, 20));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 0, 361, 81));
        code_med = new QLineEdit(page_4);
        code_med->setObjectName(QStringLiteral("code_med"));
        code_med->setGeometry(QRect(170, 120, 201, 31));
        libelle = new QLineEdit(page_4);
        libelle->setObjectName(QStringLiteral("libelle"));
        libelle->setGeometry(QRect(500, 120, 201, 31));
        mode = new QLineEdit(page_4);
        mode->setObjectName(QStringLiteral("mode"));
        mode->setGeometry(QRect(170, 200, 201, 31));
        frequence = new QLineEdit(page_4);
        frequence->setObjectName(QStringLiteral("frequence"));
        frequence->setGeometry(QRect(500, 200, 201, 31));
        quantite = new QSpinBox(page_4);
        quantite->setObjectName(QStringLiteral("quantite"));
        quantite->setGeometry(QRect(800, 210, 42, 22));
        label_3 = new QLabel(page_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 120, 151, 21));
        label_4 = new QLabel(page_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 120, 61, 21));
        label_5 = new QLabel(page_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 200, 51, 21));
        label_6 = new QLabel(page_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(390, 210, 91, 21));
        label_7 = new QLabel(page_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(740, 210, 61, 21));
        pushButton = new QPushButton(page_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(900, 200, 131, 41));
        pushButton->setStyleSheet(QLatin1String(" QPushButton{\n"
"    font: 12pt \"MS Shell Dlg 2\";\n"
" }\n"
"QPushButton:hover:!pressed\n"
"{\n"
"\n"
"	 border: 1px solid yellow;\n"
"background-color: rgb(255, 255, 127);\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover::pressed\n"
"{\n"
"\n"
"	 border: 1px solid green;\n"
"background-color: rgb(0, 255,0);\n"
"}\n"
""));
        pushButton_2 = new QPushButton(page_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 0, 81, 31));
        pushButton_3 = new QPushButton(page_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(830, 390, 121, 41));
        pushButton_3->setStyleSheet(QLatin1String(" QPushButton{\n"
"    font: 12pt \"MS Shell Dlg 2\";\n"
" }\n"
"QPushButton:hover:!pressed\n"
"{\n"
"\n"
"	 border: 1px solid yellow;\n"
"background-color: rgb(255, 255, 127);\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover::pressed\n"
"{\n"
"\n"
"	 border: 1px solid green;\n"
"background-color: rgb(0, 255,0);\n"
"}\n"
""));
        pushButton_4 = new QPushButton(page_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(830, 330, 121, 41));
        pushButton_4->setStyleSheet(QLatin1String(" QPushButton{\n"
"    font: 12pt \"MS Shell Dlg 2\";\n"
" }\n"
"QPushButton:hover:!pressed\n"
"{\n"
"\n"
"	 border: 1px solid yellow;\n"
"background-color: rgb(255, 255, 127);\n"
"}\n"
"\n"
"\n"
"\n"
"QPushButton:hover::pressed\n"
"{\n"
"\n"
"	 border: 1px solid green;\n"
"background-color: rgb(0, 255,0);\n"
"}\n"
""));
        tab_medicament = new QTableView(page_4);
        tab_medicament->setObjectName(QStringLiteral("tab_medicament"));
        tab_medicament->setGeometry(QRect(20, 270, 781, 391));
        stackedWidget->addWidget(page_4);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        tab_visite = new QTableView(page_5);
        tab_visite->setObjectName(QStringLiteral("tab_visite"));
        tab_visite->setGeometry(QRect(20, 40, 941, 621));
        retour_2 = new QPushButton(page_5);
        retour_2->setObjectName(QStringLiteral("retour_2"));
        retour_2->setGeometry(QRect(10, 10, 93, 28));
        stackedWidget->addWidget(page_5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1147, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        exit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        afficher_visite->setText(QApplication::translate("MainWindow", "Consulter les visites", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        nouvelle_visite->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><pre style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:10px; margin-right:15px; -qt-block-indent:0; text-indent:0px; font-family:'Courier New'; background-color:#ffffff;\"><br/></pre></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        nouvelle_visite->setText(QApplication::translate("MainWindow", "Nouvelle visite", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Visite Medical</span></p></body></html>", Q_NULLPTR));
        actes_medicaux->clear();
        actes_medicaux->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Choisissez l'acte", Q_NULLPTR)
         << QApplication::translate("MainWindow", "test", Q_NULLPTR)
        );
        valider->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        ordenance->setText(QApplication::translate("MainWindow", "Ordenance", Q_NULLPTR));
        retour->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">ID Viste</span></p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Nom patient</span></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Pr\303\250nom patient</span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Date naissance du patient</span></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Les actes medicaux</span></p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Observation</span></p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Diagnostic</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt; font-weight:600; text-decoration: underline;\">Ordenance</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Code Medicament</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Libelle</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Mode</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Frequence</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">Qte/jrs</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        retour_2->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
