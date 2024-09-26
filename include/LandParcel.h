#pragma once
#include <string>

class LandParcel
{
private:
    int parcelID;
    std::string location;
    double area;
    bool isAvailable;

public:
    LandParcel(int id, const std::string &loc, double ar, bool avail);

    // Getter and Setter methods
    int getParcelID() const;
    void setParcelID(int id);

    std::string getLocation() const;
    void setLocation(const std::string &loc);

    double getArea() const;
    void setArea(double ar);

    bool getAvailability() const;
    void setAvailability(bool avail);
};
