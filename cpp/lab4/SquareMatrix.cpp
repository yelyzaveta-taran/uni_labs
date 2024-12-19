#include "SquareMatrix.h"
#include <iostream>
#include <vector>

SquareMatrix::SquareMatrix(size_t size) : m_size(size)
{
    if (size == 0)
    {
        throw std::invalid_argument("Matrix size must be greater than 0.");
    }

    m_matrix = std::vector<std::vector<double>>(size, std::vector<double>(size, 0.0));

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {

            cout << "Enter an element for position[" << i << "][" << j << "]: ";
            cin >> m_matrix[i][j];
        }
    }
}

SquareMatrix::SquareMatrix(size_t size, double initialValue) : m_size(size)
{
    if (size == 0)
    {
        throw std::invalid_argument("Matrix size must be greater than 0.");
    }

    m_matrix = std::vector<std::vector<double>>(size, std::vector<double>(size, initialValue));
};

SquareMatrix::SquareMatrix(const std::vector<std::vector<double>> &matrix) : m_size(matrix.size()), m_matrix(matrix)
{
    for (const auto &row : matrix)
    {
        if (row.size() != m_size)
        {
            throw std::invalid_argument("The provided matrix is not square.");
        }
    }
}

size_t SquareMatrix::getSize() const
{
    return m_size;
}

double SquareMatrix::getElement(size_t row, size_t col) const
{
    if (row >= m_size || col >= m_size)
    {
        throw std::out_of_range("Index out of bounds.");
    }
    return m_matrix[row][col];
}

void SquareMatrix::setElement(size_t row, size_t col, double value)
{
    if (row >= m_size || col >= m_size)
    {
        throw std::out_of_range("Index out of bounds.");
    }
    m_matrix[row][col] = value;
}

void SquareMatrix::print() const
{
    std::cout << std::endl;
    for (const auto &row : m_matrix)
    {
        for (double element : row)
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

double SquareMatrix::findMaxElement() const
{
    double maxElement = m_matrix[0][0];
    for (const auto &row : m_matrix)
    {
        for (const auto &element : row)
        {
            if (element > maxElement)
            {
                maxElement = element;
            }
        }
    }
    return maxElement;
}

double SquareMatrix::getRowSum(size_t row) const
{
    if (row >= m_size)
    {
        throw std::out_of_range("Row index is out of range.");
    }
    double sum = 0;
    for (const auto &element : m_matrix[row])
    {
        sum += element;
    }
    return sum;
}