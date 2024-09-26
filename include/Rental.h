// Rental.h
#pragma once

#include "LandParcel.h"
#include <chrono> //Used for Time
#include <string>

class Rental
{
private:
    int rentalID;
    LandParcel parcel;
    std::string tenantName;
    std::chrono::system_clock::time_point startDate;
    std::chrono::system_clock::time_point endDate;

public:
    Rental(int id, const LandParcel &p, const std::string &tenant,
           const std::chrono::system_clock::time_point &start,
           const std::chrono::system_clock::time_point &end);

    int getRentalID() const;
    void setRentalID(int id);

    LandParcel getLandParcel() const;
    void setLandParcel(const LandParcel &p);

    std::string getTenantName() const;
    void setTenantName(const std::string &name);

    std::chrono::system_clock::time_point getStartDate() const;
    void setStartDate(const std::chrono::system_clock::time_point &start);

    std::chrono::system_clock::time_point getEndDate() const;
    void setEndDate(const std::chrono::system_clock::time_point &end);

    const LandParcel &getParcel() const;
};
