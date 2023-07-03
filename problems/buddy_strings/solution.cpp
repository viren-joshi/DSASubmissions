using namespace std;
class Solution {
    
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()){
            return false;
        }
        vector<int> indexes;
        map<char,int> freq;

        if(s==goal) {
            for(int i=0;i<s.length();i++){
                if(freq.find(s[i]) == freq.end()){
                    freq[s[i]] = 1;
                } else {
                    freq[s[i]]++;
                }
                if(freq[s[i]] == 2) {
                    return true;
                }
            }
        }

        for(int i = 0; i < s.length(); i++){
            if(s[i] != goal[i]) {
                indexes.push_back(i);
            }

        }
        if(indexes.size() != 2) return false;
        return (s[indexes[1]] == goal[indexes[0]] && s[indexes[0]] == goal[indexes[1]]);
    }
};