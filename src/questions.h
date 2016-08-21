/* questions.h

These are objects which represent that questionnaire questions and their modifers

Author: Alister Pineda & Adam Bignell

*/

#include "string"
using namespace std;

class question {

// Note that this class is deliberately public
// so that we can directly access the questions in rpg.cpp
public:
	string question;

	string optionA;
	string aConseq;

	string optionB;
	string bConseq;

	string optionC;
	string cConseq;
}