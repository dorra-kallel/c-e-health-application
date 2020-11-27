#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"chambre.h"
#include"machine.h"
#include <QMainWindow>

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


private:
    Ui::MainWindow *ui;
    chambre tmp;
    machine tm;
};
#endif // MAINWINDOW_H
