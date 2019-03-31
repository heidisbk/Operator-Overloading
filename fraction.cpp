#include <iostream>
#include <string>
#include <numeric>

#include "fraction.hpp"

using std::string;
using std::endl;
using std::cout;

Fraction::Fraction(int numerator, int denominator)
{
  this->numerator = numerator;
  this->denominator = denominator;
  reduire();
}

int pgcd(int a, int b)
{
  if (a == 0)
    {
      return b;
    }
  while (a != b)
    {
      if (a > b)
	{
	  a -= b;
	}
      else
	{
	  b -= a;
	}
    }
  return a;
}

void Fraction::reduire()
{
  //int r = std::gcd(this->numerator, this->denominator);
  int r = pgcd(this->numerator, this->denominator);
  this->numerator = this->numerator / r;
  this->denominator = this->denominator / r;
}


//opérations basiques
Fraction Fraction::operator*(const Fraction& fraction) const
{
  int num = this->numerator * fraction.numerator;
  int den = this->denominator * fraction.denominator;
  Fraction result(num, den);
  result.reduire();
  return result;
}

Fraction Fraction::operator/(const Fraction& fraction) const
{
  int num = this->numerator * (fraction.denominator);
  int den = this->denominator * (fraction.numerator);
  Fraction result(num, den);
  result.reduire();
  return result;
}

Fraction Fraction::operator+(const Fraction& fraction) const
{
  int num1 = this->numerator * fraction.denominator;
  int den1 = this->denominator * fraction.denominator;
  int num2 = fraction.numerator * this->denominator;
  Fraction result(num1 + num2, den1);
  result.reduire();
  return result;
}

Fraction Fraction::operator-(const Fraction& fraction) const
{
  int num1 = this->numerator * fraction.denominator;
  int den1 = this->denominator * fraction.denominator;
  int num2 = fraction.numerator * this->denominator;
  Fraction result(num1 - num2, den1);
  result.reduire();
  return result;
}


//opérations un peu moins basiques
Fraction Fraction::operator*=(const Fraction& fraction)
{
  this->numerator = this->numerator * fraction.numerator;
  this->denominator = this->denominator * fraction.denominator;
  Fraction result(this->numerator, this->denominator);
  result.reduire();
  return result;
}

Fraction Fraction::operator/=(const Fraction& fraction)
{
  this->numerator = this->numerator * (fraction.denominator);
  this->denominator = this->denominator * (fraction.numerator);
  Fraction result(this->numerator, this->denominator);
  result.reduire();
  return result;
}

Fraction Fraction::operator+=(const Fraction& fraction)
{
  int num = fraction.numerator * this->denominator;
  this->numerator = this->numerator * fraction.denominator;
  this->denominator = this->denominator * fraction.denominator;
  this->numerator = this->numerator + num;
  Fraction result(this->numerator, this->denominator);
  result.reduire();
  return result;
}

Fraction Fraction::operator-=(const Fraction& fraction)
{
  int num = fraction.numerator * this->denominator;
  this->numerator = this->numerator * fraction.denominator;
  this->denominator = this->denominator * fraction.denominator;
  this->numerator = this->numerator - num;
  Fraction result(this->numerator, this->denominator);
  result.reduire();
  return result;
}


//opérateurs de comparaison
bool Fraction::operator==(const Fraction& fraction) const
{
  if (this->numerator == fraction.numerator && this->denominator == fraction.denominator)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool Fraction::operator!=(const Fraction& fraction) const
{
  return !(*this == fraction);
}

bool Fraction::operator<(const Fraction& fraction) const
{
  int num1 = this->numerator * fraction.denominator;
  int num2 = fraction.numerator * this->denominator;
  if (num1 < num2)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool Fraction::operator<=(const Fraction& fraction) const
{
  return (*this < fraction || *this == fraction);
}

bool Fraction::operator>(const Fraction& fraction) const
{
  return !(*this <= fraction);
}

bool Fraction::operator>=(const Fraction& fraction) const
{
  return !(*this < fraction);
}


//incrémentation et decrémentation
Fraction Fraction::operator++()
{
  return (*this += Fraction(1, 1));
}

Fraction Fraction::operator++(int)
{
  Fraction truc = *this;
  *this += Fraction(1, 1);
  return truc;
}

Fraction Fraction::operator--()
{
  return (*this -= Fraction(1, 1));
}

Fraction Fraction::operator--(int)
{
  Fraction truc = *this;
  *this -= Fraction(1, 1);
  return truc;
}


//<< & >>
std::ostream& operator<<(std::ostream& o, const Fraction& fraction)
{
  o << fraction.numerator << "/" << fraction.denominator;
  return o;
}

std::istream& operator>>(std::istream& i, Fraction& fraction)
{
  int a, b;
  char c;
  i >> a >> c >> b;
  if (c == '/')
    {
      fraction = Fraction(a, b);
    }
  return i;
  cout << a << endl;
}

int main()
{
  Fraction fraction1(8, 2);
  Fraction fractionn(2, 7);
  Fraction fraction2(8, 2);
  Fraction fraction3(1, 3);
  Fraction fraction4(2, 7);
  
  //cout << fraction1.operator*(fraction2) << endl;
  cout << (fraction1 * fractionn) << endl;
  cout << (fraction1 / fractionn) << endl;
  cout << (fraction1 + fractionn) << endl;
  cout << (fraction1 - fractionn) << "\n"  << endl;

  cout << " *= " <<  (fraction1 *= fractionn) << endl;
  cout << " /= " << (fraction2 /= fractionn) << endl;
  cout << " += " << (fraction3 += fractionn) << endl;
  cout << " -= " << (fraction4 -= fractionn)<< "\n" << endl;

  Fraction fr1(3, 2);
  Fraction fr2(3, 2);
  cout << fr1 << " = " << fr2 << " ?? " << (fr1 == fr2) << endl;
  cout << fr1 << " != " << fr2 << " ?? " << (fr1 != fr2) << endl;
  cout << fr1 << " < " << fr2 << " ?? " << (fr1 < fr2) << endl;
  cout << fr1 << " <= " << fr2 << " ?? " << (fr1 <= fr2) << endl;
  cout << fr1 << " > " << fr2 << " ?? " << (fr1 > fr2) << endl;
  cout << fr1 << " >= " << fr2 << " ?? " << (fr1 >= fr2) << "\n" << endl;

  cout << " ++f " << ++fractionn << endl;
  cout << " f++ " << fractionn++ << endl;
  cout << " --f " << --fr1 << endl;
  cout << " f-- " << fr1-- << endl;

  std::cin >> fr1;
  cout << fr1 << endl;
  
  int a = 40;
  int b = 688;
  int p = pgcd(a, b);
  cout << "pgcd de " << a << " et " << b << " = " << p << endl;
}
