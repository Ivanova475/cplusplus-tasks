#include "matrix.h"


Matrix::Matrix(const size_t height, const size_t width) 
{
    data_.reserve(height);
    for (size_t i = 0; i < height; i++)
    {
        std::vector<int> temp_vector;
        temp_vector.reserve(width);
        for (size_t j = 0; j < width; j++)
        {
            temp_vector.push_back(0);
        }
        data_.push_back(std::move(temp_vector));
    }
 /*   data_.resize(height);
    for (size_t i = 0; i < height; i++)
    {
        data_[i].resize(width);
    }*/
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
    const size_t height = GetHeight();
    const size_t width = rhs.GetWidth();
    Matrix transpose_rhs = rhs.Transpose();
    Matrix matrix_result(height, width);
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            int value = 0;
            for (size_t k = 0; k < GetWidth(); k++)
            {
                value += GetValue(i, k) * transpose_rhs.GetValue(j, k);
            }
            matrix_result.SetValue(i, j, value);
        }
    }
        
    return matrix_result;
}


bool Matrix::operator==(const Matrix& rhs)
{
    if ((GetHeight() != rhs.GetHeight()) || (GetWidth() != rhs.GetWidth()))
    {
        return false;
    } else
    {
        for (size_t i = 0; i < GetHeight(); i++)
        {
            for (size_t j = 0; j < GetWidth(); j++)
            {
                if (GetValue(i, j) != rhs.GetValue(i, j))
                {
                    return false;
                }
            }
        }
    }

    return true;
}


bool Matrix::operator!=(const Matrix& rhs)
{
    return !(*this == rhs);
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
            output_stream << matrix.GetValue(y, x) << ' ';
        }
        output_stream << "\n";
    }
    
    return  output_stream;
}

