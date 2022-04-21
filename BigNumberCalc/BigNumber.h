#pragma once
#include <algorithm>
#include <iostream>
#include <string>
class BigNumber
{
private:
	std::string numerator;

	// if denominator is 1 -> int
	std::string denominator;

	// false -> positive, true -> negative
	bool sign;

	// false -> float, true -> int
	bool isInt;
public:
	BigNumber();
	BigNumber(const std::string);

	friend std::ostream& operator<<(std::ostream&, BigNumber);
	friend BigNumber operator+(const BigNumber&, const BigNumber&);
	friend BigNumber operator-(const BigNumber&, const BigNumber&);
};

