class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> dp(arr.size()), ans;
        dp[0] = arr[0];
        for(int i=1;i<arr.size();i++) 
            dp[i] = dp[i-1] ^ arr[i];
        for(auto query: queries) {
            if(query[0] == 0) {
                ans.push_back(dp[query[1]]);
            } else {
                ans.push_back(( dp[query[1]] ^ dp[query[0] - 1] ));
            }
        }
        return ans;
    }
};