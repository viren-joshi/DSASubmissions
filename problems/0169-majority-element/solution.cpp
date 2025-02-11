class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Using moores voting algorithm.
        int count = 0, element = nums[0];
        for(auto i: nums) {
            if(i==element) {
                count++;
            } else {
                if(count == 0) {
                    element = i;
                    count++;
                } else {
                    count--;
                }
            }
        }
        return element;
    }
};
