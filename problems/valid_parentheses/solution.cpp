class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char,char> m = {
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };
        char temp;
        for(char c: s) {
            if(m.contains(c)) {
                stack.push_back(c);
            } else {
                if(stack.size() != 0) {
                    temp = stack[stack.size() - 1];
                    if(m[temp] == c)
                        stack.pop_back();
                    else 
                        return false;
                } else
                    return false;
            }
        }
        return stack.size() == 0;
    }
};