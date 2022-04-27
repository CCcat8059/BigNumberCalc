#include "BigNumber.h"

BigNumber operator+(const BigNumber& a, const BigNumber& b)
{
	BigNumber result;
	if (a.isInt && b.isInt) // both are integer
	{
		result = basicAdd(a, b);
	}
	else if (!a.isInt && !b.isInt) // both are float
	{
		// TODO
	}
	else // a and b are not the same type
	{
		// TODO
	}
	// std::cout << a << " + " << b << " = " << result << '\n';
	return result;
}

BigNumber operator-(const BigNumber& a, const BigNumber& b)
{
	BigNumber result;
	if (a.isInt && b.isInt) // both are integer
	{
		result = basicSub(a, b);
	}
	else if (!a.isInt && !b.isInt) // both are float
	{
		// TODO
	}
	else // a and b are not the same type
	{
		// TODO
	}
	return result;
}

BigNumber operator*(const BigNumber& a, const BigNumber& b)
{
	//std::cout << a.isInt << " " << b.isInt << std::endl;
	BigNumber result;
	if (a.isInt && b.isInt) // both are integer
	{
		result = basicMul(a, b);
	}
	else if (!a.isInt && !b.isInt) // both are float
	{
		//std::cout << "QQ" << std::endl;
		BigNumber a1(a.numerator), a2(a.denominator), b1(b.numerator), b2(b.denominator);
		result.numerator = (a1 * b1).numerator;
		result.denominator = (a2 * b2).numerator;
		result.isInt = 0;
	}
	else // a and b are not the same type
	{
		// TODO
	}
	return result;
}

BigNumber operator/(const BigNumber& a, const BigNumber& b)
{
	BigNumber result;
	if (a.isInt && b.isInt) // both are integer
	{
		result = basicDiv(a, b);
	}
	else if (!a.isInt && !b.isInt) // both are float
	{
		BigNumber a1(a.numerator), a2(a.denominator), b1(b.numerator), b2(b.denominator);
		result.numerator = (a1 * b2).numerator;
		result.denominator = (a2 * b1).numerator;
		result.isInt = 0;
	}
	else // a and b are not the same type
	{
		// TODO
		BigNumber a1(a.numerator), a2(a.denominator), b1(b.numerator), b2(b.denominator);
		result.numerator = (a1 * b2).numerator;
		result.denominator = (a2 * b1).numerator;
		result.isInt = 1;
	}
	return result;
}

BigNumber operator%(const BigNumber& a, const BigNumber& b)
{
	// integer only
	//suppose a and b are integer
	if (a.isInt && b.isInt) {
		BigNumber r = a / b;
		return (a - (b * r));
	}
	else {
		throw "warning: number must be integer\n";

	}

}
