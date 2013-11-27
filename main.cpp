#include <iostream>
#include "TString.h"
using namespace std;

int main()
{
	/*

	TString getterString("Hallo test test. 1 2 3 test.");
	cout << "getString() returned: " << getterString.GetString() << endl;

	// L�NGE DES STRINGS: 
	TString lengthString("Hallo Herbert wie gehts dir heute so?"); // 37 Zeichen
	cout << "Laenge des String: " << lengthString.GetLength() << endl;

	// EINZELNES ZECIHEN FINDEN 
	TString findCharString("Hallo Fruchti");
	char charToFind = 'u';
	cout << "Index des gefundenen Zeichens: " << findCharString.FindChar(charToFind) << endl;

	// ZECIHEN ERSETZEN
	TString replaceCharString("Hallo Fruchti");
	char charToReplace = 'u';
	char charToFillIn = 'x';
	replaceCharString.ReplaceChar(charToReplace,charToFillIn);
	cout << "Ersetzte Chars im String: " << replaceCharString.GetString() << endl;

	// UMWANDELN IN GROSSBUCHSTABEN 
	TString uppercaseString("Hallo Herbert gib mal ne Pizza mit Bacon !");
	uppercaseString.ToUpper();
	cout << "UPPERCASE: " << uppercaseString.GetString() << endl;

	// UMWANDELN IN KLEINBUCHSTABEN 
	TString lowercaseString("Im Idealfall enthaelt dieser String nur Kleinbuchstaben!");
	lowercaseString.ToLower();
	cout << "lowercase: " << lowercaseString.GetString() << endl;

	// ZAEHLEN VON CHARS
	TString countCharString("In diesem String werden einzelne Zeichen gezaehlt!");
	char countChar = 'i';
	int counter = countCharString.countChar(countChar, false);
	cout << "Gefundene " << countChar <<  "'s: " << counter << endl;

	// SUCHEN DER POSITION EINES CHARS 0-BASIERT
	TString indexOfCharString("In diesem String werden einzelne Zeichen gesucht!");
	char indexChar = 'i';
	int index = indexOfCharString.getIndexOfChar(indexChar, 0, false);
	cout << indexChar << " gefunden an Stelle: " << index << endl;

	*/

	// SPLIT SPLIT SPLIT
	TString splitString("dieser;string;sollte;gesplittet;werden");
	//TString splitString("dieser string enthaelt das trennzeichen leider nicht...");
	char delimiter = ';';
	char ** splittedWords = splitString.split(delimiter);
	int counter = splitString.getSplitCount(delimiter);
	for (unsigned int i= 0; i < counter; i++)
	{
		cout << splittedWords[i] << endl;
	}



	return 0;
}

