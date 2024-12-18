#include "PrintedPublication.h"
#include "constants.h"

#include <iostream>

int main()
{
    double rates[] = {4.5, 3, 5, 2.8};
    size_t ratesSize = std::size(rates);

    PrintedPublication book("C++ Guide", PublicationType::Book, 350, 100, 29.99, rates, ratesSize);

    book.setName("JavaScript Guide");
    book.setType(PublicationType::Magazine);
    book.setPrice(15.50);
    book.setPageCount(85);

    book.addRate(1);

    book.printInfo();
}
