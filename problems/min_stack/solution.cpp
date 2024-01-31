class MinStack {
public:
    stack<int> stack, minStack;
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        if(val < minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
        stack.push(val);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */