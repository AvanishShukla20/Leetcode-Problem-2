class Solution {
public:
    bool isMatch(char& ch, char &sc)
    {
        return ((ch == '(' && sc == ')') || (ch == '{' && sc == '}') || (ch == '[' && sc == ']')) ;
    }
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();

        for(int i=0; i<n; i++)
        { 
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else
            {
                // ')'  or '}' or ']'
                
                if(st.empty()) return false;
                char ch = st.top();

                if(!isMatch(ch , s[i]))
                {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};