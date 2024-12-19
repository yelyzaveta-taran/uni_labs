#include "SquareMatrix.h"
#include <iostream>

int main()
{

    SquareMatrix matrix1(3);

    matrix1.print();

    std::cout << "Max Element: " << matrix1.findMaxElement() << std::endl;

    std::cout << "Row 1 Sum: " << matrix1.getRowSum(1) << std::endl;
}