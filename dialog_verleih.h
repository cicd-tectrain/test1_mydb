#ifndef DIALOG_VERLEIH_H
#define DIALOG_VERLEIH_H

#include <QDialog>
#include<QtSql>
#include<QSqlDatabase>

namespace Ui {
class Dialog_Verleih;
}

class Dialog_Verleih : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Verleih(QWidget *parent = nullptr);
    ~Dialog_Verleih();
    void show_verleih();
    void setConnetion(QSqlDatabase _con);
    QSqlDatabase getConnection();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_Verleih *ui;
    QSqlDatabase con;
};

#endif // DIALOG_VERLEIH_H
