#ifndef PIECHART_H
#define PIECHART_H

#include <QtWidgets/QWidget>
#include <QHash>

class PieChart : public QWidget
{
    Q_OBJECT
    
public:
    PieChart(QWidget *parent = 0);
    ~PieChart();
    QSize sizeHint() const;

    void addEntry(const QString& key, int val);

protected:
    void paintEvent(QPaintEvent *ev);

private:
    QHash<QString, int> values;
};

#endif
