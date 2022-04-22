#include "BigNumber.h"

BigNumber BigNumber::operator=(const BigNumber& num)
{
	this->numerator = num.numerator;
	this->denominator = num.denominator;
	this->isInt = num.isInt;
	this->sign = num.sign;
	return *this;
}