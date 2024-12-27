#ifndef VECTOR_OPS_H
#define VECTOR_OPS

#include "PrintedPublication.h"
#include <vector>
#include <algorithm>
#include <iostream>

void placeObject(vector<PrintedPublication *> &container, PrintedPublication *obj, size_t position)
{
    if (position > container.size())
    {
        container.push_back(obj);
    }
    else
    {
        container.insert(container.begin() + position, obj);
    }
}

// Searching object by name
PrintedPublication *findObject(vector<PrintedPublication *> &container, const string &name)
{
    auto it = find_if(container.begin(), container.end(), [&name](PrintedPublication *obj)
                      { return obj->getName() == name; });

    return (it != container.end()) ? *it : nullptr;
}

// Sorting by pageCount
void sortByPageCount(vector<PrintedPublication *> &container)
{
    sort(container.begin(), container.end(), [](PrintedPublication *a, PrintedPublication *b)
         { return a->getPageCount() < b->getPageCount(); });
}

// Releasing memory
void clearContainer(vector<PrintedPublication *> &container)
{
    for (auto *obj : container)
    {
        delete obj;
    }
    container.clear();
}

// Printing names of publications
void printPublicationNames(const vector<PrintedPublication *> &publications)
{
    cout << "Publications: ";
    for (size_t i = 0; i < publications.size(); ++i)
    {
        cout << publications[i]->getName();
        if (i != publications.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

#endif