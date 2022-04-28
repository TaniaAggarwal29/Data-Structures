#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void nonRepeatingLetters(string input){
    queue<char> q;
    unordered_map<char, int> m;

    for(auto x: input){
        m[x]++;
        q.push(x);
        while(!q.empty() and m[q.front()]>1)
            q.pop();
        if(q.empty()) cout << "-1" << " ";
        else cout << q.front() << " ";
    }
}

int main() {
    string input = "aabccbcd";
    nonRepeatingLetters(input);
    return 0;
}
