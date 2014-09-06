#ifndef ADDCOURSE_H
#define ADDCOURSE_H

#include <QtWidgets/QDialog>
//#include <QSqlDatabase>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QVector>

namespace Ui {
class AddCourse;
}

class AddCourse : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddCourse(QWidget *parent, QSqlDatabase db);
    ~AddCourse();


public slots:
    void onOKBtnClicked();
    void setCombos(QComboBox*);

    
private:
    Ui::AddCourse *ui;
    QSqlDatabase db;
    QList<QLineEdit*> parList;
    QList<QLineEdit*> SIList;
    QList<QLineEdit*> yardList;
    QList<QComboBox*> comboList;
};

#endif // ADDCOURSE_H
