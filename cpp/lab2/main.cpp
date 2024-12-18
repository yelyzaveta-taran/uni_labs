#include "PrintedPublication.h"
#include "constants.h"

#include <iostream>

int main()
{
    double rates[] = {4.5, 3, 5, 2.8};
    size_t ratesSize = std::size(rates);

    PrintedPublication book("C++ Guide", PublicationType::Book, 350, 100, 29.99, rates, ratesSize);

    PrintedPublication book1(book);
    book1.printInfo();
}