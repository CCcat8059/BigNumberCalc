#include "BigNumber.h"

BigNumber basicAdd(const BigNumber& a, const BigNumber& b)
{
	// integer addition (++, +-, -+, --)
	BigNumber result, aTemp(a), bTemp(b);;
	result.numerator = "";
	if (a.sign ^ b.sign) // (+,-) or (-,+)
	{
		// if abs(negative num) is greater than the other -> result is negative
		if (aTemp.sign && abs(aTemp) > b || bTemp.sign && abs(bTemp) > a)
			result.sign = true;
		if (abs(aTemp) < abs(bTemp))
			std::swap(aTemp, bTemp);
	}
	else // (+,+) or (-,-)
		result.sign = a.sign;

	int carry(0),
		aIndex = aTemp.numerator.size() - 1,
		bIndex = bTemp.numerator.size() - 1;
	for (int temp; aIndex >= 0 || bIndex >= 0; aIndex--, bIndex--)
	{
		// the index from tail to head 
		temp = carry;
		if (aIndex >= 0)
			temp += aTemp.numerator[aIndex] - '0';
		if (bIndex >= 0)
		{
			if (aTemp.sign ^ bTemp.sign) // (-,+) or (+,-) and the bigger number will be at front
				temp -= bTemp.numerator[bIndex] - '0';
			else // (+,+) or (-,-)
				temp += bTemp.numerator[bIndex] - '0';
		}

		if (temp < 0) // only will happen in a and b are not same type (+,-) or (-,+)
		{
			carry = -1;
			result.numerator = (char)(temp + 10 + '0') + result.numerator;
		}
		else // temp >= 0
		{
			carry = temp / 10;
			result.numerator = (char)((temp % 10) + '0') + result.numerator;
		}
	}
	// if carry have value -> one more digit (99 + 1 = 100)
	if (carry > 0)
		result.numerator = (char)(carry + '0') + result.numerator;

	// remove redundant 'zero'
	int zeroNum(0);
	while (result.numerator.size() > 1 && result.numerator[zeroNum] == '0')
		zeroNum++;
	result.numerator = result.numerator.substr(zeroNum);
	return result;
}


BigNumber basicSub(const BigNumber& a, const BigNumber& b)
{
	// TODO
	// integer substruction (++, +-, -+, --)

	return BigNumber();
}

BigNumber basicMul(const BigNumber& a, const BigNumber& b)
{
	// TODO
	// integer multipication (++, +-, -+, --)
	return BigNumber();
}

BigNumber basicDiv(const BigNumber& a, const BigNumber& b)
{
	// TODO
	// integer division (++, +-, -+, --)
	return BigNumber();
}

BigNumber abs(BigNumber num)
{
	num.sign = false;
	return num;
}