class Solution {
public:
    bool isgood(char ch, stack<char>& st) {
        if (st.empty()) return false;

        char top = st.top();
        if ((ch == ')' && top != '(') ||
            (ch == '}' && top != '{') ||
            (ch == ']' && top != '['))
            return false;

        st.pop();
        return true;
    }

    bool isValid(string s) {
        stack<char> st;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (isgood(s[i], st) == false) return false;
        }
        else if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
    }
    return st.empty();
    }
};