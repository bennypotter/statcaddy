#include "include/piechart.h"
#include <QtGui>

PieChart::PieChart(QWidget *parent) :
    QWidget(parent)
{
}

PieChart::~PieChart()
{
    //delete ui;
}

void PieChart::addEntry(const QString& key, int val)
{
    values.insert(key, val);
}

void PieChart::paintEvent(QPaintEvent * /*ev*/)
{

    QHash<QString, int>::const_iterator it;
    int total = 0;
    for(it = values.begin(); it != values.end(); ++it)
    total += it.value();

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);

    QStringList colorNames = QColor::colorNames();
    int colorPos = 13;
    int height = rect().height();
    QRect pieRect(0, 0, height, height);

    QRect legendRect = rect();
    legendRect.setLeft(pieRect.width());
    legendRect.adjust(10,10,-10,-10);
    int lastAngleOffset = 0;
    int currentPos = 0;

    for(it = values.begin(); it != values.end(); ++it)
    {
        int value = it.value();
        QString text = it.key();
        int angle = (int)(16*360*(value/(double)total));
        QColor col(colorNames.at(colorPos%colorNames.count()));
        colorPos++;

        QRadialGradient rg(pieRect.center(), pieRect.width()/2,
        pieRect.topLeft());
        rg.setColorAt(0, Qt::white);
        rg.setColorAt(1, col);
        p.setBrush(rg);
        QPen pen = p.pen();
        p.setPen(Qt::NoPen);

        p.drawPie(pieRect, lastAngleOffset, angle);
        lastAngleOffset += angle;

        int fh = fontMetrics().height();
        QRect legendEntryRect(0,(fh*2)*currentPos,fh,fh);
        currentPos++;
        legendEntryRect.translate(legendRect.topLeft());

        QLinearGradient lg(legendEntryRect.topLeft(),
        legendEntryRect.bottomRight());
        lg.setColorAt(0, col);
        lg.setColorAt(1, Qt::white);
        p.setBrush(QBrush(lg));
        p.drawRect(legendEntryRect);

        QPoint textStart = legendEntryRect.topRight();
        textStart = textStart + QPoint(fontMetrics().width('x'), 0);

        QPoint textEnd(legendRect.right(), legendEntryRect.bottom());
        QRect textEntryRect(textStart, textEnd);
        p.setPen(pen);
        p.drawText(textEntryRect, Qt::AlignVCenter, text);
     }
}

QSize PieChart::sizeHint() const
{
    QSize size(640,360);
    return size;
}

