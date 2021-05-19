#include <iostream>
#include <cstdio>
using namespace std;

/*
Strings --> Array of characters

Declaring strings:
char name[] = {'T', 'A', 'N', 'I', 'A', '\0'};
char name[] = "TANIA";
char *n = "TANIA";
*/

int length(char *n)
{
	int i;
	for(i=0; n[i] != '\0'; i++) {	}
	
	return i;
}

void uppercase_to_lowercase(char *n)
{
	for (int i=0; n[i] != '\0'; i++)
	{
		printf("%c", n[i]);
		n[i] = n[i] + 32;
	}
}

int main()
{
	char *name = (char *)"Tania";
	printf("length of string \"%s\" = %d", name, length(name));
	
	char *s1 = (char *)"WELCOME";
	uppercase_to_lowercase(s1);
	printf("%s", s1);
	
	
	return 0;
}
