#include "include/mainwindow.h"
#include "interface/ui_mainwindow.h"
#include "include/addplayer.h"
#include "include/addcourse.h"
#include "include/addround.h"
#include "include/databasedialog.h"
#include "include/filter.h"
#include <QStandardItemModel>
#include <QtWidgets/QMessageBox>
#include <QtGui>
#include <QtWidgets/QListView>
#include <DatabaseHelper.h>
#include <Round.h>
#include <LinkedList.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->createConnection();
    connect(ui->toolButton_8, SIGNAL(clicked()), this, SLOT(onPlayerClick()));
    connect(ui->toolButton_11, SIGNAL(clicked()), this, SLOT(onAddCourseClick()));
    connect(ui->toolButton_10, SIGNAL(clicked()), this, SLOT(onAddRoundClick()));
    connect(ui->toolButton_5, SIGNAL(clicked()), this, SLOT(onDatabaseDialogClick()));
    connect(ui->tableWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(onRoundTableViewClick()));
    connect(ui->tableWidget_2, SIGNAL(clicked(QModelIndex)), this, SLOT(onHoleTableViewClick()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabWidgetChange()));
    connect(ui->reportsTab, SIGNAL(currentChanged(int)), this, SLOT(onReportsTabChange()));
    connect(ui->filterBtn,SIGNAL(clicked()),this, SLOT(onFilterBtnClicked()));
    connect(ui->toolButton_4, SIGNAL(clicked()), this, SLOT(onRefreshButtonClicked()));

    filterOn = false;
    /***********************************************************************************************************************************
     * This loads the player for the program.
     * NOTE:This is hard coded to one and must be changed
     */
    dbh = new DatabaseHelper();
    dbh->connect("statcaddy_db");

    p = new Player();
    dbh->getPlayerById(1, p);

    p->setDatabase(*dbh);
    ui->label_6->setText(QString::fromStdString(p->getFirstname()) + " " + QString::fromStdString(p->getSurname()));
    ui->label_5->setText(QString::number(p->getHandicap()));

    LinkedList<GolfObject>* list = p->getRounds(p->getId(), new Round());

    ui->label_4->setText(QString::number(list->getSize()));
    delete list;
    buildHome();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::createConnection()
{
    /*db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("statcaddy_db");
    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),
        db.lastError().text());
        return false;
    }
    return true;*/
}

LinkedList<GolfObject>* MainWindow::getPlayedHolesList()
{
    return playedHoleList;
}

void MainWindow::setPlayedHolesList(LinkedList<GolfObject> *playedHoleList)
{
    this->playedHoleList = playedHoleList;
}

LinkedList<GolfObject>* MainWindow::getRoundList()
{
    return roundList;
}

void MainWindow::setRoundList(LinkedList<GolfObject>* roundList)
{
    this->roundList = roundList;
}

QTableWidget* MainWindow::getRoundWidget()
{
    return ui->tableWidget;
}

