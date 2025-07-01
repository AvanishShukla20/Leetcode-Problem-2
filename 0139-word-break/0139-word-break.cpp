class Solution {
public:
    bool solve(int idx, string s, unordered_set<string>& st, vector<int> & dp)
    {
        if(idx >= s.size()) return dp[idx] = true;
        if(dp[idx] != -1) return dp[idx];

        // if this is present then return true

        if(st.find(s) != st.end()) return dp[idx] = true;
        
        for(int len = 1; len<=s.size(); len++)
        {
            string sub = s.substr(idx, len);
            if(st.find(sub) != st.end() && solve(idx+len, s, st, dp) == true) return dp[idx] = true;
        }

        return dp[idx] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.size()+1, -1);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(0, s, st, dp);
    }
};