class Fraction
{
private:
  int numerator;
  int denominator;
  
public:
  Fraction(int numerator, int denominator);
  
  void reduire();
  
  Fraction operator*(const Fraction& fraction) const;
  Fraction operator/(const Fraction& fraction) const;
  Fraction operator+(const Fraction& fraction) const;
  Fraction operator-(const Fraction& fraction) const;
  
  Fraction operator*=(const Fraction& fraction);
  Fraction operator/=(const Fraction& fraction);
  Fraction operator+=(const Fraction& fraction);
  Fraction operator-=(const Fraction& fraction);
  
  bool operator==(const Fraction& fraction) const;
  bool operator!=(const Fraction& fraction) const;
  bool operator<(const Fraction& fraction) const;
  bool operator<=(const Fraction& fraction) const;
  bool operator>(const Fraction& fraction) const;
  bool operator>=(const Fraction& fraction) const;

  Fraction operator++();
  Fraction operator++(int);
  Fraction operator--();
  Fraction operator--(int);
  
  friend std::ostream& operator<<(std::ostream& o, const Fraction& fraction);
  friend std::istream& operator>>(std::istream&i, Fraction& fraction);
};

int pgcd(int a, int b);
std::ostream& operator<<(std::ostream& o, const Fraction& fraction);
std::istream& operator>>(std::istream& i, Fraction& fraction);
