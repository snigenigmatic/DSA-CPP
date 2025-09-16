#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string minSubstring(string s, string t) {
    // return the shortest substring of s that contains all characters of t
    unordered_map<char, int> tCount;
    for(char c : t) tCount[c]++;
    unordered_map<char, int> windowCount;
    int have = 0, need = tCount.size();
    int left = 0, right = 0;
    int minLen = INT_MAX, minStart = 0;
    while(right < s.size()){
        char c = s[right];
        windowCount[c]++;
        if(tCount.count(c) && windowCount[c] == tCount[c]) have++;
        while(have == need){
            if(right-left+1 < minLen){
                minLen = right-left+1;
                minStart = left;
            }
            windowCount[s[left]]--;
            if(tCount.count(s[left]) && windowCount[s[left]] < tCount[s[left]]) have--;
            left++;
        }
        right++;
    }
    if(minLen == INT_MAX) return "";
    return s.substr(minStart, minLen);
}
};

int main() {
    Solution sol;
    string s = "a";
    string t = "aa";
    cout << sol.minSubstring(s, t) << endl;
    return 0;
}
