#ifndef BOOK_H
#define BOOK_H

#include "PrintedPublication.h"
#include <vector>

using namespace std;

class Book : public PrintedPublication
{

private:
    vector<BookGenre> m_genres;
    string m_author;
    unsigned int m_chaptersNumber;

public:
    Book();
    Book(string_view name, unsigned int pageCount, unsigned int circulation, double price, double rates[],
         size_t ratesSize, vector<BookGenre> genres, string_view author, unsigned int chaptersNumber);
    Book(const Book &original);
    ~Book();

    // Setters
    void setAuthor(string_view author);
    void setChaptersNumber(unsigned int number);
    void addGenre(BookGenre genre);
    void deleteGenre(BookGenre genre);

    // Getters
    string getAuthor() const;
    unsigned int getChaptersNumber() const;
    string listGenres() const;

    // Override
    void printInfo() const override;
    string getDescription() const override;

protected:
    string genreToString(BookGenre genre) const;
};

#endif