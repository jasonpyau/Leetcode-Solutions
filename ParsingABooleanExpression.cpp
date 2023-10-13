class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        vector<char> temp;
        for (char ch : expression) {
            if (ch == ',') {
                continue;
            } else if (ch != ')') {
                st.push(ch);
                continue;
            }
            // If ), evaluate expression.
            while (st.top() != '(') {
                temp.push_back(st.top());
                st.pop();
            }
            // Pop (.
            st.pop();
            char result = (eval_op(temp, st.top())) ? 't' : 'f';
            // Pop logical operator.
            st.pop();
            st.push(result);
            temp.clear();
        }
        return (st.top() == 't');
    }
private:
    bool eval_op(vector<char>& booleans, char op) {
        if (op == '!') {
            // Only one boolean in vector.
            return (booleans.back() == 'f');
        } else if (op == '&') {
            for (char boolean : booleans) {
                if (boolean == 'f') {
                    return false;
                }
            }
        } else {
            for (char boolean : booleans) {
                if (boolean == 't') {
                    return true;
                }
            }
        }
        return (op == '&');
    }
};
