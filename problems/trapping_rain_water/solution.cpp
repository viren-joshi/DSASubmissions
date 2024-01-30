class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, sum = 0;
        int leftMax = height[l], rightMax = height[r];
        while(l < r) {
            if(leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                sum += (leftMax - height[l]);

            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                sum += (rightMax - height[r]);
            }
        }
        return sum;
    }
};