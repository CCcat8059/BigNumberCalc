#include <iostream>

#include "BigNumber.h"

using namespace std;
void basic_test();
void operator_test();
int main(int argc, char* argv[])
{
	operator_test();
	// haha
	return 0;
}

void basic_test()
{
	BigNumber inta("789");
	BigNumber intb("-456");
	BigNumber floata("1234.123");
	BigNumber floatb("-3456.789");
	BigNumber floatc("0.000123");
	BigNumber floatd("-0.789");
	cout << inta << '\n';
	cout << intb << '\n';
	cout << floata << '\n';
	cout << floatb << '\n';
	cout << floatc << '\n';
	cout << floatd << '\n';
}

void operator_test()
{
	BigNumber inta("999"), intb("1"), intc("1000");
	// cout << inta + intc << '\n';
	cout << intb - intc << '\n';
}