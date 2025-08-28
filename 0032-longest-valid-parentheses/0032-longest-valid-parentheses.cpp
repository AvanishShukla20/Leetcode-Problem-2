class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else { // s[i] == ')'
                if (st.top() == -1) st.push(i);
                else{
                    st.pop();
                }  
            }
        }

        // Add n as the boundary after the end
        st.push(n);
        int ans = 0;
        vector<int> t;
        while (!st.empty()) {
            t.push_back(st.top());
            st.pop();
        }
        reverse(t.begin(), t.end());

        for (int i = 1; i < t.size(); i++) {
            ans = max(ans, t[i] - t[i-1] - 1);
        }
        return ans;
    }
};
