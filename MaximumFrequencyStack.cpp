class FreqStack {
public:
    void push(int val) {
        int freq = ++val_to_freq[val];
        freq_to_vals[freq].push(val);
        max_freq = max(max_freq, freq);
    }
    
    int pop() {
        stack<int>& vals = freq_to_vals[max_freq];
        int val = vals.top();
        --val_to_freq[val];
        vals.pop();
        if (vals.empty()) {
            --max_freq;
        }
        return val;
    }
private:
    int max_freq = 0;
    unordered_map<int, stack<int>> freq_to_vals;
    unordered_map<int, int> val_to_freq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
