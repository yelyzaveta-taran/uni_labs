#include "Book.h"
#include "PrintedPublication.h"
#include "constants.h"

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

Book::Book() : PrintedPublication(), m_chaptersNumber(0)
{
  cout << "[Default Constructor]: Constructor was called for Book object." << endl;
};

Book::Book(string_view name, unsigned int pageCount, unsigned int circulation, double price, double rates[],
           size_t ratesSize, vector<BookGenre> genres, string_view author, unsigned int chaptersNumber)
    : PrintedPublication(name, PublicationType::Book, pageCount, circulation, price, rates, ratesSize),
      m_genres(genres), m_author(author), m_chaptersNumber(chaptersNumber)
{
  cout << "[Parametrized Constructor]: Constructor was called for Book object." << endl;
}

Book::Book(const Book &original) : PrintedPublication(original),
                                   m_genres(original.m_genres), m_author(original.m_author), m_chaptersNumber(original.m_chaptersNumber)
{
  cout << "[Copy Constructor]: Constructor was called for Book object." << endl;
};

Book::~Book()
{
  cout << "[Destructor]: Destructor was called for Book object." << endl;
}

void Book::setAuthor(string_view author)
{
  m_author = author;
  cout << "The author's value has been changed to" << author << endl;
}

void Book::setChaptersNumber(unsigned int number)
{
  if (number <= 0)
  {
    cout << "The number of chapters has to be positive value.";
    return;
  }
  m_chaptersNumber = number;
  cout << "The number of chapters value has been changed to" << number << endl;
}

void Book::addGenre(BookGenre genre)
{
  auto it = find(m_genres.begin(), m_genres.end(), genre);
  if (it != m_genres.end())
  {
    cout << "The genre is already present in the list." << endl;
    return;
  }
  m_genres.push_back(genre);
  cout << "Genre added successfully." << endl;
}

void Book::deleteGenre(BookGenre genre)
{
  auto it = remove(m_genres.begin(), m_genres.end(), genre);
  if (it == m_genres.end())
  {
    cout << "The genre is absent in the list." << endl;
    return;
  }
  m_genres.erase(it, m_genres.end());
  cout << "Genre removed successfully." << endl;
}

string Book::genreToString(BookGenre genre) const
{
  switch (genre)
  {
  case BookGenre::Fiction:
    return "Fiction";
  case BookGenre::NonFiction:
    return "NonFiction";
  case BookGenre::Mystery:
    return "Mystery";
  case BookGenre::Fantasy:
    return "Fantasy";
  case BookGenre::Biography:
    return "Biography";
  case BookGenre::ScienceFiction:
    return "Science Fiction";
  case BookGenre::Romance:
    return "Romance";
  case BookGenre::Thriller:
    return "Thriller";
  case BookGenre::Historical:
    return "Historical";
  default:
    return "Unknown Genre";
  }
}

string Book::listGenres() const
{
  if (m_genres.empty())
  {
    return "[ ]";
  }

  std::ostringstream oss;
  oss << "[ ";
  for (size_t i = 0; i < m_genres.size(); ++i)
  {
    oss << genreToString(m_genres[i]);
    if (i != m_genres.size() - 1)
    {
      oss << ", ";
    }
  }
  oss << " ]";
  return oss.str();
}

string Book::getAuthor() const
{
  return m_author;
}

unsigned int Book::getChaptersNumber() const
{
  return m_chaptersNumber;
}

void Book::printInfo() const
{
  cout << "Publication Information:" << endl;
  cout << "----------------------------------" << endl;
  cout << "Type: " << getType() << endl;
  cout << "Name: " << getName() << endl;
  cout << "Author: " << getAuthor() << endl;
  cout << "Genres: " << listGenres() << endl;
  cout << "Number of chapters: " << getChaptersNumber() << endl;
  cout << "Page Count: " << getPageCount() << endl;
  cout << "Circulation: " << getCirculation() << endl;
  cout << "Price: $" << getPrice() << endl;
  cout << "Rates: " << getRates() << endl;
  cout << "State: " << getState() << endl;
  cout << "Release date: " << getReleaseDate() << endl;
  cout << "Reprint date: " << getReprintDate() << endl;
  cout << "----------------------------------" << endl;
}