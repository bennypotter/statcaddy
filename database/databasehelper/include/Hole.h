#ifndef HOLE_H
#define HOLE_H

#include <GolfObject.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <LinkedList.h>

using namespace std;

class Hole : public GolfObject
{
    public:
        Hole();
        Hole(int);
        Hole(int,int,int,int,int,int,string);
        Hole(Hole*);
        Hole(const Hole &obj);
        virtual ~Hole();
        Hole& operator=(const Hole &obj);
        int getPar();
        void setPar(int);
        int getStrokeIndex();
        void setStrokeIndex(int);
        int getYards();
        void setYards(int);
        int getHoleNum();
        void setHoleNum(int);
        int getCourseId();
        void setCourseId(int);
        string getShape();
        void setShape(string);
        void makeFromQuery(int, char**, LinkedList<GolfObject> *);
        bool operator==(GolfObject*);
    protected:
    private:
        int courseId;
        int par;
        int strokeIndex;
        int yards;
        int holeNum;
        string shape;
};

#endif // HOLE_H
