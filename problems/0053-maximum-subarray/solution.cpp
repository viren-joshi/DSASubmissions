/* 
    Kadane's Algorithm
    https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d

*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMaxima = nums[0];
        int localMaxima = nums[0];

        for (int i = 1; i<nums.size(); i++) {
            localMaxima = max(nums[i], localMaxima + nums[i]);
            if(localMaxima > globalMaxima) {
                globalMaxima = localMaxima;
            }
        }
        return globalMaxima;
    }
};
