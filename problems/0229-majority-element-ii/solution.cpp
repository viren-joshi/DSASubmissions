class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2=0, element1 = INT_MIN, element2 = INT_MIN;
        int limit = nums.size() / 3;
        for(auto i: nums) {
            if(count1 == 0 && element2 != i) {
                element1 = i;
                count1++;
            } 
            else if (count2 == 0 && element1 != i) {
                element2 = i;
                count2++;
            } 
            else if (i==element1) count1++;
            else if (i==element2) count2++; 
            else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        int c1 = 0, c2 = 0;
        for(auto i: nums) {
            if(i==element1) c1++;
            if(i==element2) c2++;
        }
        if(c1 > limit) ans.push_back(element1);
        if(c2 > limit) ans.push_back(element2);
        return ans;
    }
};
