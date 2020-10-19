#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString date1 = ui->dateEdit->text();
    QString date = ui->dateEdit->date().toString(Qt::ISODate);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={MySQL ODBC 5.2 Unicode Driver};DATABASE=test;");
    db.setUserName("admin");
    db.setPassword("");

    if(db.open())
    {
        ui->label_3->setText("Connected");
        QSqlQuery SQLquery;
        QString query = "SELECT timestampdiff( MINUTE , min( T.time ) , max( T.time ) ) FROM ( SELECT time FROM archive JOIN card ON archive.card_id = card.id WHERE card.info = \"" + name + "\" AND date( archive.time ) = \"" + date + "\" ) AS T";
        qDebug() << query;
        if(SQLquery.exec(query))
        {
            while (SQLquery.next())
            {
                qDebug() << SQLquery.value(0).toString() << SQLquery.value(1).toString();;
                ui->label_3->setText(SQLquery.value(0).toString()+" минут");
            }
        }
        else
        {
            ui->label_3->setText("Cannot execute query");
            qDebug() << (SQLquery.lastError().text());

        }

    }
    else
    {
        ui->label_3->setText("Cannot connect to DB");
    }

}
