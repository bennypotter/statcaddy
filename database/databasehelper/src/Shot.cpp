#include "Shot.h"
#include <stdlib.h>

Shot::Shot(){}

Shot::Shot(int id):GolfObject(id){}

Shot::Shot(int id, string& club, string& lie, bool& goneForGreen, string& start,
     string& finish, string& wind, PlayedHole* pPlayedHole):GolfObject(id)
{
    this->club = club;
    this->lie = lie;
    this->goneForGreen = goneForGreen;
    this->start = start;
    this->finish = finish;
    this->wind = wind;
    this->pPlayedHole = pPlayedHole;
}

Shot::~Shot()
{
    //dtor
}

string  Shot::getClub()
{
    return club;
}

void Shot::setClub(string&)
{
    this->club = club;
}

string Shot::getLie()
{
    return lie;
}

void Shot::setLie(string&)
{
    this->lie = lie;
}

bool Shot::didGoForGreen()
{
    return goneForGreen;
}

void Shot::didGoForGreen(bool& goneForGreen)
{
    this->goneForGreen = goneForGreen;
}

string Shot::getStart()
{
    return start;
}

void Shot::setStart(string& start)
{
    this->start = start;
}

string Shot::getFinish()
{
    return finish;
}

void Shot::setFinish(string& finish)
{
    this->finish = finish;
}

string Shot::getWind()
{
    return wind;
}

void Shot::setWind(string& wind)
{
    this->wind = wind;
}

PlayedHole* Shot::getPlayedHole()
{
    return pPlayedHole;
}

void Shot::setPlayedHole(PlayedHole* pPlayedHole)
{
    this->pPlayedHole = pPlayedHole;
}

void Shot::makeFromQuery(int size, char** data, LinkedList<GolfObject>* g)
{
    Shot* temp = (Shot *)g;

    string _club = data[1];
    string _lie = data[2];
    bool _goneForGreen = atoi(data[3]);
    string _start = data[4];
    string _finish = data[5];
    string _wind = data[6];

    Shot* s = new Shot(atoi(data[0]), _club, _lie, _goneForGreen, _start, _finish, _wind, new PlayedHole(atoi(data[7])));
    g->addToHead(s);
}

bool Shot::operator==(GolfObject* item)
{
    Shot* s = (Shot *)item;

    if(this->id == s->getId())
    {
        if(this->club == s->getClub())
        {
            if(this->lie == s->getLie())
            {
                if(this->goneForGreen == s->didGoForGreen())
                {
                    if(this->start == s->getStart())
                    {
                        if(this->finish == s->getFinish())
                        {
                            if(this->wind == s->getWind())
                            {
                                if(*(this->pPlayedHole) == s->getPlayedHole())
                                    return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
