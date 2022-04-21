#include "BigNumber.h"

std::ostream& operator<<(std::ostream& os, BigNumber num)
{
	if (num.sign)
		os << '-';
	std::string output = num.numerator;


	if (!num.isInt)
	{
		int zeroNum = num.denominator.size() - output.size();
		if (zeroNum > 0)
		{
			output = std::string(zeroNum, '0') + output;
			output.insert(output.begin() + 1, '.');
		}
		else
		{
			output.insert(output.begin() + num.denominator.size(), '.');
		}
	}
	os << output;

#ifdef _DEBUG
	os << '\n' << num.numerator << '\n';
	os << num.denominator << '\n';
	os << "isInt: " << num.isInt << " sign: " << num.sign;
#endif // _DEBUG

	return os;
}

BigNumber operator+(const BigNumber& a, const BigNumber& b)
{
	BigNumber result;
	if (a.isInt && b.isInt)
	{
		result.numerator = "";
		int aSize = a.numerator.size(), bSize = b.numerator.size();

		int carry(0);
		int aIndex = aSize - 1, bIndex = bSize - 1;
		for (int temp; aIndex >= 0 || bIndex >= 0; aIndex--, bIndex--)
		{
			temp = carry;
			if (aIndex >= 0)
				temp += a.numerator[aIndex] - '0';
			if (bIndex >= 0)
				temp += b.numerator[bIndex] - '0';
			carry = temp / 10;
			result.numerator = (char)((temp % 10) + '0') + result.numerator;
		}
		if (carry > 0)
			result.numerator = (char)(carry + '0') + result.numerator;
	}
	return result;
}