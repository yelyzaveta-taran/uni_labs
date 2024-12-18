#include "PrintedPublication.h"
#include "constants.h"

#include <iostream>

int main()
{
    double rates1[] = {4.5, 3.8, 5.0};
    double rates2[] = {4.0, 4.2};

    PrintedPublication book1("C++ Guide", PublicationType::Book, 350, 5000, 29.99, rates1, 3);
    PrintedPublication book2("Design Patterns", PublicationType::Book, 400, 3000, 39.99, rates2, 2);
    PrintedPublication book3;
    PrintedPublication book4(book3);

    book4.incrementCirculation(2000);

    cout << "Book1 circulation: " << book1.getCirculation() << endl;
    cout << "Book2 circulation: " << book2.getCirculation() << endl;
    cout << "Book3 circulation: " << book3.getCirculation() << endl;
    cout << "Book4 circulation: " << book4.getCirculation() << endl;

    PrintedPublication::printStatistics();

    return 0;
}