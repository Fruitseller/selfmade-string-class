#include "TString.h"

	int x;

	TString::TString()
	{
		this->x = 0;
	}

	TString::TString (int number)	{		this->x = number;	}	TString::~TString()
	{
		
	}

	int TString::test()
	{
		return this->x;	
	}

