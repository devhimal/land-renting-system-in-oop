#include "LandParcel.h"

LandParcel::LandParcel(int id, const std::string &loc, double ar, bool avail)
    : parcelID(id), location(loc), area(ar), isAvailable(avail) {}

int LandParcel::getParcelID() const
{
    return parcelID;
}

void LandParcel::setParcelID(int id)
{
    parcelID = id;
}

std::string LandParcel::getLocation() const
{
    return location;
}

void LandParcel::setLocation(const std::string &loc)
{
    location = loc;
}

double LandParcel::getArea() const
{
    return area;
}

void LandParcel::setArea(double ar)
{
    area = ar;
}

bool LandParcel::getAvailability() const
{
    return isAvailable;
}

void LandParcel::setAvailability(bool avail)
{
    isAvailable = avail;
}
