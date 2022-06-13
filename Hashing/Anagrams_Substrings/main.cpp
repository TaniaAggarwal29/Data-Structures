// For a given string, find how many substring-pairs are anagrams


#include <iostream>
#include <vector>
#include <map>
using namespace std;

void add_to_map(map<vector<int>, int> &m, string str){
    vector<int> freq(26, 0);
    for(auto ch: str){
        freq[ch-'a']++;
    }
    m[freq]++;
}

int countAnagrams(string &str){
    map<vector<int>, int> m;
    // 1. create substrings
    for (int i = 0; i < str.length(); ++i) {
        for (int len = 1; len <= str.length()-i; ++len) {
            // 2. create freq array
            // 3. store in map using array as key
            string s_str = str.substr(i, len);
            add_to_map(m, s_str);
        }
    }
    // 4. count anagrams
    int ans = 0;
    for(auto it = m.begin(); it != m.end(); ++it){
        int n = it->second;
        ans += (n * (n-1))/2;
    }
    return ans;
}

int main() {
    string str = "abba";
    cout << countAnagrams(str) << endl;
    return 0;
}
