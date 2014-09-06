#ifndef DATABASEDIALOG_H
#define DATABASEDIALOG_H

#include <QtWidgets/QDialog>
#include <QSqlDatabase>

namespace Ui {
class DatabaseDialog;
}

class DatabaseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DatabaseDialog(QWidget *parent, QSqlDatabase db);
    ~DatabaseDialog();
    
private:
    Ui::DatabaseDialog *ui;
    QSqlDatabase db;
};

#endif // DATABASEDIALOG_H
