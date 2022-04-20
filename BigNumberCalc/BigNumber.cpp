#include "BigNumber.h"

BigNumber::BigNumber()
{
	// initial value = 0 (int)
	sign = false;
	isInt = true;
	numerator = "0";
	denominator = "1";
}

BigNumber::BigNumber(const std::string num)
{
	// avoid empty string
	if (num.empty())
	{
		sign = false;
		isInt = true;
		numerator = "0";
		denominator = "1";
	}
	else
	{
		sign = (num[0] == '-');
		// remove '-'
		numerator = num.substr(sign);
		denominator = "1";

		int pointPosition = numerator.find('.');
		// if could not find '.' -> is int
		isInt = (pointPosition == std::string::npos);

		// if is float
		if (!isInt)
		{
			// 1. remove '.'
			numerator.erase(pointPosition, 1);
			// 2. denominator should be bigger 
			denominator += std::string(numerator.size() - pointPosition, '0');
		}

		// remove redundant 'zero'
		int zeroNum(0);
		while (numerator.size() > 1 && numerator[zeroNum] == '0')
			zeroNum++;
		numerator = numerator.substr(zeroNum);
	}
}
