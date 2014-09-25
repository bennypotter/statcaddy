#include "gtest/gtest.h"
#include "databasehelper.h"
#include <iostream>

static DatabaseHelper *dbh;

TEST(Database, addPlayerToDatabase)
{
    Player * me = new Player(1, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);
    Player *p = new Player();
    dbh->getPlayerById(1, p)
            ;
    EXPECT_EQ("Ben Eyres", p->getFirstname() + " " + p->getSurname());
    ASSERT_EQ(10, p->getHandicap());
    dbh->deletePlayer(*me);
    delete p;
    delete me;
}

TEST(Database, deletePlayerFromDatabase)
{
    Player * me = new Player(2, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);
    dbh->deletePlayer(*me);
    Player *p = new Player();
    dbh->getPlayerById(1, p);

    ASSERT_NE(2, p->getId());
    EXPECT_EQ("", p->getFirstname());
    EXPECT_EQ("", p->getSurname());
    ASSERT_NE(10, p->getHandicap());
    dbh->deletePlayer(*me);
    delete me;
}

TEST(Database, findPlayerByName)
{
    Player * me = new Player(3, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);

    LinkedList<GolfObject>* l = dbh->getPlayerByName("Ben", "Eyres", new Player());
    ASSERT_EQ(1, l->getSize());
    EXPECT_EQ("Ben Eyres", ((Player *)l->get(0))->getFirstname() + " " + ((Player *)l->get(0))->getSurname());
    ASSERT_EQ(10, ((Player *)l->get(0))->getHandicap());
    dbh->deletePlayer(*me);
    delete me;
}

//getHolesByCourse
TEST(Database, findHolesByCourse)
{
    GolfCourse *gc = new GolfCourse(1,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);
    Hole h[3] = {new Hole(1,1,4,3,300,1, "leg right"),
                                new Hole(2,1,5,1,554,2, "straight"),
                                new Hole(3,1,3,3,156,3, "straight")};

    for(int i=0; i < 3; i++){
       dbh->addHole(h[i]);
    }
    std::string course_name = "Test GC";

    //TODO: Probably should look at changing this to passing a GC object
    LinkedList<GolfObject>* l = dbh->getHolesByCourse(course_name, new Hole());
    ASSERT_EQ(3, l->getSize());

    for(int i = 0; i < 3; i++){
        ASSERT_EQ(h[i].getPar(), ((Hole *)l->get(i))->getPar());
        ASSERT_EQ(h[i].getYards(), ((Hole *)l->get(i))->getYards());
        ASSERT_EQ(h[i].getStrokeIndex(), ((Hole *)l->get(i))->getStrokeIndex());
        ASSERT_EQ(h[i].getHoleNum(), ((Hole *)l->get(i))->getHoleNum());
        EXPECT_EQ(h[i].getShape(),((Hole *)l->get(i))->getShape());
    }
    dbh->deleteCourse(*gc);

    for(int i = 0; i < 3; i++){
        dbh->deleteHole(h[i]);
    }
}

//getHoleById
TEST(Database, getHoleById)
{
    GolfCourse *gc = new GolfCourse(2,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);
    Hole *h = new Hole(4,1,4,3,300,1, "leg right");
    dbh->addHole(*h);

    Hole *found = new Hole();
    dbh->getHoleById(h->getId(), found);

    ASSERT_EQ(h->getPar(), found->getPar());
    ASSERT_EQ(h->getYards(), found->getYards());
    ASSERT_EQ(h->getStrokeIndex(), found->getStrokeIndex());
    ASSERT_EQ(h->getHoleNum(), found->getHoleNum());
    EXPECT_EQ(h->getShape(),found->getShape());

    dbh->deleteCourse(*gc);
    dbh->deleteHole(*h);
}

