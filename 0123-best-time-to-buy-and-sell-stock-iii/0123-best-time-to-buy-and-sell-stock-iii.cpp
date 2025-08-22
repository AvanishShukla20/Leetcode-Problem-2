class Solution {
public: 
    int solve(int idx, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        if(k == 2) return 0;
        if(idx == prices.size()) return 0;
        if(dp[idx][buy][k] != -1) return dp[idx][buy][k];
        int maxi = 0;

        if(buy == 0)
        {
            maxi = -prices[idx] + max(maxi, solve(idx+1, 1, k, prices, dp));
            maxi = max(maxi, solve(idx+1, 0, k, prices, dp));
        }
        else
        {
            maxi = prices[idx] + max(maxi, solve(idx+1, 0, k+1, prices, dp));
            maxi = max(maxi, solve(idx+1, 1, k, prices, dp));
        } 
        return dp[idx][buy][k] = maxi;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));
        return solve(0, 0, 0, prices, dp);
    }
};