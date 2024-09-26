#include "LandRentingSystem.h"
#include <iostream>
#include <chrono>

void displayMenu()
{
    std::cout << "1. Display Available Lands" << std::endl;
    std::cout << "2. Book a Parcel" << std::endl;
    std::cout << "3. Generate Invoice" << std::endl;
    std::cout << "4. Display Booked Parcels" << std::endl; // Added option for displaying booked parcels
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main()
{
    LandRentingSystem system; //OOP Concepts used: Object Created

    // Adding land parcels with sample data
    LandParcel parcel1(1, "Location A", 100.0, true);
    LandParcel parcel2(2, "Location B", 200.0, true);
    LandParcel parcel3(3, "Location C", 150.0, true);
    LandParcel parcel4(4, "Location D", 250.0, true);
    LandParcel parcel5(5, "Location E", 300.0, true);

    system.addLandParcel(parcel1);
    system.addLandParcel(parcel2);
    system.addLandParcel(parcel3);
    system.addLandParcel(parcel4);
    system.addLandParcel(parcel5);

    int choice;
    std::string tenant;
    std::chrono::system_clock::time_point start, end;

    while (true)
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            // Display available lands
            std::cout << "Available Land Parcels:" << std::endl;
            system.displayAvailableLands();
            break;

        case 2:
            // Book a parcel
            int parcelID;
            std::cout << "Enter Land Parcel ID to book: ";
            std::cin >> parcelID;
            std::cout << "Enter tenant name: ";
            std::cin.ignore(); // To ignore any newline characters left in the input buffer
            std::getline(std::cin, tenant);

            start = std::chrono::system_clock::now(); // Current time
            end = start + std::chrono::hours(24 * 7); // Add 7 days

            system.bookParcel(parcelID, tenant, start, end);
            break;

        case 3:
            // Generate an invoice
            int invoiceID;
            std::cout << "Enter Land Parcel ID to generate invoice: ";
            std::cin >> invoiceID;
            system.generateInvoice(invoiceID);
            break;

        case 4:
            // Display booked parcels
            std::cout << "Booked Land Parcels:" << std::endl;
            system.displayBookedParcels();
            break;

        case 5:
            // Exit the program
            std::cout << "Exiting the program." << std::endl;
            return 0;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
