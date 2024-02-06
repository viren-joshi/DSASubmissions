class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ans;
        string temp;
        for(auto i : strs) {
            temp = i;
            sort(temp.begin(), temp.end());
            m[temp].push_back(i);
        }
        for(auto i:m) {
            ans.push_back(i.second);
        }
        return ans;
    }
};