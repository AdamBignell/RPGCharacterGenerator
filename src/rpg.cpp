/* rpg.cpp
 *
 *
 */
 
#include <cstdio>
#include <cstring>
 
int main (int argc, char* argv[])
{
	// Check for characters.csv file, create one if it doesn't exist
	FILE* f = fopen("characters.csv", "w+");
	if (f == NULL)
	{
		printf("DOESN'T EXIST :(\n");
	}
	
	fclose(f);
	return 0;
}
