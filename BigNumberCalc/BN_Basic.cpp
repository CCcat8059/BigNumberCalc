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
		sign = false;
		numerator = num;
		if (!isdigit(num[0]))
		{
			sign = (num[0] == '-');
			// remove '-' or '+'
			numerator = numerator.substr(1);
		}
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
		// if result.numerator's digits are all zero
		if (zeroNum == numerator.size())
			numerator = "0";
		else
			numerator = numerator.substr(zeroNum);

		if (sign && numerator == "0") // -0
			sign = false;
	}
}

BigNumber::BigNumber(const BigNumber& num)
{
	this->numerator = num.numerator;
	this->denominator = num.denominator;
	this->isInt = num.isInt;
	this->sign = num.sign;
}

BigNumber::BigNumber(const int& num)
{
	std::stringstream ss;
	ss << num;
	new (this) BigNumber(ss.str());
}

BigNumber::BigNumber(const double& num)
{
	std::stringstream ss;
	ss << num;
	new (this) BigNumber(ss.str());
}

BigNumber::BigNumber(std::string numerator, std::string denominator)
{
	// TODO parse numerator and denominator (+,- integer, float)
	this->numerator = numerator;
	this->denominator = denominator;
	this->isInt = false;
	this->sign = false;
}

void parseStrToBN(BigNumber* bigNumber, const std::string input)
{
	// avoid empty string
	if (input.empty())
	{
		bigNumber->sign = false;
		bigNumber->isInt = true;
		bigNumber->numerator = "0";
		bigNumber->denominator = "1";
	}
	else
	{
		bigNumber->sign = false;
		bigNumber->numerator = input;
		if (!isdigit(input[0]))
		{
			bigNumber->sign = (input[0] == '-');
			// remove '-' or '+'
			bigNumber->numerator = bigNumber->numerator.substr(1);
		}
		bigNumber->denominator = "1";

		int pointPosition = bigNumber->numerator.find('.');
		// if could not find '.' -> is int
		bigNumber->isInt = (pointPosition == std::string::npos);

		// if is float
		if (!bigNumber->isInt)
		{
			// 1. remove '.'
			bigNumber->numerator.erase(pointPosition, 1);
			// 2. denominator should be bigger 
			bigNumber->denominator += std::string(bigNumber->numerator.size() - pointPosition, '0');
		}

		// remove redundant 'zero'
		int zeroNum(0);
		while (bigNumber->numerator.size() > 1 && bigNumber->numerator[zeroNum] == '0')
			zeroNum++;
		// if result.numerator's digits are all zero
		if (zeroNum == bigNumber->numerator.size())
			bigNumber->numerator = "0";
		else
			bigNumber->numerator = bigNumber->numerator.substr(zeroNum);

		if (bigNumber->sign && bigNumber->numerator == "0") // -0
			bigNumber->sign = false;
	}
}