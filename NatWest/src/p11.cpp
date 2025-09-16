#include<bits/stdc++.h>
using namespace std;

class Solution{
    /**
    *@param n : number of nodes in graph
    *@param dependencies : list of dependencies where each dependency is represented as a pair (a, b) meaning a depends on b
    *@return : boolean value indicating if it's possible to start system without circular dependencies
    */
    public:
    bool canStartServices(int n, vector<pair<int, int>>& dependencies){
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(auto& dep : dependencies){
            graph[dep.second].push_back(dep.first);
            indegree[dep.first]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto& neighbor : graph[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }
        return count == n;
    }
};

int main(){
    int n = 4;
    vector<pair<int, int>> dependencies = {{1, 0}, {2, 1}, {3, 2}};
    Solution obj;
    cout<<obj.canStartServices(n, dependencies)<<endl;
    return 0;
}