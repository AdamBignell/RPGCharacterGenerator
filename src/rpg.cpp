/* rpg.cpp
 *
 *
 */
 
#include <cstdio>
#include "iostream"
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
	FILE* cf = fopen("characters.csv", "w+");
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
					break;
				}
			case(0):
				{
					fclose(cf);
					return 0;
				}
		}
		
	}
	
	
	return 0;
}

character* generate_character(question* questions)
{
	character* newChar = new character();
	for (int i = 0; i < NUM_Q; i++){
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
			cout << "print something\n";
			statChange = questions[i].cConseq;
		}

		if (strcmp(statChange.c_str(), "cStr")){
			newChar->incrcStr(1);
		}
		if (strcmp(statChange.c_str(), "cInt")){
			newChar->incrcInt(1);
		}
		if (strcmp(statChange.c_str(), "cEnd")){
			newChar->incrcEnd(1);
		}
		if (strcmp(statChange.c_str(), "cChar")){
			newChar->incrcChar(1);
		}
		if (strcmp(statChange.c_str(), "cLuck")){
			newChar->incrcLuck(1);
		}
		if (strcmp(statChange.c_str(), "cAgil")){
			newChar->incrcAgil(1);
		}
	}

	return newChar;
}
