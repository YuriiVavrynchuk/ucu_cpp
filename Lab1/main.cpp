#include "RatioNumber.h"

#include <iostream>


int main()
{
    RatioNumber ratioNumber1;
    RatioNumber ratioNumber2{2};
    RatioNumber ratioNumber3{2,5};
    const auto ratioNumber4 = ratioNumber1 + ratioNumber2;
    std::cout << ratioNumber4.GetNumerator() << "/" << ratioNumber4.GetDenominator() << std::endl;

    const auto ratioNumber5 = ratioNumber3 / ratioNumber1;
    std::cout << ratioNumber5.GetNumerator() << "/" << ratioNumber5.GetDenominator() << std::endl;
}
