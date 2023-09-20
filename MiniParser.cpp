/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> st;
        int i = 0;
        if (s[0] != '[') {
            return NestedInteger(nextInt(s, i));
        }
        for (; i < s.size(); ++i) {
            if (isdigit(s[i]) || s[i] == '-') {
                st.top().add(NestedInteger(nextInt(s, i)));
            } else {
                if (s[i] == '[') {
                    st.push(NestedInteger());
                } else if (s[i] == ']') {
                    NestedInteger nest = st.top();
                    st.pop();
                    if (st.empty()) {
                        return nest;
                    } else {
                        st.top().add(nest);
                    }
                }
            }
        }
        return NULL;
    }
private:
    int nextInt(string& s, int& i) {
        int ans = 0, sign = 1;
        if (s[i] == '-') {
            sign = -1;
            ++i;
        }
        while (i < s.size()) {
            if (isdigit(s[i])) {
                ans *= 10;
                ans += s[i]-'0';
                ++i;
            } else {
                --i;
                break;
            }
        }
        return sign*ans;
    }
};