//getPlayedHolesByHole
TEST(Database, findPlayedHolesByHole)
{
    //hole id will be 3 at this point
    GolfCourse *gc = new GolfCourse(3,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);
    Hole *h = new Hole(5,1,4,3,300,1, "leg right");
    dbh->addHole(*h);

    Player *me = new Player(4, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);

    std::string date = "20-09-14";
    std::string time = "11:01";
    std::string weather = "Sunny";
    int gross = 68;
    int nett = 66;
    int points = 38;
    //create round for the played hole
    Round *r = new Round(1, date, time, gross, nett, points, weather, me, gc);

    //create some played holes linked to hole
    gross = 4;
    nett = 3;
    points = 3;
    bool fairwayHit = true;
    bool greenHit = true;
    bool sandSave = false;
    bool upAndDown = false;
    int putts = 1;
    PlayedHole ph[3];
    int i = 0;
    while(i < 3){
        ph[i] = PlayedHole(i+1,gross, nett, points, h, r, fairwayHit, greenHit, sandSave, upAndDown, putts);
        dbh->addPlayedHole(ph[i]);
        //delete ph;
        gross++;
        nett++;
        i++;
    }

    LinkedList<GolfObject>* l = dbh->getPlayedHolesByHole(h->getId(), new PlayedHole());
    for(int j = 0; j < l->getSize(); j++){
        ASSERT_EQ(ph[j].getId(), ((PlayedHole *)l->get(j))->getId());
        ASSERT_EQ(ph[j].getGross(), ((PlayedHole *)l->get(j))->getGross());
        ASSERT_EQ(ph[j].getNett(), ((PlayedHole *)l->get(j))->getNett());
        ASSERT_EQ(ph[j].getPoints(), ((PlayedHole *)l->get(j))->getPoints());
        ASSERT_EQ(ph[j].isFairwayHit(), ((PlayedHole *)l->get(j))->isFairwayHit());
        ASSERT_EQ(ph[j].isGreenHit(), ((PlayedHole *)l->get(j))->isGreenHit());
        ASSERT_EQ(ph[j].isSandSave(), ((PlayedHole *)l->get(j))->isSandSave());
        ASSERT_EQ(ph[j].isUpAndDown(), ((PlayedHole *)l->get(j))->isUpAndDown());
        ASSERT_EQ(ph[j].getPutts(), ((PlayedHole *)l->get(j))->getPutts());
        ASSERT_EQ(ph[j].getHole()->getId(), ((PlayedHole *)l->get(j))->getHole()->getId());
        ASSERT_EQ(ph[j].getRound()->getId(), ((PlayedHole *)l->get(j))->getRound()->getId());
    }

    //delete course, hole, round, playedHoles
    dbh->deletePlayer(*me);
    dbh->deleteCourse(*gc);
    dbh->deleteHole(*h);
    dbh->deleteRound(*r);

    for(int j = 0; j < 3; j++){
        dbh->deletePlayedHole(ph[j]);
    }
    delete me;
    delete gc;
    delete h;
    delete r;
}

//getPlayedHolesByRound
TEST(Database, findPlayedHolesByRound)
{
//hole id will be 3 at this point
    GolfCourse *gc = new GolfCourse(4,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);
    Hole *h = new Hole(6,1,4,3,300,1, "leg right");
    dbh->addHole(*h);

    Player *me = new Player(5, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);

    std::string date = "20-09-14";
    std::string time = "11:01";
    std::string weather = "Sunny";
    int gross = 68;
    int nett = 66;
    int points = 38;
    //create round for the played hole
    Round *r = new Round(2, date, time, gross, nett, points, weather, me, gc);

    //create some played holes linked to hole
    gross = 4;
    nett = 3;
    points = 3;
    bool fairwayHit = true;
    bool greenHit = true;
    bool sandSave = false;
    bool upAndDown = false;
    int putts = 1;
    PlayedHole ph[3];
    int i = 0;
    while(i < 3){
        ph[i] = PlayedHole(i+4,gross, nett, points, h, r, fairwayHit, greenHit, sandSave, upAndDown, putts);
        dbh->addPlayedHole(ph[i]);
        //delete ph;
        gross++;
        nett++;
        i++;
    }

    LinkedList<GolfObject>* l = dbh->getPlayedHolesByRound(r->getId(), new PlayedHole());
    for(int j = 0; j < l->getSize(); j++){
        ASSERT_EQ(ph[j].getId(), ((PlayedHole *)l->get(j))->getId());
        ASSERT_EQ(ph[j].getGross(), ((PlayedHole *)l->get(j))->getGross());
        ASSERT_EQ(ph[j].getNett(), ((PlayedHole *)l->get(j))->getNett());
        ASSERT_EQ(ph[j].getPoints(), ((PlayedHole *)l->get(j))->getPoints());
        ASSERT_EQ(ph[j].isFairwayHit(), ((PlayedHole *)l->get(j))->isFairwayHit());
        ASSERT_EQ(ph[j].isGreenHit(), ((PlayedHole *)l->get(j))->isGreenHit());
        ASSERT_EQ(ph[j].isSandSave(), ((PlayedHole *)l->get(j))->isSandSave());
        ASSERT_EQ(ph[j].isUpAndDown(), ((PlayedHole *)l->get(j))->isUpAndDown());
        ASSERT_EQ(ph[j].getPutts(), ((PlayedHole *)l->get(j))->getPutts());
        ASSERT_EQ(ph[j].getHole()->getId(), ((PlayedHole *)l->get(j))->getHole()->getId());
        ASSERT_EQ(ph[j].getRound()->getId(), ((PlayedHole *)l->get(j))->getRound()->getId());
    }

    //delete course, hole, round, playedHoles
    dbh->deletePlayer(*me);
    dbh->deleteCourse(*gc);
    dbh->deleteHole(*h);
    dbh->deleteRound(*r);

    for(int j = 0; j < 3; j++){
        dbh->deletePlayedHole(ph[j]);
    }
    delete me;
    delete gc;
    delete h;
    delete r;
}

