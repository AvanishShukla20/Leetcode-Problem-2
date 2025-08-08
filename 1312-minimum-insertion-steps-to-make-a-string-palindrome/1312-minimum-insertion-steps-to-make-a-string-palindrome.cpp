class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp)
    {
        if(i > j || i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) return dp[i][j] = solve(i+1, j-1, s, dp);
        else
        {
            int pos1 = solve(i+1, j, s, dp) + 1;
            int pos2 = solve(i, j-1, s, dp) + 1;
            return dp[i][j] = min(pos1, pos2);
        } 
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, n-1, s, dp);
    }
};