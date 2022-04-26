#include "BigNumber.h"

std::ostream& operator<<(std::ostream& os, BigNumber num)
{
	if (num.sign)
		os << '-';
	std::string  output = num.numerator;

	if (!num.isInt && num.denominator != "1") {
		output = "";
		std::string Dividend = num.numerator;
		std::string Divisor = num.denominator;
		BigNumber BN_Divisor(Divisor);
		std::vector<BigNumber> base_num(10);
		for (size_t i = 0; i < 10; i++)
		{
			base_num[i] = BN_Divisor * i;
		}
		Dividend = "0" + Dividend;
		int index_decimalStart = Dividend.size() - Divisor.size();
		for (size_t i = 0; i < index_decimalStart+100; i++)
		{
			if(i== index_decimalStart)output += '.';
			if(i>= index_decimalStart)Dividend += '0';

			std::string Dividend_tmp = Dividend.substr(i, Divisor.size() + 1);
			int Dividend_lead = 0, Divisor_lead = 0;
			bool is_bigger_than10 = Divisor.size() > 1;
			Dividend_lead += ((char)Dividend_tmp[0] - '0') * (is_bigger_than10 ? 100 : 10);
			Dividend_lead += ((char)Dividend_tmp[1] - '0') * (is_bigger_than10 ? 10 : 1);
			Dividend_lead += ((char)Dividend_tmp[2] - '0') * (is_bigger_than10 ? 1 : 0);
			Divisor_lead += (int)(Divisor[0] - '0') * (is_bigger_than10 ? 10 : 1);
			Divisor_lead += (int)(Divisor[1] - '0') * (is_bigger_than10 ? 1 : 0);
			int quotient = Dividend_lead / Divisor_lead;
			if (base_num[quotient] > BigNumber(Dividend_tmp))
				quotient -= 1;

			std::string remainder = (base_num[quotient] - BigNumber(Dividend_tmp)).numerator;
			while (remainder.size() < Dividend_tmp.size()) {
				remainder = "0" + remainder;
			}

			Dividend.replace(i, Dividend_tmp.size(), remainder);
			//std::cout << Dividend_lead << "/" << Divisor_lead << "=" << quotient << std::endl;
			output += (char)(quotient + '0');
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