void MainWindow::buildHome()
{
    LinkedList<GolfObject>* list = p->getRounds(p->getId(), new Round());
    int fairwayCount = 0, greenCount = 0, sandCount =0, updownCount = 0,
            albatrossCount = 0, eagleCount = 0, birdieCount = 0, parCount = 0,
            bogeyCount = 0, dblBogeyCount = 0, trplBogeyCount = 0, quadBogeyCount = 0,
            fiveBogeyCount = 0, sixBogeyCount = 0, px = 0, pxx = 0, pxxx = 0, pxxxx = 0, pxxxxx = 0, pxxxxxx= 0;

    for(int i = 0; i < list->getSize(); i++)
    {
        Round *r = (Round *)list->get(i);
        LinkedList<GolfObject>* phList = p->getPlayedHoles(r->getId());
        for(int j = 0; j < phList->getSize(); j++)
        {
            PlayedHole *ph = (PlayedHole *)phList->get(j);
            Hole *h = new Hole();
            dbh->getHoleById(ph->getHole()->getId(), h);
            if(ph->isFairwayHit())
              fairwayCount++;
            if(ph->isGreenHit())
                greenCount++;
            if(ph->isSandSave())
                sandCount++;
            if(ph->isUpAndDown())
                updownCount++;

            int grossVal = ph->getGross() - h->getPar();
            switch(grossVal)
            {
                case -3:
                    albatrossCount++;
                    break;
                case -2:
                    eagleCount++;
                    break;
                case -1:
                    birdieCount++;
                case 0:
                    parCount++;
                    break;

                case 1:
                    bogeyCount++;
                    break;

                case 2:
                    dblBogeyCount++;
                    break;

                case 3:
                    trplBogeyCount++;
                    break;
                case 4:
                    quadBogeyCount++;
                    break;
                case 5:
                    fiveBogeyCount++;
                    break;
                case 6:
                    sixBogeyCount++;
                    break;
            }

            int puttVal = ph->getPutts();
            switch(puttVal)
            {
            case 1:
                px++;
                break;
            case 2:
                pxx++;
                break;
            case 3:
                pxxx++;
                break;
            case 4:
                pxxxx++;
                break;
            case 5:
                pxxxxx++;
                break;
            case 6:
                pxxxxxx++;
                break;
            }

        }
        delete phList;
    }


    double total = fairwayCount+greenCount+sandCount+updownCount;
    ui->statsChart->addEntry("FIR "+QString::number(((double)fairwayCount/total)*100), fairwayCount);
    ui->statsChart->addEntry("GIR "+QString::number(((double)greenCount/total)*100), greenCount);
    ui->statsChart->addEntry("Sand Save "+QString::number(((double)sandCount/total)*100), sandCount);
    ui->statsChart->addEntry("Up + Down "+QString::number(((double)updownCount/total)*100), updownCount);
    //ui->statsChart->setMaximumSize(100,100);
    ui->statsChart->show();

    total = albatrossCount+eagleCount+birdieCount+parCount+bogeyCount+dblBogeyCount+trplBogeyCount+quadBogeyCount+fiveBogeyCount+sixBogeyCount;
    ui->scores_Chart->addEntry("Albatross "+QString::number(((double)albatrossCount/total)*100), albatrossCount);
    ui->scores_Chart->addEntry("Eagle "+QString::number(((double)eagleCount/total)*100), eagleCount);
    ui->scores_Chart->addEntry("Birdie "+QString::number(((double)birdieCount/total)*100), birdieCount);
    ui->scores_Chart->addEntry("Par "+QString::number(((double)parCount/total)*100), parCount);
    ui->scores_Chart->addEntry("Bogey "+QString::number(((double)bogeyCount/total)*100), bogeyCount);
    ui->scores_Chart->addEntry("Dbl Bogey "+QString::number(((double)dblBogeyCount/total)*100), dblBogeyCount);
    ui->scores_Chart->addEntry("Trpl Bogey "+QString::number(((double)trplBogeyCount/total)*100), trplBogeyCount);
    ui->scores_Chart->addEntry("Quad Bogey "+QString::number(((double)quadBogeyCount/total)*100), quadBogeyCount);
    ui->scores_Chart->addEntry("Five Bogey "+QString::number(((double)fiveBogeyCount/total)*100), fiveBogeyCount);
    ui->scores_Chart->addEntry("Six Bogey "+QString::number(((double)sixBogeyCount/total)*100), sixBogeyCount);
    //ui->scores_Chart->setMaximumSize(100,100);
    ui->scores_Chart->show();

    ui->putts_Chart->addEntry("1 Putts", px);
    ui->putts_Chart->addEntry("2 Putts", pxx);
    ui->putts_Chart->addEntry("3 Putts", pxxx);
    ui->putts_Chart->addEntry("4 Putts", pxxxx);
    ui->putts_Chart->addEntry("5 Putts", pxxxxx);
    ui->putts_Chart->addEntry("6 Putts", pxxxxxx);
    //ui->putts_Chart->addEntry("7 Putts", pxxxxxxx);
    ui->putts_Chart->show();
}

