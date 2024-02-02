class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> d;

        for(int i = temperatures.size() - 1; i >= 0; i--) {
            if(d.empty()) {
                d.push(i);
                ans[i] = 0;
            } else {
                while(!d.empty() && temperatures[i] >= temperatures[d.top()]) {
                    d.pop();
                }
                if(d.empty()) {
                    ans[i] = 0;
                } else {
                    ans[i] = d.top() - i;
                }
                d.push(i);
            }
        }
        return ans;
    }
};