#include "dialog_verleih.h"
#include "ui_dialog_verleih.h"

Dialog_Verleih::Dialog_Verleih(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Verleih)
{
    ui->setupUi(this);
    con = getConnection();
    show_verleih();
}

Dialog_Verleih::~Dialog_Verleih()
{
    delete ui;
}

void Dialog_Verleih::on_pushButton_clicked()
{
    this->close();
}
void Dialog_Verleih::setConnetion(QSqlDatabase _con)
{
    con = _con;
}
QSqlDatabase Dialog_Verleih::getConnection()
{
    return con;
}
void Dialog_Verleih::show_verleih()
{
    QSqlTableModel* model_verleih = new QSqlTableModel();
    model_verleih->setTable("verleih");
    model_verleih->select();
    ui->tableView_verleih->setModel(model_verleih);

}

