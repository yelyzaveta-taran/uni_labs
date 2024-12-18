#include "PrintedPublication.h"
#include "constants.h"

#include <iostream>

int main()
{
    double rates[] = {4.5, 3, 5, 2.8};
    size_t ratesSize = std::size(rates);

    PrintedPublication book("C++ Guide", PublicationType::Book, 350, 1000, 29.99, rates, ratesSize);

    book.publish();
    book.reprint(0);

    book.printInfo();
}