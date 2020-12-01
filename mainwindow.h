#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "patient.h"
#include <QMainWindow>
#include"rendez_vous.h"
#include <QPropertyAnimation>




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
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_10_clicked();

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_20_clicked();

    void on_label_10_linkActivated(const QString &link);

    void on_label_10_linkHovered(const QString &link);

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_25_clicked();

    void on_lineEdit_8_textEdited(const QString &arg1);

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_pushButton_12_clicked();

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_2_pressed();

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
int a=0;
int h=0;
    patient p;
    rendez_vous rdv;

};

#endif // MAINWINDOW_H
