#include "include/filter.h"
#include "interface/ui_filter.h"
#include <QtSql>
#include <QStandardItemModel>
#include <QtWidgets/QMessageBox>
#include <QDebug>
#include <mainwindow.h>
/*
 * NOTE: If changes are made to the form layout the save
 * will overwrite the changes made to the original form.
 * This causes this code to fail at compilation. To fix,
 * change the namespace name to "class Filter : public Ui_Filter"
 * and the class from "Dialog to Filter"
 */



Filter::Filter(QWidget *parent, DatabaseHelper &dbh, MainWindow* main) :
    QDialog(parent),
    ui(new Ui::Filter)
{
    ui->setupUi(this);
    this->dbh = &dbh;
    this->table = table;
    fillItems();
    this->main = main;

    connect(ui->okBtn, SIGNAL(clicked()),this,SLOT(onOkBtnClicked()));
    connect(ui->cancelBtn,SIGNAL(clicked()),this,SLOT(onCancelBtnClicked()));
    connect(ui->basicBtn,SIGNAL(clicked()),this,SLOT(onBasicBtnClicked()));
    connect(ui->advancedBtn,SIGNAL(clicked()),this,SLOT(onAdvancedBtnClicked()));
    ui->positionComboBox->setVisible(false);
    ui->advancedBtn->setVisible(false);

}

Filter::~Filter()
{
    delete ui;
}

void Filter::fillItems()
{
    ui->positionComboBox->addItem("Tee");
    ui->positionComboBox->addItem("Fairway");
    ui->positionComboBox->addItem("Rough");
    ui->positionComboBox->addItem("Bunker");
    ui->positionComboBox->addItem("Green");
    ui->positionComboBox->setCurrentIndex(-1);

    ui->shapeComboBox->addItem("Straight");
    ui->shapeComboBox->addItem("Dogleg Right (Mild)");
    ui->shapeComboBox->addItem("Dogleg Right (Sharp)");
    ui->shapeComboBox->addItem("Dogleg Left (Mild)");
    ui->shapeComboBox->addItem("Dogleg Left (Sharp)");
    ui->shapeComboBox->setCurrentIndex(-1);

    LinkedList<GolfObject>* courses = dbh->getCourseList(new GolfCourse());
    ui->courseComboBox->addItem("");
    for(int i = 0; i < courses->getSize(); i++)
    {
        ui->courseComboBox->addItem(QString::fromStdString(((GolfCourse *)courses->get(i))->getName()));
    }

    //ui->courseComboBox->setCurrentIndex(-1);
}

