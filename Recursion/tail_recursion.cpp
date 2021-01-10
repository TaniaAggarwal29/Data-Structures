#include <iostream>
#include <cstdio>
using namespace std;

/*
Tail recursion makes recursive call at the end.
All the other statements are executed before calling.
*/
void tail_recursion(int n)
{
	if (n>0)
	{
		printf("%d ", n);
		tail_recursion(n-1);
	}
}

//driver code
int main()
{
	tail_recursion(5);
	return 0;
}
