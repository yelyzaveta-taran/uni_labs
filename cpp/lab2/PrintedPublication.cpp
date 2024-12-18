#include <iostream>
#include <iomanip>
#include "PrintedPublication.h"
#include "constants.h"
#include "helpers.h"

using namespace std;

PrintedPublication::PrintedPublication()
    : m_name(""), m_type(PublicationType::Book), m_state(PublicationState::Unpublished),
      m_pageCount(0), m_circulation(0), m_price(0.0), m_rates(nullptr), m_ratesSize(0),
      m_releaseDate(""), m_reprintDate("") {}

PrintedPublication::PrintedPublication(string_view name, PublicationType type, unsigned int pageCount, unsigned int circulation, double price, double rates[], size_t ratesSize)
    : m_name(name), m_type(type), m_pageCount(pageCount), m_state(PublicationState::Unpublished), m_price(price), m_ratesSize(ratesSize)
{
    if (circulation < 100)
    {
        m_circulation = 100;
        cerr << "Warning [Constructor]: The circulation count's min value is 100." << endl;
    }
    else
    {
        m_circulation = circulation;
    }

    if (ratesSize > 0 && rates != nullptr)
    {
        m_rates = new double[ratesSize];
        for (size_t i = 0; i < ratesSize; i++)
        {
            m_rates[i] = rates[i];
        }
    }
    else
    {
        cerr << "Warning [Constructor]: original's rates array is null or ratesSize is zero. No data was copied." << endl;
    }
    cout << "[Constructor]: Constructor was called." << endl;
}

PrintedPublication::~PrintedPublication()
{
    delete[] m_rates;
    m_rates = nullptr;
    cout << "[Destructor]: Destructor was called." << endl;
}

PrintedPublication::PrintedPublication(const PrintedPublication &original)
{
    m_name = original.m_name;
    m_type = original.m_type;
    m_pageCount = original.m_pageCount;
    m_circulation = original.m_circulation;
    m_price = original.m_price;
    m_ratesSize = original.m_ratesSize;

    if (original.m_rates != nullptr && m_ratesSize > 0)
    {
        m_rates = new double[m_ratesSize];
        for (size_t i = 0; i < m_ratesSize; i++)
        {
            m_rates[i] = original.m_rates[i];
        }
    }
    else
    {
        m_rates = nullptr;
        cerr << "Warning [Copy Constructor]: original's rates array is null or ratesSize is zero. No data was copied." << endl;
    }
    cout << "[Copy Constructor]: Constructor was called." << endl;
}

void PrintedPublication::updateCirculation(unsigned int newCirculation)
{
    if (newCirculation < 100)
    {
        cerr << "Error: The circulation cannot be less than 100." << endl;
        return;
    }

    m_circulation = newCirculation;

    cout << "Circulation successfully updated to " << m_circulation << "." << endl;
}

void PrintedPublication::updateName(string_view name)
{
    m_name = name;
    cout << "Name successfully updated to " << m_name << "." << endl;
}

string PrintedPublication::getType() const
{
    switch (m_type)
    {
    case PublicationType::Book:
        return "Book";
    case PublicationType::Magazine:
        return "Magazine";
    case PublicationType::Newspaper:
        return "Newspaper";
    default:
        return "Unknown";
    }
}

void PrintedPublication::updateType(PublicationType type)
{
    m_type = type;
    cout << "Type successfully updated to " << getType() << "." << endl;
}

void PrintedPublication::updatePageCount(unsigned int newCount)
{
    if (newCount <= 0)
    {
        cerr << "Error: Page count cannot be zero or negative." << endl;
        return;
    }
    m_pageCount = newCount;
    cout << "Page count successfully updated to " << m_pageCount << "." << endl;
}

void PrintedPublication::updatePrice(double newPrice)
{
    if (newPrice < 0)
    {
        cerr << "Error: Price cannot be a negative value." << endl;
        return;
    }
    m_price = newPrice;
}

void PrintedPublication::addRate(double rate)
{
    double *newRates = new double[m_ratesSize + 1];

    for (size_t i = 0; i < m_ratesSize; i++)
    {
        newRates[i] = m_rates[i];
    }

    newRates[m_ratesSize] = rate;

    delete[] m_rates;
    m_rates = newRates;

    m_ratesSize++;
}

void PrintedPublication::publish()
{
    if (m_state == PublicationState::Published || m_state == PublicationState::Reprinted)
    {
        cerr << "Error: The publication has already been published." << endl;
        return;
    }

    m_state = PublicationState::Published;

    m_releaseDate = getCurrentDate();
    cout << "The publication has been successfully published on " << m_releaseDate << "." << endl;
}

void PrintedPublication::cancelPublication()
{
    if (m_state == PublicationState::Unpublished)
    {
        cout << "Error: The publication hasn't been published yet." << endl;
        return;
    }
    m_state = PublicationState::Unpublished;
    m_releaseDate = "";
    m_reprintDate = "";
    cout << "The publication has been successfully unpublished." << endl;
}

void PrintedPublication::reprint(unsigned int circulation)
{
    if (m_state == PublicationState::Unpublished)
    {
        cerr << "Error: The publication hasn't been published yet." << endl;
        return;
    }

    if (circulation <= 0)
    {
        cerr << "Error: To reprint enter the valid circulation count." << endl;
        return;
    }

    updateCirculation(m_circulation + circulation);

    m_state = PublicationState::Reprinted;
    m_reprintDate = getCurrentDate();

    cout << "The publication has been successfully reprinted." << endl;
}

string PrintedPublication::getName() const
{
    return m_name;
}

unsigned int PrintedPublication::getPageCount() const
{
    return m_pageCount;
}

unsigned int PrintedPublication::getCirculation() const
{
    return m_circulation;
}

double PrintedPublication::getPrice() const
{
    return m_price;
}

string PrintedPublication::getRates() const
{
    ostringstream oss;
    oss << "[ ";
    for (size_t i = 0; i < m_ratesSize; i++)
    {
        oss << m_rates[i] << " ";
    }
    oss << "]";
    return oss.str();
}

string PrintedPublication::getState() const
{
    switch (m_state)
    {
    case PublicationState::Published:
        return "Published";
    case PublicationState::Unpublished:
        return "Unpublished";
    case PublicationState::Reprinted:
        return "Reprinted";
    default:
        return "Unknown";
    }
}

string PrintedPublication::getReleaseDate() const
{
    return m_releaseDate;
}

string PrintedPublication::getReprintDate() const
{
    return m_reprintDate;
}

void PrintedPublication::printInfo() const
{
    cout << "Publication Information:" << endl;
    cout << "----------------------------------" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Type: " << getType() << endl;
    cout << "Page Count: " << getPageCount() << endl;
    cout << "Circulation: " << getCirculation() << endl;
    cout << "Price: $" << getPrice() << endl;
    cout << "Rates: " << getRates() << endl;
    cout << "State: " << getState() << endl;
    cout << "Release date: " << getReleaseDate() << endl;
    cout << "Reprint date: " << getReprintDate() << endl;
    cout << "----------------------------------" << endl;
}