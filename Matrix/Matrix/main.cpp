#include <iostream>
#include <vector>

#include "matrix.h"
#include "profile.h"


#define ASSERT_EQUAL(x, y)                                         \
    if ((x) != (y))                                                \
    {                                                              \
        std::cerr << "Assertion failed. File: " << __FILE__        \
            << " Line: " << __LINE__ << " "                        \
            << x << " != " << y << " ("                            \
            << #x << " != " << #y << ")" << std::endl;             \
        fails_count++;                                             \
    }


void TestGetHeight()
{
	std::cerr << "***********************************" << std::endl;
	int fails_count = 0;
	Matrix matrix_1(0, 0);
	Matrix matrix_2(100000, 1000);
	Matrix matrix_3(100, 100);
	Matrix matrix_4(10, 5);

	ASSERT_EQUAL(matrix_1.GetHeight(), 0);
	ASSERT_EQUAL(matrix_2.GetHeight(), 100000);
	ASSERT_EQUAL(matrix_3.GetHeight(), 100);
	ASSERT_EQUAL(matrix_4.GetHeight(), 10);

	if (fails_count == 0)
	{
		std::cerr << "TestGetHeight: OK" << std::endl;
	}
	else
	{
		std::cerr << "TestGetHeight fails. fails_count = " << fails_count << std::endl;
	}
	std::cerr << "***********************************" << std::endl;
}


void TestGetWidth()
{
	std::cerr << "***********************************" << std::endl;
	int fails_count = 0;
	Matrix matrix_1(0, 0);
	Matrix matrix_2(1000, 100000);
	Matrix matrix_3(100, 100);
	Matrix matrix_4(10, 5);

	ASSERT_EQUAL(matrix_1.GetWidth(), 0);
	ASSERT_EQUAL(matrix_2.GetWidth(), 100000);
	ASSERT_EQUAL(matrix_3.GetWidth(), 100);
	ASSERT_EQUAL(matrix_4.GetWidth(), 5);

	if (fails_count == 0)
	{
		std::cerr << "TestGetWidth: OK" << std::endl;
	}
	else
	{
		std::cerr << "TestGetWidth fails. fails_count = " << fails_count << std::endl;
	}
	std::cerr << "***********************************" << std::endl;
}


void TestGetValue()
{
	std::cerr << "***********************************" << std::endl;
	int fails_count = 0;
	Matrix matrix_1(10, 10);
	Matrix matrix_2(2, 2);
	matrix_2.SetValue(0, 0, 100000);
	matrix_2.SetValue(0, 1, 10);
	matrix_2.SetValue(1, 0, -100000);
	matrix_2.SetValue(1, 1, 0);

	ASSERT_EQUAL(matrix_1.GetValue(5, 5), 0);
	ASSERT_EQUAL(matrix_2.GetValue(0, 0), 100000);
	ASSERT_EQUAL(matrix_2.GetValue(0, 1), 10);
	ASSERT_EQUAL(matrix_2.GetValue(1, 0), -100000);
	ASSERT_EQUAL(matrix_2.GetValue(1, 1), 0);

	if (fails_count == 0)
	{
		std::cerr << "TestGetValue: OK" << std::endl;
	}
	else
	{
		std::cerr << "TestGetValue fails. fails_count = " << fails_count << std::endl;
	}
	std::cerr << "***********************************" << std::endl;
}


void TestSetValue()
{
	std::cerr << "***********************************" << std::endl;
	int fails_count = 0;
	Matrix matrix_1(10, 10);
	Matrix matrix_2(2, 2);
	matrix_2.SetValue(0, 0, 100000);
	matrix_2.SetValue(0, 1, 10);
	matrix_2.SetValue(1, 0, -100000);
	matrix_2.SetValue(1, 1, 0);

	ASSERT_EQUAL(matrix_1.GetValue(5, 5), 0);
	ASSERT_EQUAL(matrix_2.GetValue(0, 0), 100000);
	ASSERT_EQUAL(matrix_2.GetValue(0, 1), 10);
	ASSERT_EQUAL(matrix_2.GetValue(1, 0), -100000);
	ASSERT_EQUAL(matrix_2.GetValue(1, 1), 0);

	if (fails_count == 0)
	{
		std::cerr << "TestSetValue: OK" << std::endl;
	}
	else
	{
		std::cerr << "TestSetValue fails. fails_count = " << fails_count << std::endl;
	}
	std::cerr << "***********************************" << std::endl;
}


