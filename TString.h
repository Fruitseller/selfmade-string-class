#ifndef __TSTRING_H__
#define __TSTRING_H__

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
class TString {  
	private:   
		char* Str;
	public: 
		TString();
		TString (const char*);
		~TString();
		const char* getString();
		const char* getString(int);
		const char* getString(int, int);
		void setString(const char*);
		int findChar(char);
		int getLength();
		void replaceChar(char, char);
		void toUpper();
		void toLower();
	    int countChar(char, bool);
		char charToLower(char);
		char charToUpper(char);
		int getIndexOfChar(char, int, bool);
		char** split(char);
		char getLastChar();
		int getSplitCount(char);
		int findString(const char*);
		bool isStringInTString(const char*);

		// ueberladene Operatoren
		TString operator+ (TString);
		bool operator> (const TString);
		bool operator< ( TString);
		TString operator= (TString);
		bool operator== (TString);

		
		
};  

#endif

