#include<bits/stdc++.h>
using namespace std;

/*
args:
    integer target : target sum 
    vector<integer> nums : array of numbers 

returns:
    minimum subarray length where elemets have sum >= target
*/

int minSubArrayLen(int target, vector<int>& nums){
    if(nums.size()<1){
        return 0;
    }
    int left = 0, right = 0, sum = 0, minLength = INT_MAX;
    while(right<nums.size()){
        sum += nums[right];
        while(sum>=target){
            minLength = min(minLength, right-left+1);
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return minLength == INT_MAX ? 0 : minLength;
}

int main(void){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 9;
    int result = minSubArrayLen(target, nums);
    cout << "Minimum subarray length: " << result << endl; // Output: 2
    return 0;
}