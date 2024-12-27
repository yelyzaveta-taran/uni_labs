#include "PrintedPublication.h"
#include "Book.h"
#include "Magazine.h"
#include "constants.h"
#include "vectorOperations.h"
#include <vector>

using namespace std;

#include <iostream>

int main()
{
    vector<PrintedPublication *> publications;

    // Placing objects in the container
    placeObject(publications, new Book("The Chronicles of AI", 300, 5000, 14.99, (double[]){4.5, 4.8, 4.5, 3.2}, 3, {BookGenre::ScienceFiction}, "John Doe", 15), 0);
    placeObject(publications, new Magazine("Tech Weekly", 50, 2000, 9.99, (double[]){4.5, 4.8}, 3, 42, "Alice Johnson", Periodicity::Weekly), 1);
    placeObject(publications, new Book("1984", 328, 5000, 19.99, (double[]){4.5, 4.8, 4.5, 3.2}, 3, {BookGenre::Fiction, BookGenre::ScienceFiction}, "George Orwell", 24), 2);

    cout << endl;
    printPublicationNames(publications);

    // Sorting by pageCount
    sortByPageCount(publications);
    cout << endl;
    cout << "Sorted Publications by Page Count:" << endl;
    for (auto *publication : publications)
    {
        cout << publication->getName() << " - " << publication->getPageCount() << " pages" << endl;
    }

    // Searching by name
    PrintedPublication *found = findObject(publications, "1984");
    cout << endl;
    if (found)
    {
        cout << "Found publication: " << found->getName() << endl;
    }
    else
    {
        cout << "Publication not found!" << endl;
    }

    // Cleaning
    clearContainer(publications);
}
