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
	cWill = 0;
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
	cWill = 0;
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
void character::incrcStr(int value){
	cStr = cStr + value;
}

int character::getcInt(){
	return cInt;
}
void character::incrcInt(int value){
	cInt = cInt + value;
}

int character::getcEnd(){
	return cEnd;
}
void character::incrcEnd(int value){
	cEnd = cEnd + value;
}

int character::getcChar(){
	return cChar;
}
void character::incrcChar(int value){
	cChar = cChar + value;
}

int character::getcWill(){
	return cWill;
}
void character::incrcWill(int value){
	cWill = cWill + value;
}

int character::getcAgil(){
	return cAgil;
}
void character::incrcAgil(int value){
	cAgil = cAgil + value;
}
