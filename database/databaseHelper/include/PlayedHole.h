#ifndef PLAYEDHOLE_H
#define PLAYEDHOLE_H

#include <GolfObject.h>
#include <Hole.h>
#include <Round.h>

class PlayedHole : public GolfObject
{
    public:
        PlayedHole();
        PlayedHole(int);
        PlayedHole(int, int&, int&, int&, Hole*, Round*, bool&, bool&, bool&, bool&, int&);
        virtual ~PlayedHole();
        int getGross();
        void setGross(int&);
        int getNett();
        void setNett(int&);
        int getPoints();
        void setPoints(int&);
        Hole* getHole();
        void setHole(Hole*);
        Round* getRound();
        void setRound(Round*);
        bool isFairwayHit();
        void isFairwayHit(bool&);
        bool isGreenHit();
        void isGreenHit(bool&);
        bool isSandSave();
        void isSandSave(bool&);
        bool isUpAndDown();
        void isUpAndDown(bool&);
        int getPutts();
        void setPutts(int&);
        void makeFromQuery(int, char**, LinkedList<GolfObject>* g);
        virtual bool operator==(GolfObject*);
    protected:
    private:
        int gross;
        int nett;
        int points;
        Hole *pHole;
        Round *pRound;
        bool fairwayHit;
        bool greenHit;
        bool sandSave;
        bool upAndDown;
        int putts;
};

#endif // PLAYEDHOLE_H
