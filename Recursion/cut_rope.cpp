/*
Given a rope of length n, 
find the maximum number of pieces you can make such that the length of every piece is in set {a, b, c}
for given three values a, b, c.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int cut_rope(int n, int a, int b, int c) {
	if (n==0) return 0;
	if (n<0) return -1;
	int temp = max(cut_rope(n-a, a, b, c), max(cut_rope(n-b, a, b, c), cut_rope(n-c, a, b, c)));
	
	if (temp==-1) return -1;
	return temp + 1;
}

int main() {
	cout<<cut_rope(5, 2, 5, 1); 
	return 0;
}
