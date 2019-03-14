#pragma once


class Calculator {
public:
    int Add(const int lhs, const int rhs);
    int Sub(const int lhs, const int rhs);
    int Mul(const int lhs, const int rhs);
    int Div(const int lhs, const int rhs);
    int GCD(const int lhs, const int rhs);
    int LCM(const int lhs, const int rhs);
    int Power(const int value, const int power);

    bool IsEqualSign(const int lhs, const int rhs);
};

