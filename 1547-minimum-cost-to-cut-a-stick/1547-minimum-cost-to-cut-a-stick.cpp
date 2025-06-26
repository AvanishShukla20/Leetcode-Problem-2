class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n); 
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m + 2, vector<int> (m+2, 0));

        for(int s = m; s>=1; s--)
        {
            for(int e = s; e<=m; e++)
            {
                int mini =  1e9;
                for(int idx = s; idx<=e;idx++)
                {
                    int v1 = cuts[e+1] - cuts[s-1] + dp[s][idx-1] +  dp[idx+1][e];
                    mini = min(mini, v1);
                }
                dp[s][e] = mini;
            }
        }
        return dp[1][m];

    }
};