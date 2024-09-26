#include "Rental.h"
#include <string>

class Invoice
{
private:
    int invoiceID;
    Rental rental;
    double totalAmount;

public:
    Invoice(int id, const Rental &r, double amount);

    int getInvoiceID() const;
    void setInvoiceID(int id);

    Rental getRental() const;
    void setRental(const Rental &r);

    double getTotalAmount() const;
    void setTotalAmount(double amount);
};
