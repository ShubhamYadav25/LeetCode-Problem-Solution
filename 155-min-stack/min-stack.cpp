class MinStack {
public:
    stack<int> values;
    stack<int> minSt;
    MinStack() {}

    void push(int val) {
        values.push(val);
        if (minSt.empty()) {
            minSt.push(val);
        } else {
            minSt.push(min(val, minSt.top()));
        }
    }

    void pop() {
        values.pop();
        minSt.pop();
    }

    int top() { return values.top(); }

    int getMin() { return minSt.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */