/* utilities.cpp

All of these functions are subtle utilities that will ease writing.

*/

#include "utilities.h"
#include <fstream>

bool CSVtoQuestions(question* questions){
	string line;
	ifstream csv("questions.csv");
	int flag = 0;
	int qNum = 0;
	if (csv){
		while(getline( csv, line, ',' )){
			if (flag = 0){
				questions[qNum].question = line;
			}
			if (flag = 1){
				questions[qNum].optionA = line;
			}
			if (flag = 2){
				questions[qNum].aConseq = line;
			}
			if (flag = 3){
				questions[qNum].optionB = line;
			}
			if (flag = 4){
				questions[qNum].bConseq = line;
			}
			if (flag = 5){
				questions[qNum].optionC = line;
			}
			if (flag = 6){
				questions[qNum].cConseq = line;
				qNum++;
			}
			flag = (flag + 1) % 7;

		}
	return true;
	}
	return false;
}

int main(){
	return 0;
}