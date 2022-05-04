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
			stores[name] = temp;
		}
		else if (input == "list")
		{
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