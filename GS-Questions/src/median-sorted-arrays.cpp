#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged;

        // Merge the two sorted arrays
        merged.reserve(n + m); // Reserve space for efficiency
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());

        // Sort the merged array
        sort(merged.begin(), merged.end());

        int length = merged.size();
        if (length % 2 == 0)
        {
            // For even length, return average of two middle elements
            return (merged[length / 2 - 1] + merged[length / 2]) / 2.0;
        }
        else
        {
            // For odd length, return middle element
            return merged[length / 2];
        }
    }
};

int main()
{
    Solution sol;

    // Test case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Test 1 - Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl; // Expected: 2.0

    // Test case 2
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Test 2 - Median: " << sol.findMedianSortedArrays(nums3, nums4) << endl; // Expected: 2.5

    // Test case 3
    vector<int> nums5 = {0, 0};
    vector<int> nums6 = {0, 0};
    cout << "Test 3 - Median: " << sol.findMedianSortedArrays(nums5, nums6) << endl; // Expected: 0.0

    return 0;
}
