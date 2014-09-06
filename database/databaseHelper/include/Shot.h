#ifndef SHOT_H
#define SHOT_H

#include <GolfObject.h>
#include <PlayedHole.h>
#include <string>

class Shot : public GolfObject
{
    public:
        Shot();
        Shot(int);
        Shot(int, string&, string&, bool&, string&, string&, string&, PlayedHole*);
        virtual ~Shot();
        string getClub();
        void setClub(string&);
        string getLie();
        void setLie(string&);
        bool didGoForGreen();
        void didGoForGreen(bool&);
        string getStart();
        void setStart(string&);
        string getFinish();
        void setFinish(string&);
        string getWind();
        void setWind(string&);
        PlayedHole* getPlayedHole();
        void setPlayedHole(PlayedHole*);
        void makeFromQuery(int, char**, LinkedList<GolfObject>*);
        virtual bool operator==(GolfObject*);
    protected:
    private:
        string club;
        string lie;
        bool goneForGreen;
        string start;
        string finish;
        string wind;
        PlayedHole* pPlayedHole;
};

#endif // SHOT_H
