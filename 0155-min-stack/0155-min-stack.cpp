// https://leetcode.com/problems/min-stack

class MinStack {
public:
    stack <int> stack,minStack;
    MinStack() {     
    }
    
    void push(int val) {
        if (minStack.empty() || getMin() >= val)
            minStack.push(val);
        stack.push(val);
    }
    
    void pop() {
        if (getMin()== top())
            minStack.pop();
        stack.pop();
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