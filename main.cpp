#include <iostream>
#include "TString.h"
using namespace std;

// Testkommentar
int main()
{
	TString demoString("Hallo test test. 1 2 3 test.");
	cout << "getString() returned: " << demoString.getString() << endl;

	return 0;
}