#include <iostream>
#include <cstdio>
using namespace std;

//to return nth term of fibonacci series
/*
This function makes call for same value of n, which is called: EXCESSIVE RECURSION.
*/
int fib1(int n)
{
	if (n<=1)
		return n;
	return fib1(n-2)+fib1(n-1);
}


int F[20];
//using MEMOIZATION
/*
Before makeing a function call for some value of n,
check if that call has already been made and we have the value or not.
For this, maintain a global array of values returned by function call for n.

If F[n] == -1, that means function call isn't made yet. Call the function and store the result.
Else, we have the value from previous call. Use it!

This removes Excessive Recursion.
*/
int fib2(int n)
{
	if (n<=1)
	{
		F[n] = n;
		return n;
	}
	else
	{
		if (F[n-2] == -1)
			F[n-2] = fib2(n-2);
		if (F[n-1] == -1)
			F[n-1] = fib2(n-1);
		return F[n-2]+F[n-1];
	}
}

//driver code
int main()
{
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	for (int i=0; i<=n; i++)
		F[i] = -1;
	int term = fib2(n);
	cout<<n<<"th fibonacci term : "<<term;
	return 0;
}
