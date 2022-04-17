#pragma once
#include <string>
class BigNumber
{
public:
	bool sign;
	std::string data;

	BigNumber();
	BigNumber(std::string);
};

