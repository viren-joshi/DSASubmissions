class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int len = s.size();
        string str(len,'a');
        for (int i = 0; i < len; i++){
            str[indices[i]] = s[i];
        }
        return str;
    }
};