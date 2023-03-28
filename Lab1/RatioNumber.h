class RatioNumber
{
private:
    int m_numerator{}, m_denominator{};
    void Simplify();

public:
    RatioNumber();
    RatioNumber(int, int);
    explicit RatioNumber(int);

    [[nodiscard]] int GetNumerator() const;
    [[nodiscard]] int GetDenominator() const;

    RatioNumber& operator+=(const RatioNumber& number);
    RatioNumber& operator-=(const RatioNumber& number);
    RatioNumber& operator*=(const RatioNumber& number);
    RatioNumber& operator/=(const RatioNumber& number);
};

RatioNumber operator+(RatioNumber ratioNumber1, const RatioNumber& ratioNumber2);
RatioNumber operator-(RatioNumber ratioNumber1, const RatioNumber& ratioNumber2);
RatioNumber operator*(RatioNumber ratioNumber1, const RatioNumber& ratioNumber2);
RatioNumber operator/(RatioNumber ratioNumber1, const RatioNumber& ratioNumber2);