//getRoundsByCourse
TEST(Database, findRoundsByCourse)
{
    GolfCourse *gc = new GolfCourse(5,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);

    Player *me = new Player(6, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);

    Round *r = new Round[2];

    std::string date = "20-09-14";
    std::string time = "11:01";
    std::string weather = "Sunny";
    int gross = 68;
    int nett = 66;
    int points = 38;
    //create round for the played hole
    r[0] = Round(1, date, time, gross, nett, points, weather, me, gc);
    dbh->addRound(r[0]);

    date = "21-09-14";
    time = "10:32";
    r[1] = Round(2, date, time, gross, nett, points, weather, me, gc);
    dbh->addRound(r[1]);

    LinkedList<GolfObject>* l = dbh->getRoundsByCourse(gc->getId(), new Round());
    ASSERT_EQ(2, l->getSize());
    for(int i = 0; i < l->getSize(); i++){
        ASSERT_EQ(r[i].getId(), ((Round *)l->get(i))->getId());
        EXPECT_EQ(r[i].getDate(), ((Round *)l->get(i))->getDate());
        EXPECT_EQ(r[i].getTime(), ((Round *)l->get(i))->getTime());
        ASSERT_EQ(r[i].getGross(), ((Round *)l->get(i))->getGross());
        ASSERT_EQ(r[i].getNett(), ((Round *)l->get(i))->getNett());
        EXPECT_EQ(r[i].getWeather(), ((Round *)l->get(i))->getWeather());
        ASSERT_EQ(r[i].getCourse()->getId(), ((Round *)l->get(i))->getCourse()->getId());
    }
    dbh->deletePlayer(*me);
    dbh->deleteCourse(*gc);


    for(int i = 0; i < 2; i++){
        dbh->deleteRound(r[i]);
    }

    delete me;
    delete gc;
}

//getRoundsByCourse
TEST(Database, findRoundsByPlayer)
{
    GolfCourse *gc = new GolfCourse(6,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);

    Player *me = new Player(7, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);

    Round *r = new Round[2];

    std::string date = "20-09-14";
    std::string time = "11:01";
    std::string weather = "Sunny";
    int gross = 68;
    int nett = 66;
    int points = 38;
    //create round for the played hole
    r[0] = Round(3, date, time, gross, nett, points, weather, me, gc);
    dbh->addRound(r[0]);

    date = "21-09-14";
    time = "10:32";
    r[1] = Round(4, date, time, gross, nett, points, weather, me, gc);
    dbh->addRound(r[1]);

    LinkedList<GolfObject>* l = dbh->getRoundsByPlayer(me->getId(), new Round());
    ASSERT_EQ(2, l->getSize());
    for(int i = 0; i < l->getSize(); i++){
        ASSERT_EQ(r[i].getId(), ((Round *)l->get(i))->getId());
        EXPECT_EQ(r[i].getDate(), ((Round *)l->get(i))->getDate());
        EXPECT_EQ(r[i].getTime(), ((Round *)l->get(i))->getTime());
        ASSERT_EQ(r[i].getGross(), ((Round *)l->get(i))->getGross());
        ASSERT_EQ(r[i].getNett(), ((Round *)l->get(i))->getNett());
        EXPECT_EQ(r[i].getWeather(), ((Round *)l->get(i))->getWeather());
        ASSERT_EQ(r[i].getCourse()->getId(), ((Round *)l->get(i))->getCourse()->getId());
    }
    dbh->deletePlayer(*me);
    dbh->deleteCourse(*gc);


    for(int i = 0; i < 2; i++){
        dbh->deleteRound(r[i]);
    }

    delete me;
    delete gc;
}

