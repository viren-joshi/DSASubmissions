#include <vector>
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = -1, temp = -1, maxArea = 0;

        for(int i = 0; i<dimensions.size(); i++) {
            temp = (double) (dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1]);
            if(temp > maxDiagonal) {
                maxDiagonal = temp;
                maxArea = (double) (dimensions[i][0] * dimensions[i][1]);
            } else if (temp == maxDiagonal) {
                maxArea = max(maxArea, (double) (dimensions[i][0] * dimensions[i][1]));
            }
        }

        return maxArea;

    }
};
