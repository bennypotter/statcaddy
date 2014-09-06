#include "include/addround.h"
#include "interface/ui_addround.h"
//#include <QtSql>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <math.h>

AddRound::AddRound(QWidget *parent, QSqlDatabase db/*, Player *player*/) :
    QDialog(parent),
    ui(new Ui::AddRound)
{
    ui->setupUi(this);
    //this->player = player;
    initializeLists();
    QString s = "SELECT name FROM GolfCourse";
    QSqlQuery query;
    query.exec(s);

    while (query.next())
            ui->courseCombo->addItem(query.value(0).toString());
    ui->courseCombo->setCurrentIndex(-1);

    connect(ui->courseCombo,SIGNAL(currentIndexChanged(int)), this,SLOT(onCourseComboIndexChanged()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(onOkButtonClicked()));    
}

AddRound::~AddRound()
{
    delete ui;
}

void AddRound::onCourseComboIndexChanged()
{
    /*QString name = ui->courseCombo->itemText(ui->courseCombo->currentIndex());
    QString s = "SELECT gc_Id FROM GolfCourse WHERE name = '"+name+"'";
    QSqlQuery query;
    query.exec(s);

    gc_Id = 0;
    while(query.next())
        gc_Id = query.value(0).toInt();

    s = "SELECT Hole.h_Id, Hole.par, Hole.strokeIndex, Hole.yards, Hole.holeNum, Hole.shape FROM GolfCourse, Hole WHERE Hole.gc_Id = "+ QString::number(gc_Id) + " AND GolfCourse.gc_Id = " + QString::number(gc_Id);

    query.exec(s);
    int i = 0;
    while(query.next())
    {
        int par = query.value(1).toInt();
        int yards = query.value(3).toInt();
        holes.append(new Hole(query.value(0).toInt(), par, query.value(2).toInt(), yards, query.value(4).toInt(), query.value(5).toString()));
        SIList[i]->setText(query.value(2).toString());
        parList[i]->setText(query.value(1).toString());
        yardList[i]->setText(query.value(3).toString());
        i++;
    }
    */
}

void AddRound::onOkButtonClicked()
{
    /*QTime t = ui->timeEdit->time();
    QDate d = ui->dateEdit->date();
    int nett = calcScore(scoreList) - player->getHandicap();
    ui->scoreTotal->setText(QString::number(nett+player->getHandicap()));

    int points = ((70-ui->scoreTotal->text().toInt()) -36)+ player->getHandicap();
    points = fabs((double)points);
    ui->puttsTotal->setText(QString::number(points));

    QString s = "INSERT INTO Round (time,date,gross,nett,stableford,weather,p_Id,gc_Id) VALUES('"+t.toString()+"', '"+d.toString("yyyy.MM.dd")+"', "+ui->scoreTotal->text()+", "+QString::number(nett)+", "+QString::number(points)+", '"+ui->comboBox->itemText(ui->comboBox->currentIndex())+"', "+QString::number(player->getPlayerId())+", "+QString::number(gc_Id)+")";
ui->lineEdit->setText(s);
    QSqlQuery query;
    query.exec(s);

    //Get RoundId of recently entered round ^^
    s = "SELECT MAX(r_Id) FROM Round";
    query.exec(s);
    int r_Id = 0;
    while(query.next())
        r_Id = query.value(0).toInt();
    //loop through the 18 holes
    for(int i = 0; i < 18; i++)
    {
        s = "INSERT INTO PlayedHole(gross, nett, points, h_Id, r_Id, fairwayHit, greenHit, sandSave, upAndDown, putts) VALUES("+scoreList[i]->text()+", "+scoreList[i]->text()+", "+scoreList[i]->text()+", "+QString::number(holes[i]->getHoleId())+", "+QString::number(r_Id)+", "+QString::number(FIRList[i]->isChecked())+", "+QString::number(GIRList[i]->isChecked())+", "+QString::number(ssList[i]->isChecked())+", "+QString::number(udList[i]->isChecked())+", "+puttsList[i]->text()+")";
        query.exec(s);
    }

    */
}

int AddRound::calcScore(QList<QLineEdit *> list)
{
    int score = 0;//this should be 0 but program adds it up 2 short of correct total???
    for(int i = 0; i < list.size(); i++)
    {
        if(list[i]->text() == "")
        {
        }
        else
        {
            score = score + list[i]->text().toInt();
        }
    }
    return score;
}

void AddRound::initializeLists()
{
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

    scoreList.append(ui->score1);
    scoreList.append(ui->score2);
    scoreList.append(ui->score3);
    scoreList.append(ui->score4);
    scoreList.append(ui->score5);
    scoreList.append(ui->score6);
    scoreList.append(ui->score7);
    scoreList.append(ui->score8);
    scoreList.append(ui->score9);
    scoreList.append(ui->score10);
    scoreList.append(ui->score11);
    scoreList.append(ui->score12);
    scoreList.append(ui->score13);
    scoreList.append(ui->score14);
    scoreList.append(ui->score15);
    scoreList.append(ui->score16);
    scoreList.append(ui->score17);
    scoreList.append(ui->score18);

    FIRList.append(ui->FIR1);
    FIRList.append(ui->FIR2);
    FIRList.append(ui->FIR3);
    FIRList.append(ui->FIR4);
    FIRList.append(ui->FIR5);
    FIRList.append(ui->FIR6);
    FIRList.append(ui->FIR7);
    FIRList.append(ui->FIR8);
    FIRList.append(ui->FIR9);
    FIRList.append(ui->FIR10);
    FIRList.append(ui->FIR11);
    FIRList.append(ui->FIR12);
    FIRList.append(ui->FIR13);
    FIRList.append(ui->FIR14);
    FIRList.append(ui->FIR15);
    FIRList.append(ui->FIR16);
    FIRList.append(ui->FIR17);
    FIRList.append(ui->FIR18);

    GIRList.append(ui->GIR1);
    GIRList.append(ui->GIR2);
    GIRList.append(ui->GIR3);
    GIRList.append(ui->GIR4);
    GIRList.append(ui->GIR5);
    GIRList.append(ui->GIR6);
    GIRList.append(ui->GIR7);
    GIRList.append(ui->GIR8);
    GIRList.append(ui->GIR9);
    GIRList.append(ui->GIR10);
    GIRList.append(ui->GIR11);
    GIRList.append(ui->GIR12);
    GIRList.append(ui->GIR13);
    GIRList.append(ui->GIR14);
    GIRList.append(ui->GIR15);
    GIRList.append(ui->GIR16);
    GIRList.append(ui->GIR17);
    GIRList.append(ui->GIR18);

    udList.append(ui->ud1);
    udList.append(ui->ud2);
    udList.append(ui->ud3);
    udList.append(ui->ud4);
    udList.append(ui->ud5);
    udList.append(ui->ud6);
    udList.append(ui->ud7);
    udList.append(ui->ud8);
    udList.append(ui->ud9);
    udList.append(ui->ud10);
    udList.append(ui->ud11);
    udList.append(ui->ud12);
    udList.append(ui->ud13);
    udList.append(ui->ud14);
    udList.append(ui->ud15);
    udList.append(ui->ud16);
    udList.append(ui->ud17);
    udList.append(ui->ud18);

    ssList.append(ui->ss1);
    ssList.append(ui->ss2);
    ssList.append(ui->ss3);
    ssList.append(ui->ss4);
    ssList.append(ui->ss5);
    ssList.append(ui->ss6);
    ssList.append(ui->ss7);
    ssList.append(ui->ss8);
    ssList.append(ui->ss9);
    ssList.append(ui->ss10);
    ssList.append(ui->ss11);
    ssList.append(ui->ss12);
    ssList.append(ui->ss13);
    ssList.append(ui->ss14);
    ssList.append(ui->ss15);
    ssList.append(ui->ss16);
    ssList.append(ui->ss17);
    ssList.append(ui->ss18);

    puttsList.append(ui->putts1);
    puttsList.append(ui->putts2);
    puttsList.append(ui->putts3);
    puttsList.append(ui->putts4);
    puttsList.append(ui->putts5);
    puttsList.append(ui->putts6);
    puttsList.append(ui->putts7);
    puttsList.append(ui->putts8);
    puttsList.append(ui->putts9);
    puttsList.append(ui->putts10);
    puttsList.append(ui->putts11);
    puttsList.append(ui->putts12);
    puttsList.append(ui->putts13);
    puttsList.append(ui->putts14);
    puttsList.append(ui->putts15);
    puttsList.append(ui->putts16);
    puttsList.append(ui->putts17);
    puttsList.append(ui->putts18);
}
