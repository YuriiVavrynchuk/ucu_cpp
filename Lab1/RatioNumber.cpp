#include "RatioNumber.h"

#include <stdexcept>

RatioNumber::RatioNumber(): m_numerator{0}, m_denominator{1}
{
}

RatioNumber::RatioNumber(int number): m_numerator{number}, m_denominator{1}
{
}

RatioNumber &RatioNumber::operator+=(const RatioNumber &number)
{
    m_numerator = m_numerator * number.m_denominator + number.m_numerator * m_denominator;
    m_denominator *= number.m_denominator;
    Simplify();
    return *this;
}

RatioNumber &RatioNumber::operator-=(const RatioNumber& number)
{
    m_numerator = m_numerator * number.m_denominator - number.m_numerator * m_denominator;
    m_denominator *= number.m_denominator;
    Simplify();
    return *this;
}

RatioNumber &RatioNumber::operator*=(const RatioNumber &number)
{
    m_numerator *= number.m_numerator;
    m_denominator *= number.m_denominator;
    Simplify();
    return *this;
}

RatioNumber &RatioNumber::operator/=(const RatioNumber &number)
{
    if(!number.m_numerator)
    {
        throw std::runtime_error("Zero division");
    }

    m_numerator *= number.m_denominator;
    m_denominator *= number.m_numerator;
    Simplify();
    return *this;
}

int RatioNumber::GetNumerator() const
{
    return m_numerator;
}

int RatioNumber::GetDenominator() const
{
    return m_denominator;
}

void RatioNumber::Simplify()
{
    if (!(m_numerator % m_denominator))
    {
        m_numerator /= m_denominator;
        m_denominator = 1;
    }
}

RatioNumber::RatioNumber(const int numerator, const int denominator): m_numerator{numerator}, m_denominator{denominator}
{
}

RatioNumber operator+(RatioNumber ratioNumber1, const RatioNumber& ratioNumber2)
{
    return ratioNumber1 += ratioNumber2;
}

RatioNumber operator-(RatioNumber ratioNumber1, const RatioNumber& ratioNumber2)
{
    return ratioNumber1 -= ratioNumber2;
}

RatioNumber operator*(RatioNumber ratioNumber1, const RatioNumber& ratioNumber2)
{
    return ratioNumber1 *= ratioNumber2;
}

RatioNumber operator/(RatioNumber ratioNumber1, const RatioNumber& ratioNumber2)
{
    return ratioNumber1 /= ratioNumber2;
}
