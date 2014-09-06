#include "databasehelper.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>


using namespace std;

LinkedList<GolfObject>* DatabaseHelper::lList;

DatabaseHelper::DatabaseHelper()
{
}

DatabaseHelper::~DatabaseHelper()
{
    //dtor
}

sqlite3 * DatabaseHelper::connect(char *location)
{
    int rc;
    rc = sqlite3_open(location, &this->db);

    if( rc )
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }
    return db;
}

void DatabaseHelper::disconnect()
{
    sqlite3_close(this->db);
}

int DatabaseHelper::callback(void *data, //Data provided in the 4th argument of sqlite3_exec()
                             int argc, //The number of columns in row
                             char **argv, //An array of string representing fields in the row
                             char **azColName //An array of strings representing column names
                              )
{
    ((GolfObject *) data)->makeFromQuery(argc, argv, lList);
    //lList->addToHead((GolfObject *)data);

    return 0;
}

void DatabaseHelper::runQuery(char *sql, GolfObject* go)
{
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_exec(db, sql, callback, (void*)go, &zErrMsg);

    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        //fprintf(stdout, "Operation done successfully\n");
    }
}

LinkedList<GolfObject>* DatabaseHelper::getHolesByCourse(string& name, Hole* h)
{
    //Find Course Id of the course
    lList = new LinkedList<GolfObject>();
    string query = "SELECT * FROM golfCourse WHERE name = '"+name+"'";
    GolfCourse *gc = new GolfCourse();
    runQuery(&query[0], gc);
    delete gc;
    GolfCourse* _gc = (GolfCourse *)lList->get(0);
    stringstream convert;
    convert << _gc->getId();
    delete lList; //Delete the list as it is no longer in use

    lList = new LinkedList<GolfObject>(); // Create a new list for the holes
    //Find holes related to the course
    query = "SELECT * FROM Hole WHERE gc_Id = "+convert.str();
    runQuery(&query[0], h);
    delete h;
    return lList;
}

 void DatabaseHelper::getHoleById(int id, Hole* h)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM Hole WHERE h_Id = "+convert.str();
    runQuery(&query[0], h);
    *h = *(Hole *)lList->get(0);
    delete lList;
}

LinkedList<GolfObject>* DatabaseHelper::getPlayedHolesByHole(int id, PlayedHole* ph)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM PlayedHole WHERE h_Id ="+convert.str();
    runQuery(&query[0], ph);
    return lList;
}

LinkedList<GolfObject>* DatabaseHelper::getPlayedHolesByRound(int id, PlayedHole* ph)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM PlayedHole WHERE r_Id = "+convert.str();
    runQuery(&query[0], ph);
    return lList;
}

void DatabaseHelper::getPlayedHoleById(int id, PlayedHole* ph)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM PlayedHole WHERE ph_Id = "+convert.str();
    runQuery(&query[0], ph);
    *ph = *(PlayedHole *)lList->get(0);
    delete lList;
}

//return a list as it is possible there could be two John Smiths in the database
LinkedList<GolfObject>* DatabaseHelper::getPlayerByName(string first, string last, Player* p)
{
    lList = new LinkedList<GolfObject>();
    string query = "SELECT * FROM Player WHERE firstName = '"+first+"' AND lastName = '"+last+"'";
    runQuery(&query[0], p);
    return lList;
}

void DatabaseHelper::getPlayerById(int id, Player* p)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM Player WHERE p_Id = "+convert.str();
    runQuery(&query[0], p);
    *p = *(Player *)lList->get(0);
    delete lList;
}

LinkedList<GolfObject>* DatabaseHelper::getRoundsByPlayer(int id, Round* r)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM Round WHERE p_Id = "+convert.str();
    runQuery(&query[0], r);
    return lList;
}

LinkedList<GolfObject>* DatabaseHelper::getRoundsByCourse(int id, Round* r)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM Round WHERE gc_Id = "+convert.str();
    runQuery(&query[0], r);
    return lList;
}

LinkedList<GolfObject>* DatabaseHelper::getRoundByDateTime(string date, string time, Round* r)
{
    lList = new LinkedList<GolfObject>();
    string query = "SELECT * FROM Round WHERE date = '"+date+"' AND time = '"+time+"'";
    runQuery(&query[0], r);
    return lList;
}

LinkedList<GolfObject>* DatabaseHelper::getRoundsByWeather(string weather, Round* r)
{
    lList = new LinkedList<GolfObject>();
    string query = "SELECT * FROM Round WHERE weather = '"+weather+"'";
    runQuery(&query[0], r);
    return lList;
}

void DatabaseHelper::getRoundById(int id, Round* r)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM Round WHERE r_Id = "+convert.str();
    runQuery(&query[0], r);
    *r = *(Round *)lList->get(0);
    delete lList;
}

LinkedList<GolfObject>* DatabaseHelper::getShotsByPlayedHole(int id, Shot* s)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM Shot WHERE ph_Id ="+convert.str();
    runQuery(&query[0], s);
    return lList;
}

LinkedList<GolfObject>* DatabaseHelper::getShotsByClub(string club, Shot* s)
{
    lList = new LinkedList<GolfObject>();
    string query = "SELECT * FROM Shot WHERE club = '"+club+"'";
    runQuery(&query[0], s);
    return lList;
}

LinkedList<GolfObject>* DatabaseHelper::getShotsByLie(string lie, Shot* s)
{
    lList = new LinkedList<GolfObject>();
    string query = "SELECT * FROM Shot WHERE lie = '"+lie+"'";
    runQuery(&query[0], s);
    return lList;
}

void DatabaseHelper::getShotById(int id, Shot* s)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM Shot WHERE s_Id = "+convert.str();
    runQuery(&query[0], s);
    *s = *(Shot *)lList->get(0);
    delete lList;
}

LinkedList<GolfObject>* DatabaseHelper::getCourseByAddress(string addL1, string addL2, string postcode, GolfCourse* gc)
{
    lList = new LinkedList<GolfObject>();
    string query = "SELECT * FROM golfCourse WHERE addL1 = '"+addL1+"' AND addL2 = '"+addL2+"' AND postcode = '"+postcode+"'";
    runQuery(&query[0], gc);
    return lList;
}

LinkedList<GolfObject>* DatabaseHelper::getCoursesByPar(int par, GolfCourse* gc)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << par;
    string query = "SELECT * FROM golfCourse WHERE par ="+convert.str();
    runQuery(&query[0], gc);
    return lList;
}

void DatabaseHelper::getCourseById(int id, GolfCourse* gc)
{
    lList = new LinkedList<GolfObject>();
    stringstream convert;
    convert << id;
    string query = "SELECT * FROM golfCourse WHERE gc_Id = "+convert.str();
    runQuery(&query[0], gc);
    *gc = *(GolfCourse *)lList->get(0);
    delete lList;
}

void DatabaseHelper::getCourseByName(string name, GolfCourse* gc)
{
    lList = new LinkedList<GolfObject>();
    string query = "SELECT * FROM golfCourse WHERE name = '"+name+"'";
    runQuery(&query[0], gc);
    *gc = *(GolfCourse *)lList->get(0);
    delete lList;
}

LinkedList<GolfObject>* DatabaseHelper::getCourseList(GolfCourse* gc)
{
    lList = new LinkedList<GolfObject>();
    string query = "SELECT * FROM golfCourse";
    runQuery(&query[0], gc);
    return lList;
}
