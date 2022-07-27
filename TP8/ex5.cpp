#include <iostream>
#include <cmath>

using namespace std;

class Fraction{
    public:
        Fraction();
        Fraction(int num_, int den_);
        int numerator() const;
        int denominator() const;
        void normalise();
        void write() const;
        Fraction sum(const Fraction& right);
        Fraction sub(const Fraction& right);
        Fraction mul(const Fraction& right);
        Fraction div(const Fraction& right);

    private:
        int num;
        int den;
        static int gcd(int a, int b);
};

Fraction::Fraction()
{
    num = 0;
    den = 1;
}

Fraction::Fraction(int num_, int den_)
{
    num = num_;
    den = den_;
    normalise();
}

int Fraction::numerator() const
{
    return num;
}

int Fraction::denominator() const
{
    return den;
}

int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

void Fraction::normalise() {
  int g = gcd(num, den);
  num /= g;
  den/= g;
  if (den< 0) {
    num = - num;
    den = - den;
  }
}

void Fraction::write() const {
  cout << numerator() << '/' << denominator();
}

Fraction Fraction::sum(const Fraction& right)
{
    int resnum = num*right.denominator() + right.numerator()*den;
    int resden = den*right.denominator();
    Fraction res = Fraction(resnum,resden);
    res.normalise();
    return res;
}

Fraction Fraction::sub(const Fraction& right)
{
    int resnum = num*right.denominator() - right.numerator()*den;
    int resden = den*right.denominator();
    Fraction res = Fraction(resnum,resden);
    res.normalise();
    return res;
}

Fraction Fraction::mul(const Fraction& right)
{
    int resnum = num*right.numerator();
    int resden = den*right.denominator();
    Fraction res = Fraction(resnum,resden);
    res.normalise();
    return res;
}

Fraction Fraction::div(const Fraction& right)
{
    int resnum = num*right.denominator();
    int resden = den*right.numerator();
    Fraction res = Fraction(resnum,resden);
    res.normalise();
    return res;
}
