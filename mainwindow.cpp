#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connection();
    show_Leser();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    QString connString = "Driver={MySql ODBC 8.0 ANSI Driver};";
           // connString += "SERVER=localhost:3306;DATABASE=bibliothek;";//salim
                connString += "SERVER=localhost:3306;DATABASE=mydb;";
            connString += "USER=root;PASSWORD=1234;";

    db.setDatabaseName(connString);
}

void MainWindow::show_Leser()
{
    if(db.open())
    {
        //msgBox.information(this,"Info","Your are connected");
        //qDebug() << "Your are connected";
        model_leser = new QSqlTableModel();
       // model_leser->setTable("leser");
        model_leser->setTable("clients");
        model_leser->select();
        ui->tableView_Leser->setModel(model_leser);
        design(ui->tableView_Leser);
        connect(ui->tableView_Leser->selectionModel(),
                SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
                SLOT(on_leser_verleih()));

    }
    else
    {
        //msgBox.information(this,"Failed","The connection failed");
        qDebug() << "The connection failed";
    }
}
void MainWindow::design(QTableView* table)
{
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
}

void MainWindow::on_leser_verleih()
{
    int currentRow = ui->tableView_Leser->currentIndex().row();
    //int _leserId = model_leser->record(currentRow).value("leserId").toInt();
   // QString _zuname = model_leser->record(currentRow).value("zuname").toString();//salim
    QString _zuname = model_leser->record(currentRow).value("client_name").toString();

    //qDebug() << "Aktueller Zeile: " << currentRow << "leserId: " << _leserId << "zuname: " << _zuname;

    QSqlTableModel* model_leser_verleih = new QSqlTableModel();
    model_leser_verleih->setTable("v_leser_verleih");

    //1. Variante
    //model_leser_verleih->setFilter(QString("zuname like '%1'").arg(_zuname));

    //2. Variante
    //zuname like 'Riegler'
    QString query = "zuname like '";
    query += _zuname;
    query += "'";
    model_leser_verleih->setFilter(query);

    model_leser_verleih->select();
    ui->tableView_leser_verleih->setModel(model_leser_verleih);
    design(ui->tableView_leser_verleih);
}

void MainWindow::on_pushButton_t_buecher_clicked()
{
    dialog_buecher = new Dialog_buecher(this);
    dialog_buecher->setModal(true);
    dialog_buecher->exec();
    dialog_buecher->setConnection(db);

}


void MainWindow::on_pushButton_t_Verleih_clicked()
{
    dialog_verleih = new Dialog_Verleih(this);
    dialog_verleih->setModal(true);
    dialog_verleih->exec();
    dialog_verleih->setConnetion(db);

}

