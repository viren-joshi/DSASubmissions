class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        int i=1,j=l-2;
        int startProd=nums[0],endProd=nums[l-1];
        vector<int> ans(l,31);
        ans[0] = 1;
        ans[l-1] = 1;
        for(; i<l-1; i++,j--) {
            if(i<j) {
                ans[i] = startProd;
                ans[j] = endProd;
                
            } else if (i>j) {
                ans[i]*=startProd;
                ans[j]*=endProd;
            } else {
                ans[i] = startProd * endProd;
            }
            startProd*=nums[i];
            endProd*=nums[j];
        }
        ans[0] = endProd;
        ans[l-1] = startProd;
        return ans;
    }
};