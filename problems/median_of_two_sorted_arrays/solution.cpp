class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ap1 = 0,ap2 = 0,count=0;
        vector<int> ans;
        while (ap1<nums1.size() && ap2<nums2.size()) {
            if(nums1[ap1] < nums2[ap2]){
                ans.push_back(nums1[ap1]);
                ap1++;
                count++;
            } else if (nums1[ap1] > nums2[ap2]) {
                ans.push_back(nums2[ap2]);
                ap2++;
                count++;
            } else {
                ans.push_back(nums1[ap1]);
                ap1++;
                ans.push_back(nums2[ap2]);
                ap2++;
                count+=2;
            }
        }
        while(ap1<nums1.size() && ap2>=nums2.size()) {
            ans.push_back(nums1[ap1]);
            ap1++;
            count++;
        }
        while(ap1>=nums1.size() && ap2<nums2.size()) {
            ans.push_back(nums2[ap2]);
            ap2++;
            count++;
        }
        if(count%2==0) {
            return ((ans[(count/2) - 1] + ans[count/2]) / 2.0);
        } else {
            return ans[count/2];
        }
    }
};