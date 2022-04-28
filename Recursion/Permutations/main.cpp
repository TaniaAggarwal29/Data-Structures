// Generate all permutations of a given string

#include <iostream>
using namespace std;

void permutations(string s, int start=0, string ans=""){
    if(ans.length() == s.length()){
        cout << ans << endl;
        return;
    }
    for(int i=start; i<s.length(); i++){
        swap(s[start], s[i]);
        permutations(s, start+1, ans+s[start]);
//        swap(s[start], s[i]);
    }
}

int main() {
    permutations("abcdef");
    return 0;
}
