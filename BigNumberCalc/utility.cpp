#include "BigNumber.h"
BigNumber basicAdd(const BigNumber& a, const BigNumber& b)
{
	// integer addition (++, +-, -+, --)
	BigNumber result, aTemp(a), bTemp(b);
	result.numerator = "";
	if (aTemp.sign ^ bTemp.sign) // (+,-) or (-,+)
	{
		// if abs(negative num) is greater than the other -> result is negative
		if (aTemp.sign && abs(aTemp) > b || bTemp.sign && abs(bTemp) > a)
			result.sign = true;
		if (abs(aTemp) < abs(bTemp))
			std::swap(aTemp, bTemp);
	}
	else // (+,+) or (-,-)
		result.sign = aTemp.sign;

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
	// if result.numerator's digits are all zero
	if (zeroNum == result.numerator.size())
		result.numerator = "0";
	else
		result.numerator = result.numerator.substr(zeroNum);
	return result;
}

BigNumber basicSub(const BigNumber& a, const BigNumber& b)
{
	// integer substruction
	BigNumber temp(b);
	temp.sign = !temp.sign;
	return (a + temp);
}

BigNumber basicMul(const BigNumber& a, const BigNumber& b)
{
	// TODO
	// integer multipication (++, +-, -+, --)
	BigNumber result, aTemp(a), bTemp(b);

	//check if a or b =0
	bool is_a_zero = true;
	bool is_b_zero = true;
	for (size_t i = 0; i < aTemp.numerator.length(); i++)
	{
		is_a_zero = is_a_zero && aTemp.numerator[i] == '0';
	}
	for (size_t i = 0; i < bTemp.numerator.length(); i++)
	{
		is_b_zero = is_b_zero && bTemp.numerator[i] == '0';
	}
	if (is_a_zero || is_b_zero) {
		return BigNumber();
	}


	result.numerator = "";
	result.sign = aTemp.sign ^ bTemp.sign;
	int len = aTemp.numerator.length() + bTemp.numerator.length();
	int* value = new int[len];
	for (size_t i = 0; i < len; i++)
	{
		value[i] = 0;
	}
	for (int i = aTemp.numerator.length() - 1; i >= 0; i--)
	{
		for (int j = bTemp.numerator.length() - 1; j >= 0; j--)
		{
			int index = aTemp.numerator.length() - 1 - i + bTemp.numerator.length() - 1 - j;
			value[index] += (aTemp.numerator[i] - '0') * (bTemp.numerator[j] - '0');
		}
	}
	for (int i = 0; i < len-1; i++)
	{
		value[i + 1] += value[i] / 10;
		value[i] = value[i] % 10;
	}
	int index = len - 1;

	while (value[index] == 0)
	{
		index--;
	}
	while (index >= 0) {
		result.numerator = result.numerator + (char)(value[index--] + '0');
	}
	return result;

}

BigNumber basicDiv(const BigNumber& a, const BigNumber& b)
{
	// TODO
	// integer division (++, +-, -+, --)
	BigNumber result, aTemp(a), bTemp(b);
	std::string temp = bTemp.denominator;
	bTemp.denominator = bTemp.numerator;
	bTemp.numerator = temp;
	result = aTemp * bTemp;
	std::cout << result.numerator << '/' << result.denominator << '\n';

	return result;

}

BigNumber abs(BigNumber num)
{
	num.sign = false;
	return num;
}