#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> highFive(vector<vector<int>>& items){
            map<int, vector<int>> scores; // map to keep track of student scores
            for(auto& item:items){
                int studentId = item[0];
                int score = item[1];
                scores[studentId].push_back(score);
            }
            vector<vector<int>> result;
            for(auto& pair : scores){
                int studentId = pair.first;
                vector<int>& studentScores = pair.second;
                sort(studentScores.begin(), studentScores.end(), greater<int>());
                int sumTopFive = 0;
                for(int j = 0;j<5 && j<studentScores.size();j++){
                    sumTopFive += studentScores[j];
                }
                int average = sumTopFive / min(5, (int)studentScores.size());
                result.push_back({studentId, average});
            }
            return result;
        }
};

int main(void){
    Solution sol;
    vector<vector<int>> items = {{1,91},{1,92},{2,93},{2,97},{1,60},{2,77},{1,65},{1,87},{1,100},{2,100},{2,76}};
    vector<vector<int>> result = sol.highFive(items);
    for(auto& res:result){
        cout << res[0] << " " << res[1] << endl; // Output student ID and average score
    }
    return 0;
}