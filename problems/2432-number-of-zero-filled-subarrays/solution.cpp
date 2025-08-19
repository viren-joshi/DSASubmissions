/*

    I observed this pattern for the number of sub-arrays for the no of consecutive 0s.
        1 -> 1
        2 -> 3
        3 -> 6
        4 -> 10
        5 -> 15

    This means that the current count (streak, or no. of consecutive 0s) needs to be added to the
    total sub-array count to consider all the possible sub-arrays.

    For one 0, we have 1 sub-array.
    For two 0s, we have 3 sub-arrays i.e. 2 more than the previous. (streak = 2 hence we add 2)
    For three 0s, we have 6 sub-arrys i.e. 3 mroe than the preivous. (streak = 3 hence we add 3)
    and so on.

    (Improved on second submission by directly using globalCount and removed tempCount)

*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long globalCount = 0;
        int count = 0;
        for (int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                count++;
                globalCount+=count;
            } else {
                    count = 0;
            }
        }
        return globalCount;
    }
};
