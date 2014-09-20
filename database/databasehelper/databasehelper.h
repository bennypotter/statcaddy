#ifndef DATABASEHELPER_H
#define DATABASEHELPER_H

#include <sqlite3.h>
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
    int buildDatabase();
    void runQuery(char *sql, GolfObject*);
    void insert(char *sql);
    //Holes
    LinkedList<GolfObject>* getHolesByCourse(string&, Hole*);
    void addHole(Hole &h);
    void getHoleById(int id, Hole* h);
    //PlayedHoles
    LinkedList<GolfObject>* getPlayedHolesByHole(int id, PlayedHole*);
    LinkedList<GolfObject>* getPlayedHolesByRound(int id, PlayedHole*);
    void getPlayedHoleById(int id, PlayedHole*);
    //Player
    LinkedList<GolfObject>* getPlayerByName(string,string, Player*);
    void getPlayerById(int, Player*);
    void addPlayer(Player &);
    void deletePlayer(Player &);
    //Rounds
    LinkedList<GolfObject>* getRoundsByPlayer(int, Round*);
    LinkedList<GolfObject>* getRoundsByCourse(int, Round*);
    LinkedList<GolfObject>* getRoundByDateTime(string date, string time, Round*);
    LinkedList<GolfObject>* getRoundsByWeather(string, Round*);
    void getRoundById(int, Round*);
    //Shots
    LinkedList<GolfObject>* getShotsByPlayedHole(int, Shot*);
    LinkedList<GolfObject>* getShotsByClub(string, Shot*);
    LinkedList<GolfObject>* getShotsByLie(string, Shot *);
    void getShotById(int, Shot*);
    //Course
    void addCourse(GolfCourse &);
    void deleteCourse(GolfCourse &);
    LinkedList<GolfObject>* getCourseByAddress(string, string, string, GolfCourse*);
    LinkedList<GolfObject>* getCoursesByPar(int, GolfCourse*);
    void getCourseByName(string, GolfCourse*);
    LinkedList<GolfObject>* getCourseList(GolfCourse*gc);
    void getCourseById(int, GolfCourse*);

    sqlite3* db;
protected:


private:
    static int callback(void *data, int argc, char **argv, char **azColName);
    static int makeTableCallback(void *data, int argc, char **argv, char **azColName);
    static LinkedList<GolfObject> *lList;
    string intToString(int val);

};

#endif // DATABASEHELPER_H