void Filter::onOkBtnClicked()
{
    QList<QCheckBox*>weatherBoxes;
    weatherBoxes.append(ui->rainyBox);
    weatherBoxes.append(ui->windyBox);
    weatherBoxes.append(ui->sunnyBox);
    weatherBoxes.append(ui->windandrainBox);
    weatherBoxes.append(ui->foggyBox);

    LinkedList<GolfObject>* r_List;
    LinkedList<Round>* searchResults = new LinkedList<Round>();
    QString course = "";
    GolfCourse *gc;
    QString test = ui->courseComboBox->itemText(ui->courseComboBox->currentIndex());
    if((ui->courseComboBox->currentIndex() != -1) &&
            (ui->courseComboBox->itemText(ui->courseComboBox->currentIndex()) != ""))
    {
        course = ui->courseComboBox->itemText(ui->courseComboBox->currentIndex());
        dbh->getCourseByName(course.toStdString(), gc = new GolfCourse());
        r_List = dbh->getRoundsByCourse(gc->getId(), new Round());
    }
    else
    {
        r_List = new LinkedList<GolfObject>();
        for(int i = 0; i < weatherBoxes.size(); i++)
        {
            if(weatherBoxes.at(i)->isChecked())
            {
                QString weather = weatherBoxes.at(i)->text();
                LinkedList<GolfObject>* rw_List = dbh->getRoundsByWeather(weather.toStdString(), new Round());
                for(int j = 0; j < rw_List->getSize(); j++)
                {
                    r_List->addToHead(rw_List->get(j));
                }
            }
        }
    }

    //Search each weather box and see if it was checked
    for(int i = 0; i < weatherBoxes.size(); i++)
    {
        if(weatherBoxes.at(i)->isChecked())
        {
            //Look through any round with corresponding weather
            for(int j = 0; j < r_List->getSize(); j++)
            {
                //Locate in r_List
                string weather = ((Round *)r_List->get(j))->getWeather();
                if(QString::fromStdString(weather) == weatherBoxes.at(i)->text())
                    searchResults->addToHead((Round *)r_List->get(j));
            }
        }
    }

    //Now we have the rounds we can get played holes using the roundID
    LinkedList<PlayedHole>* fullPh_List = new LinkedList<PlayedHole>();
    for(int i = 0; i < searchResults->getSize(); i++)
    {
        //for every round, get the played holes.
        LinkedList<GolfObject>* ph_List = dbh->getPlayedHolesByRound(searchResults->get(i)->getId(), new PlayedHole());
        for(int j = 0; j < ph_List->getSize(); j++)
        {
            fullPh_List->addToHead((PlayedHole *)ph_List->get(j));
        }
    }

    //With the list of played holes remove any that
    //do not match our criteria
    int count = 0;
    //for(int i = 0; i < fullPh_List->getSize(); i++)
    Node<PlayedHole>* n = fullPh_List->head;
    while(n)
    {
        bool removed = false;
        Hole *h = fullPh_List->get(count)->getHole();
        if(fullPh_List->get(count)->getRound()->getId() == 636)
        {
            int test = 1;
        }
        //Populate Hole
        dbh->getHoleById(h->getId(), h);
        QString sshape = QString::fromStdString(h->getShape());
        //Filter By;
        //Par
        if(ui->parSpinBox->text() != "0")
        {
            int par = ui->parSpinBox->text().toInt();
            if(h->getPar() != par)
            {
                n = n->next;
                //int hn = n->data->getHole()->getHoleNum();
                //int hp = n->data->getHole()->getPar();
                fullPh_List->deleteNode(count);
                removed = true;
            }
        }

        if(!removed)
        {
            //Distance a To b
            //Stroke Index
            if(ui->strokeindexSpinBox->text() != "0")
            {
                int si = ui->strokeindexSpinBox->text().toInt();
                if(h->getStrokeIndex() != si)
                {
                    n = n->next;
                    fullPh_List->deleteNode(count);
                    removed = true;
                }
            }
        }

        if(!removed)
        {
            //Hole shape
            if(ui->shapeComboBox->currentIndex() != -1)
            {
                QString holeShape = ui->shapeComboBox->itemText(ui->shapeComboBox->currentIndex());
                if(holeShape.toStdString() != h->getShape())
                {
                    n = n->next;
                    fullPh_List->deleteNode(count);
                    removed = true;
                }
            }
        }

        //Fairways
        if(!removed)
        {
           if(ui->firCheckBox->isChecked())
           {
               if(!fullPh_List->get(count)->isFairwayHit())
               {
                   n = n->next;
                   fullPh_List->deleteNode(count);
                   removed = true;
               }
           }
        }

        if(!removed)
        {
           if(ui->girCheckBox->isChecked())
           {
               if(!fullPh_List->get(count)->isGreenHit())
               {
                   n = n->next;
                   fullPh_List->deleteNode(count);
                   removed = true;
               }
           }
        }

        if(!removed)
        {
           if(ui->udCheckBox->isChecked())
           {
               if(!fullPh_List->get(count)->isUpAndDown())
               {
                   n = n->next;
                   fullPh_List->deleteNode(count);
                   removed = true;
               }
           }
        }

        if(!removed)
        {
           if(ui->sandsaveCheckBox->isChecked())
           {
               if(!fullPh_List->get(count)->isSandSave())
               {
                   n = n->next;
                   fullPh_List->deleteNode(count);
                   removed = true;
               }
           }
        }

        if(!removed)
        {
            //hole distance
            int from = ui->distanceSpinBox_1->text().toInt();
            int to = ui->distanceSpinBox_2->text().toInt();
            if(h->getYards() < from || h->getYards() > to)
            {
                n = n->next;
                fullPh_List->deleteNode(count);
                removed = true;
            }
        }

        if(!removed)
        {
            if(ui->puttsSpinBox->text().toInt() != -1)
            {
                int numPutts = ui->puttsSpinBox->text().toInt();
                if(numPutts != fullPh_List->get(count)->getPutts())
                {
                    n = n->next;
                    fullPh_List->deleteNode(count);
                    removed = true;
                }
            }
        }

        if(!removed)
        {
            count++;
            n = n->next;
        }

    }
    //use hole list to match search criteria against played holes.
    main->setRoundList((LinkedList<GolfObject> *)searchResults);
    main->setPlayedHolesList((LinkedList<GolfObject> *)fullPh_List);
    main->getRoundWidget()->setRowCount(searchResults->getSize());
    main->getRoundWidget()->setColumnCount(6);
    main->getRoundWidget()->setHorizontalHeaderItem(0, new QTableWidgetItem("Date"));
    main->getRoundWidget()->setHorizontalHeaderItem(1, new QTableWidgetItem("Time"));
    main->getRoundWidget()->setHorizontalHeaderItem(2, new QTableWidgetItem("Weather"));
    main->getRoundWidget()->setHorizontalHeaderItem(3, new QTableWidgetItem("Gross"));
    main->getRoundWidget()->setHorizontalHeaderItem(4, new QTableWidgetItem("Nett"));
    main->getRoundWidget()->setHorizontalHeaderItem(5, new QTableWidgetItem("Stableford"));

    for(int i = 0 ; i < searchResults->getSize(); i++)
    {
        main->getRoundWidget()->setItem(i,0, new QTableWidgetItem(QString::fromStdString(((Round *)searchResults->get(i))->getDate())));
        main->getRoundWidget()->setItem(i,1, new QTableWidgetItem(QString::fromStdString(((Round *)searchResults->get(i))->getTime())));
        main->getRoundWidget()->setItem(i,2, new QTableWidgetItem(QString::fromStdString(((Round *)searchResults->get(i))->getWeather())));
        main->getRoundWidget()->setItem(i,3, new QTableWidgetItem(QString::number(((Round *)searchResults->get(i))->getGross())));
        main->getRoundWidget()->setItem(i,4, new QTableWidgetItem(QString::number(((Round *)searchResults->get(i))->getNett())));
        main->getRoundWidget()->setItem(i,5, new QTableWidgetItem(QString::number(((Round *)searchResults->get(i))->getPoints())));
    }
    //table->resizeColumnsToContents();
    main->getRoundWidget()->setSelectionBehavior(QAbstractItemView::SelectRows);
    main->getRoundWidget()->resizeColumnsToContents();
    main->getRoundWidget()->setEditTriggers(QAbstractItemView::NoEditTriggers);
    main->filterOn = true;

    /*
    QMessageBox *msgBox = new QMessageBox();
    msgBox->setWindowTitle("I Worked!!");
    msgBox->setInformativeText(s+" "+QString::number(size));
    msgBox->show();
    */
    this->close();

}

void Filter::onCancelBtnClicked()
{
    this->close();
}

void Filter::onBasicBtnClicked()
{

}

void Filter::onAdvancedBtnClicked()
{

}
