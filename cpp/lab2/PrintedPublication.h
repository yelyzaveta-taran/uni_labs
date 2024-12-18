#ifndef PRINTED_PUBLICATION_H
#define PRINTED_PUBLICATION_H

#include <string>
#include "constants.h"

using namespace std;

class PrintedPublication
{
private:
    string m_name;
    PublicationType m_type;
    PublicationState m_state;
    unsigned int m_pageCount;
    unsigned int m_circulation;
    double m_price;
    double *m_rates;
    size_t m_ratesSize;
    string m_releaseDate;
    string m_reprintDate;

public:
    // Constructors
    PrintedPublication();
    PrintedPublication(string_view name, PublicationType type, unsigned int pageCount, unsigned int circulation, double price, double rates[], size_t ratesSize);
    PrintedPublication(const PrintedPublication &original);

    // Destructor
    ~PrintedPublication();

    // Methods
    void publish();
    void cancelPublication();
    void reprint(unsigned int circulation);
    void incrementCirculation(unsigned int circulation);
    void addRate(double rate);

    // Setters
    void setName(string_view newName);
    void setType(PublicationType type);
    void setPageCount(unsigned int newCount);
    void setCirculation(unsigned int newCirculation);
    void setPrice(double newPrice);

    // Getters
    void printInfo() const;
    string getName() const;
    string getType() const;
    unsigned int getPageCount() const;
    unsigned int getCirculation() const;
    double getPrice() const;
    string getRates() const;
    string getState() const;
    string getReleaseDate() const;
    string getReprintDate() const;
};

#endif