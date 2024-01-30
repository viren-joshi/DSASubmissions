class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int temp1,temp2;
        for(string i : tokens) {
            if(i == "+") {
                temp1 = s.top();
                s.pop();
                temp2 = s.top();
                s.pop();
                s.push(temp2 + temp1);
            } else if (i == "-") {
                temp1 = s.top();
                s.pop();
                temp2 = s.top();
                s.pop();
                s.push(temp2 - temp1);
            } else if (i == "*") {
                temp1 = s.top();
                s.pop();
                temp2 = s.top();
                s.pop();
                s.push(temp2 * temp1);
            } else if (i == "/") {
                temp1 = s.top();
                s.pop();
                temp2 = s.top();
                s.pop();
                s.push(temp2 / temp1);
            } else
                s.push(stoi(i));
        }
        return s.top();
    }
};