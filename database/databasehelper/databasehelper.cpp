#include "databasehelper.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cstring>


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
                             char **argv, //An array of strings representing fields in the row
                             char **azColName //An array of strings representing column names
                              )
{

    ((GolfObject *) data)->makeFromQuery(argc, argv, lList);
    return 0;
}

int DatabaseHelper::makeTableCallback(void *data, //Data provided in the 4th argument of sqlite3_exec()
                             		int argc, //The number of columns in row
                             		char **argv, //An array of string representing fields in the row
                             		char **azColName //An array of strings representing column names
					)
{
    //Could get rid of this function?
    return 0;
}

void DatabaseHelper::runQuery(char *sql, GolfObject* go)
{
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_exec(db, sql, callback, (void*)go, &zErrMsg);

    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error-: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void DatabaseHelper::insert(char *sql)
{
    char *zErrMsg = 0;
    int  rc;


    rc = sqlite3_exec(db, sql, makeTableCallback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error---: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    //return 1;
    }else{}
}

int DatabaseHelper::buildDatabase()
{
    char *sql;
    sql = "CREATE TABLE golfCourse" \
        "( " \
	"gc_Id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, " \
	"strokeIndex int, " \
	"par int, " \
	"name varchar(255), " \
	"addL1 varchar(255), " \
	"addL2 varchar(255), " \
	"postcode varchar(255)" \
        ");" \

	"CREATE TABLE Player(" \
	"p_Id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," \
	"firstName varchar(255) NOT NULL," \
	"lastName varchar(255) NOT NULL," \
	"handicap INTEGER NOT NULL);" \

	"CREATE TABLE Hole" \
	"(" \
	"h_Id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," \
	"gc_Id INTEGER NOT NULL," \
	"par INTEGER NOT NULL," \
	"strokeIndex INTEGER NOT NULL," \
	"yards INTEGER NOT NULL," \
	"holeNum INTEGER NOT NULL," \
	"shape varchar(255) NOT NULL," \
	"FOREIGN KEY (gc_Id) REFERENCES golfCourse(gc_Id)" \
	");" \

	"CREATE TABLE Round(" \
	"r_Id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," \
	"time DATETIME NOT NULL," \
	"date DATETIME NOT NULL," \
	"gross INTEGER NOT NULL," \
	"nett INTEGER NOT NULL," \
	"stableford INTEGER NOT NULL," \
	"weather varchar(255) NOT NULL," \
	"p_Id INTEGER NOT NULL," \
	"gc_Id INTEGER NOT NULL," \
	"FOREIGN KEY (p_Id) REFERENCES Player (p_Id)," \
	"FOREIGN KEY (gc_Id) REFERENCES golfCourse (gc_Id)); " \

	"CREATE TABLE PlayedHole(" \
	"ph_Id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," \
	"gross INTEGER NOT NULL," \
	"nett INTEGER NOT NULL," \
	"points INTEGER NOT NULL," \
	"h_Id INTEGER NOT NULL," \
	"r_Id INTEGER NOT NULL," \
	"fairwayHit tinyint," \
	"greenHit tinyint," \
	"sandSave tinyint," \
	"upAndDown tinyint," \
	"putts INTEGER," \
	"FOREIGN KEY (h_Id) REFERENCES Hole(h_Id)," \
	"FOREIGN KEY (r_Id) REFERENCES Round(r_Id));" \

	"CREATE TABLE Shot" \
	"(" \
	"s_Id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT," \
	"club varchar(255) NOT NULL," \
	"lie varchar(255) NOT NULL," \
	"gfg tinyint(1) NOT NULL," \
	"start varchar(255) NOT NULL," \
	"finish varchar(255) NOT NULL," \
	"wind varchar(255) NOT NULL," \
	"ph_Id INTEGER NOT NULL," \
	"FOREIGN KEY (ph_Id) REFERENCES PlayedHole(ph_Id)" \
	");";

    char *zErrMsg = 0;
    int  rc;


    rc = sqlite3_exec(db, sql, makeTableCallback, 0, &zErrMsg);

    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error--: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
	return 1;
    }else{
        fprintf(stdout, "Table created successfully\n");
    return 0;
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

string DatabaseHelper::intToString(int val)
{
    ostringstream conv;
    conv << val;
    string a = conv.str();
    return a;
}

void DatabaseHelper::addHole(Hole &h)
{
    string par = intToString(h.getPar());
    string si = intToString(h.getStrokeIndex());
    string yards = intToString(h.getYards());
    string holenum = intToString(h.getHoleNum());
    string gc_id = intToString(1);
    string query = "INSERT INTO Hole(strokeIndex, par, yards, holeNum, shape, gc_id) VALUES(";
    string values = si+ ", " + par + ", " + yards +", " +holenum+ ", '" +h.getShape()+ "', " +gc_id+ ");";
    string full_string = query+values;
    cout << full_string << endl;
    insert(&full_string[0]);
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
    if(lList->getSize() != 0){
        *p = *(Player *)lList->get(0);
    }
    else{
        delete p;
        *p = NULL;
    }
    delete lList;
}

void DatabaseHelper::addPlayer(Player &p)
{
    ostringstream convert1;
    convert1 << p.getId();
    string id = convert1.str();
    ostringstream convert2;
    convert2 << p.getHandicap();
    string hcap = convert2.str();
    string query = "INSERT INTO Player(firstName, lastName, handicap) VALUES(";
    string values = std::string("'") + p.getFirstname()+ "', '" + p.getSurname() + "', " + hcap +");";
    string full_string = query+values;
    insert(&full_string[0]);
}

void DatabaseHelper::deletePlayer(Player &p)
{
    ostringstream convert;
    convert << p.getId();
    string id = convert.str();
    string query = string("DELETE FROM Player WHERE p_Id = ") + id;
    insert(&query[0]);
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

void DatabaseHelper::addCourse(GolfCourse &c)
{
    ostringstream convert1;
    convert1 << c.getStrokeIndex();
    string si = convert1.str();
    ostringstream convert2;
    convert2 << c.getPar();
    string par = convert2.str();
    string query = "INSERT INTO golfCourse(strokeIndex, par, name, addL1, addL2, postcode) VALUES(";
    string values = si + ", " + par + ", '" + c.getName() +"', '" +c.getAddL1()+ "', '"+ c.getAddL2() +"', '"+c.getPostcode()+"');";
    string full_string = query+values;
    insert(&full_string[0]);
}

void DatabaseHelper::deleteCourse(GolfCourse &c)
{
    ostringstream convert;
    convert << c.getId();
    string id = convert.str();
    string query = string("DELETE FROM golfCourse WHERE gc_Id = ") + id;
    insert(&query[0]);
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
