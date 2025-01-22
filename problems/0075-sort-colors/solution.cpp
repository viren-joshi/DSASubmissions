class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0, b=0,c=0;
        for(auto i: nums) {
            if(i==0) a++;
            else if (i==1) b++;
            else c++;
        }
        for(int i=0;i<a;i++) {
            nums[i] = 0;
        }
        for(int i=a; i<a+b; i++) {
            nums[i] = 1;
        }
        for(int i=a+b; i<nums.size(); i++) {
            nums[i] = 2;
        }
    }
};
