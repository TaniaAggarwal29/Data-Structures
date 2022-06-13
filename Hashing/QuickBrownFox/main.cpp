#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int min_bars(string str, unordered_set<string> &s, int idx){
    if(str[idx] == '\0')
        return 0;

    string curr_str = "";
    int ans = INT_MAX;
    for(int i=idx; str[i] != '\0'; i++){
        curr_str += str[i];
        if(s.find(curr_str) != s.end()){
            int rem_ans = min_bars(str, s, i+1);
            if(rem_ans != -1){
                ans = min(ans, 1+rem_ans);
            }
        }
    }
    if(ans==INT_MAX) return -1;
    return ans;
}

int main() {
    string str = "thequickbrownfoxjumpsoverthehighbridge";
    vector<string> words = {"the", "fox", "jumps", "lazy", "lazyfox", "highbridge", "the",
                            "over", "bridge", "high", "tall", "quick", "brown"};
    unordered_set<string> s;
    for(auto word: words){
        s.insert(word);
    }
    cout << min_bars(str, s, 0)-1 << endl;
    return 0;
}
