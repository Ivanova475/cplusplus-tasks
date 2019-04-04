#pragma once

#include <iostream>
#include <vector>
#include <istream>
#include <ostream>
#include <utility>
#include <future>
#include <cassert>

#include "profile.h"


class Matrix
{
    friend std::istream& operator >> (std::istream& input_stream, Matrix& matrix);

public:
    Matrix(const size_t height, const size_t width);
    virtual ~Matrix() = default;

    size_t GetHeight() const;
    size_t GetWidth() const;

    int GetValue(const size_t height_index, const size_t width_index) const;
    void SetValue(const size_t height_index, const size_t width_index,
        const int value);

    Matrix Transpose() const;

    Matrix operator*(const Matrix& rhs) const;

    bool operator==(const Matrix& rhs) const;
    bool operator!=(const Matrix& rhs) const;

private:
    std::vector<std::vector<int>> data_;
};


std::istream& operator >> (std::istream& input_stream, Matrix& matrix);
std::ostream& operator<<(std::ostream& output_stream, const Matrix& matrix);


std::vector<std::vector<int>> Multiplication(const std::vector<std::vector<int>>& lhs,
    const std::vector<std::vector<int>>& rhs, size_t begin_pos, size_t end_pos);