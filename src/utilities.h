/* utilities.h

All of these functions are subtle utilities that will ease writing.

*/

#include <string>
using namespace std;
#include "questions.h"
#include "character.h"

bool CSVtoQuestions(question* questions);

bool writeCharacterCSV(character* character);

bool askQuestions(question* questions, character* newChar);