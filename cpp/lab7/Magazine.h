#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "PrintedPublication.h"

class Magazine : public PrintedPublication
{
private:
    unsigned int m_issueNumber;
    string m_editorName;
    Periodicity m_periodicity;

public:
    // constructors
    Magazine();
    Magazine(string_view name, unsigned int pageCount, unsigned int circulation, double price,
             double rates[], size_t ratesSize, unsigned int issueNumber, string_view editorName, Periodicity periodicity);
    Magazine(const Magazine &original);

    // setters
    void setIssueNumber(unsigned int issueNumber);
    void setEditorName(string_view editorName);
    void setPeriodicity(Periodicity periodicity);

    // getters
    unsigned int getIssueNumber() const;
    string getEditorName() const;
    Periodicity getPeriodicity() const;

    void printInfo() const override;
    string getDescription() const override;

protected:
    string periodicityToString(Periodicity periodicity) const;
};

#endif
