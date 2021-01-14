/*
nCr can be calculated using PASCAL'S TRIANGLE:

					1						<-- 0C0
				1		1					<-- 1C0, 1C1
			1		2		1				<-- 2C0, 2C1, 2C2
		1		3		3		1			<-- 3C0, 3C1, 3C2, 3C3
	1		4		6		4		1		<-- 4C0, 4C1, 4C2, 4C3, 4C4
1		5		10		10		5		1	<-- 5C0, 5C1, 5C2, 5C3, 5C4, 5C5

*/

#include <iostream>
#include <cstdio>
using namespace std;

int C(int n, int r)
{
	if (r==0 || n==r)
		return 1;
	else
		return C(n-1, r-1) + C(n-1, r);
}

int main()
{
	int n, r;
	cout<<"Enter the value of n, r: ";
	cin>>n>>r;
	
	int ans = C(n, r);
	printf("%d C %d = %d", n, r, ans);
	return 0;
}
