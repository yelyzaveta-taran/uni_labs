#include "PrintedPublication.h"
#include "Book.h"
#include "constants.h"

#include <iostream>

int main()
{
    Book book;
    book.addGenre(BookGenre::Fantasy);
    book.addGenre(BookGenre::Fantasy);
    book.addGenre(BookGenre::Historical);
    book.deleteGenre(BookGenre::Historical);
    book.deleteGenre(BookGenre::Historical);
    book.printInfo();
}
