/* 

Two Approaches are possible.

1. Count and Put
    We iterate through the entire array and count the number of 0s, 1s and 2s.
    Then we just repalce the array with the values in the correct order.

2. Low - Mid - High Approach
    Set low, mid = 0 and high = size - 1
    (
        Assume that everthing on the 
            left of low is 0 
            left of mid is 1
            right of high is 2
    )
    We use mid as the iterator, hence mid <= high.

    For every value of mid:
        if  arr[mid] is 0:
            swap arr[mid] and arr[low] (Now, low -> 0 and mid -> 1, so)
            mid++
            low++
        
        if arr[mid] is 1:
            (mid aleary points to 1, no change just increment)
            mid++
        
        if arr[mid] is 2:
            swap arr[mid] and arr[high] (Now mid -> 0/1 and high -> 2, so)
            high --
            (We do not increment mid, as after swapping it could be a 0 or 1, 
            we check its value in the next iteration)


*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high;
        high = nums.size() - 1;
        while(mid <= high) {
            switch(nums[mid]) {
                case 0:
                    swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high]);
                    high--;
            }
        }
    }
};
