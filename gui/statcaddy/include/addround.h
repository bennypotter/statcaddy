#ifndef ADDROUND_H
#define ADDROUND_H

#include <QtWidgets/QDialog>
#include <QSqlDatabase>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>

namespace Ui {
class AddRound;
}

class AddRound : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddRound(QWidget *parent, QSqlDatabase db/*, Player *player*/);
    ~AddRound();
    int calcScore(QList<QLineEdit*> list);
    void initializeLists();

public slots:
    void onCourseComboIndexChanged();
    void onOkButtonClicked();

    
private:
    Ui::AddRound *ui;
    QList<QLabel*> parList;
    QList<QLabel*> SIList;
    QList<QLabel*> yardList;
    QList<QLineEdit*> scoreList;
    QList<QCheckBox*> FIRList;
    QList<QCheckBox*> GIRList;
    QList<QCheckBox*> udList;
    QList<QCheckBox*> ssList;
    QList<QLineEdit*> puttsList;
    //Player *player;
    QSqlDatabase db;
    int gc_Id;
    //QList<Hole*> holes;
};

#endif // ADDROUND_H
