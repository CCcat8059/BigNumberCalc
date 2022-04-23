#include "BigNumber.h"

BigNumber basicAdd(const BigNumber& a, const BigNumber& b)
{
	// integer addition (++, +-, -+, --)
	if ((a.sign == 0 && b.sign == 0) || (a.sign == 1 && b.sign == 1)) //(+,+) (-,-)
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
		if (a.sign == 1 && b.sign == 1) 
		{
			result.sign = 1;
		}
		return result;
	}
	else // (+,-) or (-,+)
	{ 
		BigNumber result, aTemp(a), bTemp(b);
		if (aTemp.isInt && bTemp.isInt)
		{
			if (a.sign == 1)
			{
				std::swap(aTemp, bTemp);
			}
			if (bTemp.numerator > aTemp.numerator)
			{
				std::swap(aTemp, bTemp);
				result.sign = true; // result is negetive
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