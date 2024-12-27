#include "Magazine.h"
#include "constants.h"
#include <iostream>
#include <sstream>

using namespace std;

Magazine::Magazine()
    : PrintedPublication(), m_issueNumber(0), m_editorName(""), m_periodicity(Periodicity::Monthly)
{
    setType(PublicationType::Magazine);
}

Magazine::Magazine(string_view name, unsigned int pageCount, unsigned int circulation, double price,
                   double rates[], size_t ratesSize, unsigned int issueNumber, string_view editorName, Periodicity periodicity)
    : PrintedPublication(name, PublicationType::Magazine, pageCount, circulation, price, rates, ratesSize),
      m_issueNumber(issueNumber), m_editorName(editorName), m_periodicity(periodicity) {}

Magazine::Magazine(const Magazine &original) : PrintedPublication(original),
                                               m_issueNumber(original.m_issueNumber), m_editorName(original.m_editorName), m_periodicity(original.m_periodicity) {}

void Magazine::setIssueNumber(unsigned int issueNumber)
{
    m_issueNumber = issueNumber;
}

void Magazine::setEditorName(string_view editorName)
{
    m_editorName = editorName;
}

void Magazine::setPeriodicity(Periodicity periodicity)
{
    m_periodicity = periodicity;
}

// Getter methods
unsigned int Magazine::getIssueNumber() const
{
    return m_issueNumber;
}

string Magazine::getEditorName() const
{
    return m_editorName;
}

Periodicity Magazine::getPeriodicity() const
{
    return m_periodicity;
}

string Magazine::periodicityToString(Periodicity periodicity) const
{
    switch (periodicity)
    {
    case Periodicity::Daily:
        return "Daily";
    case Periodicity::Weekly:
        return "Weekly";
    case Periodicity::BiWeekly:
        return "Bi-Weekly";
    case Periodicity::Monthly:
        return "Monthly";
    case Periodicity::Quarterly:
        return "Quarterly";
    case Periodicity::Annually:
        return "Annually";
    default:
        return "Unknown";
    }
}

string Magazine::getDescription() const
{
    stringstream ss;
    ss << "Magazine description: " << "\n"
       << "Name: " << getName() << "\n"
       << "Issue Number: " << m_issueNumber << "\n"
       << "Periodicity: " << periodicityToString(m_periodicity) << "\n"
       << "Editor: " << m_editorName;
    return ss.str();
}

void Magazine::printInfo() const
{
    cout << "Publication Information:" << endl;
    cout << "----------------------------------" << endl;
    cout << "Type: " << getType() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Issue number: " << getIssueNumber() << endl;
    cout << "Editor name: " << getEditorName() << endl;
    cout << "Periodicity: " << periodicityToString(getPeriodicity()) << endl;
    cout << "Page Count: " << getPageCount() << endl;
    cout << "Circulation: " << getCirculation() << endl;
    cout << "Price: $" << getPrice() << endl;
    cout << "Rates: " << getRates() << endl;
    cout << "State: " << getState() << endl;
    cout << "Release date: " << getReleaseDate() << endl;
    cout << "Reprint date: " << getReprintDate() << endl;
    cout << "----------------------------------" << endl;
}