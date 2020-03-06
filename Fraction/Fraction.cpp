#include <iostream>

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction(int numer = 0, int denom = 1) : numerator(numer), denominator(denom) {}

	static int nod(int a, int b)
	{
		return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
	}

	void reduce()
	{
		int nod = Fraction::nod(numerator, denominator);
		numerator /= nod;
		denominator /= nod;
	}

	friend std::ostream& operator<<(std::ostream& os, Fraction& fraction);
	friend std::istream& operator>>(std::istream& is, Fraction& fraction);

	friend Fraction operator+(Fraction& first, Fraction& second);
	friend Fraction operator-(Fraction& first, Fraction& second);
	friend Fraction operator*(Fraction& first, Fraction& second);
	friend Fraction operator/(Fraction& first, Fraction& second);

	friend bool operator==(Fraction& first, Fraction& second);
	friend bool operator!=(Fraction& first, Fraction& second);
	friend bool operator>(Fraction& first, Fraction& second);
	friend bool operator<(Fraction& first, Fraction& second);

};

std::ostream& operator<<(std::ostream& os, Fraction& fraction)
{
	os << fraction.numerator << '/' << fraction.denominator;

	return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction)
{
	is >> fraction.numerator;
	std::cout << '/' << '\n';
	is >> fraction.denominator;

	return is;
}

Fraction operator+(Fraction& first, Fraction& second)
{
	return Fraction((first.numerator * (first.denominator * second.denominator) / first.denominator)
		+ (second.numerator * (first.denominator * second.denominator) / second.denominator), first.denominator * second.denominator);
}

Fraction operator-(Fraction& first, Fraction& second)
{
	return Fraction((first.numerator * (first.denominator * second.denominator) / first.denominator)
		- (second.numerator * (first.denominator * second.denominator) / second.denominator), first.denominator * second.denominator);
}

Fraction operator*(Fraction& first, Fraction& second)
{
	return Fraction(first.numerator * second.numerator, first.denominator * second.denominator);
}

Fraction operator/(Fraction& first, Fraction& second)
{
	return Fraction(first.numerator * second.denominator, first.denominator * second.numerator);
}

bool operator==(Fraction& first, Fraction& second)
{
	return ((first.numerator * ((first.denominator * second.denominator) / first.denominator)) 
				== second.numerator * ((first.denominator * second.denominator) / second.denominator));
}

bool operator!=(Fraction& first, Fraction& second)
{
	return ((first.numerator * ((first.denominator * second.denominator) / first.denominator))
		!= second.numerator * ((first.denominator * second.denominator) / second.denominator));
}

bool operator>(Fraction& first, Fraction& second)
{
	return ((first.numerator * ((first.denominator * second.denominator) / first.denominator))
		> second.numerator * ((first.denominator * second.denominator) / second.denominator));
}

bool operator<(Fraction& first, Fraction& second)
{
	return ((first.numerator * ((first.denominator * second.denominator) / first.denominator))
		< second.numerator * ((first.denominator * second.denominator) / second.denominator));
}

int main()
{
	Fraction fr1(2, 6);
	Fraction fr2(4, 6);

	std::cout << fr1 << '\n';
	std::cout << fr2 << '\n';

	Fraction fr3 = fr1 / fr2;

	std::cout << fr3 << '\n';

	Fraction fr6 = fr1 * fr2;
	
	fr6.reduce();

	std::cout << fr6 << '\n';

	bool s = fr1 < fr2;

	std::cout << s << '\n';

	return 0;
}