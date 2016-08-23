/* rpg.cpp
 *
 *
 */
 
#include <cstdio>
#include "iostream"
#include "fstream"
#include "questions.h"
#include "utilities.h"
#include "character.h"
#include <cstring>

using namespace std;

#define NUM_Q 2

// prototypes
character* generate_character(question* questions);
 
int main (int argc, char* argv[])
{
	// Check for characters.csv file, create one if it doesn't exist
	ifstream cf;
	cf.open("characters.csv");
	if (cf == NULL)
	{
		printf("CRITICAL: unable to access characters.csv\n");
		return 1;
	}

	
	question questions[NUM_Q];

	if (CSVtoQuestions(questions) == false)
	{
		printf("CRITICAL: unable to access questions.csv\n");
		return 1;
	}

	// Need to load in the questions

	int sel;
	
	while(1)
	{
		printf("Select an option:\n\n");
		printf("1	-	Generate Character\n");
		printf("0	-	Exit\n");
		printf("\nNum: ");
		cin >> sel;
		
		switch (sel)
		{
			case(1):
				{
					character* newChar = generate_character(questions);
					writeCharacterCSV(newChar);	
					break;
				}
			case(0):
				{
					cf.close();
					return 0;
				}
		}
		
	}
	
	
	return 0;
}

character* generate_character(question* questions)
{
	character* newChar = new character();
	cout << "\nPlease enter your name:" << endl;
	string name;

	// These two lines accept a name and ignore whiteapce
	cin >> ws;
	getline(cin, name);

	newChar->setName(name);

	for (int i = 0; i < NUM_Q; i++){
		// This loop "asks" all the questions loaded from the csv
		// Note that it requires proper setting of NUM_Q lest the program seg fault
		string choice;
		cout << "\n" << questions[i].question << endl;
		cout << "\t A." << questions[i].optionA << endl;
		cout << "\t B." << questions[i].optionB << endl;
		cout << "\t C." << questions[i].optionC << endl;
		cout <<  "\nPlease enter A, B, or C:" << endl;
		cin >> choice;

		string statChange;
		if (choice == "A"){
			statChange = questions[i].aConseq;
		}
		if (choice == "B"){
			statChange = questions[i].bConseq;
		}
		if (choice == "C"){
			statChange = questions[i].cConseq;
		}


		// Note that the ' == 0' is strictly necessary
		// As well, be very prudent with whitespace in the CSV 'attribute' fields
		if (strcmp(statChange.c_str(), "cStr") == 0){
			newChar->incrcStr(1);
		}
		if (strcmp(statChange.c_str(), "cInt") == 0){
			newChar->incrcInt(1);
		}
		if (strcmp(statChange.c_str(), "cEnd") == 0){
			newChar->incrcEnd(1);
		}
		if (strcmp(statChange.c_str(), "cChar") == 0){
			cout << "why?" << endl;
			newChar->incrcChar(1);
		}
		if (strcmp(statChange.c_str(), "cWill") == 0){
			newChar->incrcWill(1);
		}
		if (strcmp(statChange.c_str(), "cAgil") == 0){
			newChar->incrcAgil(1);
		}
	}

	// Need something that interprets profession. To be discussed with Alister

	return newChar; // Return a now-complete instance of the player
}
