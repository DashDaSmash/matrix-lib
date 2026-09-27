#include "Matrix.hpp"
#include <iostream>

Matrix createIdentityMatrix(size_t size)
{
    Matrix mat(size, size);
    for (size_t i = 0; i < size; ++i)
    {
        mat(i, i) = 1.0;
    }
    return mat; // Moved out without heap allocation copies!
}

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
    std::cout << "\nValue at (4, 2): " << matrix(4, 2) << "\n";

    std::cout << "\nCreating 3x3 Identity Matrix via move semantics\n";
    Matrix m1 = createIdentityMatrix(3);
    m1.print();

    std::cout << "\nMoving m1 ownership into m2\n";
    Matrix m2 = std::move(m1);

    std::cout << "m2 Contents:\n";
    m2.print();

    std::cout << "m1 State after move:\n";
    m1.print();

    std::cout << "\nTesting std::optional bounds access on m2:\n";

    auto val1 = m2.at(1, 1);
    if (val1.has_value()) {
        std::cout << "Element at (1,1): " << val1.value() << "\n";
    }

    auto val2 = m2.at(5, 5);
    if (!val2.has_value()) {
        std::cout << "Element at (5,5): Out of bounds (Returned std::nullopt)!\n";
    }


    std::cout << "\nstd::span Views & Arithmetic Demo\n\n";

    Matrix mat(3, 3);

    std::cout << "Initialize matrix and apply scalar += 2.0\n";
    mat += 2.0;
    mat.print();

    std::cout << "\nApply scalar *= 3.0\n";
    mat *= 3.0;
    mat.print();

    std::cout << "\nExtracting row 1 as std::span and modifying elements\n";
    std::span<double> row1 = mat.getRowView(1);

    for (double& val : row1) {
        val = 99.0;
    }

    std::cout << "Matrix after modifying Row 1 via std::span view:\n";
    mat.print();


    std::cout << "Exiting scope. Memory will be cleaned up automatically by std::unique_ptr\n";
    return 0;
}