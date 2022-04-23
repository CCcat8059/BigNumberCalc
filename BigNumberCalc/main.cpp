#include <iostream>

#include "BigNumber.h"

using namespace std;
void basic_test();
void operator_test();
void relational_test();
int main(int argc, char* argv[])
{
	// basic_test();
	operator_test();
	// relational_test();
	return 0;
}

void basic_test()
{
	BigNumber inta("789");
	BigNumber intb("+789");
	BigNumber intc("-456");
	cout << inta << '\n';
	cout << intb << '\n';
	cout << intc << '\n';

	BigNumber floata("1234.123");
	BigNumber floatb("+1234.123");
	BigNumber floatc("-3456.789");
	cout << floata << '\n';
	cout << floatb << '\n';
	cout << floatc << '\n';

	BigNumber floatd("0.000123");
	BigNumber floate("+0.000123");
	BigNumber floatf("-0.789");

	cout << floatd << '\n';
	cout << floate << '\n';
	cout << floatf << '\n';
}

void operator_test()
{
	BigNumber inta("-1"), intb("1"), intc("-1000");
	//cout << inta + intc << '\n';
	//cout << intc + inta << '\n';

	cout << abs(inta) + intc << '\n';
	cout << intc + abs(inta) << '\n';

	cout << inta + abs(intc) << '\n';
	cout << abs(intc) + inta << '\n';

	cout << abs(inta) + abs(intc) << '\n';
	cout << abs(intc) + abs(inta) << '\n';
}

void relational_test()
{
	BigNumber inta("1000"), intb("-1000");
	BigNumber intc("100"), intd("-100");
	cout << inta << " > " << intb << (inta > intb ? " yes" : " no") << '\n';
	cout << inta << " > " << intc << (inta > intc ? " yes" : " no") << '\n';
	cout << inta << " > " << intd << (inta > intd ? " yes" : " no") << '\n';

	cout << intb << " > " << inta << (intb > inta ? " yes" : " no") << '\n';
	cout << intb << " > " << intc << (intb > intc ? " yes" : " no") << '\n';
	cout << intb << " > " << intd << (intb > intd ? " yes" : " no") << '\n';

	cout << intc << " > " << inta << (intc > inta ? " yes" : " no") << '\n';
	cout << intc << " > " << intb << (intc > intb ? " yes" : " no") << '\n';
	cout << intc << " > " << intd << (intc > intd ? " yes" : " no") << '\n';

	cout << intd << " > " << inta << (intd > inta ? " yes" : " no") << '\n';
	cout << intd << " > " << intb << (intd > intb ? " yes" : " no") << '\n';
	cout << intd << " > " << intc << (intd > intc ? " yes" : " no") << '\n';
}