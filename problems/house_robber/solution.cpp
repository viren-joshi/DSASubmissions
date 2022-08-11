class Solution {
public:
    int rob(vector<int>& nums) {
        
        int l = nums.size();
        if(l==0) return 0;
        int p = nums[0], p2 = 0,pick,npick,current;
        for(int i=1;i<l;i++){
            pick = nums[i] + p2;
            npick = 0 + p;
            current = max(pick,npick);
            p2 = p;
            p = current;
        }
        return p;
        
    }
};