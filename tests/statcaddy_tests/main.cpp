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
    GolfCourse *gc = new GolfCourse(1,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);
    Hole *h = new Hole(1,1,4,3,300,1, "leg right");
    dbh->addHole(*h);

    LinkedList<GolfObject>* l = dbh->getHoleById(new Hole());

    ASSERT_EQ(1, l->getSize());
    ASSERT_EQ(h.getPar(), ((Hole *)l->get(i))->getPar());
    ASSERT_EQ(h.getYards(), ((Hole *)l->get(i))->getYards());
    ASSERT_EQ(h.getStrokeIndex(), ((Hole *)l->get(i))->getStrokeIndex());
    ASSERT_EQ(h.getHoleNum(), ((Hole *)l->get(i))->getHoleNum());
    EXPECT_EQ(h.getShape(),((Hole *)l->get(i))->getShape());

    dbh->deleteCourse(*gc);
    dbh->deleteHole(*h);
}

//getPlayedHolesByHole
TEST(Database, getPlayedHolesByHole)
{
    //hole id will be 3 at this point
    GolfCourse *gc = new GolfCourse(1,72,74, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*gc);
    Hole *h = new Hole(1,1,4,3,300,1, "leg right");
    dbh->addHole(*h);

    Player *me = new Player(3, "Ben", "Eyres", 10);
    dbh->addPlayer(*me);

    //create round for the played hole
    Round *r = new Round("20-09-14", "11:01", 68, 66, 38, "Sunny", me, gc);

    //create some played holes linked to hole
}

//getPlayedHolesByRound

//getRoundsByPlayer

//getRoundsByCourse

//GetRoundsByDateTime

//getRoundByWEather

//getShotsByPlayedHoled

//getShotsByClub

//getShotsByLie

//addCourse


TEST(Database, addCourseToDatabase)
{
    GolfCourse *c = new GolfCourse(1, 74, 72, "Test GC", "add line 1", "add line 2", "cf8sl0");
    dbh->addCourse(*c);
    GolfCourse *pC = new GolfCourse();
    dbh->getCourseById(1, pC);
    ASSERT_EQ(74, pC->getStrokeIndex());
    ASSERT_EQ(72, pC->getPar());
    EXPECT_EQ(c->getName(), pC->getName());
    EXPECT_EQ(c->getAddL1(), pC->getAddL1());
    EXPECT_EQ(c->getAddL2(), pC->getAddL2());
    EXPECT_EQ(c->getPostcode(), pC->getPostcode());
    dbh->deleteCourse(*c);

    delete c;
    delete pC;
}
//getCourseByAddress

//getCourseByPar

//getCourseByName

//getCourseList

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

