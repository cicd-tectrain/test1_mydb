#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QDebug>
#include<QTableView>

#include "dialog_buecher.h"
#include "dialog_verleih.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void show_Leser();
    void connection();
    void design(QTableView* table);

private slots:
    void on_leser_verleih();
    void on_pushButton_t_buecher_clicked();

    void on_pushButton_t_Verleih_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QMessageBox msgBox;
    QSqlTableModel* model_leser;
    Dialog_buecher* dialog_buecher;
    Dialog_Verleih* dialog_verleih;

};
#endif // MAINWINDOW_H
