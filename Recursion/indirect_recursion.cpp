#include <iostream>
#include <cstdio>
using namespace std;

/*
In Indirect recursion, function does't directly calls itself, but calls another function 
which calls this function again forming a cycle.

For eg., say funA -> funB -> funC -> funA
*/

void funcB(int n);

void funcA(int n)
{
	if (n>0)
	{
		printf("%d ", n);
		funcB(n-1);
	}
}

void funcB(int n)
{
	if (n>0)
	{
		printf("%d ", n);
		funcA(n/2);
	}
}

//driver code
int main()
{
	funcA(21);	//prints : 21 20 10 9 4 3 1
	return 0;
}
