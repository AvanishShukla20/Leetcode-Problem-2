class Solution {
public:
    int lcs(int i, int j, string s1, string s2, vector<vector<int>>& dp)
    {
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        //match

        if(s1[i - 1] == s2[j - 1]) return 1 + lcs(i-1,j-1, s1, s2, dp);

        int not_match = 0 + max(lcs(i-1, j, s1, s2, dp), lcs(i, j-1, s1, s2, dp));

        return dp[i][j] = not_match;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m+1, -1));

        int Longest_common_len = lcs(n, m, word1, word2, dp);
        cout<<Longest_common_len<<endl;

        int ans = n + m - 2*Longest_common_len;
        return ans;
    }
};