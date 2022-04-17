#include "Integer.h"

Integer::Integer() :BigNumber()
{

}

Integer::Integer(std::string num) :BigNumber(num)
{
	// only store integer part
	int point = data.find('.');
	data = data.substr(0, point);
}