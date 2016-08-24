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

void character::assignProf(){
	int traitArray[6];

	// Note that indexing by Value is perhaps unintuitive,
	// But ultimately makes determining the max easier
	traitArray[0] = cStr;
	traitArray[1] = cInt;
	traitArray[2] = cEnd;
	traitArray[3] = cChar;
	traitArray[4] = cWill;
	traitArray[5] = cAgil;

	int max = -1;
	int max2 = -1;

	for (int i = 0; i < 6; i++){
		if (traitArray[i] > max){
			max = i;
		}
		else if ( (traitArray[i] > max2) && (traitArray[i] <= max)){
			max2 = i;
		}
	}

	// If the difference between max and max2 is sufficiently wide,
	// we consider the player of "pure profession"
	if (max - max2 >= 4){
		if (max == 0){
			prof = "PureDroid";
		}
		if (max == 1){
			prof = "Transhuman";
		}
		if (max == 2){
			prof = "Cyborg";
		}
		if (max == 3){
			prof = "Prince";
		}
		if (max == 4){
			prof = "Clairvoyant";
		}
		if (max == 5){
			prof = "Assassin";
		}
	}

	// Forgive me for what I'm about to do:
	// The below represents "mixed professions"
	else {
		if ((max == 0 && max2 == 1) || (max == 1 && max2 == 0)){
			prof == "DataDroid";
		}
		if ((max == 0 && max2 == 2) || (max == 2 && max2 == 0)){
			prof == "MechPilot";
		}
		if ((max == 0 && max2 == 3) || (max == 3 && max2 == 0)){
			prof == "MECHiavelli";
		}
		if ((max == 0 && max2 == 4) || (max == 4 && max2 == 0)){
			prof == "BattleBishop";
		}
		if ((max == 0 && max2 == 5) || (max == 5 && max2 == 0)){
			prof == "Hoverbiker";
		}
		if ((max == 1 && max2 == 2) || (max == 2 && max2 == 1)){
			prof == "Mal-Medic";
		}
		if ((max == 1 && max2 == 3) || (max == 3 && max2 == 1)){
			prof == "Stemcellian";
		}
		if ((max == 1 && max2 == 4) || (max == 4 && max2 == 1)){
			prof == "DataPriest";
		}
		if ((max == 1 && max2 == 5) || (max == 5 && max2 == 1)){
			prof == "NanoForm";
		}
		if ((max == 2 && max2 == 3) || (max == 3 && max2 == 2)){
			prof == "Body Guardian";
		}
		if ((max == 2 && max2 == 4) || (max == 4 && max2 == 2)){
			prof == "Bio-Immune";
		}
		if ((max == 2 && max2 == 5) || (max == 5 && max2 == 2)){
			prof == "Morpher";
		}
		if ((max == 3 && max2 == 4) || (max == 4 && max2 == 3)){
			prof == "OmniClone";
		}
		if ((max == 3 && max2 == 5) || (max == 5 && max2 == 3)){
			prof == "Netsurgent";
		}
		if ((max == 4 && max2 == 5) || (max == 5 && max2 == 4)){
			prof == "NeuroHacker";
		}
	}
	return;
}