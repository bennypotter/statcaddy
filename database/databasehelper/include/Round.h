#ifndef ROUND_H
#define ROUND_H

#include <GolfObject.h>
#include <string>
//#include <Player.h>
#include <GolfCourse.h>

class Player;

class Round : public GolfObject
{
    public:
        Round();
        Round(int);
        Round(int, string&, string&, int&, int&, int&, string&, Player*, GolfCourse*);
        virtual ~Round();
        string getTime();
        void setTime(string&);
        string getDate();
        void setDate(string);
        int getGross();
        void setGross(int&);
        int getNett();
        void setNett(int&);
        int getPoints();
        void setPoints(int&);
        string getWeather();
        void setWeather(string&);
        Player* getPlayer();
        void setPlayer(Player*);
        GolfCourse* getCourse();
        void setCourse(GolfCourse*);
        void makeFromQuery(int, char**, LinkedList<GolfObject>*);
        virtual bool operator==(GolfObject*);
    protected:
    private:
        string time;
        string date;
        int gross;
        int nett;
        int points;
        string weather;
        Player* pPlayer;
        GolfCourse* pCourse;
};

#endif // ROUND_H
