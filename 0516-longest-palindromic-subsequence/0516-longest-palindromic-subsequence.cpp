class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp)
    {
        if(i > j) return 0;
        if(i == j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        // true condition
        if(s[i] == s[j]) res = 2 + solve(i+1, j-1,s, dp);
        else
        {
            int pos1 = solve(i, j-1, s, dp);
            int pos2 = solve(i+1, j, s, dp);
            res = max(pos1, pos2);
        }

        return dp[i][j] = res;
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0, n-1, s, dp);
    }
};