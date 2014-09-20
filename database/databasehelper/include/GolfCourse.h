#ifndef GOLFCOURSE_H
#define GOLFCOURSE_H

#include <GolfObject.h>
#include <string>

using namespace std;

class GolfCourse : public GolfObject
{
    public:
        GolfCourse();
        GolfCourse(int);
        GolfCourse(int,int,int,string,string,string, string);
        virtual ~GolfCourse();
        int getStrokeIndex();
        void setStrokeIndex(int&);
        int getPar();
        void setPar(int&);
        string getName();
        void setName(string&);
        string getAddL1();
        void setAddL1(string&);
        string getAddL2();
        void setAddL2(string&);
        string getPostcode();
        void setPostcode(string&);
        void makeFromQuery(int, char**, LinkedList<GolfObject> *);
        bool operator==(GolfObject*);
    protected:
    private:
        int strokeIndex;
        int par;
        string name;
        string addL1;
        string addL2;
        string postcode;
};

#endif // GOLFCOURSE_H
