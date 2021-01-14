#include <iostream>
#include <cstdio>
using namespace std;

void toh(int n, int A, int B, int C)
{
	if (n>0)
	{
		toh(n-1, A, C, B);
		printf("Move from Tower %d to Tower %d\n", A, C);
		toh(n-1, B, A, C);
	}
}

int main()
{
	int n;
	cout<<"Enter number of discs: ";
	cin>>n;
	toh(n, 1, 2, 3);
	return 0;
}
