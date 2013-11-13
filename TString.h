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
		TString (char*);
		~TString();
		char* getString();
		void setString(char*);
		TString (int);
		int findChar(char);
		int length();
};  

#endif

