class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size(), cnt = 0; // this cnt plays major role 
        
        for(int i = 0; i < num.size(); i++)
        {
            while(!st.empty() && st.top() > num[i] && cnt < k)
            {
                st.pop();
                cnt++;
            }

            if(!st.empty() || num[i] != '0') st.push(num[i]);
            
        }

        while(!st.empty() && cnt < k)
        {
            st.pop();
            cnt++;
        }

        if(st.empty()) return "0";
        string ans = "";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        cout<<"ans : "<<ans<<endl;
        reverse(ans.begin(), ans.end());

        return ans;

    }
};