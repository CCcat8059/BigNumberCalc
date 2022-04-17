#include <iostream>

#include "Integer.h"

using namespace std;
int main(int argc, char* argv[])
{
	Integer a("-101561.512");
	cout << a.data << ' ' << a.sign;
	return 0;
}
