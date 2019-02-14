#include <iostream>
#include <vector>

#include "matrix.h"



int main()
{
	int matrix_height = 0;
	int matrix_width = 0;

	std::cin >> matrix_height >> matrix_width;
    Matrix matrix1(matrix_height, matrix_width);
    std::cin >> matrix1;

	std::cin >> matrix_height >> matrix_width;
	Matrix matrix2(matrix_height, matrix_width);
	std::cin >> matrix2;

	Matrix res = matrix1 * matrix2;

	std::cout << res << std::endl; 
	std::cout << res.Transpose() << std::endl;
	
	return 0;
}