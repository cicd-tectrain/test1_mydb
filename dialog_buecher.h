#ifndef DIALOG_BUECHER_H
#define DIALOG_BUECHER_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>
#include<QTableView>

namespace Ui {
class Dialog_buecher;
}

class Dialog_buecher : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_buecher(QWidget *parent = nullptr);
    ~Dialog_buecher();
    void show_buecher();
    void design(QTableView* table);
    void setConnection(QSqlDatabase _con);
    QSqlDatabase getConnection();


private slots:
    void on_pushButton_Close_clicked();

private:
    Ui::Dialog_buecher *ui;
    QSqlDatabase con;       //connection
    QSqlTableModel* model_buecher;
};

#endif // DIALOG_BUECHER_H
