/*
    Intuition:
    Split the input array into +ve and -ve arrays by iterating through it.
    This also preserves the order in which the values appeared for each signed number.

    Then combine the two arrays starting with the +ve array.

    We can do the problem in O(1) space via a two-pointer approach, 
    but then the time complexity could be ~ O(n^2),
    as we would have to shift elements to preserve 
    the order of values and have the -ve +ve sequence
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg, ans;
        for (int i: nums) {
            if(i>0) pos.emplace_back(i);
            else neg.emplace_back(i);
        }
        for(int i = 0; i < nums.size()/2; i++){
            ans.emplace_back(pos[i]);
            ans.emplace_back(neg[i]);
        }
        return ans;
    }
};
