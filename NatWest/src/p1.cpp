/*
Given multiple points, calculate the euclidian distance between pairs nd find which delivery path (or specific pair)
has maximum travel time
*/

#include <bits/stdc++.h>
using namespace std;

/**
* @class Solution
* @brief A class to encapsulate the solution for calculating maximum travel time between points.
*/

class Solution{
    public:
    /**
    * @brief Calculate the Euclidean distance between two points.
    * @param p1 The first point.
    * @param p2 The second point.
    * @return The Euclidean distance between the two points.
    */
    double euclidianDistance(pair<int, int> p1, pair<int, int>p2){
        return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
    }

    /**
    * @brief Calculate the maximum travel time between all pairs of points.
    * @param points A vector of points represented as pairs of integers.
    * @return The maximum travel time between any two points.
    */
    double maxTravelTime(vector<pair<int, int>> points){
        double maxDist = 0.0;
        for(int i = 0;i<points.size();i++){
            for(int j = i+1;j<points.size();j++){
                double dist = euclidianDistance(points[i], points[j]);
                maxDist = max(maxDist, dist);
            }
        }
        return maxDist;
    }
};

int main(void){
    Solution Sol;
    vector<pair<int, int>> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    cout << "Maximum Travel Time: " << Sol.maxTravelTime(points) << endl;
}