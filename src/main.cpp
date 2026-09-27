#include "Matrix.hpp"
#include <iostream>

int main()
{
    std::cout << "Allocation and Indexing Demo\n";

    Matrix matrix(3, 3);

    matrix(0, 0) = 1.0;
    matrix(1, 1) = 5.5;
    matrix(2, 2) = 9.9;

    std::cout << "Matrix Contents:\n";
    matrix.print();

    std::cout << "\nValue at (1, 1): " << matrix(1, 1) << "\n";
    std::cout << "\nValue at (2, 2): " << matrix(2, 2) << "\n";

    std::cout << "Exiting scope. Memory will be cleaned up automatically by std::unique_ptr\n";
    return 0;
}