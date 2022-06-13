#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs){
    unordered_map<vector<int>, vector<string>> m;
    for (string str: strs) {
        vector<int> freq(26, 0);
        for(char ch: str)
            freq[ch-'a']++;

        m[freq].push_back(str);
    }
    vector<vector<string>> ans;
    for(auto [key, val]: m){
        ans.push_back(val);
    }
    return ans;
}
int main() {
    vector<string> strs = {"abc", "bca", "dog", "god", "odg", "def"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(auto str_arr: ans){
        for(auto str: str_arr)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
