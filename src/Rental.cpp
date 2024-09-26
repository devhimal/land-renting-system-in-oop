// Rental.cpp
#include "Rental.h"

Rental::Rental(int id, const LandParcel &p, const std::string &tenant,
               const std::chrono::system_clock::time_point &start,
               const std::chrono::system_clock::time_point &end)
    : rentalID(id), parcel(p), tenantName(tenant), startDate(start), endDate(end) {}

int Rental::getRentalID() const
{
    return rentalID;
}

void Rental::setRentalID(int id)
{
    rentalID = id;
}

LandParcel Rental::getLandParcel() const
{
    return parcel;
}

void Rental::setLandParcel(const LandParcel &p)
{
    parcel = p;
}

std::string Rental::getTenantName() const
{
    return tenantName;
}

void Rental::setTenantName(const std::string &name)
{
    tenantName = name;
}

std::chrono::system_clock::time_point Rental::getStartDate() const
{
    return startDate;
}

void Rental::setStartDate(const std::chrono::system_clock::time_point &start)
{
    startDate = start;
}

std::chrono::system_clock::time_point Rental::getEndDate() const
{
    return endDate;
}

void Rental::setEndDate(const std::chrono::system_clock::time_point &end)
{
    endDate = end;
}

const LandParcel &Rental::getParcel() const
{
    return parcel;
}
