#include "matrix.h"


Matrix::Matrix(const size_t height, const size_t width)
{
    data_.resize(height);
    for (size_t i = 0; i < height; i++)
    {
        data_[i].resize(width);
    }
}


size_t Matrix::GetHeight() const
{
    return data_.size();
}


size_t Matrix::GetWidth() const
{
    if (GetHeight() == 0)
    {
        return 0;
    }
    else
    {
        return data_[0].size();
    }
}


Tree Matrix::GetValue(const size_t height_index, const size_t width_index) const
{
    return data_[height_index][width_index];
}


void Matrix::SetValue(const size_t height_index, const size_t width_index, const Tree& new_tree)
{
    data_[height_index][width_index] = new_tree;
}


auto Matrix::GetData()
{
    return data_;
}

