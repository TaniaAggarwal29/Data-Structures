/*
Taylor Series using Horner's Rule:
e^x 
= 1 + x/1 + (x^2)/2! + (x^3)/3! + (x^4)/4! + ....
= 1 + x/1 [ 1 + x/2 + x^2/(3*2) + x^3/(4*3*2) ]
= 1 + x/1 [ 1 + x/2 [ 1 + x/3 + x^2/(4*3) ] ]
= 1 + x/1 [ 1 + x/2 [ 1 + x/3 [ 1 + x/4 ] ] ]
*/

#include <iostream>
#include <cstdio>
using namespace std;

double e(int x, int n)
{
	static double ans = 1;
	if (n==0)
		return ans;
	ans = ((double)x/n)*ans + 1;
	return e(x, n-1);
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
