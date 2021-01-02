/********************************************************************************
** Form generated from reading UI file 'modifier_visite.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIER_VISITE_H
#define UI_MODIFIER_VISITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_modifier_visite
{
public:
    QLabel *label_10;
    QDateEdit *date_naiss_patient;
    QLineEdit *nom_patient_2;
    QLineEdit *prenom_patient;
    QLabel *label_11;
    QLabel *label_14;
    QTextEdit *diagnostic;
    QLabel *label_9;
    QLabel *label_13;
    QTextEdit *observation;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *id;
    QLabel *label_15;

    void setupUi(QDialog *modifier_visite)
    {
        if (modifier_visite->objectName().isEmpty())
            modifier_visite->setObjectName(QString::fromUtf8("modifier_visite"));
        modifier_visite->resize(973, 822);
        modifier_visite->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 30, 48);"));
        label_10 = new QLabel(modifier_visite);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 200, 131, 20));
        date_naiss_patient = new QDateEdit(modifier_visite);
        date_naiss_patient->setObjectName(QString::fromUtf8("date_naiss_patient"));
        date_naiss_patient->setGeometry(QRect(270, 250, 221, 41));
        date_naiss_patient->setStyleSheet(QString::fromUtf8("QDateEdit{\n"
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
        date_naiss_patient->setCalendarPopup(true);
        nom_patient_2 = new QLineEdit(modifier_visite);
        nom_patient_2->setObjectName(QString::fromUtf8("nom_patient_2"));
        nom_patient_2->setGeometry(QRect(270, 130, 221, 41));
        nom_patient_2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        prenom_patient = new QLineEdit(modifier_visite);
        prenom_patient->setObjectName(QString::fromUtf8("prenom_patient"));
        prenom_patient->setGeometry(QRect(270, 190, 221, 41));
        prenom_patient->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        label_11 = new QLabel(modifier_visite);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 260, 231, 20));
        label_14 = new QLabel(modifier_visite);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 570, 131, 20));
        diagnostic = new QTextEdit(modifier_visite);
        diagnostic->setObjectName(QString::fromUtf8("diagnostic"));
        diagnostic->setGeometry(QRect(270, 570, 621, 161));
        diagnostic->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
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
        label_9 = new QLabel(modifier_visite);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 140, 131, 20));
        label_13 = new QLabel(modifier_visite);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 370, 131, 20));
        observation = new QTextEdit(modifier_visite);
        observation->setObjectName(QString::fromUtf8("observation"));
        observation->setGeometry(QRect(270, 360, 621, 141));
        observation->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
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
        label = new QLabel(modifier_visite);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 20, 461, 31));
        pushButton = new QPushButton(modifier_visite);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 750, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {	\n"
"border:none;\n"
"background-color:#0000FF;\n"
"	background-position: left center;\n"
"\n"
"    background-repeat: no-repeat;\n"
"\n"
"	border-radius: 5px;\n"
"border:1px solid transparent;\n"
"color:rgb(255, 255, 255);\n"
"	text-align: center;\n"
"\n"
"border-left:4px solid #0000FF;\n"
"	\n"
"}\n"
"QPushButton:hover {\n"
"	background-color:rgb(0, 0, 128);\n"
"	\n"
"}\n"
"QPushButton:pressed {\n"
"border:2px solid rgb(0, 0, 128);\n"
"\n"
"\n"
"}\n"
""));
        pushButton_2 = new QPushButton(modifier_visite);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 750, 121, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {	\n"
"border:none;\n"
"background-color:#0000FF;\n"
"	background-position: left center;\n"
"\n"
"    background-repeat: no-repeat;\n"
"\n"
"	border-radius: 5px;\n"
"border:1px solid transparent;\n"
"color:rgb(255, 255, 255);\n"
"	text-align: center;\n"
"\n"
"border-left:4px solid #0000FF;\n"
"	\n"
"}\n"
"QPushButton:hover {\n"
"	background-color:rgb(0, 0, 128);\n"
"	\n"
"}\n"
"QPushButton:pressed {\n"
"border:2px solid rgb(0, 0, 128);\n"
"\n"
"\n"
"}\n"
""));
        id = new QLineEdit(modifier_visite);
        id->setObjectName(QString::fromUtf8("id"));
        id->setEnabled(false);
        id->setGeometry(QRect(270, 80, 221, 31));
        id->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
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
        label_15 = new QLabel(modifier_visite);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 80, 131, 20));

        retranslateUi(modifier_visite);

        QMetaObject::connectSlotsByName(modifier_visite);
    } // setupUi

    void retranslateUi(QDialog *modifier_visite)
    {
        modifier_visite->setWindowTitle(QCoreApplication::translate("modifier_visite", "Modfier visite", nullptr));
        label_10->setText(QCoreApplication::translate("modifier_visite", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Pr\303\250nom patient</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("modifier_visite", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Date naissance du patient</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("modifier_visite", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Diagnostic</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("modifier_visite", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Nom patient</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("modifier_visite", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">Observation</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("modifier_visite", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; text-decoration: underline; color:#ffffff;\">Modifier Visite</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("modifier_visite", "Valider ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("modifier_visite", "Annuler", nullptr));
        label_15->setText(QCoreApplication::translate("modifier_visite", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#ffffff;\">ID_Visite</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modifier_visite: public Ui_modifier_visite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIER_VISITE_H
