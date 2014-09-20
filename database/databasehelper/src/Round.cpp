#include "Round.h"
#include "Player.h"
#include <stdlib.h>

Round::Round()
{
    //ctor
}

Round::Round(int id):GolfObject(id){}

Round::Round(int id, string& time, string& date, int& gross, int& nett,
             int& points, string& weather, Player* pPlayer,
             GolfCourse* pCourse):GolfObject(id)
{
    this->time = time;
    this->date = date;
    this->gross = gross;
    this->nett = nett;
    this->points = points;
    this->weather = weather;
    this->pPlayer = pPlayer;
    this->pCourse = pCourse;
}

Round::~Round()
{
    //dtor
}

string Round::getTime()
{
    return time;
}

void Round::setTime(string& time)
{
    this->time = time;
}

string Round::getDate()
{
    return date;
}

void Round::setDate(string date)
{
    this->date = date;
}

int Round::getGross()
{
    return gross;
}

void Round::setGross(int& gross)
{
    this->gross = gross;
}

int Round::getNett()
{
    return nett;
}

void Round::setNett(int& nett)
{
    this->nett = nett;
}

int Round::getPoints()
{
    return points;
}

void Round::setPoints(int& points)
{
    this->points = points;
}

string Round::getWeather()
{
    return weather;
}

void Round::setWeather(string& weather)
{
    this->weather = weather;
}

Player* Round::getPlayer()
{
    return pPlayer;
}

void Round::setPlayer(Player* pPlayer)
{
    this->pPlayer = pPlayer;
}

GolfCourse* Round::getCourse()
{
    return pCourse;
}

void Round::setCourse(GolfCourse* pCourse)
{
    this->pCourse = pCourse;
}

void Round::makeFromQuery(int size, char** data, LinkedList<GolfObject>* g)
{
    Round* temp = (Round *)g;
    string _time = data[1];
    string _date = data[2];
    int _gross = atoi(data[3]);
    int _nett = atoi(data[4]);
    int _points = atoi(data[5]);
    string _weather = data[6];
    Round* r = new Round(atoi(data[0]), _time, _date, _gross, _nett, _points,
             _weather, new Player(atoi(data[7])), new GolfCourse(atoi(data[8])));
    g->addToHead(r);
}

bool Round::operator==(GolfObject *item)
{
    Round* r = (Round *)item;

    if(this->time == r->getTime())
    {
        if(this->date == r->getDate())
        {
            if(this->gross == r->getGross())
            {
                if(this->nett == r->getNett())
                {
                    if(this->points == r->getPoints())
                    {
                        if(this->weather == r->getWeather())
                        {
                            if(*(this->pPlayer) == r->getPlayer())
                            {
                                if(*(this->pCourse) == r->getCourse())
                                {
                                    if(this->id == r->getId())
                                        return true;
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
