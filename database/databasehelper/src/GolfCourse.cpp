#include "GolfCourse.h"
#include <stdlib.h>
#include <iostream>

GolfCourse::GolfCourse()
{
    //ctor
}

GolfCourse::GolfCourse(int id):GolfObject(id){}

GolfCourse::GolfCourse(int id, int strokeIndex, int par, string name,
                       string addL1, string addL2, string postcode) :
                           GolfObject(id)
{
    this->strokeIndex = strokeIndex;
    this->par = par;
    this->name = name;
    this->addL1 = addL1;
    this->addL2 = addL2;
    this->postcode = postcode;
}

GolfCourse::~GolfCourse()
{
    //dtor
}

int GolfCourse::getPar()
{
    return par;
}

int GolfCourse::getStrokeIndex()
{
    return strokeIndex;
}

string GolfCourse::getName()
{
    return name;
}

string GolfCourse::getAddL1()
{
    return addL1;
}

string GolfCourse::getAddL2()
{
    return addL2;
}

string GolfCourse::getPostcode()
{
    return postcode;
}

void GolfCourse::makeFromQuery(int size, char** data, LinkedList<GolfObject>* g)
{
    GolfCourse* gc = new GolfCourse(atoi(data[0]), atoi(data[1]), atoi(data[2]), data[3], data[4], data[5], data[6]);
    g->addToHead(gc);
    /*
    cout << "AT GolfCourse" << endl;
    cout << "Hole ID = " << temp->getId() << endl;
    cout << "Par = " << temp->getPar() << endl;
    cout << "Yards = " << temp->getPostcode() << endl;
    cout << "SI = " << temp->getStrokeIndex() << endl;
    cout << "Hole Number = " << temp->getAddL1() << endl;
    */
}

bool GolfCourse::operator==(GolfObject *item)
{
    GolfCourse *gc = (GolfCourse*)item;
    if(this->id == gc->getId())
    {
        if(this->par == gc->getPar())
        {
            if(this->strokeIndex == gc->getStrokeIndex())
            {
                if(this->addL1 == gc->getAddL1())
                {
                    if(this->addL2 == gc->getAddL2())
                    {
                        if(this->name == gc->getName())
                        {
                            if(this->postcode == gc->getPostcode())
                                return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
