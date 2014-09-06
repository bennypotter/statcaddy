#ifndef ADDPLAYER_H
#define ADDPLAYER_H

#include <QtWidgets/QDialog>
#include <QtSql>
#include <QtWidgets/QMessageBox>

namespace Ui {
class AddPlayer;
}

class AddPlayer : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddPlayer(QWidget *parent, QSqlDatabase db);
    ~AddPlayer();



public slots:
    void onOkButtonClicked();
    
private:
    Ui::AddPlayer *ui;
    QSqlDatabase db;
};

#endif // ADDPLAYER_H
