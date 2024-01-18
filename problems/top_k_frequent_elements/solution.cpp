class Solution {
    static bool compare(pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<pair<int,int>> p;
        vector<int> ans;
        for(auto i : nums) {
            m[i]++;
        }
        
        for(auto i: m) {
            p.push_back(pair{i.first,i.second});
        }

        sort(p.begin(), p.end(), compare);

        for(int i=0;i<k;i++) {
            ans.push_back(p[i].first);
        }

        return ans;
    }
};