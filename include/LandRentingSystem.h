#ifndef LANDRENTINGSYSTEM_H
#define LANDRENTINGSYSTEM_H

#include "LandParcel.h"
#include "Rental.h"
#include "Invoice.h"
#include <vector>

class LandRentingSystem
{
private:
    std::vector<LandParcel> parcels;
    std::vector<Rental> rentals;
    std::vector<Invoice> invoices;
    std::vector<LandParcel> landParcels;

public:
    void addLandParcel(const LandParcel &parcel);
    void bookParcel(int parcelID, const std::string &tenantName, const std::chrono::system_clock::time_point &start, const std::chrono::system_clock::time_point &end);
    void generateInvoice(int rentalID);
    void displayAvailableLands() const;
    void displayBookedParcels() const;
};

#endif // LANDRENTINGSYSTEM_H
