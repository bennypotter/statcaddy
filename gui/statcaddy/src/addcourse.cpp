#include "include/addcourse.h"
#include "interface/ui_addcourse.h"
//#include <QtSql>

AddCourse::AddCourse(QWidget *parent, QSqlDatabase db) :
    QDialog(parent),
    ui(new Ui::AddCourse)
{
    this->db = db;
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onOKBtnClicked()));

    comboList.append(ui->shape1);
    comboList.append(ui->shape2);
    comboList.append(ui->shape3);
    comboList.append(ui->shape4);
    comboList.append(ui->shape5);
    comboList.append(ui->shape6);
    comboList.append(ui->shape7);
    comboList.append(ui->shape8);
    comboList.append(ui->shape9);
    comboList.append(ui->shape10);
    comboList.append(ui->shape11);
    comboList.append(ui->shape12);
    comboList.append(ui->shape13);
    comboList.append(ui->shape14);
    comboList.append(ui->shape15);
    comboList.append(ui->shape16);
    comboList.append(ui->shape17);
    comboList.append(ui->shape18);


    yardList.append(ui->yard1);
    yardList.append(ui->yard2);
    yardList.append(ui->yard3);
    yardList.append(ui->yard4);
    yardList.append(ui->yard5);
    yardList.append(ui->yard6);
    yardList.append(ui->yard7);
    yardList.append(ui->yard8);
    yardList.append(ui->yard9);
    yardList.append(ui->yard10);
    yardList.append(ui->yard11);
    yardList.append(ui->yard12);
    yardList.append(ui->yard13);
    yardList.append(ui->yard14);
    yardList.append(ui->yard15);
    yardList.append(ui->yard16);
    yardList.append(ui->yard17);
    yardList.append(ui->yard18);


    parList.append(ui->par1);
    parList.append(ui->par2);
    parList.append(ui->par3);
    parList.append(ui->par4);
    parList.append(ui->par5);
    parList.append(ui->par6);
    parList.append(ui->par7);
    parList.append(ui->par8);
    parList.append(ui->par9);
    parList.append(ui->par10);
    parList.append(ui->par11);
    parList.append(ui->par12);
    parList.append(ui->par13);
    parList.append(ui->par14);
    parList.append(ui->par15);
    parList.append(ui->par16);
    parList.append(ui->par17);
    parList.append(ui->par18);


    SIList.append(ui->SI1);
    SIList.append(ui->SI2);
    SIList.append(ui->SI3);
    SIList.append(ui->SI4);
    SIList.append(ui->SI5);
    SIList.append(ui->SI6);
    SIList.append(ui->SI7);
    SIList.append(ui->SI8);
    SIList.append(ui->SI9);
    SIList.append(ui->SI10);
    SIList.append(ui->SI11);
    SIList.append(ui->SI12);
    SIList.append(ui->SI13);
    SIList.append(ui->SI14);
    SIList.append(ui->SI15);
    SIList.append(ui->SI16);
    SIList.append(ui->SI17);
    SIList.append(ui->SI18);

    for(int i = 0; i < comboList.size(); i++)
        setCombos(comboList[i]);
}

AddCourse::~AddCourse()
{
    delete ui;
}

void AddCourse::onOKBtnClicked()
{
    QString s = "INSERT INTO golfCourse (strokeIndex,par,name,addL1,addL2,postcode) VALUES ('"+ui->totalSI->text()+"', '"+ui->totalPar->text()+"', '"+ui->lineEdit->text()+"', '"+ui->lineEdit_2->text()+"', '"+ui->lineEdit_4->text()+"', '"+ui->lineEdit_5->text()+"')";
    QSqlQuery query;
    query.exec(s);

    s = "SELECT MAX(gc_Id) FROM golfCourse";
    query.exec(s);
    int gc_Id = 0;
    while (query.next())
    {
        gc_Id = query.value(0).toInt();
    }

    for(int i = 0; i < 18; i++)
    {
        QString s1 = "INSERT INTO Hole (par, strokeIndex, yards, holeNum, shape, gc_Id) VALUES("+parList[i]->text()+", "+SIList[i]->text()+", "+yardList[i]->text()+", "+QString::number(i+1)+", '"+comboList[i]->itemText(comboList[i]->currentIndex())+"', "+QString::number(gc_Id)+")";
        query.exec(s1);
    }
}

void AddCourse::setCombos(QComboBox *box)
{
    box->addItem("Straight");
    box->addItem("Dogleg Right (Sharp)");
    box->addItem("Dogleg Right (Mild)");
    box->addItem("Dogleg Left (Sharp)");
    box->addItem("Dogleg Left (Mild)");
}
