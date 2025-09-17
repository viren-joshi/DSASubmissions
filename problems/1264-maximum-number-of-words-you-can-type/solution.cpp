#include <bits/stdc++.h>
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<char> brknLetters(brokenLetters.begin(), brokenLetters.end());
        int count = 0;
        bool flag;
        string temp;
        stringstream ss(text);
        while(ss >> temp){
            flag = true;
            for(char c: temp){
                if(brknLetters.count(c) != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }
        return count;
    }
};
