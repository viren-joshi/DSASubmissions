class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = 0, maxLength = 0, length = 0;
        for(int num:nums) {
            if(num > maxElement) {
                maxElement = num;
                maxLength = 0;
                length = 0;
            }
            if(maxElement == num) {
                length++;
            } else {
                length = 0;
            }

            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};