#include <iostream>
#include <stack>
using namespace std;

bool is_balanced(string input){
    stack<char> s;

    for(auto x: input){
        switch(x){
            case '(':
            case '[':
            case '{':
                s.push(x);
                break;

            case ')':
                if(!s.empty() and s.top()=='(')
                    s.pop();
                else return false;
                break;

            case ']':
                if(!s.empty() and s.top()=='[')
                    s.pop();
                else return false;
                break;

            case '}':
                if(!s.empty() and s.top()=='{')
                    s.pop();
                else return false;
                break;

            default: continue;
        }
    }
    if(s.empty()) return true;
    return false;
}

int main() {
    string input = "(a+(b+c)+[c*{a+b])";
    bool ans = is_balanced(input);
    if(ans)
        cout << "Balanced!" << endl;
    else
        cout << "Not Balanced!" << endl;
    return 0;
}
