#include "PrintedPublication.h"
#include "Book.h"
#include "Magazine.h"
#include "constants.h"

#include <iostream>

int main()
{
    Book myBook("The Chronicles of AI", 300, 5000, 14.99, (double[]){4.5, 4.8, 4.5, 3.2}, 3, {BookGenre::ScienceFiction}, "John Doe", 15);
    Magazine myMagazine("Tech Weekly", 50, 2000, 9.99, (double[]){4.5, 4.8}, 3, 42, "Alice Johnson", Periodicity::Weekly);

    myBook.printInfo();
    cout << myBook.getDescription() << endl;

    myMagazine.printInfo();
    cout << myMagazine.getDescription() << endl;
}
