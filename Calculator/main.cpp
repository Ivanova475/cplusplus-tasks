#include <iostream>

#include "calculator.h"


#define ASSERT_EQUAL(x, y)                                         \
    if ((x) != (y))                                                \
    {                                                              \
        std::cerr << "Assertion failed. File: " << __FILE__        \
            << " Line: " << __LINE__ << " "                        \
            << x << " != " << y << " ("                            \
            << #x << " != " << #y << ")" << std::endl;             \
        fails_count++;                                             \
    }


void TestAdd()
{
    std::cerr << "***********************************" << std::endl;
    int fails_count = 0;
    Calculator calc;

    ASSERT_EQUAL(calc.Add(-2, 2), 0);
    ASSERT_EQUAL(calc.Add(0, 10000), 10000);
    ASSERT_EQUAL(calc.Add(1000000, 1000000), 2000000);
    ASSERT_EQUAL(calc.Add(-1000000, -1000000), -2000000);

    if (fails_count == 0)
    {
        std::cerr << "TestAdd: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestAdd fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "***********************************" << std::endl;
}


void TestSub()
{
    std::cerr << "***********************************" << std::endl;
    int fails_count = 0;
    Calculator calc;

    ASSERT_EQUAL(calc.Sub(2, 2), 0);
    ASSERT_EQUAL(calc.Sub(0, -10000), 10000);
    ASSERT_EQUAL(calc.Sub(1000000, -1000000), 2000000);
    ASSERT_EQUAL(calc.Sub(-1000000, 1000000), -2000000);

    if (fails_count == 0)
    {
        std::cerr << "TestSub: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestSub fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "***********************************" << std::endl;
}


void TestMul()
{
    std::cerr << "***********************************" << std::endl;
    int fails_count = 0;
    Calculator calc;

    ASSERT_EQUAL(calc.Mul(2, 2), 4);
    ASSERT_EQUAL(calc.Mul(0, -10000), 0);
    ASSERT_EQUAL(calc.Mul(-100, -100), 10000);
    ASSERT_EQUAL(calc.Mul(-13, 2), -26);

    if (fails_count == 0)
    {
        std::cerr << "TestMul: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestMul fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "***********************************" << std::endl;
}


void TestDiv()
{
    std::cerr << "***********************************" << std::endl;
    int fails_count = 0;
    Calculator calc;

    ASSERT_EQUAL(calc.Div(2, 1), 2);
    ASSERT_EQUAL(calc.Div(0, -10000), 0);
    ASSERT_EQUAL(calc.Div(-100, -100), 1);
    ASSERT_EQUAL(calc.Div(-13, 13), -1);
    ASSERT_EQUAL(calc.Div(-24, 7), -3);
    ASSERT_EQUAL(calc.Div(45, 8), 5);

    if (fails_count == 0)
    {
        std::cerr << "TestDiv: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestDiv fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "***********************************" << std::endl;
}


void TestIsEqualSign()
{
    std::cerr << "***********************************" << std::endl;
    int fails_count = 0;
    Calculator calc;

    ASSERT_EQUAL(calc.IsEqualSign(-2, 2), 0);
    ASSERT_EQUAL(calc.IsEqualSign(0, 2), 1);
    ASSERT_EQUAL(calc.IsEqualSign(-2, 0), 1);
    ASSERT_EQUAL(calc.IsEqualSign(-2000000, 2000000), 0);
    ASSERT_EQUAL(calc.IsEqualSign(100, 100), 1);
    ASSERT_EQUAL(calc.IsEqualSign(-200, -200), 1);

    if (fails_count == 0)
    {
        std::cerr << "TestIsEqualSign: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestIsEqualSign fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "***********************************" << std::endl;
}


void TestGCD()
{
    std::cerr << "***********************************" << std::endl;
    int fails_count = 0;
    Calculator calc;

    ASSERT_EQUAL(calc.GCD(-2, 2), 2);
    ASSERT_EQUAL(calc.GCD(13, 23), 1);
    ASSERT_EQUAL(calc.GCD(1000000, 1000000), 1000000);
    ASSERT_EQUAL(calc.GCD(50, 25), 25);
    ASSERT_EQUAL(calc.GCD(0, 25), 25);
    ASSERT_EQUAL(calc.GCD(50, 75), 25);

    if (fails_count == 0)
    {
        std::cerr << "TestGCD: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestGCD fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "***********************************" << std::endl;
}


void TestLCM()
{
    std::cerr << "***********************************" << std::endl;
    int fails_count = 0;
    Calculator calc;

    ASSERT_EQUAL(calc.LCM(-2, 2), 2);
    ASSERT_EQUAL(calc.LCM(0, 10000), 0);
    ASSERT_EQUAL(calc.LCM(23, 25), 575);
    ASSERT_EQUAL(calc.LCM(34, 17), 34);

    if (fails_count == 0)
    {
        std::cerr << "TestLCM: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestLCM fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "***********************************" << std::endl;
}


void TestPower()
{
    std::cerr << "***********************************" << std::endl;
    int fails_count = 0;
    Calculator calc;

    ASSERT_EQUAL(calc.Power(1, 2), 1);
    ASSERT_EQUAL(calc.Power(0, 0), 1);
    ASSERT_EQUAL(calc.Power(1000000, 0), 1);
    ASSERT_EQUAL(calc.Power(-2, 3), -8);
    ASSERT_EQUAL(calc.Power(2, 3), 8);

    if (fails_count == 0)
    {
        std::cerr << "TestPower: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestPower fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "***********************************" << std::endl;
}


void TestAll()
{
    TestAdd();
    TestSub();
    TestMul();
    TestDiv();
    TestIsEqualSign();
    TestGCD();
    TestLCM();
    TestPower();
}


int main()
{
    TestAll();

    return 0;
}
