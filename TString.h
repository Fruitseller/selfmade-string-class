#ifndef __TSTRING_H__
#define __TSTRING_H__

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
		int test(); 
};  

#endif 