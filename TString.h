#ifndef __TSTRING_H__
#define __TSTRING_H__

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class TString {  
	private:   
		int x;
		char *string;

	public: 
		TString();
		TString (const char*);
		~TString();
		const char* getString();
		void setString(const char*);
		TString (int);
		int findChar(char);
		int length();
		void replaceChar(char, char);
		void toUpper();
		void toLower();
};  

#endif

