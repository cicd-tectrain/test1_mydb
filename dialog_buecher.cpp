#include "dialog_buecher.h"
#include "ui_dialog_buecher.h"

Dialog_buecher::Dialog_buecher(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_buecher)
{
    ui->setupUi(this);
    con = getConnection();
    show_buecher();
}

Dialog_buecher::~Dialog_buecher()
{
    delete ui;
}
void Dialog_buecher::setConnection(QSqlDatabase _con)
{
    con = _con;
}
QSqlDatabase Dialog_buecher::getConnection()
{
    return con;
}
void Dialog_buecher::show_buecher()
{
    QSqlTableModel* model_buecher = new QSqlTableModel();
    model_buecher->setTable("buecher");
    model_buecher->select();
    ui->tableView_buecher->setModel(model_buecher);
    design(ui->tableView_buecher);
}
void Dialog_buecher::design(QTableView* table)
{
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
}

void Dialog_buecher::on_pushButton_Close_clicked()
{
    this->close();
}

