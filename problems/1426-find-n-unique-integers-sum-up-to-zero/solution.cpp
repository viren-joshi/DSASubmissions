class Solution {
public:
    vector<int> sumZero(int n) {
        if(n == 1) return {0};
        vector<int> ans;
        for(int i = (-1) * n/2; i <= 0; i++) {
            if(i==0) {
                if(n%2==0) continue;
                ans.push_back(i);
                continue;
            }
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};
