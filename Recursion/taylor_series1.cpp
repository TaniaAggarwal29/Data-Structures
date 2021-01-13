/*
Taylor Series:
e^x = 1 + x/1 + (x^2)/2! + (x^3)/3! + (x^4)/4! + ....
*/

#include <iostream>
#include <cstdio>
using namespace std;

double e(int x, int n)
{
	static double f=1, p=1;
	double res = 0;
	if (n==0)
		return 1;
	res = e(x, n-1);
	f *= n;	//calculates factorial
	p *= x;	//calculates power
	return res + p/f;
}

//driver code
int main()
{
	int x, n;
	cout<<"Enter the values of x and n: ";
	cin>>x>>n;
	
	double ans = e(x, n);
	printf("e ^ %d = %lf", x, ans);
	return 0;
}
