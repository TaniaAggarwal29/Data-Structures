#include <iostream>
#include <cstdio>
using namespace std;

/*
function call uses function call as a parameter. Like:
function(function(n-1))
*/

int nested_recursion(int n)
{
	if (n>100)
		return n-10;
	else
		return nested_recursion(nested_recursion(n+11));
}

//driver code
int main()
{
	int result = nested_recursion(95);
	printf("%d", result);
	return 0;
}
