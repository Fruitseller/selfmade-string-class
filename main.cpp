#include <iostream>
#include "TString.h"
using namespace std;

int main()
{
	TString demoString("Hallo test test. 1 2 3 test.");
	cout << "getString() returned: " << demoString.getString() << endl;

	/* LÄNGE DES STRINGS: */
	TString lengthString("Hallo Herbert wie gehts dir heute so?"); // 37 Zeichen
	cout << "Laenge des String: " << lengthString.length() << endl;

	TString findCharString("Hallo Fruchti");
	char charToFind = 'u';
	cout << "Index des gefundenen Zeichens: " << findCharString.findChar(charToFind) << endl;

	return 0;
}

