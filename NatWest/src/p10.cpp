#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    /**
    *@param requests : array of requests timestamps as seconds
    *@param windowSize : size of the time window in seconds
    *@return : maximum number of requests in any time window of size windowSize
    */
    int maxRequestsInWindow(vector<int>& requests, int windowSize){
        sort(requests.begin(), requests.end());
        int maxRequests = 0;
        int left = 0;
        for(int right = 0; right < requests.size(); right++){
            while(requests[right] - requests[left] > windowSize){
                left++;
            }
            maxRequests = max(maxRequests, right - left + 1);
        }
        return maxRequests;
    }
};

int main(){
    vector<int> requests = {1, 2, 3, 5, 8, 13, 21};
    int windowSize = 5;
    Solution obj;
    cout<<obj.maxRequestsInWindow(requests, windowSize)<<endl;
    return 0;
}