/* rpg.cpp
 *
 *
 */
 
#include <cstdio>
#include "iostream"
#include <cstring>

using namespace std;
 
int main (int argc, char* argv[])
{
	// Check for characters.csv file, create one if it doesn't exist
	FILE* cf = fopen("characters.csv", "w+");
	if (cf == NULL)
	{
		printf("DOESN'T EXIST :(\n");
	}
	
	FILE* qf= fopen("questions.csv", "r")
	if (qf == NULL)
	{
		printf("DOESN'T EXIST :(\n");
	}
	
	int sel;
	
	while(1)
	{
		printf("Select an option:\n");
		printf("1	-	Generate Character");
		printf("0	-	Exit");
		printf("\n\nSelect: ");
		
	}
	
	fclose(f);
	return 0;
}
