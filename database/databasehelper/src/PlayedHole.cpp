#include "PlayedHole.h"

PlayedHole::PlayedHole()
{
    //ctor
}

PlayedHole::PlayedHole(int id) : GolfObject(id){}

PlayedHole::PlayedHole(int id, int& gross, int& nett, int& points,
                         Hole *pHole, Round *pRound, bool& fairway, bool& green,
                         bool& sand, bool& upAndDown, int& putts) : GolfObject(id)
{
    this->gross = gross;
    this->nett = nett;
    this->points = points;
    this->pHole = pHole;
    this->pRound = pRound;
    this->fairwayHit = fairway;
    this->greenHit = green;
    this->sandSave = sand;
    this->upAndDown = upAndDown;
    this->putts = putts;

}

PlayedHole::~PlayedHole()
{
    //dtor
}

int PlayedHole::getGross()
{
    return gross;
}

void PlayedHole::setGross(int& gross)
{
    this->gross = gross;
}

int PlayedHole::getNett()
{
    return nett;
}

void PlayedHole::setNett(int& nett)
{
    this->nett = nett;
}

int PlayedHole::getPoints()
{
    return points;
}

void PlayedHole::setPoints(int& points)
{
    this->points = points;
}

bool PlayedHole::isFairwayHit()
{
    return fairwayHit;
}

void PlayedHole::isFairwayHit(bool& fairway)
{
    this->fairwayHit = fairway;
}

bool PlayedHole::isGreenHit()
{
    return greenHit;
}

void PlayedHole::isGreenHit(bool& green)
{
    this->greenHit = green;
}

bool PlayedHole::isSandSave()
{
    return sandSave;
}

void PlayedHole::isSandSave(bool& sand)
{
    this->sandSave = sand;
}

bool PlayedHole::isUpAndDown()
{
    return upAndDown;
}

void PlayedHole::isUpAndDown(bool& upAndDown)
{
    this->upAndDown = upAndDown;
}

Hole* PlayedHole::getHole()
{
    return pHole;
}

void PlayedHole::setHole(Hole* pHole)
{
    this->pHole = pHole;
}

Round* PlayedHole::getRound()
{
    return pRound;
}

void PlayedHole::setRound(Round* pRound)
{
    this->pRound = pRound;
}

int PlayedHole::getPutts()
{
    return putts;
}

void PlayedHole::setPutts(int& putts)
{
    this->putts = putts;
}

void PlayedHole::makeFromQuery(int size, char** data, LinkedList<GolfObject>* g)
{
    PlayedHole* temp = (PlayedHole *)g;

    int _gross = atoi(data[1]);
    int _nett = atoi(data[2]);
    int _points = atoi(data[3]);
    //Values 4 and 5 are not implemented here
    bool fairway = atoi(data[6]);
    bool green = atoi(data[7]);
    bool sand = atoi(data[8]);
    bool _upAndDown = atoi(data[9]);
    int _putts = atoi(data[10]);

    PlayedHole* ph = new PlayedHole(atoi(data[0]), _gross, _nett, _points, new Hole(atoi(data[4])), new Round(atoi(data[5])), fairway, green, sand, _upAndDown, _putts);
    g->addToTail(ph);
}

bool PlayedHole::operator==(GolfObject* g)
{
    PlayedHole* ph = (PlayedHole *)g;

    if(this->gross == ph->getGross())
    {
        if(this->nett == ph->getNett())
        {
            if(this->points == ph->getPoints())
            {
                if(this->fairwayHit == ph->isFairwayHit())
                {
                    if(this->greenHit == ph->isFairwayHit())
                    {
                        if(this->sandSave == ph->isSandSave())
                        {
                            if(this->upAndDown == ph->isUpAndDown())
                            {
                                if(this->putts == ph->getPutts())
                                {
                                    if(this->id == ph->getId())
                                    {
                                        if(*(this->pHole) == ph->getHole())
                                            return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
