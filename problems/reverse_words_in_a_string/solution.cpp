class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int cnt=0;
        string temp;
        for(int i=0; i<s.length();i++){
            temp = "";
            while(s[i]!=' ' && i<s.length()){
                temp+=s[i];
                i++;
            }
            if(temp != ""){
                v.push_back(temp);
                cnt++;
            }
        }
        temp = "";
        for(int i=cnt-1;i>=0;i--){
            temp+=v[i];
            if(i != 0) temp+=" ";
        }
        return temp;
    }
};