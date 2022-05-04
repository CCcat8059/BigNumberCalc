#include <iostream>

#include "Variable.h"
#include "BigNumber.h"
#include "FrontEndAnalyze.h"

using namespace std;
int main(int argc, char* argv[])
{
	for (string input; cin >> input;)
	{
		for (char& c : input)
		{
			if (isalpha(c))
				c = tolower(c);
		}
		if (input == "set")
		{
			cout << "please input variable name: ";
			string name, expression;
			cin >> name;

			if (!nameIsValid(name))
			{
				cout << "Error: the name is not valid.\n";
				continue;
			}
			cout << "please input expression or number: ";
			cin >> expression;
			BigNumber temp(expression);

			cout << "which type you want to store to?\n1. Integer\t2. Decimal\n";
			int choice;
			cin >> choice;
			if (choice == 1)
				temp = floatToInt(temp);
			else if (choice == 2)
				temp = intToFloat(temp);
			else
			{
				cout << "please input 1 or 2 to choose type.\n";
				continue;
			}
			stores[name] = temp;
		}
		else if (input == "list")
		{
			if (stores.empty())
			{
				cout << "there's no variable in list.\n";
				continue;
			}
			for (const auto& s : stores)
				cout << s.first << ' ' << s.second << '\n';
		}
		else if (input == "clear")
		{
			stores.clear();
		}
		else if (input == "delete")
		{
			if (stores.empty())
			{
				cout << "there's no variable can delete.\n";
				continue;
			}
			cout << "please input variable name: ";
			string name;
			cin >> name;
			auto iter = stores.find(name);
			if (iter == stores.end())
			{
				cout << "the variable \"" << name << "\" can't be found.\n";
				continue;
			}
			stores.erase(iter);
			cout << "delete \"" << name << "\" successfully.\n";
		}
		else
		{
			cout << convert(input) << '\n';
		}
	}
	return 0;
}