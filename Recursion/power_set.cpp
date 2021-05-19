/*
Given a string, print all the subsets of it (in any order)
*/

#include <iostream>
using namespace std;

void power_set(string str, int index=0, string curr="") {
	if (index == str.length()){
		cout<<curr<<" ";
		return;
	}
	power_set(str, index+1, curr);
	power_set(str, index+1, curr+str[index]);
}

int main() {
	
	power_set("abc");
	
	return 0;
}
