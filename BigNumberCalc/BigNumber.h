#pragma once
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
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
#pragma region Constructor
	BigNumber();
	BigNumber(const std::string);
	BigNumber(const BigNumber&);
	BigNumber(const int&);
	BigNumber(const double&);
#pragma endregion
	BigNumber(std::string a, std::string b);

#pragma region BigNumber operator overloading
	BigNumber operator=(const BigNumber&);
	BigNumber operator+=(const BigNumber&);
	BigNumber operator-=(const BigNumber&);
	BigNumber operator*=(const BigNumber&);
	BigNumber operator/=(const BigNumber&);


	friend BigNumber operator+(const BigNumber&, const BigNumber&);
	friend BigNumber operator-(const BigNumber&, const BigNumber&);
	friend BigNumber operator*(const BigNumber&, const BigNumber&);
	friend BigNumber operator*(const BigNumber&, int intB);       //BN*INT by haha
	friend BigNumber operator/(const BigNumber&, const BigNumber&);
	friend BigNumber operator%(const BigNumber&, const BigNumber&);


	friend bool operator==(const BigNumber&, const BigNumber&);
	friend bool operator!=(const BigNumber&, const BigNumber&);
	friend bool operator>(const BigNumber&, const BigNumber&);
	friend bool operator>=(const BigNumber&, const BigNumber&);
	friend bool operator<(const BigNumber&, const BigNumber&);
	friend bool operator<=(const BigNumber&, const BigNumber&);


	friend std::ostream& operator<<(std::ostream&, BigNumber);
#pragma endregion

#pragma region utility
	// for positive integers' basic operation
	friend BigNumber basicAdd(const BigNumber&, const BigNumber&);
	friend BigNumber basicSub(const BigNumber&, const BigNumber&);
	friend BigNumber basicMul(const BigNumber&, const BigNumber&);
	friend BigNumber basicDiv(const BigNumber&, const BigNumber&);
	friend BigNumber abs(BigNumber);
	friend BigNumber reciprocal(BigNumber);
	friend BigNumber gcd(const BigNumber&, const BigNumber&);
#pragma endregion


#pragma region operator overloading with int
	BigNumber operator=(const int&);
	BigNumber operator+=(const int&);
	BigNumber operator-=(const int&);
	BigNumber operator*=(const int&);
	BigNumber operator/=(const int&);


	friend BigNumber operator+(const BigNumber&, const int&);
	friend BigNumber operator+(const int&, const BigNumber&);
	friend BigNumber operator-(const BigNumber&, const int&);
	friend BigNumber operator-(const int&, const BigNumber&);
	friend BigNumber operator*(const BigNumber&, const int&);
	friend BigNumber operator*(const int&, const BigNumber&);
	friend BigNumber operator/(const BigNumber&, const int&);
	friend BigNumber operator/(const int&, const BigNumber&);


	friend BigNumber operator==(const BigNumber&, const int&);
	friend BigNumber operator==(const int&, const BigNumber&);
	friend BigNumber operator!=(const BigNumber&, const int&);
	friend BigNumber operator!=(const int&, const BigNumber&);
	friend BigNumber operator>(const BigNumber&, const int&);
	friend BigNumber operator>(const int&, const BigNumber&);
	friend BigNumber operator>=(const BigNumber&, const int&);
	friend BigNumber operator>=(const int&, const BigNumber&);
	friend BigNumber operator<(const BigNumber&, const int&);
	friend BigNumber operator<(const int&, const BigNumber&);
	friend BigNumber operator<=(const BigNumber&, const int&);
	friend BigNumber operator<=(const int&, const BigNumber&);
#pragma endregion
};

