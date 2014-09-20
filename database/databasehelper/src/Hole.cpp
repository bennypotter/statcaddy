#include "Hole.h"
#include <cstring>

Hole::Hole(){}

Hole::Hole(int id):GolfObject(id){}

Hole::Hole(int id, int courseId, int par, int strokeIndex, int yards, int holeNum, string shape)
        :GolfObject(id)
{
    this->par = par;
    this->strokeIndex = strokeIndex;
    this->yards = yards;
    this->holeNum = holeNum;
    this->shape = shape;
}

Hole::Hole(Hole* source):GolfObject(source->getId())
{
    this->par = source->getPar();
    this->strokeIndex = source->getStrokeIndex();
    this->yards = source->getYards();
    this->holeNum = source->getHoleNum();
    this->shape = source->getShape();
}

Hole::Hole(const Hole &obj):GolfObject(obj)
{
    cout << "In copy constructor" << endl;
    par = obj.par;
    strokeIndex = obj.strokeIndex;
    yards = obj.yards;
    holeNum = obj.holeNum;
    cout << obj.shape << endl;
    shape = obj.shape;
    //shape = new char[strlen(obj.shape)+1];
    //strcpy(shape, obj.shape);
}

Hole::~Hole()
{
}

Hole& Hole::operator=(const Hole &obj)
{
    id = obj.id;
    par = obj.par;
    strokeIndex = obj.strokeIndex;
    yards = obj.yards;
    holeNum = obj.holeNum;
    shape = obj.shape;
    //shape = new char[strlen(obj.shape)+1];
    //strcpy(shape, obj.shape);
}

int Hole::getPar()
{
    return par;
}

void Hole::setPar(int par)
{
    this->par = par;
}

int Hole::getStrokeIndex()
{
    return strokeIndex;
}

void Hole::setStrokeIndex(int par)
{
    this->strokeIndex = strokeIndex;
}

int Hole::getYards()
{
    return yards;
}

void Hole::setYards(int yards)
{
    this->yards = yards;
}

int Hole::getHoleNum()
{
    return holeNum;
}

void Hole::setHoleNum(int holeNum)
{
    this->holeNum = holeNum;
}

string Hole::getShape()
{
    return shape;
}

void Hole::setShape(string shape)
{
    this->shape = shape;
}

void Hole::makeFromQuery(int size, char** data, LinkedList<GolfObject>* g)
{
    //Hole* temp = (Hole *)g;
    Hole *h = new Hole(atoi(data[0]), atoi(data[1]), atoi(data[2]), atoi(data[3]), atoi(data[4]), atoi(data[5]), data[6]);
    //*temp = h;
    g->addToTail(h);

    //printf("AT Hole\n");
    //printf("Hole ID = %d\n", h->getId());
    //printf("Par = %d\n", h->getPar());
    //printf("Yards = %d\n", h->getYards());
    //printf("SI = %d\n", h->getStrokeIndex());
    //printf("Hole Number = %d\n", h->getHoleNum());
//    printf("Shape = %s\n", temp->getShape());
}

bool Hole::operator==(GolfObject *item)
{
    Hole *h = (Hole*)item;
    if(this->id == item->getId())
    {
        if(this->par == h->getPar())
        {
            if(this->strokeIndex == h->getStrokeIndex())
            {
                if(this->yards == h->getYards())
                {
                    if(this->holeNum == h->getHoleNum())
                    {
                        if(this->shape == h->getShape())
                            return true;
                    }
                }
            }
        }
    }
    return false;
}
