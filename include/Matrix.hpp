#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <memory>
#include <iostream>
#include <optional>
#include <span>

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

    Matrix(Matrix&& other) noexcept;

    Matrix& operator=(Matrix&& other) noexcept;

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

    std::optional<double> at(size_t row, size_t col) const;

    std::span<double> getRowView(size_t row);
    std::span<const double> getRowView(size_t row) const;

    Matrix& operator+=(double scalar);
    Matrix& operator*=(double scalar);

    void print() const;
};

#endif