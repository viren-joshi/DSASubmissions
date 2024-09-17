class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> freq;
        vector<string> ans;
        string word;
        stringstream ss1(s1), ss2(s2);
        while(ss1 >> word) {
            freq[word]++;
        }
        while(ss2 >> word) {
            freq[word]++;
        }
        for(auto i = freq.begin(); i!=freq.end(); i++) {
            if(i->second == 1) {
                ans.push_back(i->first);
            }
        }
        return ans;
    }
};