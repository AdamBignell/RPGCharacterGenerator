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
	
	FILE* qf= fopen("questions.csv", "r");
	if (qf == NULL)
	{
		printf("DOESN'T EXIST :(\n");
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
				break;
			case(0):
				fclose(cf);
				return 0;
		}
		
	}
	
	
	return 0;
}
