class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> all(allowed.begin(), allowed.end());
        int length = all.size(), count = 0;
        bool flag;
        for(auto word : words) {
            flag = true;
            unordered_set<char> temp(word.begin(), word.end());
            for(auto c: temp) {
                if(all.find(c) == all.end()){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};