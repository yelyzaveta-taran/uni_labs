#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "PrintedPublication.h"
#include "constants.h"
#include "helpers.h"

using namespace std;

PrintedPublication::PrintedPublication(const char *name, PublicationType type, unsigned int pageCount, unsigned int circulation, double price)
    : m_type(type), m_pageCount(pageCount), m_circulation(circulation), m_price(price), m_state(State::Unpublished)
{
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
};

PrintedPublication::~PrintedPublication()
{
    delete[] m_name;
    m_name = nullptr;
}

void PrintedPublication::updateCirculation(unsigned int newCirculation)
{
    if (newCirculation <= 0)
    {
        std::cerr << "Error: Circulation cannot be zero or negative." << std::endl;
        return;
    }

    m_circulation = newCirculation;

    std::cout << "Circulation successfully updated to " << m_circulation << "." << std::endl;
}

void PrintedPublication::updateName(const char *name)
{
    delete[] m_name;

    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);

    std::cout << "Name successfully updated to " << m_name << "." << std::endl;
}

const char *PrintedPublication::getType() const
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
    std::cout << "Type successfully updated to " << getType() << "." << std::endl;
}

void PrintedPublication::updatePageCount(unsigned int newCount)
{
    if (newCount <= 0)
    {
        std::cerr << "Error: Page count cannot be zero or negative." << std::endl;
        return;
    }
    m_pageCount = newCount;
    std::cout << "Page count successfully updated to " << m_pageCount << "." << std::endl;
}

void PrintedPublication::updatePrice(double newPrice)
{
    if (newPrice <= 0)
    {
        std::cerr << "Error: Price cannot be zero or negative." << std::endl;
        return;
    }
}

void PrintedPublication::publish()
{
    if (m_state == State::Published || m_state == State::Reprinted)
    {
        std::cerr << "Error: The publication has already been published." << std::endl;
        return;
    }

    if (m_circulation <= 0)
    {
        std::cerr << "Error: The circulation cannot be zero or negative." << std::endl;
        return;
    }

    m_state = State::Published;

    m_releaseDate = getCurrentDate();
    std::cout << "The publication has been successfully published on " << m_releaseDate << "." << std::endl;
}

void PrintedPublication::cancelPublication()
{
    if (m_state = State::Unpublished)
    {
        std::cout << "Error: The publication hasn't been published yet." << std::endl;
        return;
    }
    m_state = State::Unpublished;
    m_releaseDate = "";
    m_reprintDate = "";
    std::cout << "The publication has been successfully unpublished." << std::endl;
}

void PrintedPublication::reprint(unsigned int newCirculation)
{
    if (m_state == State::Unpublished)
    {
        std::cerr << "Error: The publication hasn't been published yet.";
        return;
    }
    if (newCirculation <= m_circulation)
    {
        std::cerr << "Error: The circulation count must be increased.";
        return;
    };

    updateCirculation(newCirculation);

    m_state = State::Reprinted;
    m_reprintDate = getCurrentDate();

    std::cout << "The publication has been successfully reprinted." << std::endl;
}

const char *PrintedPublication::getName() const
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

const char *PrintedPublication::getState() const
{
    switch (m_state)
    {
    case State::Published:
        return "Published";
    case State::Unpublished:
        return "Unpublished";
    case State::Reprinted:
        return "Reprinted";
    default:
        return "Unknown";
    }
}

const char *PrintedPublication::getReleaseDate() const
{
    return m_releaseDate;
}

const char *PrintedPublication::getReprintDate() const
{
    return m_reprintDate;
}

void PrintedPublication::printInfo() const
{
    std::cout << "Publication Information:" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Page Count: " << getPageCount() << std::endl;
    std::cout << "Circulation: " << getCirculation() << std::endl;
    std::cout << setprecision(2);
    std::cout << "Price: $" << getPrice() << std::endl;
    std::cout << "State: " << getState() << std::endl;
    std::cout << "Release date: " << getReleaseDate() << std::endl;
    std::cout << "Reprint date: " << getReprintDate() << std::endl;
    std::cout << "----------------------------------" << std::endl;
}