#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    double circleIntersectionArea(double x1, double y1, double r1,
                              double x2, double y2, double r2) {
    // compute overlap area between two circles
    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    if (d >= r1 + r2) return 0.0; // no
    if (d <= abs(r1 - r2)) {
        double r = min(r1, r2);
        return M_PI * r * r; // one circle is inside the other
    }
    double r1sqr = r1 * r1;
    double r2sqr = r2 * r2;
    double alpha = acos((r1sqr + (d * d) - r2sqr) / (2 * r1 * d)) * 2;
    double beta = acos((r2sqr + (d * d) - r1sqr) / (2 * r2 * d)) * 2;
    double area1 = 0.5 * r1sqr * (alpha - sin(alpha));
    double area2 = 0.5 * r2sqr * (beta - sin(beta));
    return area1 + area2;
}
};

int main(void) {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    Solution sol;
    cout << sol.circleIntersectionArea(x1, y1, r1, x2, y2, r2) << endl;
}
