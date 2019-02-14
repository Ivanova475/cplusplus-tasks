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


int Matrix::GetValue(const size_t height_index, const size_t width_index) const
{
    return data_[height_index][width_index];
}


void Matrix::SetValue(const size_t height_index, const size_t width_index, const int value)
{
    data_[height_index][width_index] = value;
}


Matrix Matrix::Transpose() const
{
    const size_t width = GetWidth();
    const size_t height = GetHeight();
    Matrix transpose_matrix(width, height);
    for (size_t i = 0; i < width; i++)
    {
        for (size_t j = 0; j < height; j++)
        {
            transpose_matrix.SetValue(i, j, GetValue(j, i));
        }
    }
    
    return transpose_matrix;
}


Matrix Matrix::operator*(const Matrix& rhs)
{
    if (GetWidth() != rhs.GetHeight())
    {
        std::cerr << "Wrong matrix size!" << "\n";
        Matrix matrix;
        
        return matrix;
    }
    else
    {
        const size_t height = GetHeight();
        const size_t width = rhs.GetWidth();
        Matrix matrix_result(height, width);
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                int value = 0;
                for (size_t k = 0; k < GetWidth(); k++)
                {
                    value += GetValue(i, k) * rhs.GetValue(k, j);
                }
                matrix_result.SetValue(i, j, value);
            }
        }
        
        return matrix_result;
    }
}


std::istream& operator>>(std::istream& input_stream, Matrix& matrix)
{
    for (size_t y = 0; y < matrix.GetHeight(); y++)
    {
        for (size_t x = 0; x < matrix.GetWidth(); x++)
        {
            int temp_int = 0;
            input_stream >> temp_int;
            matrix.SetValue(y, x, temp_int);
        }
    }
    
    return input_stream;
}


std::ostream& operator<<(std::ostream& output_stream, const Matrix& matrix)
{
    for (size_t y = 0; y < matrix.GetHeight(); y++)
    {
        for (size_t x = 0; x < matrix.GetWidth(); x++)
        {
            int temp_int = 0;
            output_stream << matrix.GetValue(y, x) << ' ';
        }
        output_stream << std::endl;
    }
    
    return  output_stream;
}

