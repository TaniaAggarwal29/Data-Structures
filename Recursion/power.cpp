#include <iostream>
#include <cstdio>
using namespace std;

//This function returns m raised to power n, irrespective of time complexity
int power(int m, int n)
{
	if (n==0)
		return 1;
	return m*power(m, n-1);
}


//More effective algorithm - with reduced number of operations
int power1(int m, int n)
{
	if (n==0)
		return 1;
	if (n%2==0)
		return power1(m*m, n/2);
	else
		return m*power1(m*m, (n-1)/2);
}

//driver code
int main()
{
	int m, n;
	cout<<"Enter the value of m, n : ";
	cin>>m>>n;
	
	int ans = power(m, n);
	printf("%d ^ %d = %d\n", m, n, ans);
	
	int ans1 = power1(m, n);
	printf("%d ^ %d = %d\n", m, n, ans1);
	return 0;
}
