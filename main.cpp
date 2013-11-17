#include <iostream>
#include "TString.h"
using namespace std;

int main()
{
	TString getterString("Hallo test test. 1 2 3 test.");
	cout << "getString() returned: " << getterString.getString() << endl;

	/* LÄNGE DES STRINGS: */
	TString lengthString("Hallo Herbert wie gehts dir heute so?"); // 37 Zeichen
	cout << "Laenge des String: " << lengthString.length() << endl;

	TString findCharString("Hallo Fruchti");
	char charToFind = 'u';
	cout << "Index des gefundenen Zeichens: " << findCharString.findChar(charToFind) << endl;

	TString replaceCharString("Hallo Fruchti");
	char charToReplace = 'u';
	char charToFillIn = 'x';
	replaceCharString.replaceChar(charToReplace,charToFillIn);
	cout << "Ersetzte Chars im String: " << replaceCharString.getString() << endl;


	TString uppercaseString("Hallo Herbert gib mal ne Pizza mit Bacon !");
	uppercaseString.toUpper();
	cout << endl << endl << "UPPERCASE: " << uppercaseString.getString() << endl << endl;

	TString lowercaseString("Im Idealfall enthaelt dieser String nur Kleinbuchstaben!");
	lowercaseString.toLower();
	cout << endl << endl << "lowercase: " << lowercaseString.getString() << endl << endl;

	return 0;
}

