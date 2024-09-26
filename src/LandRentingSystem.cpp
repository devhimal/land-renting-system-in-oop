#include "LandRentingSystem.h"
#include <chrono>
#include <iostream>
#include <fstream>

// Define a cost per square meter in NPR
const double COST_PER_SQUARE_METER_NPR = 100.0; // Adjust this value as needed

void LandRentingSystem::addLandParcel(const LandParcel &parcel)
{
    landParcels.push_back(parcel);
}

void LandRentingSystem::bookParcel(int parcelID, const std::string &tenantName, const std::chrono::system_clock::time_point &start, const std::chrono::system_clock::time_point &end)
{
    for (auto &parcel : landParcels) // Changed from parcels to landParcels
    {
        if (parcel.getParcelID() == parcelID && parcel.getAvailability())
        {
            parcel.setAvailability(false);
            Rental newRental(rentals.size() + 1, parcel, tenantName, start, end);
            rentals.push_back(newRental);
            std::cout << "Parcel booked successfully." << std::endl;
            return;
        }
    }
    std::cout << "Parcel not available or not found." << std::endl;
}

void LandRentingSystem::generateInvoice(int id)
{
    // Open the file for writing
    std::ofstream outFile("invoice_output.txt");
    if (!outFile.is_open())
    {
        std::cerr << "Unable to open file for writing." << std::endl;
        return;
    }

    // Iterate over the land parcels to find the matching parcel ID
    for (const auto &parcel : landParcels)
    {
        if (parcel.getParcelID() == id)
        {
            // Find the rental associated with this parcel ID
            for (const auto &rental : rentals)
            {
                if (rental.getParcel().getParcelID() == id)
                { // Use the getter method
                    // Calculate rental cost
                    auto startDate = std::chrono::system_clock::to_time_t(rental.getStartDate());
                    auto endDate = std::chrono::system_clock::to_time_t(rental.getEndDate());
                    auto duration = std::chrono::duration_cast<std::chrono::hours>(rental.getEndDate() - rental.getStartDate()).count();
                    double rentalCost = duration / 24.0 * COST_PER_SQUARE_METER_NPR * parcel.getArea(); // Convert hours to days

                    // Write to the file
                    outFile << "Generating invoice for Parcel ID: " << id << "\n";
                    outFile << "Location: " << parcel.getLocation() << "\n";
                    outFile << "Area: " << parcel.getArea() << " square meters\n";
                    outFile << "Rental Duration: " << duration / 24.0 << " days\n"; // Convert hours to days
                    outFile << "Cost Per Square Meter: NPR " << COST_PER_SQUARE_METER_NPR << "\n";
                    outFile << "Total Rental Cost: NPR " << rentalCost << "\n";

                    // Optionally close the file here
                    outFile.close();
                    return; // Exit the function after generating the invoice
                }
            }
            break; // Exit the loop once the parcel is found
        }
    }

    // Close the file if it is still open (in case no matching parcel ID was found)
    if (outFile.is_open())
    {
        outFile.close();
    }
}

void LandRentingSystem::displayBookedParcels() const
{
    if (rentals.empty())
    {
        std::cout << "No parcels are currently booked." << std::endl;
        return;
    }

    for (const auto &rental : rentals)
    {
        const LandParcel &parcel = rental.getParcel(); // Use the getter method
        auto duration = std::chrono::duration_cast<std::chrono::hours>(rental.getEndDate() - rental.getStartDate()).count();
        double rentalCost = duration / 24.0 * COST_PER_SQUARE_METER_NPR * parcel.getArea(); // Convert hours to days
        std::cout << "-----------Your Booking Details-----------" << std::endl;
        std::cout << "Rental ID: " << rental.getRentalID() << std::endl;
        std::cout << "Tenant: " << rental.getTenantName() << std::endl;
        std::cout << "Parcel ID: " << parcel.getParcelID() << std::endl;
        std::cout << "Location: " << parcel.getLocation() << std::endl;
        std::cout << "Area: " << parcel.getArea() << " square meters" << std::endl;
        std::cout << "Rental Duration: " << duration / 24.0 << " days" << std::endl; // Convert hours to days
        std::cout << "Cost Per Square Meter: NPR " << COST_PER_SQUARE_METER_NPR << std::endl;
        std::cout << "Total Rental Cost: NPR " << rentalCost << std::endl;
        std::cout << "-----------Your Booking Details-----------" << std::endl;
    }
}

void LandRentingSystem::displayAvailableLands() const
{
    std::cout << std::endl;
    std::cout << "-----Listing of the available lands-------" << std::endl;
    for (const auto &parcel : landParcels)
    {
        if (parcel.getAvailability())
        {
            std::cout << "Land Parcel ID: " << parcel.getParcelID()
                      << ", Location: " << parcel.getLocation()
                      << ", Area: " << parcel.getArea()
                      << ", Available: " << (parcel.getAvailability() ? "Yes" : "No") << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "-----Listing of the available lands-------" << std::endl;
}
