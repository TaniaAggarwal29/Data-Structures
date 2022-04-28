#include <iostream>
#include <stack>
using namespace std;

bool has_redundant(string input){
    stack<char> s;

    for (auto x: input){
        if(x != ')')
            s.push(x);
        else {
            bool operand_found = false;
            while(!s.empty() and s.top() != '('){
                char top = s.top();
                if(top=='+' or top=='-' or top=='*' or top=='/')
                    operand_found = true;
                s.pop();
            }
            s.pop();
            if(!operand_found) return true;
        }
    }
    return false;
}

int main() {
    string input = "((a+b))";
    bool ans = has_redundant(input);
    if(ans) cout << "Input has Redundant Parenthesis!" << endl;
    else cout << "No Redundant Parenthesis" << endl;
    return 0;
}
