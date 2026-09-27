#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(size_t rows, size_t cols) : rows_(rows), data_(std::make_unique<double[]>(rows * cols))
{
    for (size_t i = 0; i < rows_ * cols_; i++)
    {
        data_[i] = 0.0;
    }
}

double &Matrix::operator()(size_t rows, size_t cols)
{
    return data_[index(rows, cols)];
}

const double &Matrix::operator()(size_t rows, size_t cols) const
{
    return data_[index(rows, cols)];
}

void Matrix::print() const
{
    for (size_t row = 0; row < rows_; row++) {
        std::cout << "[";
        for (size_t col = 0; col < cols_; col++) {
            std::cout << (*this)(row, col) << " ";
        }
        std::cout << "]\n";
    }
}