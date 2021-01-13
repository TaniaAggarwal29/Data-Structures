#include <iostream>
#include <cstdio>
using namespace std;

int factorial(int n)
{
	if (n==0)
		return 1;
	return n*factorial(n-1);
}

//driver code
int main()
{
	int n;
	cout<<"Enter the value of n : ";
	cin>>n;
	
	if (n<0)
		cout<<"invalid input.";
	else
	{
		int fact = factorial(n);
		printf("Factorial of %d = %d", n, fact);
	}
	return 0;
}
