#include <iostream>

#include "BigNumber.h"

using namespace std;
int main(int argc, char* argv[])
{
	BigNumber inta("789");
	BigNumber intb("-456");
	BigNumber floata("1234.123");
	BigNumber floatb("-3456.789");
	BigNumber floatc("0.000123");
	BigNumber floatd("-0.789");
	BigNumber floatd("1234");
	// Jovi is branching
	cout << inta + inta;
	return 0;
}