void MainWindow::onPlayerClick()
{
    /*AddPlayer *ap = new AddPlayer(this, db);
    ap->show();*/
}

void MainWindow::onAddCourseClick()
{
    /*AddCourse *ac = new AddCourse(this, db);
    ac->show();*/
}

void MainWindow::onAddRoundClick()
{
    /*AddRound *ar = new AddRound(this, db, player);
    ar->show();*/
}

void MainWindow::onDatabaseDialogClick()
{
    /*DatabaseDialog *dd = new DatabaseDialog(this, db);
    dd->show();*/
}

void MainWindow::onFilterBtnClicked()
{
    Filter *fd = new Filter(this, *dbh, this);
    fd->show();
}

void MainWindow::onTabWidgetChange()
{
    switch(ui->tabWidget->currentIndex())
    {
        case 1:
        {
           /*
             * Select all scores from round belonging to specified player
             *
             * NOTE: player ID is hardcoded to 1...this need to be changed
             * for multiplayer DB
             */
            QVector<QPointF> data;

            LinkedList<GolfObject>* r_list = this->p->getRounds(this->p->getId(), new Round());

            int count = 0;
            for(int i = r_list->getSize()-1; i > -1; i--)
            {

                int score = ((Round *)r_list->get(i))->getGross();
                QPointF point;
                point.setX(count);
                point.setY(score);
                data.push_back(point);
                count++;
            }

            /*
             * NOTE: 0 = gross scores
             */

            ui->plotter->setCurveData(0, data);
            break;
        }
    }
}

void MainWindow::onReportsTabChange()
{
    /*
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setWindowTitle("I Worked!!");
    msgBox->setInformativeText("The Current index tab is "+ QString::number(ui->reportsTab->currentIndex()));
    msgBox->show();
    */

    switch(ui->reportsTab->currentIndex())
    {
        case 0:
        {
        QVector<QPointF> data;

        LinkedList<GolfObject>* r_list = this->p->getRounds(this->p->getId(), new Round());

        int count = 0;
        for(int i = r_list->getSize()-1; i > -1; i--)
        {

            int score = ((Round *)r_list->get(i))->getGross();
            QPointF point;
            point.setX(count);
            point.setY(score);
            data.push_back(point);
            count++;
        }

        /*
         * NOTE: 0 = gross scores
         */

        ui->plotter->setCurveData(0, data);
        break;
        }

        /***********************************************************************************************************************************
        * This loads the first tableview of rounds tab.
        * One reason for it not updating when a new round is added could be due to the code location here
        */
        case 1:
        {
            LinkedList<GolfObject>* r_List;
            if(!filterOn)
            {
                r_List = p->getRounds(p->getId(), new Round());
            }
            else
            {
                r_List = getRoundList();
            }

            ui->tableWidget->setRowCount(r_List->getSize());
            ui->tableWidget->setColumnCount(6);
            ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Date"));
            ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Time"));
            ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Weather"));
            ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Gross"));
            ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Nett"));
            ui->tableWidget->setHorizontalHeaderItem(5, new QTableWidgetItem("Stableford"));

            for(int i = 0 ; i < r_List->getSize(); i++)
            {
                ui->tableWidget->setItem(i,0, new QTableWidgetItem(QString::fromStdString(((Round *)r_List->get(i))->getDate())));
                ui->tableWidget->setItem(i,1, new QTableWidgetItem(QString::fromStdString(((Round *)r_List->get(i))->getTime())));
                ui->tableWidget->setItem(i,2, new QTableWidgetItem(QString::fromStdString(((Round *)r_List->get(i))->getWeather())));
                ui->tableWidget->setItem(i,3, new QTableWidgetItem(QString::number(((Round *)r_List->get(i))->getGross())));
                ui->tableWidget->setItem(i,4, new QTableWidgetItem(QString::number(((Round *)r_List->get(i))->getNett())));
                ui->tableWidget->setItem(i,5, new QTableWidgetItem(QString::number(((Round *)r_List->get(i))->getPoints())));
            }

            QHeaderView* header = ui->tableWidget->horizontalHeader();
            header->setSectionResizeMode(QHeaderView::Stretch);

        break;
        }

    }
}


