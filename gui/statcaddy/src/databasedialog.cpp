#include "include/databasedialog.h"
#include "interface/ui_databasedialog.h"
#include <QtSql>

DatabaseDialog::DatabaseDialog(QWidget *parent, QSqlDatabase db) :
    QDialog(parent),
    ui(new Ui::DatabaseDialog)
{
    ui->setupUi(this);
    this->db = db;

    QString d = "pragma database_list";
    QSqlQuery query1;
    query1.exec(d);
    QString pg;
    while(query1.next())
        pg = query1.value(2).toString();
    ui->lineEdit_3->setText(pg);
    int s_size = pg.size();
    for(int i = 0; i < s_size; i++)
        if (pg.at(i) == '/')
        {
            pg.remove(0,i+1);
            s_size = pg.size();
            i=0;
        }
    ui->lineEdit->setText(pg);

    QString s = "pragma page_count";
    QSqlQuery query;
    query.exec(s);
    double pg_count = 0;
    while(query.next())
        pg_count = query.value(0).toDouble();

    s = "pragma page_size";
    query.exec(s);
    double pg_size = 0;
    while(query.next())
        pg_size = query.value(0).toDouble();

    double size = (pg_size * pg_count)/1048576; //size of db in MB's
    size = floor(size * 100) / 100;
    ui->lineEdit_4->setText(QString::number(size));




}

DatabaseDialog::~DatabaseDialog()
{
    delete ui;
}
