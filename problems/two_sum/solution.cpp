class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans = {0,1};
        int temp,l=nums.size();
        map<int,int> map;
        for(int i=0;i<l; i++) {
            map[nums[i]] = i;
        }
        for (int i=0; i<l; i++) {
            temp = target-nums[i];
            cout<<"H"<<map.count(temp);
            if(map.count(temp) && map[temp] != i) {
                ans[0] = i;
                ans[1] = map[temp];
            }
        }
        return ans;
    }
};