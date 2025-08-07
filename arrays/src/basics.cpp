#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int search(vector<int> &arr, int size, int n)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == n)
        {
            return i; // Return the index of the found element
        }
    }
    return -1;
}

int insert(vector<int> &arr, int idx, int n)
{
    if (idx < 0 || idx > arr.size())
    {
        return -1; // Invalid index
    }
    arr.insert(arr.begin() + idx, n); // Insert element at the specified index
    return 0;                         // Return 0 on successful insertion
}

int deleteElement(vector<int> &arr, int n)
{
    auto it = find(arr.begin(), arr.end(), n);
    if (it != arr.end())
    {
        arr.erase(it); // Remove the element if found
        return 0;      // Return 0 on successful deletion
    }
    return -1; // Return -1 if the element was not found
}

int maxElement(vector<int> &arr)
{
    if (arr.empty())
    {
        return -1; // Return -1 if the array is empty
    }
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res = max(res, arr[i]); // Find the maximum element
    }
    return res;
}

int sorted(vector<int> &arr)
{
    for (int i = i; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return 0; // Return 0 if the array is not sorted
        }
    }
    return 1; // Return 1 if the array is sorted
}

int reverseArray(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
    return 0; // Return 0 on successful reversal
}

pair<int, int> minMaxArr(vector<int> &arr)
{
    if (arr.empty())
    {
        return {-1, -1};
    }
    int minval = arr[0];
    int maxval = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < minval)
        {
            minval = arr[i]; // Update minimum value
        }
        if (arr[i] > maxval)
        {
            maxval = arr[i]; // Update maximum value
        }
    }
    return {minval, maxval}; // Return a pair of minimum and maximum values
}

int sumElements(vector<int> &arr)
{
    if (arr.size() == 0 || arr.empty())
    {
        return 0; // Return 0 if the array is empty
    }
    if (arr.size() == 1)
    {
        return arr[0]; // Return the single element if the array has only one element
    }
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

int removeDuplicateElemets(vector<int> &arr)
{
    /*if(arr.empty()){
        return 0;
    }
    sort(arr.begin(), arr.end());

    auto iterator = unique(arr.begin(), arr.end());
    arr.erase(iterator, arr.end()); // Remove duplicates
    return arr.size(); // Return the new size of the array after removing duplicates
    */
    if (arr.empty())
    {
        return 0;
    }
    int res = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    arr.resize(res); // Resize the array to remove duplicates
    return res;      // Return the new size of the array after removing duplicates
}

int leftRotate(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return -1;
    }
    int first = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = first;
    return 0;
}

int leftRotateByK(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0 || k == 0)
    {
        return -1;
    }
    k = k % n; // handle cases where k > n
    if (k == 0)
    {
        return 0; // No rotation needed
    }
    vector<int> temp(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[(i + k) % n];
    }
    return 0; // Return 0 on successful rotation
}

int leader(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        return -1; // Return -1 if the array is empty
    }
    int curr_leader = arr[n - 1];
    cout << curr_leader << " "; // Print the last element as a leader
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > curr_leader)
        {
            curr_leader = arr[i];
            cout << curr_leader << " "; // Print the new leader
        }
    }
    cout << endl; // Print a new line after printing all leaders
    return 0;     // Return 0 on successful execution
}

int maxDiff(vector<int>&arr){
    int n = arr.size();
    if(n<2){
        return -1;
    }
    int max_diff = arr[1] - arr[0];
    int minElement = arr[0];
    for(int i = 1;i<n;i++){
        max_diff = max(max_diff, arr[i] - minElement);
        minElement = min(minElement, arr[i]);
    }
    return max_diff;
}

vector<int> productExceptSelf(const vector<int>& arr){
    int n = arr.size();
    if(n<2){
        return {};
    }
    vector<int> results(n,1);
    int leftProduct = 1;
    for(int i = 0;i<n;++i){
        results[i] *= leftProduct;
        leftProduct *= arr[i];
    }

    int rightProduct = 1;
    for(int j = n-1;j>=0;--j){
        results[j] *= rightProduct;
        rightProduct *= arr[j];
    }

    return results;
}

vector<int> countDistinctElements(const vector<int>& arr, int k){
    int n = arr.size();
    if(n<k || k<=0){
        return {};
    }
    unordered_map<int, int> freqMap;
    vector<int> results;

    for(int i = 0;i<k;i++){
        freqMap[arr[i]]++;
    }

    results.push_back(freqMap.size());

    for(int i = k;i<n-1;i++){
        freqMap[arr[i]]++;
        freqMap[arr[i-k]]--;
        if(freqMap[arr[i-k]] == 0){
            freqMap.erase(arr[i-k]);
        }
        results.push_back(freqMap.size());
    }
    return results;
}

/*
longestSubSegment : takes vector of integers arr and integer k as input.
It returns the length of longest sub-segment with at most k distinct elements.
*/

int longestSubSegment(const vector<int>&arr, int k){
    int n = arr.size();
    if(n==0 || k<=0){
        return 0; // Return 0 if the array is empty or k is non-positive    
    }
    unordered_map<int, int> freqMap;
    int left = 0, right = 0, maxLength = 0;
    while(right < n){
        freqMap[arr[right]]++;
        while(freqMap.size() > k){
            freqMap[arr[left]]--;
            if(freqMap[arr[left]] == 0){
                freqMap.erase(arr[left]);
            }
            left++;
        }
        maxLength = max(maxLength, right-left+1);
        right++;
    }
    return maxLength;
}

int main(void)
{
    // vector<int> arr = {1,2,3,5,5};
    // int n = 3;
    // int index = search(arr, arr.size(), n);
    // if (index != -1)
    // {
    //     cout << "Element found at index: " << index << endl;
    // }
    // else
    // {
    //     cout << "Element not found" << endl;
    // }
    // cout<<"current leader: "<<leader(arr)<<endl;
    // cout<<maxDiff(arr)<<endl;
    // vector<int> result = productExceptSelf(arr);
    // cout << "Product except self: ";

    // vector<int> result = countDistinctElements(arr, 3);

    // for (int val : result)
    // {
    //     cout << val << " ";
    // }
    // cout << endl;
    vector<int> arr = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};
    cout<<longestSubSegment(arr, 2)<<endl;
    // expected output: 3 3 3
    // return;
}