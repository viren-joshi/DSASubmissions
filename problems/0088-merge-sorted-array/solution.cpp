class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = n-1;
        int rep = m+n-1;
        while(right >= 0) {
            if(left>=0 && nums2[right] < nums1[left]) {
                nums1[rep] = nums1[left];
                left--;
            } else {
                nums1[rep] = nums2[right];
                right--;
            }
            rep--;
        }
    }
};
