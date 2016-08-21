/* utilities.cpp

All of these functions are subtle utilities that will ease writing.

*/

#include "utilities.h"
#include <fstream>
#include "iostream"

using namespace std;

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