/*
 * When the round table viewer is clicked we display the hole stats for that round below
 */
void MainWindow::onRoundTableViewClick()
{
    LinkedList<GolfObject>* r_List = p->getRounds(p->getId(), new Round());

    ui->tableWidget_2->setColumnCount(11);
    ui->tableWidget_2->setHorizontalHeaderItem(0, new QTableWidgetItem("Hole ID"));
    ui->tableWidget_2->setHorizontalHeaderItem(1, new QTableWidgetItem("Hole"));
    ui->tableWidget_2->setHorizontalHeaderItem(2, new QTableWidgetItem("Par"));
    ui->tableWidget_2->setHorizontalHeaderItem(3, new QTableWidgetItem("Gross"));
    ui->tableWidget_2->setHorizontalHeaderItem(4, new QTableWidgetItem("Nett"));
    ui->tableWidget_2->setHorizontalHeaderItem(5, new QTableWidgetItem("Stableford"));
    ui->tableWidget_2->setHorizontalHeaderItem(6, new QTableWidgetItem("Fariway"));
    ui->tableWidget_2->setHorizontalHeaderItem(7, new QTableWidgetItem("Green"));
    ui->tableWidget_2->setHorizontalHeaderItem(8, new QTableWidgetItem("Up and Down"));
    ui->tableWidget_2->setHorizontalHeaderItem(9, new QTableWidgetItem("Sand Save"));
    ui->tableWidget_2->setHorizontalHeaderItem(10, new QTableWidgetItem("Putts"));


    ui->tableWidget_2->setColumnHidden(0, true);
    ui->tableWidget_2->setColumnHidden(1, true);
    ui->tableWidget_2->setColumnHidden(2, true);


    //Get played holes
    int itemIndex = ui->tableWidget->currentIndex().row();
    LinkedList<GolfObject>* ph_List;

    if(!filterOn)
    {
        Round *r = (Round *)r_List->get(itemIndex);
        ph_List = p->getPlayedHoles(r->getId());

    }
    else
    {
        ui->tableWidget_2->setColumnHidden(0, false);
        ui->tableWidget_2->setColumnHidden(1, false);
        ui->tableWidget_2->setColumnHidden(2, false);
        Round *r = (Round *)getRoundList()->get(itemIndex);
        ph_List = new LinkedList<GolfObject>();
        LinkedList<GolfObject>* tempList = getPlayedHolesList();
        for(int i = 0; i < tempList->getSize(); i++)
        {
            int playedHoleRoundID = ((PlayedHole *)tempList->get(i))->getRound()->getId();
            if(r->getId() == playedHoleRoundID)
            {
                ph_List->addToHead(tempList->get(i));
                int thisPar = ((PlayedHole *)tempList->get(i))->getHole()->getPar();
                thisPar = thisPar;
            }
        }
    }
    delete r_List;

    ui->tableWidget_2->setRowCount(ph_List->getSize());
    int indexCount = 0;
    for(int j = ph_List->getSize()-1; j > -1; j--)
    {
        ui->tableWidget_2->setItem(indexCount,3, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->getGross())));
        ui->tableWidget_2->setItem(indexCount,4, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->getNett())));
        ui->tableWidget_2->setItem(indexCount,5, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->getPoints())));
        ui->tableWidget_2->setItem(indexCount,6, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->isFairwayHit())));
        ui->tableWidget_2->setItem(indexCount,7, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->isGreenHit())));
        ui->tableWidget_2->setItem(indexCount,8, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->isUpAndDown())));
        ui->tableWidget_2->setItem(indexCount,9, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->isSandSave())));
        ui->tableWidget_2->setItem(indexCount,10, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->getPutts())));

        if(filterOn)
        {
            ui->tableWidget_2->setItem(indexCount,0, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->getHole()->getId())));
            ui->tableWidget_2->setItem(indexCount,1, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->getHole()->getHoleNum())));
            ui->tableWidget_2->setItem(indexCount,2, new QTableWidgetItem(QString::number(((PlayedHole *)ph_List->get(j))->getHole()->getPar())));
        }
        indexCount++;

    }
    delete ph_List;

    QHeaderView* header = ui->tableWidget_2->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::onHoleTableViewClick()
{
    ui->tableWidget_3->setColumnCount(6);
    ui->tableWidget_3->setHorizontalHeaderItem(0, new QTableWidgetItem("Started From"));
    ui->tableWidget_3->setHorizontalHeaderItem(1, new QTableWidgetItem("Lie Type"));
    ui->tableWidget_3->setHorizontalHeaderItem(2, new QTableWidgetItem("Wind Direction"));
    ui->tableWidget_3->setHorizontalHeaderItem(3, new QTableWidgetItem("Club"));
    ui->tableWidget_3->setHorizontalHeaderItem(4, new QTableWidgetItem("Going for Green"));
    ui->tableWidget_3->setHorizontalHeaderItem(5, new QTableWidgetItem("Result"));

    int r_itemIndex = ui->tableWidget->currentIndex().row();
    int ph_itemIndex = ui->tableWidget_2->currentIndex().row();

    LinkedList<GolfObject>* r_List = p->getRounds(p->getId(), new Round());
    Round *r = (Round *)r_List->get(r_itemIndex);
    LinkedList<GolfObject>* ph_List = p->getPlayedHoles(r->getId());
    delete r_List;
    PlayedHole *ph = (PlayedHole *)ph_List->get(ph_itemIndex);
    LinkedList<GolfObject>* s_List = dbh->getShotsByPlayedHole(ph->getId(), new Shot());
    delete ph_List;
    ui->tableWidget_3->setRowCount(s_List->getSize());

    int indexCount = 0;
    for(int i = s_List->getSize()-1; i > -1; i--)
    {
        ui->tableWidget_3->setItem(indexCount,0, new QTableWidgetItem(QString::fromStdString(((Shot *)s_List->get(i))->getStart())));
        ui->tableWidget_3->setItem(indexCount,1, new QTableWidgetItem(QString::fromStdString(((Shot *)s_List->get(i))->getLie())));
        ui->tableWidget_3->setItem(indexCount,2, new QTableWidgetItem(QString::fromStdString(((Shot *)s_List->get(i))->getWind())));
        ui->tableWidget_3->setItem(indexCount,3, new QTableWidgetItem(QString::fromStdString(((Shot *)s_List->get(i))->getClub())));
        ui->tableWidget_3->setItem(indexCount,4, new QTableWidgetItem(QString::number(((Shot *)s_List->get(i))->didGoForGreen())));
        ui->tableWidget_3->setItem(indexCount,5, new QTableWidgetItem(QString::fromStdString(((Shot *)s_List->get(i))->getFinish())));
        indexCount++;
    }
    delete s_List;

    QHeaderView* header = ui->tableWidget_3->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::onRefreshButtonClicked()
{
    if(filterOn)
    {
        filterOn = false;

        while (ui->tableWidget_2->rowCount() > 0)
        {
            ui->tableWidget_2->removeRow(0);
        }

        while (ui->tableWidget_3->rowCount() > 0)
        {
            ui->tableWidget_3->removeRow(0);
        }
        delete this->getPlayedHolesList();
        delete this->getRoundList();

        ui->tableWidget_2->setColumnHidden(0, true);
        ui->tableWidget_2->setColumnHidden(1, true);
        ui->tableWidget_2->setColumnHidden(2, true);

        onReportsTabChange();
    }
}
