class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));

        for(int i = 0; i <= n; i++)
        {
            dp[i][0][2] = 0;
            dp[i][1][2] = 0;
        }

        for(int b = 0; b<=1; b++)
        {
            for(int c = 0; c <= 2; c++)
            {
                dp[n][b][c] = 0;
            }
        }


        for(int idx = n-1; idx >= 0; idx--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int cap = 1; cap >= 0; cap--)
                {
                    int profit = 0;

        if(buy)
        {
            int Buythis = -prices[idx] + dp[idx+1][0][cap]; 
            int notBuythis = 0 + dp[idx+1][1][cap];
            profit = max(Buythis, notBuythis);
        }
        else
        {
            int sellthis = prices[idx] + dp[idx+1][1][cap+1];
            int notsellthis = 0 + dp[idx+1][0][cap];
            profit = max(sellthis, notsellthis);
        }

        dp[idx][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][0];
    }
};