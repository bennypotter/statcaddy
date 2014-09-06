#ifndef PLOTTERSETTINGS_H
#define PLOTTERSETTINGS_H

class PlotSettings
{
public:
    PlotSettings();

    void scroll(int dx, int dy);
    void adjust();
    double spanX() const {return maxX - minX;}
    double spanY() const {return maxY - minY;}

    double minX; //X axis start
    double maxX; //X axis finsih
    int numXTicks; // X axis interval
    double minY;
    double maxY;
    int numYTicks;

private:
    static void adjustAxis(double &min, double &max, int &numTicks);
};

#endif // PLOTTERSETTINGS_H