//getRoundsByDateTime
TEST(Database, findRoundsByDateTime)
{
    GolfCourse *gc = new GolfCourse(7,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);

    Player *me = new Player(8, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);

    Round *r = new Round[2];

    std::string date = "20-09-14";
    std::string time = "11:01";
    std::string weather = "Sunny";
    int gross = 68;
    int nett = 66;
    int points = 38;
    //create round for the played hole
    r[0] = Round(5, date, time, gross, nett, points, weather, me, gc);
    dbh->addRound(r[0]);

    date = "21-09-14";
    time = "10:32";
    r[1] = Round(6, date, time, gross, nett, points, weather, me, gc);
    dbh->addRound(r[1]);

    LinkedList<GolfObject>* l = dbh->getRoundByDateTime(r[0].getDate(), r[0].getTime(), new Round());
    ASSERT_EQ(1, l->getSize());
    for(int i = 0; i < l->getSize(); i++){
        ASSERT_EQ(r[i].getId(), ((Round *)l->get(i))->getId());
        EXPECT_EQ(r[i].getDate(), ((Round *)l->get(i))->getDate());
        EXPECT_EQ(r[i].getTime(), ((Round *)l->get(i))->getTime());
        ASSERT_EQ(r[i].getGross(), ((Round *)l->get(i))->getGross());
        ASSERT_EQ(r[i].getNett(), ((Round *)l->get(i))->getNett());
        EXPECT_EQ(r[i].getWeather(), ((Round *)l->get(i))->getWeather());
        ASSERT_EQ(r[i].getCourse()->getId(), ((Round *)l->get(i))->getCourse()->getId());
    }
    dbh->deletePlayer(*me);
    dbh->deleteCourse(*gc);


    for(int i = 0; i < 2; i++){
        dbh->deleteRound(r[i]);
    }

    delete me;
    delete gc;
}

//getRoundByWEather
TEST(Database, findRoundsByWeather)
{
    GolfCourse *gc = new GolfCourse(8,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);

    Player *me = new Player(9, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);

    Round *r = new Round[2];

    std::string date = "20-09-14";
    std::string time = "11:01";
    std::string weather = "Sunny";
    int gross = 68;
    int nett = 66;
    int points = 38;
    //create round for the played hole
    r[0] = Round(7, date, time, gross, nett, points, weather, me, gc);
    dbh->addRound(r[0]);

    date = "21-09-14";
    time = "10:32";
    r[1] = Round(8, date, time, gross, nett, points, weather, me, gc);
    dbh->addRound(r[1]);

    LinkedList<GolfObject>* l = dbh->getRoundsByWeather("Sunny", new Round());
    ASSERT_EQ(2, l->getSize());
    for(int i = 0; i < l->getSize(); i++){
        ASSERT_EQ(r[i].getId(), ((Round *)l->get(i))->getId());
        EXPECT_EQ(r[i].getDate(), ((Round *)l->get(i))->getDate());
        EXPECT_EQ(r[i].getTime(), ((Round *)l->get(i))->getTime());
        ASSERT_EQ(r[i].getGross(), ((Round *)l->get(i))->getGross());
        ASSERT_EQ(r[i].getNett(), ((Round *)l->get(i))->getNett());
        EXPECT_EQ(r[i].getWeather(), ((Round *)l->get(i))->getWeather());
        ASSERT_EQ(r[i].getCourse()->getId(), ((Round *)l->get(i))->getCourse()->getId());
    }
    dbh->deletePlayer(*me);
    dbh->deleteCourse(*gc);


    for(int i = 0; i < 2; i++){
        dbh->deleteRound(r[i]);
    }

    delete me;
    delete gc;
}

//getShotsByPlayedHoled

//getShotsByClub

//getShotsByLie

//addCourse
TEST(Database, addCourseToDatabase)
{
    GolfCourse *c = new GolfCourse(9, 72, 74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*c);
    GolfCourse *pC = new GolfCourse();
    dbh->getCourseById(c->getId(), pC);
    ASSERT_EQ(c->getStrokeIndex(), pC->getStrokeIndex());
    ASSERT_EQ(c->getPar(), pC->getPar());
    EXPECT_EQ(c->getName(), pC->getName());
    EXPECT_EQ(c->getAddL1(), pC->getAddL1());
    EXPECT_EQ(c->getAddL2(), pC->getAddL2());
    EXPECT_EQ(c->getPostcode(), pC->getPostcode());
    dbh->deleteCourse(*c);

    delete c;
    delete pC;
}

