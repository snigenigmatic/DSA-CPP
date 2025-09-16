#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minMeetingRooms(vector<pair<int, int>>& intervals){
        vector<int> start, end;
        for(auto& periods : intervals){
            start.push_back(periods.first);
            end.push_back(periods.second);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int rooms = 0, res = 0, i=0, j=0;
        while(i<start.size()){
            if(start[i]<end[j]){
                rooms++;
                res = max(res, rooms);
                i++;
            } else {
                rooms--;
                j++;
            }
        }
        return res;
    }
};

int main(){
    int n = 3;
    vector<pair<int, int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    Solution obj;
    cout<<obj.minMeetingRooms(intervals)<<endl;
    return 0;
}