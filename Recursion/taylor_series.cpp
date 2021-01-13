/*
Taylor Series:
e^x = 1 + x/1 + (x^2)/2! + (x^3)/3! + (x^4)/4! + ....
*/

#include <iostream>
#include <cstdio>
using namespace std;

int factorial(int n)
{
	if (n==0)
		return 1;
	return n*factorial(n-1);
}

int power(int m, int n)
{
	if (n==0)
		return 1;
	if (n%2==0)
		return power(m*m, n/2);
	else
		return m*power(m*m, (n-1)/2);
}

double taylor_series(int x, int n)
{
	if (n==0)
		return 1;
	else
		return taylor_series(x, n-1) + (double)(power(x, n))/factorial(n);
}

//driver code
int main()
{
	int x, n;
	cout<<"Enter the values of x and n: ";
	cin>>x>>n;
	
	double ans = taylor_series(x, n);
	printf("e ^ %d = %lf", x, ans);
	return 0;
}
