#include "PrintedPublication.h"
#include "constants.h"

int main()
{
    double rates[] = {4.5, 4.7, 4.8, 4.6};
    size_t ratesSize = std::size(rates);

    PrintedPublication book("C++ Guide", PublicationType::Book, 350, 100, 29.99, rates, ratesSize);
    book.cancelPublication();
    book.printInfo();
}