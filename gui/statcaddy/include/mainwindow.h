#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QMainWindow>
#include <QtWidgets/QMainWindow>
//#include <QtSql>
//#include <QMessageBox>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTableWidget>
#include "databasehelper.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     bool createConnection();
     void buildHome();
     bool filterOn;
     LinkedList<GolfObject>* getPlayedHolesList();
     void setPlayedHolesList(LinkedList<GolfObject>* playedHoleList);
     LinkedList<GolfObject>* getRoundList();
     void setRoundList(LinkedList<GolfObject>* roundList);
     QTableWidget* getRoundWidget();

public slots:
    void onPlayerClick();
    void onAddCourseClick();
    void onAddRoundClick();
    void onDatabaseDialogClick();
    void onRoundTableViewClick();
    void onHoleTableViewClick();
    void onTabWidgetChange();
    void onReportsTabChange();
    void onFilterBtnClicked();
    void onRefreshButtonClicked();//toolButton4

private:
    Ui::MainWindow *ui;
    Player *p;
    DatabaseHelper *dbh;
    LinkedList<GolfObject>* roundList;
    LinkedList<GolfObject>* playedHoleList;

};

#endif // MAINWINDOW_H
