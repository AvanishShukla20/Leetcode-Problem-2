class Solution {
public:
    bool solve(int i, int j,  string& s, vector<vector<int>>& dp)
    {
        if(i > j) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = solve(i+1, j-1, s, dp);
        return dp[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int idx = 0, maxlen = INT_MIN;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(solve(i, j, s, dp) == true)
                {
                    if(j-i+1 > maxlen)
                    {
                        maxlen = j-i+1;
                        idx = i;
                    }
                }
            }
        }

        string ans = s.substr(idx, maxlen);
        return ans;

    }
};