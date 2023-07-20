class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int top;
        for (int asteroid : asteroids) {
            if (asteroid < 0) {
                top = 0;
                while (!st.empty() && st.top() > 0 && abs(asteroid) > st.top()) {
                    top = st.top();
                    st.pop();
                }
                if (st.empty()) {
                    if (abs(asteroid) > top) {
                        st.push(asteroid);
                    }
                } else if (abs(asteroid) == st.top()) {
                    st.pop();
                } else if (st.top() < 0) {
                    st.push(asteroid);
                }
            } else {
                st.push(asteroid);
            }
        }
        vector<int> ans(st.size());
        for (int i = ans.size()-1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
