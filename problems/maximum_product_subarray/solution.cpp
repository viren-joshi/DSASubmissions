class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product=nums[0];
        int productmax=product;
        int productmin=product;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
                swap(productmax,productmin);
            productmax=max(nums[i],nums[i]*productmax);
            productmin=min(nums[i],nums[i]*productmin);
            product=max(product,productmax);
        }
        return product;
    }
};