/* rpg.cpp
 *
 *
 */
 
#include <cstdio>
#include "iostream"
#include <cstring>

using namespace std;

#define NUM_Q 50

// prototypes
void generate_character(void);
 
int main (int argc, char* argv[])
{
	// Check for characters.csv file, create one if it doesn't exist
	FILE* cf = fopen("characters.csv", "w+");
	if (cf == NULL)
	{
		printf("CRITICAL: unable to access characters.csv\n");
		return 1;
	}
	
	// Check for characters.csv file, 
	FILE* qf= fopen("questions.csv", "r");
	if (qf == NULL)
	{
		printf("CRITICAL: \"questions.csv\" missing\n");
		//fclose(cf);
		//return 1;
	}
	
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
				generate_character();
				break;
			case(0):
				fclose(cf);
				return 0;
		}
		
	}
	
	
	return 0;
}

void generate_character(void)
{
	for (int i = 0; i < NUM_Q; i++)
		printf("QUESTION %i\n", i);
	return;
}
