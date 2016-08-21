/* character.h

The 'character' class is one instance of a character including their name and stats

Authors: Alister Pineda & Adam Bignell
*/

#include "string"
using namespace std;

class character {
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

	// Getters and setters below
	string getName();
	void setName(string newName);

	string getProf();
	void setProf(string newProf);

	int getcStr();
	void incrcStr(int value);

	int getcInt();
	void incrcInt(int value);

	int getcEnd();
	void incrcEnd(int value);

	int getcChar();
	void incrcChar(int value);

	int getcLuck();
	void incrcLuck(int value);

	int getcAgil();
	void incrcAgil(int value);
};