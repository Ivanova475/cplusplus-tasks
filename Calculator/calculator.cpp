#include <iostream>
#include <exception>

#include "calculator.h"


int Calculator::Add(const int lhs, const int rhs)
{
    return lhs + rhs;
}


int Calculator::Sub(const int lhs, const int rhs)
{
    return lhs - rhs;
}


int Calculator::Mul(const int lhs, const int rhs)
{
    return lhs * rhs;
}


int Calculator::Div(const int lhs, const int rhs)
{
    if (rhs == 0)
    {
        throw std::runtime_error("Division by zero.");
    }
    return lhs / rhs;
}


int Calculator::Power(const int value, const int power)
{
    if (power == 0)
    {
        return 1;
    }

    return value * Power(value, power - 1);
}


bool Calculator::IsEqualSign(const int lhs, const int rhs)
{
    if (((int64_t)lhs * rhs) > 0)
    {
        return true;
    }

    return false;
}


int Calculator::GCD(const int lhs, const int rhs)
{
    int abs_lhs = abs(lhs);
    int abs_rhs = abs(rhs);
    while ((abs_lhs > 0) && (abs_rhs > 0))
    {
        if (abs_lhs > abs_rhs)
        {
            abs_lhs = abs_lhs % abs_rhs;
        }
        else
        {
            abs_rhs = abs_rhs % abs_lhs;
        }
    }

    return Add(abs_rhs, abs_lhs);
}


int Calculator::LCM(const int lhs, const int rhs)
{
    int tmp = Mul(lhs, rhs);
    return Div(abs(tmp), GCD(lhs, rhs));
}
