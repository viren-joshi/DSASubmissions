class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        deque<int> d;

        for(int i = temperatures.size() - 1; i >= 0; i--) {
            if(d.empty()) {
                d.push_front(i);
                ans[i] = 0;
            } else {
                while(!d.empty() && temperatures[i] >= temperatures[d.front()]) {
                    d.pop_front();
                }
                if(d.empty()) {
                    ans[i] = 0;
                } else {
                    ans[i] = d.front() - i;
                }
                d.push_front(i);
            }
        }
        return ans;
    }
};