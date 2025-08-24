/*
!Check Notes!

As per the hint, we need to maintain a sliding window with atleast one 0 in it.

We do that having two pointers (left and right). 
right is the same variable we iterate the array with, so we increase the size of the window 
every iteration

After increasing the window, we see check for a new zero, if found,
we remove the older one by decreasing the window size (increment left)

Hence, for every iteration, 
the ans, the maximum no. of ones after deleting one element is (size of window - no. of zeroes)

There is one edge case, that if the array contains all 1s, 
then the ans is len(arr) - 1 as one element should always be deleted.

*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int zero = 0;
        int ans = 0;
        for(int right = 0; right < len; right++){
            if(nums[right] == 0) zero++;
            while(zero > 1) {
                if(nums[left] == 0) zero--;
                left++;
            }
            ans = max(ans, right - left + 1 - zero);
        }

        if(ans == len)
            return ans - 1;
            return ans;

    }
};
