#include "BigNumber.h"

BigNumber::BigNumber()
{
	sign = false;
	data = "";
}

BigNumber::BigNumber(std::string num)
{
	if (num.empty())
	{
		sign = false;
		data = "";
	}
	else
	{
		sign = (num[0] == '-');
		if (sign)
			data = num.substr(1);
		else
			data = num;;
	}
}
