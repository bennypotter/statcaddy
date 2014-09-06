#ifndef PLAYER_H
#define PLAYER_H

#include <GolfObject.h>
#include "LinkedList.h"
#include "PlayedHole.h"
#include <string>

using namespace std;

class DatabaseHelper;   // implemented due to cyclic dependency
                        //(DatabaseHelper.h needs Player.h and
                        // Player.h needs DatabaseHelper.h)
class Round;

class Player : public GolfObject
{
    public:
        Player();
        Player(int);
        Player(int id, DatabaseHelper& database);
        Player(int, string, string, int);
        Player( const Player &obj); //Copy Constructor
        virtual ~Player();
        Player& operator=(const Player &obj);
        string getFirstname();
        void setFirstname(string);
        string getSurname();
        void setSurname(string);
        int getHandicap();
        void setHandicap(int );
        void setDatabase(DatabaseHelper &);
        void makeFromQuery(int, char**, LinkedList<GolfObject>*);
        bool operator==(GolfObject*);
        LinkedList<GolfObject>* getRounds(int, Round*);
        Round* getRound(string date, string time);
        LinkedList<GolfObject>* getPlayedHoles(int);
        PlayedHole* getPlayedHole(int);
    protected:
    private:
        string firstname;
        string surname;
        int handicap;
        DatabaseHelper* database;
};

#endif // PLAYER_H
