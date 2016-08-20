/* character.cpp

The 'character' class is one instance of a character including their name and stats

Authors: Alister Pineda & Adam Bignell
*/

#include "character.h"
#include "string"
using namespace std;

character::character(){
	name = "NULL";
	prof = "NULL";

	cStr = 0;
	cInt = 0;
	cEnd = 0;
	cChar = 0;
	cLuck = 0;
	cAgil = 0;
}

// This allows us to instantiate with player entered name directly
character::character(string newName){
	name = newName;
	prof = "NULL";

	cStr = 0;
	cInt = 0;
	cEnd = 0;
	cChar = 0;
	cLuck = 0;
	cAgil = 0;
}

// Getters and setters below
string character::getName(){
	return name;
}
void character::setName(string newName){
	name = newName;
}

string character::getProf(){
	return prof;
}
void character::setProf(string newProf){
	prof = newProf;
}

int character::getcStr(){
	return cStr;
}
void character::setcStr(int newcStr){
	cStr = newcStr;
}

int character::getcInt(){
	return cInt;
}
void character::setcInt(int newcInt){
	cInt = newcInt;
}

int character::getcEnd(){
	return cEnd;
}
void character::setcEnd(int newcEnd){
	cEnd = newcEnd;
}

int character::getcChar(){
	return cChar;
}
void character::setcChar(int newcChar){
	cChar = newcChar;
}

int character::getcLuck(){
	return cLuck;
}
void character::setcLuck(int newcLuck){
	cLuck = newcLuck;
}

int character::getcAgil(){
	return cAgil;
}
void character::setcAgil(int newcAgil){
	cAgil = newcAgil;
}