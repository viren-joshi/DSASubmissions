class Solution {
public:
    bool isVowel(char c){
        return (c =='a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
    }

    string toGoatLatin(string sentence) {
        vector<string> words;
        string ans;
        string temp = "";
        for(int i = 0; i <= sentence.length(); i++){
            if(i==sentence.length()){
                words.push_back(temp);
            }
            if(sentence[i]==' '){
                words.push_back(temp);
                temp = "";
            } else {
                temp+=sentence[i];
            }
        }
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            if(isVowel(s[0])) {
                s = s + "ma";
            } else {
                s = s.substr(1,s.length()-1) + s[0] + "ma";
            }
            for(int j = i; j>=0; j--){
                s = s + "a";
            }
            if(i!=0)
            s= " " + s;
            ans.append(s);
        }
        
        return ans;

    }
};