// Intuition

// Sliding Window

// Sort the array so that we can see the best possible values. 
// Iterate over the array (using index variable [right]) and check the maximum possible frequency. 
// We have an increasing sliding window. That does not decrease, once increased.
// 
// We can get the frequency of the [target] element = right - left + 1 
//  (right is inclusive of the target).

// We can store the sum of the window [curr] as we slide it.
// We can calculate the no. of operations required to convert all number in the window into [target]
//  by calculating ((size of window) * target - curr). 
// If that value is <= k then, means that size is the biggest we've seen so far
// If that value is > k then, the operations are more than the allowed ones,
//  so we slide the window forward by incrementing left (right gets incremented in the outer loop everytime)
// 
// Since the size is the same as the largest window we've gotten so far.
// so as answer we return
//  arr.size() - left



class Solution {
public:

    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int left = 0;
        long curr = 0;

        for (int right = 0; right < nums.size(); right++) {
            long target = nums[right];
            curr += target;

            if ((right-left+1) * target - curr > k) {
                curr -= nums[left];
                left++;
            }
        }
        return nums.size() - left;

    }
};
