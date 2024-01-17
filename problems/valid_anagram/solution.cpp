class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        
        int l = s.size();
        if(l!=t.size())
        return false;
        for(int i = 0; i<l; i++) {
            map[s[i]]--;
            map[t[i]]++;
        }
        for(auto i = map.begin(); i!=map.end(); ++i) {
            if(i->second!=0)
            return false;
        }
        return true;
    }
};