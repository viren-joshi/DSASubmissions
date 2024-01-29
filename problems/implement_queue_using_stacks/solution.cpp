class MyQueue {
public:
    stack<int> myStack;
    MyQueue() {
    }
    
    void push(int x) {
        vector<int> a;
        while(!myStack.empty()) {
            a.push_back(myStack.top());
            myStack.pop();
        }
        myStack.push(x);
        for(auto i = a.rbegin(); i!=a.rend(); ++i) {
            myStack.push(*i);
        }
    }
    
    int pop() {
        int val = myStack.top();
        myStack.pop();
        return val;
    }
    
    int peek() {
        return myStack.top();
    }
    
    bool empty() {
        return myStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

 /*
    ["MyQueue","empty","push","push","empty","peek","push","push","peek","pop","empty","peek","pop","empty"]
[[],[],[1],[1],[],[],[5],[5],[],[],[],[],[],[]]
["MyQueue","push","pop","push","empty","push","pop","peek","push","empty","pop","pop","push","push","peek","empty","empty","empty","pop","pop","push","push","pop","empty","empty","pop","push","empty","push","pop","push","peek","empty","pop","peek","push","empty","push","empty","push","peek","pop","empty","empty","pop","push","pop","pop","empty","push","pop","push","push","empty","empty","empty","peek","peek","peek","empty","pop","empty","pop","push","empty","pop","pop","push","empty","push","pop","empty","pop","push","peek","pop","push","push","push","push","empty","pop","peek","pop","pop","push","peek","pop","pop","push","pop","push","peek","push","empty","push","empty","push","peek","pop","pop"]
[[],[7],[],[8],[],[4],[],[],[4],[],[],[],[5],[7],[],[],[],[],[],[],[9],[8],[],[],[],[],[9],[],[4],[],[5],[],[],[],[],[6],[],[7],[],[5],[],[],[],[],[],[5],[],[],[],[2],[],[7],[5],[],[],[],[],[],[],[],[],[],[],[2],[],[],[],[8],[],[2],[],[],[],[2],[],[],[1],[7],[9],[5],[],[],[],[],[],[8],[],[],[],[7],[],[6],[],[7],[],[4],[],[2],[],[],[]]
["MyQueue","push","push","push","push","push","peek","push","push","push","push","peek","pop","pop","pop","pop","peek","pop","pop","peek","pop"]
[[],[1],[4],[9],[2],[2],[],[1],[2],[7],[1],[],[],[],[],[],[],[],[],[],[]]
["MyQueue","push","push","push","push","push","push","push","push","push","push","peek","pop","pop","pop","pop","pop","pop","pop","peek","pop"]
[[],[5],[6],[7],[6],[1],[8],[2],[5],[4],[7],[],[],[],[],[],[],[],[],[],[]]
["MyQueue","push","push","push","push","push","push","push","push","push","push","peek","pop","pop","pop","pop","pop","pop","empty","peek","pop"]
[[],[4],[5],[6],[7],[8],[1],[1],[2],[3],[4],[],[],[],[],[],[],[],[],[],[]]
["MyQueue","empty","push","push","push","push","push","empty","push","push","push","peek","empty","peek","pop","pop","empty","pop","pop","peek","pop"]
[[],[],[1],[1],[1],[1],[1],[],[3],[4],[5],[],[],[],[],[],[],[],[],[],[]]
["MyQueue","push","pop","empty","push","pop","push","pop","push","peek","empty","pop","push","pop","push","peek","pop","empty","push","pop","push"]
[[],[1],[],[],[2],[],[3],[],[4],[],[],[],[5],[],[6],[],[],[],[7],[],[8]]
["MyQueue","push","push","peek","pop","push","empty","pop","pop","push","push","empty","push","empty","pop","pop","peek","peek","peek","empty","empty","push","pop","pop","push","peek","pop","push","empty","pop","push","empty","empty","pop","push","empty","pop","push","empty","pop","push","peek","push","empty","pop","empty","pop","push","pop","push","empty","pop","push","empty","pop","push","pop","push","peek","pop","push","empty","pop","push","pop","push","push","empty","push","push","pop","empty","pop","push","pop","peek","pop","pop","push","peek","peek","push","empty","push","push","empty","empty","peek","empty","push","pop","pop","pop","peek","empty","pop","push","peek","empty","empty","peek"]
[[],[9],[3],[],[],[5],[],[],[],[3],[8],[],[8],[],[],[],[],[],[],[],[],[4],[],[],[4],[],[],[8],[],[],[3],[],[],[],[4],[],[],[8],[],[],[2],[],[6],[],[],[],[],[1],[],[7],[],[],[8],[],[],[5],[],[6],[],[],[3],[],[],[9],[],[2],[6],[],[3],[5],[],[],[],[6],[],[],[],[],[9],[],[],[2],[],[3],[4],[],[],[],[],[3],[],[],[],[],[],[],[1],[],[],[],[]]
 */