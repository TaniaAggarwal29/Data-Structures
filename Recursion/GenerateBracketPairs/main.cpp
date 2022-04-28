// Given n, generate all n pairs of balanced parentheses

#include <iostream>
#include <vector>
using namespace std;

vector<string> generateParentheses(int n, int open = 0, int close = 0, int count = 0, string ans=""){
    static vector<string> result;
    if(count == 2*n){
        result.push_back(ans);
        return result;
    }
    if(open < n){
        result = generateParentheses(n, open+1, close, count+1, ans + "(");
    }
    if(close<open){
        result = generateParentheses(n, open, close+1, count+1, ans + ")");
    }
    return result;
}

int main() {
    vector<string> ans = generateParentheses(4);
    for(auto x: ans)
        cout << x << endl;
    return 0;
}
