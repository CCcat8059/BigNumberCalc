#include <iostream>

#include "BigNumber.h"

using namespace std;
int main(int argc, char* argv[])
{
	BigNumber inta("123");
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
	return 0;
}
