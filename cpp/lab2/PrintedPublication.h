#ifndef PRINTED_PUBLICATION_H
#define PRINTED_PUBLICATION_H

#include <string>
#include "constants.h"

using namespace std;

class PrintedPublication
{
private:
    char *m_name;
    PublicationType m_type;
    unsigned int m_pageCount;
    unsigned int m_circulation;
    double m_price;
    const char *m_releaseDate;
    const char *m_reprintDate;
    State m_state;

    void updateCirculation(unsigned int newCirculation);

public:
    // Constructors
    PrintedPublication(const char *name, PublicationType type, unsigned int pageCount, unsigned int circulation, double price);

    // Destructor
    ~PrintedPublication();

    // Methods
    void publish();
    void cancelPublication();
    void reprint(unsigned int newCirculation);

    // Setters
    void updateName(const char *newName);
    void updateType(PublicationType type);
    void updatePageCount(unsigned int newCount);
    void updatePrice(double newPrice);

    // Getters
    void printInfo() const;
    const char *getName() const;
    const char *getType() const;
    unsigned int getPageCount() const;
    unsigned int getCirculation() const;
    double getPrice() const;
    const char *getState() const;
    const char *getReleaseDate() const;
    const char *getReprintDate() const;
};

#endif