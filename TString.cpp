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
		this->SetString(input);
	}

	TString::~TString()
	{
		if (this->string != NULL)
		{
			delete[] this->string;
		}
	}

	const char* TString::GetString()
	{
		if (this->string != NULL)
			return this->string;
		else
			return "Nix gesetzt";
	}

	void TString::SetString(const char *input)
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
	void TString::ToUpper()
	{
		for(int i=0; i <= this->GetLength(); i++)
		{
			if(this->string[i] >= 97 && this->string[i] <= 122 )
			{
				this->string[i] -= 32;
			}
		}

	}

	// CONVERTIERT DEN STRING ZU KLEINBUCHSTABEN
	void TString::ToLower()
	{
		for(int i=0; i <= this->GetLength(); i++)
		{
			if(this->string[i] >= 65 && this->string[i] <= 90 )
			{
				this->string[i] += 32;
			}
		}

	}

	// CONVERTIERT EINEN CHAR ZUM KLEINBUCHSTABEN
	char TString::charToLower(char x)
	{
		if(x >= 65 && x <= 90 )
			{
				x += 32;
			}
		return x;
	}

	// CONVERTIERT EINEN CHAR ZUM GROßBUCHSTABEN
	char TString::charToUpper(char x)
	{
		if(x >= 97 && x <= 122 )
		{
			x -= 32;
		}
		return x;
	}

	//LIEFERT DEN INDEX DES ERSTEN GEFUNDENEN ZEICHENS (0 BASIERUNG WIRD AUFGEHOBEN), WENN DAS ZEICHEN NICHT VORHANDEN IST LIEFERT DIE FUNKTION -1
	int TString::FindChar(char needle)
	{
		int returner = -1;

		int i = 0;
		while(this->GetString()[i] != '\0')
		{
			if(this->GetString()[i] == needle)
			{
				returner =  i;
				return returner + 1;
			}
			i++;
		};

		return returner;
	}

	//LIEFERT DIE LÄNGE DES STRING OHNE NULLTERMINIERUNG
	int TString::GetLength()
	{
		int i=0;
		while(this->GetString()[i] != '\0')
		{
			i++;
		};
		return i;
	}

	//ERSETZT ALLE GEFUNDENEN CHARS('SEARCH') IM STRING MIT DEM CHAR 'REPLACE'
	void TString::ReplaceChar(char search, char replace)
	{
		int length = this->GetLength();
		char * newString = this->string;

		for(int x = 0; x < this->GetLength(); x++)
		{
			if(newString[x] == search)
			{
				newString[x] = replace;
			}
		}

		this->string = newString;
	}

	//LIEFERT DIE ANZAHL DER GEFUNDENEN CHARS IM STRING
	// WENN caseSensitive AUF FALSE STEHT WIRD ALLES IN KLEINBUCHSTABEN UMGEWANDELT
	int TString::countChar(char c, bool caseSensitive = false)
	{
		char *dummy;
		dummy = this->string;

		if(!caseSensitive)
		{
			for(int i=0; i <= this->GetLength(); i++)
			{
				dummy[i] = this->charToLower(dummy[i]);
			}
			c = this->charToLower(c);
		}

		int i=0;
		int count = 0;
		while(dummy[i] != '\0')
		{
			if(dummy[i] == c)
			{
				count++;
			}
			i++;
		};
		return count;
	}

	// LIEFERT -1 WENN NICHTS GEFUNDEN WURDE
	int TString::getIndexOfChar(char x, int start = 0, bool caseSensitive = true)
	{
		int index = -1;
		char *dummy;
		dummy = this->string;

		if(!caseSensitive)
		{
			for(int i=0; i <= this->GetLength(); i++)
			{
				dummy[i] = this->charToLower(dummy[i]);
			}
			x = this->charToLower(x);
		}
		
		if(start < this->GetLength() && start >= 0)
		{
			int i = start;
			for(i; i <= this->GetLength(); i++)
			{
				if(dummy[i] == x)
				{
					return i;
				}
			}
		}
		return index;
	}


	char TString::getLastChar()
	{
		int index = this->GetLength() -1;
		return this->string[index];
	}


	char** TString::split(char delimiter)
	{
		// ALS ERSTES WIRD DIE ANZAHL DER TRENZEICHEN ERMITTELT
		int count = this->countChar(delimiter);
		if(!this->getLastChar() == delimiter)
		{
			count ++;
		}
		// DANN DIE GROESSE DES ARRAYS DER RUECKGABEWERTE FESTGELEGT
		char ** explodedString = new char * [count];

		int i = 0;
		int nextIndex = this->getIndexOfChar(delimiter,0,true);
		int wordCount = 0;

		while(wordCount <= count + 1)
		{
			if(nextIndex == -1)
			{
				for(i; i < this->GetLength(); i++)
				{
					cout << this->string[i];
				}
			}
			else
			{
				for(i; i < nextIndex; i++)
				{
					cout << this->string[i];
				}
			}
			wordCount ++;
			i++;
			nextIndex = this->getIndexOfChar(delimiter,i,true);
			cout << endl;
		};
		


		return explodedString; 
	}