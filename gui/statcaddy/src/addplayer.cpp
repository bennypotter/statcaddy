#include "include/addplayer.h"
#include "interface/ui_addplayer.h"
#include <QtSql>

AddPlayer::AddPlayer(QWidget *parent, QSqlDatabase db) :
    QDialog(parent),
    ui(new Ui::AddPlayer)
{
    ui->setupUi(this);

    this->db = db;
    //this->db.open();
    connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(onOkButtonClicked()));

    /*
    QSqlQuery query(this->db);
    query.exec("SELECT * FROM Player WHERE id = 1");

    while (query.next()) {
    QString title = query.value(0).toString();
    ui->lineEdit->setText(title);
    }*/
}

AddPlayer::~AddPlayer()
{
    delete ui;
}

void AddPlayer::onOkButtonClicked()
{
    QString qstr = QString::number(ui->spinBox->value());
    QSqlQuery query;
    QString s = "INSERT INTO Player (firstname, lastname, handicap) VALUES ('"+ui->lineEdit->text()+"', '"+ui->lineEdit_2->text()+"', "+qstr+")";
   // query.exec("INSERT INTO Player (firstname, lastname, handicap) VALUES ('"+ui->lineEdit->text()+"', '"+ui->lineEdit_2->text()+"', "+ui->spinBox->value()+")");
    //ui->lineEdit->setText(s);
    //query.exec(s);
}
