class Solution {
public:
    bool helper(char& opr, vector<bool> & vec)
    {
        bool istruepresent = false, isfalsepresent = false;
        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i] == true) istruepresent = true;
            if(vec[i] == false) isfalsepresent = true;
        }

        if(opr == '&') return isfalsepresent == false;
        if(opr == '|') return istruepresent == true;
        return !vec[0];
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack<char> st;
        for(int i=0; i<n; i++)
        {
            if (expression[i] == ',' || expression[i] == ' ') continue;

            if (expression[i] != ')') {
                st.push(expression[i]);
            } 
            else
            {
                vector<bool> vec;

                
                while (!st.empty() && st.top() != '(') {
                    if (st.top() == 't') vec.push_back(true);
                    else if (st.top() == 'f') vec.push_back(false);
                    st.pop();
                }

                st.pop(); // remove '('
                char opr = st.top(); st.pop();

                bool r = helper(opr, vec);
                if(r == false) st.push('f');
                else st.push('t');
            }
        }


        if(!st.empty() && st.top() == 't') return true;
        return  false;
    }
};