#include "matrix.h"


std::vector<std::vector<int>> Multiplication(const std::vector<std::vector<int>>& lhs,
    const std::vector<std::vector<int>>& rhs_transpose, size_t begin_pos, size_t end_pos)
{
	assert(begin_pos <= end_pos);

	std::vector<std::vector<int>> result;

	const size_t height = end_pos - begin_pos;
	const size_t width = rhs_transpose.size();

	result.reserve(height);

	for (size_t i = begin_pos; i < end_pos; i++)
	{
		std::vector<int> tmp;
		tmp.reserve(width);

		for (size_t j = 0; j < width; j++)
		{
			int value = 0;
			for (size_t k = 0; k < rhs_transpose[0].size(); k++)
			{
				value += lhs[i][k] * rhs_transpose[j][k];
			}

			tmp.push_back(std::move(value));
		}

		result.push_back(std::move(tmp));
	}

	return result;
}


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


Matrix Matrix::operator*(const Matrix& rhs) const
{
	if (GetWidth() != rhs.GetHeight())
	{
		std::cerr << "Wrong matrix size!" << "\n";
		Matrix matrix(0, 0);

		return matrix;
	}
	const size_t height = GetHeight();
	const size_t width = rhs.GetWidth();
	Matrix transpose_rhs = rhs.Transpose();
	std::vector<std::vector<int>> rhs_part = transpose_rhs.data_;
	std::vector<std::vector<int>> lhs_part = data_;
	{LOG_DURATION("parallel_3")
		const size_t threads_number = 3;
	    const size_t one_piece_size = height / (threads_number + 1);
	    std::vector<std::future<std::vector<std::vector<int>>>> matrix_parts;
	    matrix_parts.reserve(threads_number);

	    for (size_t i = 0; i < threads_number; i++)
	    {
		    const size_t begin_pos = (i + 1) * one_piece_size;
		    const size_t end_pos = ((i + 1 == threads_number) && (one_piece_size != 0)) ?
			    height : (i + 2) * one_piece_size;

		    std::future<std::vector<std::vector<int>>> matrix_part = std::async(
			    std::launch::async, Multiplication, lhs_part, rhs_part, begin_pos, end_pos
		    );

		    matrix_parts.push_back(std::move(matrix_part));
	    }

	    const size_t begin_pos = 0;
	    const size_t end_pos = (one_piece_size == 0) ?
		    height : one_piece_size;
	    std::vector<std::vector<int>> result_matrix = Multiplication(lhs_part, rhs_part, begin_pos, end_pos);

	    for (size_t i = 0; i < threads_number; i++)
	    {
		    matrix_parts[i].wait();
		    std::vector<std::vector<int>> part = matrix_parts[i].get();

		    for (size_t j = 0; j < part.size(); j++)
		    {
			    result_matrix.push_back(std::move(part[j]));
		    }
	    }

	    Matrix matrix_result(0, 0);
	    matrix_result.data_ = result_matrix;
	    return matrix_result;
	}
}


bool Matrix::operator==(const Matrix& rhs) const
{
	if ((GetHeight() != rhs.GetHeight()) || (GetWidth() != rhs.GetWidth()))
	{
		return false;
	}
	else
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


bool Matrix::operator!=(const Matrix& rhs) const
{
	return !(*this == rhs);
}


std::istream& operator >> (std::istream& input_stream, Matrix& matrix)
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


/*Matrix Matrix::operator*(const Matrix& rhs) const 
{
	if (GetWidth() != rhs.GetHeight())
	{
		std::cerr << "Wrong matrix size!" << "\n";
		Matrix matrix(0, 0);

		return matrix;
	}
	const size_t height = GetHeight();
	const size_t width = rhs.GetWidth();
	Matrix matrix_result(height, width);
	{LOG_DURATION("Non cache friendly")
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
	}
		return matrix_result;

}*/
