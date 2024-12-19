#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include <vector>

using namespace std;

class SquareMatrix
{
private:
    size_t m_size;
    vector<vector<double>> m_matrix;

public:
    SquareMatrix(size_t size);
    SquareMatrix(size_t size, double initialValue);
    SquareMatrix(const vector<vector<double>> &matrix);

    size_t getSize() const;
    double getElement(size_t row, size_t col) const;

    void setElement(size_t row, size_t col, double value);

    void print() const;

    double findMaxElement() const;
    double getRowSum(size_t row) const;
};

#endif