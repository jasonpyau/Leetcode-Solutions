class MinStack {
public:
    void push(int val) {
        st.push(val);
        if (val <= curr_min) {
            curr_min = val;
            min_st.push(curr_min);
        }
    }
    
    void pop() {
        if (st.top() == curr_min) {
            min_st.pop();
            curr_min = (min_st.empty()) ? INT_MAX : min_st.top();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }

private:
    stack<int> st;
    stack<int> min_st;
    int curr_min = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
