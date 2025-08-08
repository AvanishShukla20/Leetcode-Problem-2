class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp)
    {
        if(i == j || j < i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j])
        {
            return solve(i+1, j-1, s, dp);
        }
        int mini = 1e6;

        mini = min(mini, 1 + solve(i+1, j, s, dp));
        mini = min(mini, 1 + solve(i, j-1, s, dp));
        return dp[i][j] = mini;
    }
    int minInsertions(string s) {
        int  n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, s, dp);
    }
};