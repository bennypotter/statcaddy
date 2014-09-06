#ifndef PLOTTER_H
#define PLOTTER_H

#include <QtWidgets/QWidget>
#include <QMap>
#include <QPixmap>
#include <QVector>
#include <QtWidgets/QToolButton>
#include "PlotterSettings.h"

//class QToolButton;
//class PlotSettings;

class Plotter : public QWidget
{
    Q_OBJECT
    
public:
    Plotter(QWidget *parent = 0);

    void setPlotSettings(const PlotSettings &settings);
    void setCurveData(int id, const QVector<QPointF> &data);
    void clearCurve(int id);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void wheelEvent(QWheelEvent *);

private:
    void updateRubberBandRegion();
    void refreshPixmap(); //Updates the display
    void drawGrid(QPainter *painter);
    void drawCurves(QPainter *painter);

    enum {Margin = 50 };

    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QMap<int, QVector<QPointF> > curveMap; //Stores x/y coords
    QVector<PlotSettings> zoomStack; //Holds all the current zoom settings in a vector so you can zoom in and out
    int curZoom; //Holds the current index for the zoomStack vector
    bool rubberBandIsShown;
    QRect rubberBandRect;// region to be zoomed in on via the click and drag
    QPixmap pixmap; //Image is placed here before displayed onto screen (double buffering technique)
};

#endif
