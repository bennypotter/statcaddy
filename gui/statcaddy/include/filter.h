#ifndef FILTER_H
#define FILTER_H

#include <QtWidgets/QDialog>
#include <QVector>
#include <QtWidgets/QCheckBox>
#include <DatabaseHelper.h>
#include <QtWidgets/QTableWidget>

class MainWindow;

namespace Ui {
class Filter;
}

class Filter : public QDialog
{
    Q_OBJECT

public:
    explicit Filter(QWidget *parent, DatabaseHelper &dbh, MainWindow* main);
    ~Filter();

private:
    Ui::Filter *ui;
    DatabaseHelper *dbh;
    QTableWidget *table;
    void fillItems();
    MainWindow *main;

public slots:
    void onOkBtnClicked();
    void onCancelBtnClicked();
    void onBasicBtnClicked();
    void onAdvancedBtnClicked();
};

#endif // FILTER_H
