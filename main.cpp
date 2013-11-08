#include <iostream>
#include "TString.h"
using namespace std;

void main()
{
	TString demoString(15);
	int test = demoString.test();
	cout << "Int test() returned: " << test << endl;
	system("pause");
}