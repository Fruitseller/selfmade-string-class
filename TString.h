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
		const char* GetString();
		void SetString(const char*);
		TString (int);
		int FindChar(char);
		int GetLength();
		void ReplaceChar(char, char);
		void ToUpper();
		void ToLower();
	    int countChar(char, bool);
		char charToLower(char);
		char charToUpper(char);
		int getIndexOfChar(char, int, bool);
		char** split(char);
		char getLastChar();
		int getSplitCount(char);
};  

#endif

