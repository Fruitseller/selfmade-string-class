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

	// CONVERTIERT DEN STRING ZU GROßBUCHSTABEN
	void TString::toUpper()
	{
		for(int i=0; i <= this->length(); i++)
		{
			if(this->string[i] >= 97 && this->string[i] <= 122 )
			{
				this->string[i] -= 32;
			}
		}

	}

	// CONVERTIERT DEN STRING ZU KLEINBUCHSTABEN
	void TString::toLower()
	{
		for(int i=0; i <= this->length(); i++)
		{
			if(this->string[i] >= 65 && this->string[i] <= 90 )
			{
				this->string[i] += 32;
			}
		}

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

		return returner;
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

	//ERSETZT ALLE GEFUNDENEN CHARS('SEARCH') IM STRING MIT DEM CHAR 'REPLACE'
	void TString::replaceChar(char search, char replace)
	{
		int length = this->length();
		char * newString = this->string;

		for(int x = 0; x < this->length(); x++)
		{
			if(newString[x] == search)
			{
				newString[x] = replace;
			}
		}

		this->string = newString;
	}

