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
	BigNumber result;
	if (a.isInt && b.isInt) // both are integer
	{
		result = basicMul(a, b);
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

BigNumber operator/(const BigNumber& a, const BigNumber& b)
{
	BigNumber result;
	if (a.isInt && b.isInt) // both are integer
	{
		result = basicDiv(a, b);
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

BigNumber operator%(const BigNumber& a, const BigNumber& b)
{
	// !!! integer only !!!
	// suppose a and b are integer
	if (!a.isInt || !b.isInt)
		throw "warning: number must be integer\n";

	BigNumber temp = a / b;
	return (a - (b * temp));
}
