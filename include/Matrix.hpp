#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <memory>
#include <iostream>

class Matrix
{
private:
    size_t rows_;
    size_t cols_;

    std::unique_ptr<double[]> data_;

public:
    Matrix(size_t rows, size_t cols);

    ~Matrix() = default;

    Matrix(const Matrix &) = delete;
    Matrix &operator=(const Matrix &) = delete;

    size_t rows() const
    {
        return rows_;
    }
    size_t cols() const
    {
        return cols_;
    }

    size_t index(size_t rows, size_t cols) const
    {
        return rows * cols_ + cols;
    }

    double& operator()(size_t rows, size_t cols);
    const double& operator()(size_t rows, size_t cols) const;

    void print() const;
};

#endif