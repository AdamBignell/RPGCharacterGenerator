/* utilities.cpp

All of these functions are subtle utilities that will ease writing.

*/

#include "utilities.h"
#include <fstream>
#include "cstring"
#include "character.h"
#include "iostream"

using namespace std;

#define NUM_Q 20

bool CSVtoQuestions(question* questions){
	string line;
	ifstream csv("questions.csv");
	int flag = 0;
	int qNum = 0;
	if (csv){
		while(getline( csv, line, ',' ) && (qNum < 50)){
			if (flag == 0){
				questions[qNum].question = line;
				//cout << questions[qNum].question << endl;
			}
			if (flag == 1){
				questions[qNum].optionA = line;
				//cout << line << endl;
			}
			if (flag == 2){
				questions[qNum].aConseq = line;
				//cout << line << endl;
			}
			if (flag == 3){
				questions[qNum].optionB = line;
				//cout << line << endl;
			}
			if (flag == 4){
				questions[qNum].bConseq = line;
				//cout << line << endl;
			}
			if (flag == 5){
				questions[qNum].optionC = line;
				//cout << line << endl;
			}
			if (flag == 6){
				questions[qNum].cConseq = line;
				//cout << line << endl;
				qNum++;
			}
			flag = (flag + 1) % 7;

		}
	return true;
	}
	return false;
}

bool writeCharacterCSV(character* character){
	ofstream csv;
	// This is an odd-looking syntax but it specifies to open that we wish to explicitly output and append
	csv.open("characters.csv", ios::out | ios::app );
	csv << character->getName() << ",";
	csv << character->getProf() << ",";
	csv << character->getcStr() << ",";
	csv << character->getcInt() << ",";
	csv << character->getcEnd() << ",";
	csv << character->getcChar() << ",";
	csv << character->getcAgil() << ",";
	csv << character->getcWill() << ",\n";

	return true;
}

bool askQuestions(question* questions, character* newChar){
	for (int i = 0; i < NUM_Q; i++){
		// This loop "asks" all the questions loaded from the csv
		// Note that it requires proper setting of NUM_Q lest the program seg fault
		string choice;
		cout << questions[i].question << endl;
		cout << "\t A." << questions[i].optionA << endl;
		cout << "\t B." << questions[i].optionB << endl;
		cout << "\t C." << questions[i].optionC << endl;
		cout <<  "\nPlease enter A, B, or C:" << endl;
		cin >> choice;

		while (choice != "A" && choice != "B" && choice != "C" ) {
			cout << "\nYou did not enter a valid choice. Please enter A, B, or C" << endl;
			choice = "";
			cin >> choice;
		}

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
	return true;
}
