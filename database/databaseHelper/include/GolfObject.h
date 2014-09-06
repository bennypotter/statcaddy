#ifndef GOLFOBJECT_H
#define GOLFOBJECT_H

#include <LinkedList.h>

class GolfObject
{
    public:
        GolfObject();
        GolfObject(int);
        GolfObject(GolfObject*);
        GolfObject( const GolfObject &obj); //Copy Constructor
        virtual ~GolfObject();
        int getId();
        void setId(int);
        virtual bool operator==(GolfObject*);
        virtual void makeFromQuery(int, char**, LinkedList<GolfObject> *) = 0;
    protected:
        int id;
    private:
};

#endif // GOLFOBJECT_H
