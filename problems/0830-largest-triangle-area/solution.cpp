#include <cmath>
class Solution {
public:

    double calculateDistance(int x1, int y1, int x2, int y2) {
        return sqrt(pow((double)x1-x2, 2) + pow((double)y1-y2, 2));
    }

    double area(double s, double a, double b, double c) {
        return sqrt(s * (s-a) * (s - b) * (s - c));
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0.0;
        for(int i=0; i<points.size()-2; i++) {
            for(int j = i+1; j<points.size()-1; j++) {
                for(int k = j+1; k<points.size(); k++) {
                    double a = calculateDistance(points[i][0], points[i][1], points[j][0], points[j][1]);
                    double b = calculateDistance(points[i][0], points[i][1], points[k][0], points[k][1]);
                    double c = calculateDistance(points[j][0], points[j][1], points[k][0], points[k][1]);
                    double s = (a + b + c) / 2;
                    maxArea = max(maxArea, area(s, a, b ,c));
                }
            }
        }
        return maxArea;
    }
};
