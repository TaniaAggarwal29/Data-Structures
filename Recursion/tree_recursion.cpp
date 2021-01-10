#include <iostream>
#include <cstdio>
using namespace std;

/*
tree recursion, unlike linear recursion, makes more than one recursive calls
*/
void tree_recursion(int n)
{
	if (n>0)
	{
		tree_recursion(n-1);
		printf("%d ", n);
		tree_recursion(n-1);
	}
}

//driver code
int main()
{
	tree_recursion(3);	//prints : 1 2 1 3 1 2 1
	return 0;
}
