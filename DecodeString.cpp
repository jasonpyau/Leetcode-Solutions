class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        stack<string> st;
        st.push(string());
        while (i < s.size()) {
            string next = parseNext(s, i);
            if (isdigit(next[0])) {
                // Push the number to repeat
                st.push(next);
                // Parse the '[' and push an empty string
                parseNext(s, i);
                st.push(string());
            } else if (next == "]") {
                // Pop off string to repeat
                string repeat = st.top();
                st.pop();
                // Pop off the number to repeat
                int n = stoi(st.top());
                st.pop();
                for (int j = 0; j < n; ++j) {
                    st.top().append(repeat);
                }
            } else {
                st.top().append(next);
            }
        }
        return st.top();
    }
private:
    // Parse '[', ']', consecutive digits/letters
    string parseNext(string& s, int& i) {
        if (!isalnum(s[i])) {
            return string(1, s[i++]);
        }
        string next;
        if (isdigit(s[i])) {
            while (i < s.size() && isdigit(s[i])) {
                next.push_back(s[i]);
                ++i;
            }
        } else {
            while (i < s.size() && isalpha(s[i])) {
                next.push_back(s[i]);
                ++i;
            }
        }
        return next;
    }
};
