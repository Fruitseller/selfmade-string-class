#include "TString.h"

	int x;
	char *string;

	TString::TString()
	{
		this->string = NULL;
	}

	TString::TString(const char *input)
	{
		this->string = NULL;
		this->setString(input);
	}

	TString::~TString()
	{
		if (this->string != NULL)
		{
			delete[] this->string;
		}
	}

	const char* TString::getString()
	{
		if (this->string != NULL)
			return this->string;
		else
			return "Nix gesetzt";
	}

	void TString::setString(const char *input)
	{
		if (this->string != NULL)
		{
			delete[] this->string;
		}

		this->string = new char[strlen(input) + 1];

		strcpy(this->string,input);
	}

	TString::TString(int number)
	{
		this->x = number;
	}

	//LIEFERT DEN INDEX DES ERSTEN GEFUNDENEN ZEICHENS (0 BASIERUNG WIRD AUFGEHOBEN), WENN DAS ZEICHEN NICHT VORHANDEN IST LIEFERT DIE FUNKTION -1
	int TString::findChar(char needle)
	{
		int returner = -1;

		int i = 0;
		while(this->getString()[i] != '\0')
		{
			if(this->getString()[i] == needle)
			{
				returner =  i;
				return returner + 1;
			}
			i++;
		};

		return returner +1;
	}

	//LIEFERT DIE LÄNGE DES STRING OHNE NULLTERMINIERUNG
	int TString::length()
	{
		int i=0;
		while(this->getString()[i] != '\0')
		{
			i++;
		};
		return i;
	}

