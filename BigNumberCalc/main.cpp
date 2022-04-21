#include <iostream>

#include "BigNumber.h"

using namespace std;
int main(int argc, char* argv[])
{
	BigNumber inta("1500");
	BigNumber intb("-33");
	//BigNumber floata("1234.123");
	//BigNumber floatb("-3456.789");
	//BigNumber floatc("0.000123");
	//BigNumber floatd("-0.789");
	cout << inta + intb << endl;
	cout << inta - intb << endl;
	return 0;
}
