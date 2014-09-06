#include "Player.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
#include "Round.h"
#include "DatabaseHelper.h"

using namespace std;

Player::Player()
{

}

Player::Player(int id) : GolfObject(id)
{

}

Player::Player(int id, DatabaseHelper& database) : GolfObject(id)
{
    this->database = &database;
}

Player::Player(int id, string firstname, string surname, int handicap)
        :GolfObject(id)
{
    this->firstname = firstname;
    this->surname = surname;
    this->handicap = handicap;
}

Player::Player(const Player &obj):GolfObject(obj)
{
    handicap = obj.handicap;
    firstname = obj.firstname;
    surname = obj.surname;
}

Player::~Player()
{

}

Player& Player::operator=(const Player &obj)
{
    this->id = obj.id;
    handicap = obj.handicap;
    firstname = obj.firstname;
    surname = obj.surname;
}

string Player::getFirstname()
{
    return firstname;
}

void Player::setFirstname(string firstname)
{
    this->firstname = firstname;
}

string Player::getSurname()
{
    return surname;
}

void Player::setSurname(string surname)
{
    this->surname = surname;
}

int Player::getHandicap()
{
    return handicap;
}

void Player::setHandicap(int handicap)
{
    this->handicap = handicap;
}

void Player::setDatabase(DatabaseHelper &dbh)
{
    this->database = &dbh;
}

void Player::makeFromQuery(int size, char** data, LinkedList<GolfObject>* g)
{
    int i = atoi(data[3]);
    Player* p = new Player(atoi(data[0]),data[1],data[2], i);
    g->addToHead(p);
}

bool Player::operator==(GolfObject *item)
{
    Player *p = (Player*)item;
    if(this->id == item->getId())
    {
        if(this->firstname == p->getFirstname())
        {
            if(this->surname == p->getSurname())
            {
                if(this->getHandicap() == p->getHandicap())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

LinkedList<GolfObject>* Player::getRounds(int id, Round* r)
{
    return database->getRoundsByPlayer(id, new Round());
}

Round* Player::getRound(string date, string time)
{
    LinkedList<GolfObject>* _list = database->getRoundByDateTime(date, time, new Round());

    int listSize = _list->getSize();

    for(int i = 0; i < listSize; i++)
    {
        Round* temp = (Round *)_list->get(i);
        if(temp->getDate()==date && temp->getTime()==time && temp->getPlayer()->getId() == id)
            return temp;
    }
    return NULL;
}

LinkedList<GolfObject>* Player::getPlayedHoles(int id)
{
    return database->getPlayedHolesByRound(id, new PlayedHole());
}

PlayedHole* Player::getPlayedHole(int id)
{
    PlayedHole* ph = new PlayedHole();
    database->getPlayedHoleById(id, ph);
    return ph;;
}
