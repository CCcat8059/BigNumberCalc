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