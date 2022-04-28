// Given a number N and a phone keypad, find out all possible strings generated from that number combination

#include <iostream>
#include <vector>
using namespace std;

vector<string> keypad = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generateKeypadStrings(string input, string ans="", int index=0){
    if(index == input.length()){
        cout << ans << endl;
        return;
    }
    int n = input[index] - '0';

    if(n==0 or n==1)
        generateKeypadStrings(input, ans, index+1);

    for(char i : keypad[n]){
        generateKeypadStrings(input, ans+i, index+1);
    }
}


int main() {
    generateKeypadStrings("012");
    return 0;
}
