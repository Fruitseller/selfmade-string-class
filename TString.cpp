#include "TString.h"

	int x;
	char *string;

	TString::TString()
	{
		this->x = 0;
	}

	TString::TString (char *string)
	{
		this->string = string;
	}

	TString::~TString()
	{
		
	}

	char* TString::getString()
	{
		return this->string;
	}

	void TString::setString(char *string)
	{

	}

	TString::TString (int number)
	{
		this->x = number;
	}

	int TString::test()
	{
		return this->x;	
	}

