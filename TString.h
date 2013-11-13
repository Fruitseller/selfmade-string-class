#ifndef __TSTRING_H__
#define __TSTRING_H__

#include <iostream>
#include <stdio.h>

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
};  

#endif 