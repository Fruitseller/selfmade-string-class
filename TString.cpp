#include "TString.h"

	char *Str;

	TString::TString()
	{
		this->Str = NULL;
	}

	TString::TString(const char *input)
	{
		this->Str = NULL;
		this->setString(input);
	}

	TString::~TString()
	{
		if (this->Str != NULL)
		{
			delete[] this->Str;
		}
	}

	const char* TString::getString()
	{
		if (this->Str != NULL)
			return this->Str;
		else
			return "\0";
	}

	const char* TString::getString(int index)
	{
		char *shortendString = new char[(this->getLength() - index) + 1];
		int counter = 0;

		for (int i = index; i < this->getLength(); i++)
		{
			shortendString[counter] = this->Str[i];
			counter++;
		}

		return shortendString;
	}

	const char* TString::getString(int begin, int end)
	{
		if (begin > end || begin > this->getLength() || end > this->getLength())
			return "\0";

		char *tinyString = new char[(end - begin) + 1];
		int counter = 0;

		for (int i = begin; i < this->getLength(); i++)
		{
			while (i != end)
			{
				tinyString[counter] = this->Str[i];
				counter++;
				i++;
			}

			tinyString[counter] = '\0';

			return tinyString;
		}
	}

	void TString::setString(const char *input)
	{
		if (this->Str != NULL)
		{
			delete[] this->Str;
		}

		this->Str = new char[strlen(input) + 1];

		strcpy(this->Str,input);
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

	//LIEFERT DIE LAENGE DES STRING OHNE NULLTERMINIERUNG
	int TString::getLength()
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
		int length = this->getLength();
		char * newString = this->Str;

		for(int x = 0; x < this->getLength(); x++)
		{
			if(newString[x] == search)
			{
				newString[x] = replace;
			}
		}

		this->Str = newString;
	}

	// CONVERTIERT DEN STRING ZU GROSSBUCHSTABEN
	void TString::toUpper()
	{
		for(int i=0; i <= this->getLength(); i++)
		{
			if(this->Str[i] >= 97 && this->Str[i] <= 122 )
			{
				this->Str[i] -= 32;
			}
		}

	}

	// CONVERTIERT DEN STRING ZU KLEINBUCHSTABEN
	void TString::toLower()
	{
		for(int i=0; i <= this->getLength(); i++)
		{
			if(this->Str[i] >= 65 && this->Str[i] <= 90 )
			{
				this->Str[i] += 32;
			}
		}

	}

	//LIEFERT DIE ANZAHL DER GEFUNDENEN CHARS IM STRING
	// WENN caseSensitive AUF FALSE STEHT WIRD ALLES IN KLEINBUCHSTABEN UMGEWANDELT
	int TString::countChar(char c, bool caseSensitive = false)
	{
		char *dummy;
		dummy = this->Str;

		if(!caseSensitive)
		{
			for(int i=0; i <= this->getLength(); i++)
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

	// CONVERTIERT EINEN CHAR ZUM KLEINBUCHSTABEN
	char TString::charToLower(char x)
	{
		if(x >= 65 && x <= 90 )
			{
				x += 32;
			}
		return x;
	}

	// CONVERTIERT EINEN CHAR ZUM GROSSBUCHSTABEN
	char TString::charToUpper(char x)
	{
		if(x >= 97 && x <= 122 )
		{
			x -= 32;
		}
		return x;
	}

	// LIEFERT -1 WENN NICHTS GEFUNDEN WURDE
	int TString::getIndexOfChar(char x, int start = 0, bool caseSensitive = true)
	{
		int index = -1;
		char *dummy;
		dummy = this->Str;

		if(!caseSensitive)
		{
			for(int i=0; i <= this->getLength(); i++)
			{
				dummy[i] = this->charToLower(dummy[i]);
			}
			x = this->charToLower(x);
		}
		
		if(start < this->getLength() && start >= 0)
		{
			int i = start;
			for(i; i <= this->getLength(); i++)
			{
				if(dummy[i] == x)
				{
					return i;
				}
			}
		}
		return index;
	}

	char** TString::split(char delimiter)
	{
		// ALS ERSTES WIRD DIE ANZAHL DER TRENZEICHEN ERMITTELT
		int count = 0;
		count = this->getSplitCount(delimiter)-1;
		if(count == 0)
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
			// FALLS DER DELIMITER IM STRING NICHT AUFTAUCHT WIRD DER GANZE STRING GEDINGST
			if(nextIndex == -1)
			{
				explodedString[0] = this->Str;
			}
			else
			{
				int length = (nextIndex - i) + 1;
				char * splitWord = new char[length];
				int x = 0;
				for(i; i < nextIndex; i++)
				{
					splitWord[x] = this->Str[i];
					x++;
				}
				splitWord[length -1] = '\0';
				explodedString[wordCount] = splitWord;
			}
			wordCount ++;
			i++;
			nextIndex = this->getIndexOfChar(delimiter,i,true);
			if(nextIndex == -1)
				{
					nextIndex = this->getLength();
				}
		};

		return explodedString; 
	}

	char TString::getLastChar()
	{
		int index = this->getLength() -1;
		return this->Str[index];
	}

	int TString::getSplitCount(char delimiter)
	{
		int count = this->countChar(delimiter);
		if(!this->getLastChar() == delimiter)
		{
			count ++;
		}
		// ARRAY GROESSE OHNE 0 BASIERUNG
		return count +1;
	}

	int TString::findString(const char* stringToFind)
	{
		int counter = 0;

		if (strlen(stringToFind) > this->getLength())
		{
			return -1;
		}

		for (int i = 0; i < this->getLength(); i++)
		{
			while (this->Str[i] == stringToFind[counter])
			{
				counter++;
				i++;

				if (counter == strlen(stringToFind))
				{
					return i - counter;
				}
			}

		}

		return -1;
	}

	bool TString::isStringInTString(const char* stringToFind)
	{
		if (this->findString(stringToFind) != -1)
			return true;
		return false;
	}

	TString TString::operator+ (TString b)
		{   
		
			char * dummy;
			int gesamt;
			TString Temp;
			gesamt = strlen(Str);    //Str.getLength();
			gesamt += strlen(b.Str);//b.getLength();
			if (gesamt > 0)
				{
					dummy = new char[gesamt + 1];
					strcpy (dummy,Str);
					strcat (dummy, b.Str);
					Temp.setString(dummy);
					delete [] dummy;
					return Temp;
				}
			return Temp; 
		}
	bool TString::operator> (const TString inp)
		{
			int laengeA, laengeB;
			laengeA = strlen(Str); 
			laengeB = strlen(inp.Str);
			return(laengeA > laengeB );
		}

	TString TString::operator= (TString inp)
		{
			setString(inp.Str);
			return Str;
		}
	bool TString::operator< (const TString inp)
		{
			int laengeA, laengeB;
			laengeA = this->getLength();
			laengeB = strlen(inp.Str);
			return(laengeA > laengeB );
		}
	
	bool TString::operator== (TString inp)
		{
			char *strA = this->Str;
			int laengeStrA = this->getLength();
			int laengeStrB = strlen(inp.Str);
			if (laengeStrA < laengeStrB) 
				{
					// laengeStrB ist grösser
					for (int i = 0; i <= laengeStrB; i++)
						{
							if (this->Str[i] != inp.Str[i]) return false;
						}
				}
			else
				{
					for (int i = 0; i <= laengeStrA; i++)
						{
							if (this->Str[i] != inp.Str[i]) return false;
						}
				}
			return true; // wird zurückgegeben wenn die Zeichenketten nicht ungleich sind

		}