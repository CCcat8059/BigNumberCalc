#include "BigNumber.h"

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

BigNumber operator-(const BigNumber& a, const BigNumber& b)
{
	BigNumber result, aTemp(a), bTemp(b);
	if (aTemp.isInt && bTemp.isInt)
	{
		if (bTemp > aTemp)
		{
			std::swap(aTemp, bTemp);
			result.sign = true;
		}
		result.numerator = "";
		int aSize = aTemp.numerator.size(), bSize = bTemp.numerator.size();

		int carry(0);
		int aIndex = aSize - 1, bIndex = bSize - 1;
		for (int temp; aIndex >= 0 || bIndex >= 0; aIndex--, bIndex--)
		{
			// the index from tail to head 
			temp = carry;
			if (aIndex >= 0)
				temp += aTemp.numerator[aIndex] - '0';
			if (bIndex >= 0)
				temp -= bTemp.numerator[bIndex] - '0';

			if (temp < 0)
			{
				carry = -1;
				result.numerator = (char)(temp + 10 + '0') + result.numerator;
			}
			else
			{
				carry = 0;
				result.numerator = (char)(temp + '0') + result.numerator;
			}
		}

		// remove redundant 'zero'
		int zeroNum(0);
		while (result.numerator.size() > 1 && result.numerator[zeroNum] == '0')
			zeroNum++;
		result.numerator = result.numerator.substr(zeroNum);
	}
	return result;
}