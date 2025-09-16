#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string maxNumberWithSwaps(string s, int k) {
    // s is string of digits
    // perform at most k adjacent swaps to maximize the number
    int n = s.size();
    for(int i = 0;i<n && k > 0;i++){
        // find the maximum digit in the next k positions
        int pos = i;
        for(int j = i+1;j<n && j <= i + k;j++){
            if(s[j] > s[pos]){
                pos = j;
            }
        }
        // If a larger digit is found, swap it to the current position
        if(pos != i){
            std::swap(s[i], s[pos]);
            k -= (pos - i);  // Reduce k by the number of swaps made
        }
    }
    return s;
}

    // No need for a custom swap function; use std::swap instead
};

int main() {
    Solution sol;
    string s = "2736";
    int k = 1;
    cout << "Maximized Number: " << sol.maxNumberWithSwaps(s, k) << endl;
    return 0;
}
