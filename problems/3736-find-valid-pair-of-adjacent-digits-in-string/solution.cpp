class Solution {
public:
    string findValidPair(string s) {
        map<int,int> numbers;
        for (auto i : s) {
            int num = i - '0';
            numbers[num]++;
        }
        for(int i=0; i<s.size()-1; i++) {
            int curr = s[i] - '0';
            int next = s[i+1] - '0';
            if( numbers[curr] == curr && numbers[next] == next && curr!=next){
                return s.substr(i,2);
            }
        }
        return "";
    }
};
