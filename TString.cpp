#include "TString.h"

	int x;
	char *string;

	TString::TString()
	{
		this->string = NULL;
	}

	TString::TString (char *input)
	{
		this->string = new char[strlen(input) + 1];

		strcpy(this->string, input);
	}

	TString::~TString()
	{
		if (this->string != NULL)
			delete[] this->string;
	}

	char* TString::getString()
	{
		if (this->string != NULL)
			return this->string;
		else
			return "Nix gesetzt";
	}

	void TString::setString(char *input)
	{
		if (this->string != NULL)
		delete[] this->string;

	this->string = new char[strlen(input) + 1];

	strcpy(this->string,input);
	}

	TString::TString (int number)
	{
		this->x = number;
	}

