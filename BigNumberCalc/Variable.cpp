#include "Variable.h"

std::map<std::string, BigNumber> stores;

bool nameIsValid(const std::string& name)
{
	if (name == "set" || name == "list")
		return false;
	if (!isalpha(name[0]))
		return false;
	for (const char& c : name)
	{
		if (!(isalpha(c) || isdigit(c)))
			return false;
	}
	return true;
}