#include <iostream>
#include "TString.h"
using namespace std;

// Testkommentar
int main()
{
	TString demoString(15);
	int test = demoString.test();
	cout << "Int test() returned: " << test << endl;
	
	TString demoString2("Hallo test test. 1 2 3 test.");
	cout << "getString() returned: " << demoString2.getString() << endl;

	return 0;
}