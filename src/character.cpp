/* character.cpp

The 'character' class is one instance of a character including their name and stats

Authors: Alister Pineda & Adam Bignell
*/

#include "character.h"
#include "iostream"
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

	// Useful for Listing info
	// Probably will become the "Show stats" option
	// cout << "Strength is: " << traitArray[0] << endl;
	// cout << "Intelligence is: " << traitArray[1] << endl;
	// cout << "Endurance is: " << traitArray[2] << endl;
	// cout << "Charisma is: " << traitArray[3] << endl;
	// cout << "Willpower is: " << traitArray[4] << endl;
	// cout << "Agility is: " << traitArray[5] << endl;

	int max = 0;
	int max2 = 0;

	for (int i = 0; i < 6; i++){
		if (traitArray[i] > traitArray[max]){
			max = i;
		}
		// Note there is a nasty bug here:
		// If the player just so happens to have many repeated values for traits,
		// this function assumes that their "second best" is the last instance of this repetition
		// We could either have handling for this case, or invent some class that represents 'balance'
		// As it stands the traits are biased in reverse order (according to traitArray)
		else if ( (traitArray[i] >= traitArray[max2]) && (traitArray[i] <= traitArray[max]) ){
			max2 = i;
		}
	}

	cout << "Max is: " << max << endl;
	cout << "Max2 is: " << max2 << endl;

	// If the difference between max and max2 is sufficiently wide,
	// we consider the player of "pure profession"
	if (traitArray[max] - traitArray[max2] >= 4){
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
			prof = "DataDroid";
		}
		if ((max == 0 && max2 == 2) || (max == 2 && max2 == 0)){
			prof = "MechPilot";
		}
		if ((max == 0 && max2 == 3) || (max == 3 && max2 == 0)){
			prof = "MECHiavelli";
		}
		if ((max == 0 && max2 == 4) || (max == 4 && max2 == 0)){
			prof = "BattleBishop";
		}
		if ((max == 0 && max2 == 5) || (max == 5 && max2 == 0)){
			prof = "Hoverbiker";
		}
		if ((max == 1 && max2 == 2) || (max == 2 && max2 == 1)){
			prof = "Mal-Medic";
		}
		if ((max == 1 && max2 == 3) || (max == 3 && max2 == 1)){
			prof = "Stemcellian";
		}
		if ((max == 1 && max2 == 4) || (max == 4 && max2 == 1)){
			prof = "DataPriest";
		}
		if ((max == 1 && max2 == 5) || (max == 5 && max2 == 1)){
			prof = "NanoForm";
		}
		if ((max == 2 && max2 == 3) || (max == 3 && max2 == 2)){
			prof = "Body Guardian";
		}
		if ((max == 2 && max2 == 4) || (max == 4 && max2 == 2)){
			prof = "Bio-Immune";
		}
		if ((max == 2 && max2 == 5) || (max == 5 && max2 == 2)){
			prof = "Morpher";
		}
		if ((max == 3 && max2 == 4) || (max == 4 && max2 == 3)){
			prof = "OmniClone";
		}
		if ((max == 3 && max2 == 5) || (max == 5 && max2 == 3)){
			prof = "Netsurgent";
		}
		if ((max == 4 && max2 == 5) || (max == 5 && max2 == 4)){
			prof = "NeuroHacker";
		}
	}
	return;
}

void character::printDetails(){
	cout << "\n" << getName() << ", your profession is: " << getProf() << endl;
	return;
}