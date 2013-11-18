#include <iostream>
#include "TString.h"
using namespace std;

int main()
{
	TString getterString("Hallo test test. 1 2 3 test.");
	cout << "getString() returned: " << getterString.GetString() << endl;

	/* LÄNGE DES STRINGS: */
	TString lengthString("Hallo Herbert wie gehts dir heute so?"); // 37 Zeichen
	cout << "Laenge des String: " << lengthString.GetLength() << endl;

	TString findCharString("Hallo Fruchti");
	char charToFind = 'u';
	cout << "Index des gefundenen Zeichens: " << findCharString.FindChar(charToFind) << endl;

	TString replaceCharString("Hallo Fruchti");
	char charToReplace = 'u';
	char charToFillIn = 'x';
	replaceCharString.ReplaceChar(charToReplace,charToFillIn);
	cout << "Ersetzte Chars im String: " << replaceCharString.GetString() << endl;


	TString uppercaseString("Hallo Herbert gib mal ne Pizza mit Bacon !");
	uppercaseString.ToUpper();
	cout << endl << endl << "UPPERCASE: " << uppercaseString.GetString() << endl << endl;

	TString lowercaseString("Im Idealfall enthaelt dieser String nur Kleinbuchstaben!");
	lowercaseString.ToLower();
	cout << endl << endl << "lowercase: " << lowercaseString.GetString() << endl << endl;

	return 0;
}

