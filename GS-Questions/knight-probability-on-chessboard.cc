#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n,0));

        dp[row][column]=1.0;

        vector<vector<int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

        for(int move = 1;move<=k;move++){
            vector<vector<double>> newDp(n,vector<double>(n,0));
            for(int r = 0;r<n;r++){
                for(int c = 0;c<n;c++){
                    for(const auto& m : moves){
                        int newR = r+m[0];
                        int newC = c+m[1];
                        if(isValid(newR, newC, n)){
                            newDp[newR][newC] += dp[r][c]/8.0;
                        }
                    }
                }
            }
            dp=newDp;
        }
        double probability = 0;
        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                probability+=dp[r][c];
            }
        }
        return probability;
    }

    bool isValid(int r, int c, int n){
        return r>=0 && r<n && c>=0 && c<n;
    }
};

int main() {
    Solution sol;

    // Test case 1
    cout << "Test 1 - Probability: " << sol.knightProbability(3, 2, 0, 0) << endl; // Expected: 0.0625

    // Test case 2
    cout << "Test 2 - Probability: " << sol.knightProbability(1, 0, 0, 0) << endl; // Expected: 1.0

    // Test case 3
    cout << "Test 3 - Probability: " << sol.knightProbability(8, 30, 6, 4) << endl; // Expected: Close to a value based on the knight's movement

    return 0;
}