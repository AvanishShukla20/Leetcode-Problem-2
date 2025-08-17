class Solution {
public:
    bool isPalindrome(int i, int j, string& s, vector<vector<int>>& pal)
    { 
        if(pal[i][j] != -1) return pal[i][j];

        while(i < j)
        {
            if(s[i] != s[j]) return pal[i][j] = false;
            i++;
            j--;
        }
        return pal[i][j] = true;
    }

    int solve(int i,int& n, string& s, vector<int>& dp, vector<vector<int>>& pal)
    {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;

        for(int j = i; j < n; j++)
        {
            if(isPalindrome(i, j, s, pal))
            {
                int pos = 1 + solve(j+1,n, s, dp, pal);
                mini = min(mini, pos);
            }
        }
        return dp[i] = mini;

    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        vector<vector<int>> pal(n, vector<int> (n, -1));

        return solve(0,n, s, dp, pal) - 1;
    }
};