#include "GolfObject.h"

GolfObject::GolfObject()
{
}

GolfObject::GolfObject(int id)
{
    this->id = id;
}

GolfObject::GolfObject(GolfObject* source)
{
    this->id = source->getId();
}

GolfObject::GolfObject(const GolfObject &obj)
{
    id = obj.id;
}


GolfObject::~GolfObject()
{
    //dtor
}
int GolfObject::getId()
{
    return id;
}

void GolfObject::setId(int id)
{
    this->id = id;
}

bool GolfObject::operator==(GolfObject *item)
{
    if(this->id == item->getId())
        return true;
    else
        return false;
}
