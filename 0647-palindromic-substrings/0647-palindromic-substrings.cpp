class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int j=0;j<n;j++) // end is taken in first loop
        {
            for(int i=0; i<=j; i++)
            {
                if((s[i] == s[j]) && ( (j-i <= 1) || ( dp[i+1][j-1] == true)))
                {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        } 

        return cnt;
    }
};