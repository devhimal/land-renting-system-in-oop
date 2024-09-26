#include "Invoice.h"

Invoice::Invoice(int id, const Rental &r, double amount)
    : invoiceID(id), rental(r), totalAmount(amount) {}

int Invoice::getInvoiceID() const
{
    return invoiceID;
}

void Invoice::setInvoiceID(int id)
{
    invoiceID = id;
}

Rental Invoice::getRental() const
{
    return rental;
}

void Invoice::setRental(const Rental &r)
{
    rental = r;
}

double Invoice::getTotalAmount() const
{
    return totalAmount;
}

void Invoice::setTotalAmount(double amount)
{
    totalAmount = amount;
}
