/* character.h

The 'character' class is one instance of a character including their name and stats

Authors: Alister Pineda & Adam Bignell
*/

#include "string"

class character(){
private:
	string name;
	string prof;

	// Could include levels, items etc.

	// Note that c stands for 'character' to avoid 'int str', 'int int', and 'int char'
	int cStr;
	int cInt;
	int cEnd;
	int cChar;
	int cLuck;
	int cAgil;

public:
	character();

	// This allows us to instantiate with player entered name directly
	character(string newName);

	string getName();
	void setName(string newName);

	string getProf();
	void setProf(string newProf);

	int getcStr();
	void setcStr(int newcStr);

	int getcInt();
	void setcInt(int newcInt);

	int getcEnd();
	void setcEnd(int newcEnd);

	int getcChar();
	void setcChar(int newcChar);

	int getcLuck();
	void setcLuck(int newcLuck);

	int getcAgil();
	void setcAgil(int newcAgil);
}