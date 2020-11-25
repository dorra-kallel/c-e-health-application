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
#include <QtWidgets/QVBoxLayout>
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
    QDateEdit *date_naiss_patient;
    QComboBox *actes_medicaux;
    QLineEdit *nom_patient_2;
    QLineEdit *prenom_patient;
    QTextEdit *observation;
    QTextEdit *diagnostic;
    QPushButton *valider;
    QPushButton *ordenance;
    QPushButton *retour;
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
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *tab_medicament;
    QPushButton *pushButton_3;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QStackedWidget *stackedWidget_2;
    QWidget *page_6;
    QWidget *page_7;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *page_8;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *mode_modif;
    QLineEdit *code_med_modif;
    QLineEdit *freq__modif;
    QLabel *label_6;
    QLineEdit *libelle__modif;
    QLabel *label_16;
    QPushButton *pushButton_5;
    QSpinBox *qts_modif;
    QPushButton *pdf;
    QWidget *page_2;
    QWidget *page_5;
    QTableView *tab_visite;
    QPushButton *retour_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLineEdit *nom_chercher;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1549, 1107);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(29, 30, 48);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-30, 10, 1571, 1021));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(630, 90, 371, 411));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        exit = new QPushButton(layoutWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setStyleSheet(QLatin1String("QPushButton {\n"
"background-image: url(C:/Users/HP/Documents/Health-application/icons/16x16/cil-folder-open.png);\n"
"	background-position: left center;\n"
"\n"
"    background-repeat: no-repeat;\n"
"\n"
"	border: 40px solid transparent;\n"
"color:rgb(238, 238, 238);\n"
"	border-radius: 400px;	\n"
"	background-color:#3d50eb;\n"
"border-left:4px solid #3d50eb;\n"
"    font: 20pt \"MS Shell Dlg 2\";\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:rgb(255, 255, 255);\n"
"		background-color: rgb(63, 84, 244);\n"
"}\n"
"QPushButton:pressed {	\n"
"	border: 10px solid rgb(55, 74, 214) ;\n"
"}"));

        gridLayout->addWidget(exit, 2, 0, 1, 1);

        afficher_visite = new QPushButton(layoutWidget);
        afficher_visite->setObjectName(QStringLiteral("afficher_visite"));
        afficher_visite->setStyleSheet(QLatin1String("QPushButton {\n"
"background-image: url(C:/Users/HP/Documents/Health-application/icons/16x16/cil-folder-open.png);\n"
"	background-position: left center;\n"
"\n"
"    background-repeat: no-repeat;\n"
"\n"
"	border: 40px solid transparent;\n"
"color:rgb(238, 238, 238);\n"
"	border-radius: 400px;	\n"
"	background-color:#3d50eb;\n"
"border-left:4px solid #3d50eb;\n"
"    font: 20pt \"MS Shell Dlg 2\";\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:rgb(255, 255, 255);\n"
"		background-color: rgb(63, 84, 244);\n"
"}\n"
"QPushButton:pressed {	\n"
"	border: 10px solid rgb(55, 74, 214) ;\n"
"}"));

        gridLayout->addWidget(afficher_visite, 1, 0, 1, 1);

        nouvelle_visite = new QPushButton(layoutWidget);
        nouvelle_visite->setObjectName(QStringLiteral("nouvelle_visite"));
        nouvelle_visite->setStyleSheet(QLatin1String("QPushButton {\n"
"background-image: url(C:/Users/HP/Documents/Health-application/icons/16x16/cil-folder-open.png);\n"
"	background-position: left center;\n"
"\n"
"    background-repeat: no-repeat;\n"
"\n"
"	border: 40px solid transparent;\n"
"color:rgb(238, 238, 238);\n"
"	border-radius: 400px;	\n"
"	background-color:#3d50eb;\n"
"border-left:4px solid #3d50eb;\n"
"    font: 20pt \"MS Shell Dlg 2\";\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"color:rgb(255, 255, 255);\n"
"		background-color: rgb(63, 84, 244);\n"
"}\n"
"QPushButton:pressed {	\n"
"	border: 10px solid rgb(55, 74, 214) ;\n"
"}"));

        gridLayout->addWidget(nouvelle_visite, 0, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(680, 30, 261, 31));
        stackedWidget->addWidget(page);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        date_naiss_patient = new QDateEdit(page_3);
        date_naiss_patient->setObjectName(QStringLiteral("date_naiss_patient"));
        date_naiss_patient->setGeometry(QRect(580, 300, 221, 41));
        date_naiss_patient->setStyleSheet(QLatin1String("QDateEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QDateEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        actes_medicaux = new QComboBox(page_3);
        actes_medicaux->setObjectName(QStringLiteral("actes_medicaux"));
        actes_medicaux->setGeometry(QRect(580, 360, 221, 41));
        actes_medicaux->setStyleSheet(QLatin1String("QComboBox{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"\n"
"}\n"
"QComboBox:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        actes_medicaux->setEditable(false);
        nom_patient_2 = new QLineEdit(page_3);
        nom_patient_2->setObjectName(QStringLiteral("nom_patient_2"));
        nom_patient_2->setGeometry(QRect(580, 180, 221, 41));
        nom_patient_2->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        prenom_patient = new QLineEdit(page_3);
        prenom_patient->setObjectName(QStringLiteral("prenom_patient"));
        prenom_patient->setGeometry(QRect(580, 240, 221, 41));
        prenom_patient->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        observation = new QTextEdit(page_3);
        observation->setObjectName(QStringLiteral("observation"));
        observation->setGeometry(QRect(580, 420, 391, 161));
        observation->setStyleSheet(QLatin1String("QTextEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QTextEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        diagnostic = new QTextEdit(page_3);
        diagnostic->setObjectName(QStringLiteral("diagnostic"));
        diagnostic->setGeometry(QRect(580, 620, 391, 161));
        diagnostic->setStyleSheet(QLatin1String("QTextEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QTextEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        valider = new QPushButton(page_3);
        valider->setObjectName(QStringLiteral("valider"));
        valider->setGeometry(QRect(580, 810, 161, 71));
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
"\n"
""));
        ordenance = new QPushButton(page_3);
        ordenance->setObjectName(QStringLiteral("ordenance"));
        ordenance->setGeometry(QRect(770, 810, 201, 71));
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
        retour->setGeometry(QRect(70, 10, 101, 41));
        retour->setStyleSheet(QStringLiteral(""));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(330, 190, 131, 20));
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(330, 250, 131, 20));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(330, 310, 231, 20));
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(330, 370, 171, 20));
        label_13 = new QLabel(page_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(330, 420, 131, 20));
        label_14 = new QLabel(page_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(340, 620, 131, 20));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_2 = new QLabel(page_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 0, 361, 81));
        code_med = new QLineEdit(page_4);
        code_med->setObjectName(QStringLiteral("code_med"));
        code_med->setGeometry(QRect(210, 120, 201, 31));
        code_med->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        libelle = new QLineEdit(page_4);
        libelle->setObjectName(QStringLiteral("libelle"));
        libelle->setGeometry(QRect(540, 120, 201, 31));
        libelle->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        mode = new QLineEdit(page_4);
        mode->setObjectName(QStringLiteral("mode"));
        mode->setGeometry(QRect(210, 200, 201, 31));
        mode->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        frequence = new QLineEdit(page_4);
        frequence->setObjectName(QStringLiteral("frequence"));
        frequence->setGeometry(QRect(540, 200, 201, 31));
        frequence->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        quantite = new QSpinBox(page_4);
        quantite->setObjectName(QStringLiteral("quantite"));
        quantite->setGeometry(QRect(840, 210, 42, 22));
        quantite->setStyleSheet(QLatin1String("QSpinBox{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QPsinBox:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        label_7 = new QLabel(page_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(780, 210, 61, 21));
        pushButton = new QPushButton(page_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(940, 200, 131, 41));
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
        pushButton_2->setGeometry(QRect(40, 0, 81, 31));
        tab_medicament = new QTableView(page_4);
        tab_medicament->setObjectName(QStringLiteral("tab_medicament"));
        tab_medicament->setGeometry(QRect(60, 490, 791, 441));
        tab_medicament->setStyleSheet(QLatin1String("QTableView{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QTableView:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        tab_medicament->setSelectionMode(QAbstractItemView::SingleSelection);
        tab_medicament->setSelectionBehavior(QAbstractItemView::SelectRows);
        tab_medicament->horizontalHeader()->setStretchLastSection(true);
        pushButton_3 = new QPushButton(page_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(870, 490, 111, 41));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {	\n"
"border:none;\n"
"	background-image: url(C:/Users/HP/Documents/Health-application/icons/16x16/cil-x.png);\n"
"	background-position: left center;\n"
"padding-left:5px;\n"
"    background-repeat: no-repeat;\n"
"background-color:rgb(232, 45, 76);\n"
"	border-radius: 5px;\n"
"border:1px solid transparent;\n"
"color:rgb(255, 255, 255);\n"
"	text-align: center;\n"
"border-left:4px solid rgb(232, 45, 76);\n"
"\n"
"	\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(240, 46, 78);\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"border:2px solid rgb(179, 34, 58);\n"
"\n"
"\n"
"}\n"
""));
        label_17 = new QLabel(page_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(50, 120, 151, 21));
        label_17->setStyleSheet(QStringLiteral(""));
        label_18 = new QLabel(page_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(50, 200, 51, 21));
        label_18->setStyleSheet(QStringLiteral(""));
        label_19 = new QLabel(page_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(440, 120, 61, 21));
        label_20 = new QLabel(page_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(440, 200, 91, 21));
        stackedWidget_2 = new QStackedWidget(page_4);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(40, 310, 999, 159));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        stackedWidget_2->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        verticalLayoutWidget = new QWidget(page_7);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 961, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget_2->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        verticalLayoutWidget_2 = new QWidget(page_8);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 961, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(page_8);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 31, 151, 21));
        label_3->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(page_8);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(420, 31, 61, 21));
        label_5 = new QLabel(page_8);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 91, 51, 21));
        mode_modif = new QLineEdit(page_8);
        mode_modif->setObjectName(QStringLiteral("mode_modif"));
        mode_modif->setGeometry(QRect(190, 91, 201, 31));
        mode_modif->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        code_med_modif = new QLineEdit(page_8);
        code_med_modif->setObjectName(QStringLiteral("code_med_modif"));
        code_med_modif->setEnabled(false);
        code_med_modif->setGeometry(QRect(190, 31, 201, 31));
        code_med_modif->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border: 5px solid transparent;border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 5px solid transparent;}"));
        freq__modif = new QLineEdit(page_8);
        freq__modif->setObjectName(QStringLiteral("freq__modif"));
        freq__modif->setGeometry(QRect(530, 91, 201, 31));
        freq__modif->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        label_6 = new QLabel(page_8);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(420, 91, 91, 21));
        libelle__modif = new QLineEdit(page_8);
        libelle__modif->setObjectName(QStringLiteral("libelle__modif"));
        libelle__modif->setGeometry(QRect(530, 31, 201, 31));
        libelle__modif->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        label_16 = new QLabel(page_8);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(740, 31, 61, 20));
        pushButton_5 = new QPushButton(page_8);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(750, 91, 181, 28));
        qts_modif = new QSpinBox(page_8);
        qts_modif->setObjectName(QStringLiteral("qts_modif"));
        qts_modif->setGeometry(QRect(800, 31, 71, 31));
        qts_modif->setStyleSheet(QLatin1String("QSpinBox{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QPsinBox:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        stackedWidget_2->addWidget(page_8);
        pdf = new QPushButton(page_4);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(870, 580, 111, 41));
        pdf->setStyleSheet(QLatin1String(" QPushButton{\n"
"    font: 12pt \"MS Shell Dlg 2\";\n"
"color:white;\n"
"background-image:url(C:/Users/Pavillion/Desktop/E-HEALTH/icons/24x24/cil-3d);\n"
"background-position: left center;\n"
"background-repeat:no-repeat;\n"
"\n"
" }\n"
"QPushButton:hover:!pressed\n"
"{\n"
"\n"
"	 border: 1px solid yellow;\n"
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
"background-color: rgb(0, 255,0);\n"
"}\n"
"\n"
""));
        stackedWidget->addWidget(page_4);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        tab_visite = new QTableView(page_5);
        tab_visite->setObjectName(QStringLiteral("tab_visite"));
        tab_visite->setGeometry(QRect(40, 290, 1421, 621));
        tab_visite->setStyleSheet(QLatin1String("QTableView{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QTableView:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        tab_visite->setSelectionMode(QAbstractItemView::SingleSelection);
        tab_visite->setSelectionBehavior(QAbstractItemView::SelectRows);
        tab_visite->setGridStyle(Qt::SolidLine);
        tab_visite->horizontalHeader()->setDefaultSectionSize(175);
        tab_visite->horizontalHeader()->setMinimumSectionSize(80);
        tab_visite->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tab_visite->horizontalHeader()->setStretchLastSection(true);
        tab_visite->verticalHeader()->setVisible(false);
        tab_visite->verticalHeader()->setDefaultSectionSize(50);
        retour_2 = new QPushButton(page_5);
        retour_2->setObjectName(QStringLiteral("retour_2"));
        retour_2->setGeometry(QRect(90, 10, 93, 28));
        pushButton_6 = new QPushButton(page_5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(1480, 330, 93, 28));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton {	\n"
"border:none;\n"
"	background-image: url(C:/Users/HP/Documents/Health-application/icons/16x16/cil-x.png);\n"
"	background-position: left center;\n"
"padding-left:5px;\n"
"    background-repeat: no-repeat;\n"
"background-color:rgb(232, 45, 76);\n"
"	border-radius: 5px;\n"
"border:1px solid transparent;\n"
"color:rgb(255, 255, 255);\n"
"	text-align: center;\n"
"border-left:4px solid rgb(232, 45, 76);\n"
"\n"
"	\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(240, 46, 78);\n"
"\n"
"}\n"
"QPushButton:pressed {\n"
"border:2px solid rgb(179, 34, 58);\n"
"\n"
"\n"
"}\n"
""));
        pushButton_7 = new QPushButton(page_5);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(1480, 380, 93, 28));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton {	\n"
"border:none;\n"
"background-color:#009688;\n"
"	background-image: url(C:/Users/HP/Documents/Health-application/icons/16x16/cil-description.png);\n"
"	background-position: left center;\n"
"\n"
"    background-repeat: no-repeat;\n"
"\n"
"	border-radius: 5px;\n"
"border:1px solid transparent;\n"
"color:rgb(255, 255, 255);\n"
"	text-align: center;\n"
"\n"
"border-left:4px solid #009688;\n"
"	\n"
"}\n"
"QPushButton:hover {\n"
"	background-color:rgb(0, 175, 157);\n"
"	\n"
"}\n"
"QPushButton:pressed {\n"
"border:2px solid rgb(0, 132, 119);\n"
"\n"
"\n"
"}\n"
""));
        pushButton_8 = new QPushButton(page_5);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(1480, 430, 93, 28));
        pushButton_9 = new QPushButton(page_5);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(1480, 480, 93, 28));
        pushButton_10 = new QPushButton(page_5);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(1480, 530, 93, 28));
        nom_chercher = new QLineEdit(page_5);
        nom_chercher->setObjectName(QStringLiteral("nom_chercher"));
        nom_chercher->setEnabled(true);
        nom_chercher->setGeometry(QRect(50, 230, 231, 41));
        nom_chercher->setStyleSheet(QLatin1String("QLineEdit{\n"
"background-color:#25283b;\n"
"\n"
"border:1px solid rgb(61, 70, 86);\n"
"color:rgb(255, 255, 255);\n"
"padding-left:16px;\n"
"border:1px solid rgb(61, 70, 86);\n"
"border-top-right-radius:10px;\n"
"border-down-right-radius:10px;\n"
"}\n"
"QLineEdit:focus{\n"
"border: 1px solid rgb(180, 180, 180);\n"
"}"));
        stackedWidget->addWidget(page_5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1549, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(2);


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
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; text-decoration: underline; color:#ffffff;\">Visite Medical</span></p></body></html>", Q_NULLPTR));
        actes_medicaux->clear();
        actes_medicaux->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Choisissez l'acte", Q_NULLPTR)
         << QApplication::translate("MainWindow", "test", Q_NULLPTR)
        );
        valider->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        ordenance->setText(QApplication::translate("MainWindow", "Ordonnance", Q_NULLPTR));
        retour->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Nom patient</span></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Pr\303\250nom patient</span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Date naissance du patient</span></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Les actes medicaux</span></p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Observation</span></p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Diagnostic</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt; font-weight:600; text-decoration: underline; color:#ffffff;\">Ordonnance</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Qte/jrs</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Code Medicament</span></p></body></html>", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Mode</span></p></body></html>", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Libelle</span></p></body></html>", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Frequence</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Code Medicament</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Libelle</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Mode</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Frequence</span></p></body></html>", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffffff;\">Qte/jrs</span></p></body></html>", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Confirmer modification", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        retour_2->setText(QApplication::translate("MainWindow", "Retour", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Tri asc", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "Tri desc", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "Excel", Q_NULLPTR));
        nom_chercher->setText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
