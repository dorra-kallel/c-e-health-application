/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit_12;
    QTableView *tabrechercher;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(773, 495);
        lineEdit_12 = new QLineEdit(Dialog);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(40, 220, 113, 20));
        tabrechercher = new QTableView(Dialog);
        tabrechercher->setObjectName(QStringLiteral("tabrechercher"));
        tabrechercher->setGeometry(QRect(260, 140, 371, 311));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 282, 131, 41));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"  \n"
"  border-radius: 10px;\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0.613065, y1:0.511, x2:0.969, y2:0, stop:0.18593 rgba(2, 136, 148, 226), stop:0.959799 rgba(0, 0, 0, 161));\n"
"	\n"
"color:rgb(255, 255, 255);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover,QPushButton:hover\n"
"{\n"
"    border: 4px solid QLinearGradient( x1: 2, y1: 2, x2: 2, y2: 3, stop: 0 #08E8DE , stop: 3 #d7801a);\n"
"}\n"
""));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog", "rechercher", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
