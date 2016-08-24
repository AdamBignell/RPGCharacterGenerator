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

#define NUM_Q 20

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

	cout << "\n";
	newChar->setName(name);

	askQuestions(questions, newChar);

	newChar->assignProf();
	
	// Need something that interprets profession. To be discussed with Alister

	return newChar; // Return a now-complete instance of the player
}
