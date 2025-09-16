#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPerfectSquare(int x) {
    int r = sqrt(x);
    return r*r == x;
}

int countPerfectSquares(vector<int>& arr) {
    // count how many elements in arr are perfect squares
    int count = 0;
    for(int num : arr) {
        if(isPerfectSquare(num)) count++;
    }
    return count;
}
};

int main() {
    Solution sol;
    vector<int> arr = {4, 5, 6, 9, 10, 16, 20};
    cout << sol.countPerfectSquares(arr) << endl;
}