//getCourseByAddress
TEST(Database, findCourseByAddress)
{
    GolfCourse *c = new GolfCourse(10, 72, 74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*c);
    LinkedList<GolfObject>* l = dbh->getCourseByAddress(c->getAddL1(), c->getAddL2(), c->getPostcode(), new GolfCourse());

    ASSERT_EQ(1, l->getSize());
    ASSERT_EQ(c->getStrokeIndex(), ((GolfCourse *)l->get(0))->getStrokeIndex());
    ASSERT_EQ(c->getPar(), ((GolfCourse *)l->get(0))->getPar());
    EXPECT_EQ(c->getName(), ((GolfCourse *)l->get(0))->getName());
    EXPECT_EQ(c->getAddL1(), ((GolfCourse *)l->get(0))->getAddL1());
    EXPECT_EQ(c->getAddL2(), ((GolfCourse *)l->get(0))->getAddL2());
    EXPECT_EQ(c->getPostcode(), ((GolfCourse *)l->get(0))->getPostcode());
    dbh->deleteCourse(*c);

    delete c;
}

//getCourseByPar
TEST(Database, findCoursesByPar)
{
    GolfCourse *c = new GolfCourse(11, 72, 74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*c);
    LinkedList<GolfObject>* l = dbh->getCoursesByPar(74, new GolfCourse());

    ASSERT_EQ(1, l->getSize());
    ASSERT_EQ(c->getStrokeIndex(), ((GolfCourse *)l->get(0))->getStrokeIndex());
    ASSERT_EQ(c->getPar(), ((GolfCourse *)l->get(0))->getPar());
    EXPECT_EQ(c->getName(), ((GolfCourse *)l->get(0))->getName());
    EXPECT_EQ(c->getAddL1(), ((GolfCourse *)l->get(0))->getAddL1());
    EXPECT_EQ(c->getAddL2(), ((GolfCourse *)l->get(0))->getAddL2());
    EXPECT_EQ(c->getPostcode(), ((GolfCourse *)l->get(0))->getPostcode());
    dbh->deleteCourse(*c);

    delete c;
}

//getCourseByName
TEST(Database, findCourseByName)
{
    GolfCourse *c = new GolfCourse(12, 72, 74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*c);
    GolfCourse *pC = new GolfCourse();
    dbh->getCourseByName(c->getName(), pC);
    ASSERT_EQ(c->getStrokeIndex(), pC->getStrokeIndex());
    ASSERT_EQ(c->getPar(), pC->getPar());
    EXPECT_EQ(c->getName(), pC->getName());
    EXPECT_EQ(c->getAddL1(), pC->getAddL1());
    EXPECT_EQ(c->getAddL2(), pC->getAddL2());
    EXPECT_EQ(c->getPostcode(), pC->getPostcode());
    dbh->deleteCourse(*c);

    delete c;
    delete pC;
}

//getCourseList
TEST(Database, findAllCourse)
{
    GolfCourse *c0 = new GolfCourse(12, 74, 74, "Test GC_0", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*c0);

    GolfCourse *c1 = new GolfCourse(13, 73, 74, "Test GC_1", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*c1);

    GolfCourse *c2 = new GolfCourse(14, 70, 69, "Test GC_2", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*c2);

    GolfCourse cArray[3] = {*c0, *c1, *c2};
    LinkedList<GolfObject>* l = dbh->getCourseList(new GolfCourse());

    ASSERT_EQ(3, l->getSize());
    for(int i = 0; i < 3; i++){
        ASSERT_EQ(cArray[i].getStrokeIndex(), ((GolfCourse *)l->get(i))->getStrokeIndex());
        ASSERT_EQ(cArray[i].getPar(), ((GolfCourse *)l->get(i))->getPar());
        EXPECT_EQ(cArray[i].getName(), ((GolfCourse *)l->get(i))->getName());
        EXPECT_EQ(cArray[i].getAddL1(), ((GolfCourse *)l->get(i))->getAddL1());
        EXPECT_EQ(cArray[i].getAddL2(), ((GolfCourse *)l->get(i))->getAddL2());
        EXPECT_EQ(cArray[i].getPostcode(), ((GolfCourse *)l->get(i))->getPostcode());
        dbh->deleteCourse(cArray[i]);
    }

    delete c0;
    delete c1;
    delete c2;
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    int returnValue;
    dbh = new DatabaseHelper();
    //Do whatever setup here you will need for your tests here
    //
    //
    dbh->connect("statcaddy_db");
    int err = dbh->buildDatabase();
    std::cout << err << endl;
    if(err){
        std::cout << "There was a error with the DB" << endl;
        return 1;
    }
    //Player *p = new Player();
    //dbh->getPlayerById(1, p);

    returnValue =  RUN_ALL_TESTS();

    //Do Your teardown here if required
    //
    //
    dbh->disconnect();
    delete dbh;
    //delete the da
    return returnValue;
}
//g++ gt_trial.cpp -o gt_trial -I/home/ben/gtest-1.7.0/include -L/home/ben/gtest-1.7.0/lib -lgtest -lpthread

