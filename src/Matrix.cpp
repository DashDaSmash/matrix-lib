#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols), data_(std::make_unique<double[]>(rows * cols))
{
    for (size_t i = 0; i < rows_ * cols_; i++)
    {
        data_[i] = 0.0;
    }
}

Matrix::Matrix(Matrix &&other) noexcept : rows_(other.rows_), cols_(other.cols_), data_(std::move(other.data_))
{
    other.rows_ = 0;
    other.cols_ = 0;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        rows_ = other.rows_;
        cols_ = other.cols_;

        data_ = std::move(other.data_);

        other.rows_ = 0;
        other.cols_ = 0;
    }
    return *this;
}

std::optional<double> Matrix::at(size_t row, size_t col) const {
    if (row >= rows_ || col >= cols_) {
        return std::nullopt;
    }
    return data_[index(row, col)];
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
    if (!data_) {
        std::cout << "[ This matrix is empty or moved already ]\n";
        return;
    }
    for (size_t row = 0; row < rows_; row++)
    {
        std::cout << "[";
        for (size_t col = 0; col < cols_; col++)
        {
            std::cout << (*this)(row, col) << " ";
        }
        std::cout << "]\n";
    }
}