void TestEqual()
{
	std::cerr << "***********************************" << std::endl;
	int fails_count = 0;
	Matrix matrix_1(2, 2);
	Matrix matrix_2(2, 2);
	matrix_2.SetValue(0, 0, 3);
	matrix_2.SetValue(1, 0, 2);
	matrix_2.SetValue(0, 1, 2);
	matrix_2.SetValue(1, 1, 3);
	Matrix matrix_3(2, 2);
	matrix_3.SetValue(0, 0, 1);
	matrix_3.SetValue(1, 0, 0);
	matrix_3.SetValue(0, 1, 0);
	matrix_3.SetValue(1, 1, 1);
	Matrix matrix_4(2, 4);

	ASSERT_EQUAL((matrix_4 == matrix_2), false);
	ASSERT_EQUAL((matrix_2 == matrix_2), true);
	ASSERT_EQUAL((matrix_1 != matrix_3), true);
	ASSERT_EQUAL((matrix_3 != matrix_3), false);

	if (fails_count == 0)
	{
		std::cerr << "TestEqual: OK" << std::endl;
	}
	else
	{
		std::cerr << "TestEqual fails. fails_count = " << fails_count << std::endl;
	}
	std::cerr << "***********************************" << std::endl;
}


void TestTranspose()
{
	std::cerr << "***********************************" << std::endl;
	int fails_count = 0;
	Matrix matrix_1(2, 2);
	matrix_1.SetValue(0, 0, 100000);
	matrix_1.SetValue(0, 1, 10);
	matrix_1.SetValue(1, 0, -100000);
	matrix_1.SetValue(1, 1, 0);
	Matrix matrix_2(2, 2);
	matrix_2.SetValue(0, 0, 100000);
	matrix_2.SetValue(1, 0, 10);
	matrix_2.SetValue(0, 1, -100000);
	matrix_2.SetValue(1, 1, 0);
	Matrix matrix_3(2, 2);
	matrix_3.SetValue(0, 0, 10);
	matrix_3.SetValue(1, 0, 0);
	matrix_3.SetValue(0, 1, 0);
	matrix_3.SetValue(1, 1, 10);
	Matrix matrix_4(1, 2);
	Matrix matrix_5(2, 1);

	ASSERT_EQUAL(matrix_1.Transpose(), matrix_2);
	ASSERT_EQUAL(matrix_3.Transpose(), matrix_3);
	ASSERT_EQUAL(matrix_4.Transpose(), matrix_5);

	if (fails_count == 0)
	{
		std::cerr << "TestTranspose: OK" << std::endl;
	}
	else
	{
		std::cerr << "TestTranspose fails. fails_count = " << fails_count << std::endl;
	}
	std::cerr << "***********************************" << std::endl;
}


void TestMultiplication()
{
	std::cerr << "***********************************" << std::endl;
	int fails_count = 0;
	Matrix matrix_1(2, 2);
	Matrix matrix_2(2, 2);
	matrix_2.SetValue(0, 0, 3);
	matrix_2.SetValue(1, 0, 2);
	matrix_2.SetValue(0, 1, 2);
	matrix_2.SetValue(1, 1, 3);
	Matrix matrix_3(2, 2);
	matrix_3.SetValue(0, 0, 1);
	matrix_3.SetValue(1, 0, 0);
	matrix_3.SetValue(0, 1, 0);
	matrix_3.SetValue(1, 1, 1);
	Matrix matrix_4(2, 2);
	matrix_3.SetValue(0, 0, 100000);
	matrix_3.SetValue(1, 0, -100000);
	matrix_3.SetValue(0, 1, -100000);
	matrix_3.SetValue(1, 1, 100000);
	Matrix matrix_5(2, 1);
	matrix_5.SetValue(0, 0, 1);
	matrix_5.SetValue(1, 0, 1);
	Matrix matrix_6(2, 1);
	matrix_6.SetValue(0, 0, 5);
	matrix_6.SetValue(1, 0, 5);
	Matrix matrix_7(4, 4);
	matrix_7.SetValue(0, 0, 1);
	matrix_7.SetValue(1, 1, 1);
	matrix_7.SetValue(2, 2, 1);
	matrix_7.SetValue(3, 3, 1);
	Matrix matrix_8(4, 4);
	matrix_7.SetValue(0, 0, 2);
	matrix_7.SetValue(1, 1, 2);
	matrix_7.SetValue(2, 2, 2);
	matrix_7.SetValue(3, 3, 2);

	ASSERT_EQUAL(matrix_1 * matrix_2, matrix_1);
	ASSERT_EQUAL(matrix_3 * matrix_4, matrix_4);
	ASSERT_EQUAL(matrix_2 * matrix_5, matrix_6);
	ASSERT_EQUAL(matrix_7 * matrix_8, matrix_8);

	if (fails_count == 0)
	{
		std::cerr << "TestMultiplication: OK" << std::endl;
	}
	else
	{
		std::cerr << "TestMultiplication fails. fails_count = " << fails_count << std::endl;
	}
	std::cerr << "***********************************" << std::endl;
}


void RunTests()
{
	TestGetHeight();
	TestGetWidth();
	TestGetValue();
	TestSetValue();
	TestEqual();
	TestTranspose();
	TestMultiplication();
}


int main()
{
	Matrix m1(1000, 1000);
	Matrix m2(1000, 1000);
	auto m3 = m1 * m2;
	return 0;
}