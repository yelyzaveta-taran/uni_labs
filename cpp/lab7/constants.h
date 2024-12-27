#ifndef CONSTANTS_H
#define CONSTANTS_H

enum struct PublicationType
{
    Book,
    Newspaper,
    Magazine
};

enum struct PublicationState
{
    Published,
    Unpublished,
    Reprinted
};

enum class BookGenre
{
    Fiction,
    NonFiction,
    Mystery,
    Fantasy,
    Biography,
    ScienceFiction,
    Romance,
    Thriller,
    Historical
};

enum class Periodicity
{
    Daily,
    Weekly,
    BiWeekly,
    Monthly,
    Quarterly,
    Annually
};

#endif