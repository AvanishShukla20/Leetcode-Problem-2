class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k == n) return "0";

        // not able to think of solution even the brute force :(
        stack<char> st;

        for(int i=0; i<n;i++)
        {
            while(!st.empty() && st.top() > num[i] && k > 0)
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // remove extra k 

        while(k>0)
        {
            st.pop();
            k--;
        }
        string ans = "";
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        while(!ans.empty() && ans.back() == '0')
        {
            ans.pop_back();
        }


        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};