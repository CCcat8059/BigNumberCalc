#pragma once
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
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
	// create an object from single number
	BigNumber(const std::string);
	BigNumber(const BigNumber&);
	BigNumber(const short&);
	BigNumber(const int&);
	BigNumber(const long long&);
	BigNumber(const double&);
	// create an object from numerator and denominator
	BigNumber(std::string, std::string);
#pragma endregion

#pragma region BigNumber operator overloading
	BigNumber operator=(const BigNumber&);
	BigNumber operator+=(const BigNumber&);
	BigNumber operator-=(const BigNumber&);
	BigNumber operator*=(const BigNumber&);
	BigNumber operator/=(const BigNumber&);
	BigNumber operator%=(const BigNumber&);


	friend BigNumber operator+(const BigNumber&, const BigNumber&);
	friend BigNumber operator-(const BigNumber&, const BigNumber&);
	friend BigNumber operator*(const BigNumber&, const BigNumber&);
	friend BigNumber operator/(const BigNumber&, const BigNumber&);
	friend BigNumber operator%(const BigNumber&, const BigNumber&);
	BigNumber& operator++();
	BigNumber operator++(int);
	BigNumber& operator--();
	BigNumber operator--(int);


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
	// mathematic calculate
	friend BigNumber abs(BigNumber);
	friend BigNumber reciprocal(BigNumber);
	friend BigNumber gcd(const BigNumber&, const BigNumber&);
	friend BigNumber lcm(const BigNumber&, const BigNumber&);
	friend BigNumber power(const BigNumber&, const BigNumber&);
	friend BigNumber factorial(const BigNumber&);
	// others
	friend bool isValidPower(const BigNumber&);
	friend void simplifyNum(BigNumber&);
#pragma endregion

#pragma region operator overloading with int
	BigNumber operator=(const int&);
	BigNumber operator+=(const int&);
	BigNumber operator-=(const int&);
	BigNumber operator*=(const int&);
	BigNumber operator/=(const int&);
	BigNumber operator%=(const int&);


	friend BigNumber operator+(const BigNumber&, const int&);
	friend BigNumber operator+(const int&, const BigNumber&);
	friend BigNumber operator-(const BigNumber&, const int&);
	friend BigNumber operator-(const int&, const BigNumber&);
	friend BigNumber operator*(const BigNumber&, const int&);
	friend BigNumber operator*(const int&, const BigNumber&);
	friend BigNumber operator/(const BigNumber&, const int&);
	friend BigNumber operator/(const int&, const BigNumber&);
	friend BigNumber operator%(const BigNumber&, const int&);
	friend BigNumber operator%(const int&, const BigNumber&);


	friend bool operator==(const BigNumber&, const int&);
	friend bool operator==(const int&, const BigNumber&);
	friend bool operator!=(const BigNumber&, const int&);
	friend bool operator!=(const int&, const BigNumber&);
	friend bool operator>(const BigNumber&, const int&);
	friend bool operator>(const int&, const BigNumber&);
	friend bool operator>=(const BigNumber&, const int&);
	friend bool operator>=(const int&, const BigNumber&);
	friend bool operator<(const BigNumber&, const int&);
	friend bool operator<(const int&, const BigNumber&);
	friend bool operator<=(const BigNumber&, const int&);
	friend bool operator<=(const int&, const BigNumber&);
#pragma endregion
};

