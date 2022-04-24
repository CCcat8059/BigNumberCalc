#pragma once
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
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
	BigNumber(const BigNumber&);
	BigNumber(const int&);
	BigNumber(const double&);

	BigNumber operator=(const BigNumber&);
	BigNumber operator+=(const BigNumber&);
	BigNumber operator-=(const BigNumber&);
	BigNumber operator*=(const BigNumber&);
	BigNumber operator/=(const BigNumber&);

	friend BigNumber operator+(const BigNumber&, const BigNumber&);
	friend BigNumber operator-(const BigNumber&, const BigNumber&);
	friend BigNumber operator*(const BigNumber&, const BigNumber&);
	friend BigNumber operator/(const BigNumber&, const BigNumber&);


	friend bool operator==(const BigNumber&, const BigNumber&);
	friend bool operator!=(const BigNumber&, const BigNumber&);
	friend bool operator>(const BigNumber&, const BigNumber&);
	friend bool operator>=(const BigNumber&, const BigNumber&);
	friend bool operator<(const BigNumber&, const BigNumber&);
	friend bool operator<=(const BigNumber&, const BigNumber&);


	friend std::ostream& operator<<(std::ostream&, BigNumber);

	// for positive integers' basic operation
	friend BigNumber basicAdd(const BigNumber&, const BigNumber&);
	friend BigNumber basicSub(const BigNumber&, const BigNumber&);
	friend BigNumber basicMul(const BigNumber&, const BigNumber&);
	friend BigNumber basicDiv(const BigNumber&, const BigNumber&);
	friend BigNumber abs(BigNumber);
	friend BigNumber reciprocal(BigNumber);
};

