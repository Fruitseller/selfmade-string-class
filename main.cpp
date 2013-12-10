#include <iostream>
#include "TString.h"

using namespace std;

int main()
{
	

	TString getterString("12345678abcdefgh");
	cout << "getString() returned: " << getterString.getString() << endl;

	cout << "shorten string: " << getterString.getString(5) << endl;
	int indexOfString = 0;
	indexOfString = getterString.findString("abc");
	cout << "Founded specific string: " << getterString.getString(indexOfString) << endl;

	TString sentence("Hallo und guten Tag meine Damen und Herren");
	cout << "Output specific piece of String: " << sentence.getString(16, 19) << endl;


	// LAENGE DES STRINGS:
	TString lengthString("Hallo Herbert wie gehts dir heute so?"); // 37 Zeichen
	cout << "Laenge des String: " << lengthString.getLength() << endl;

	// EINZELNES ZECIHEN FINDEN 
	TString findCharString("Hallo Fruchti");
	char charToFind = 'u';
	cout << "Index des gefundenen Zeichens: " << findCharString.findChar(charToFind) << endl;

	// ZECIHEN ERSETZEN
	TString replaceCharString("Hallo Fruchti");
	char charToReplace = 'u';
	char charToFillIn = 'x';
	replaceCharString.replaceChar(charToReplace,charToFillIn);
	cout << "Ersetzte Chars im String: " << replaceCharString.getString() << endl;

	// UMWANDELN IN GROSSBUCHSTABEN 
	TString uppercaseString("Hallo Herbert gib mal ne Pizza mit Bacon !");
	uppercaseString.toUpper();
	cout << "UPPERCASE: " << uppercaseString.getString() << endl;

	// UMWANDELN IN KLEINBUCHSTABEN 
	TString lowercaseString("Im Idealfall enthaelt dieser String nur Kleinbuchstaben!");
	lowercaseString.toLower();
	cout << "lowercase: " << lowercaseString.getString() << endl;

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

	// SPLIT SPLIT SPLIT
	TString splitString("dieser;string;sollte;gesplittet;werden");
	//TString splitString("dieser string enthaelt das trennzeichen leider nicht...");
	char delimiter = ';';
	char ** splittedWords = splitString.split(delimiter);
	int counterTheSecond = splitString.getSplitCount(delimiter);
	TString aStrings[counterTheSecond];
	for (unsigned int i= 0; i < counterTheSecond; i++)
	{
		aStrings[i].setString(splittedWords[i]);
		cout << aStrings[i].getString() << endl;
	}

	//TString a("teil1");
	//TString b("Teil2");
	//cout<<(a+b).getString();
	//cout<<a.getString();
	
	// Zuweisungsoperator
	//TString A("Test");
	//TString B;
	//TString C("Test");

	/*B = A;
	cout<<B.getString();

    cout<<(A > C);*/

	//cout<<(A == C);

	return 0;
}

