#include <iostream>
#include <cstdio>
using namespace std;

/*
This is a practice problem for recursion.
Else, direct formula n*(n+1)/2 can be used for sum of n natural numbers.

This can also be done using loop and looping will take lesser space than recursion.
though, time complexity would remain same.
*/
int sum(int n)
{
	if (n<=0)
		return 0;
	return n+sum(n-1);
}

//driver code
int main()
{
	int n;
	cout<<"Enter the value of n : ";
	cin>>n;
	
	int ans = sum(n);
	printf("Sum of natural numbers upto %d is %d", n, ans);
	return 0;
}
