#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    /**
     * @param times: a 2D array where times[i] = (u, v, w) means there is a directed edge from u to v with weight w
     * @param n: the number of nodes
     * @param k: the starting node
     * @return: the time it takes for all nodes to receive the signal, or -1 if not all can receive
     */
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto& edge : times){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();
            if(dist > distance[node]) continue;
            for(auto& [neighbor, weight] : graph[node]){
                if(dist + weight < distance[neighbor]){
                    distance[neighbor] = dist + weight;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }
        int ans = *max_element(distance.begin()+1, distance.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
    int n = 4, k = 2;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    Solution obj;
    cout<<obj.networkDelayTime(times, n, k)<<endl;
    return 0;
}