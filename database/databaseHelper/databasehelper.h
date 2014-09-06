#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H

#include <include/sqlite3.h>
#include <string>
#include <include/GolfObject.h>
#include <include/Hole.h>
#include <include/GolfCourse.h>
#include <include/PlayedHole.h>
#include <include/Shot.h>
#include <include/Player.h>
#include <include/Round.h>
#include <include/LinkedList.h>

class DatabaseHelper
{
public:
    DatabaseHelper();
    virtual ~DatabaseHelper();
    sqlite3* connect(char *location);
    void disconnect();
    void runQuery(char *sql, GolfObject*);
    LinkedList<GolfObject>* getHolesByCourse(string&, Hole*);
    void getHoleById(int id, Hole* h);
    LinkedList<GolfObject>* getPlayedHolesByHole(int id, PlayedHole*);
    LinkedList<GolfObject>* getPlayedHolesByRound(int id, PlayedHole*);
    void getPlayedHoleById(int id, PlayedHole*);
    LinkedList<GolfObject>* getPlayerByName(string,string, Player*);
    void getPlayerById(int, Player*);
    LinkedList<GolfObject>* getRoundsByPlayer(int, Round*);
    LinkedList<GolfObject>* getRoundsByCourse(int, Round*);
    LinkedList<GolfObject>* getRoundByDateTime(string date, string time, Round*);
    LinkedList<GolfObject>* getRoundsByWeather(string, Round*);
    void getRoundById(int, Round*);
    LinkedList<GolfObject>* getShotsByPlayedHole(int, Shot*);
    LinkedList<GolfObject>* getShotsByClub(string, Shot*);
    LinkedList<GolfObject>* getShotsByLie(string, Shot *);
    void getShotById(int, Shot*);
    LinkedList<GolfObject>* getCourseByAddress(string, string, string, GolfCourse*);
    LinkedList<GolfObject>* getCoursesByPar(int, GolfCourse*);
    void getCourseByName(string, GolfCourse*);
    LinkedList<GolfObject>* getCourseList(GolfCourse*gc);
    void getCourseById(int, GolfCourse*);
    sqlite3* db;
protected:


private:
    static int callback(void *data, int argc, char **argv, char **azColName);
    static LinkedList<GolfObject> *lList;

};

#endif // DATABASEHELPER_H
